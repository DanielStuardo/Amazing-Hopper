#!/usr/bin/hopper

#include <hbasic.h>

Begin
   ancho=500
   alto=500
   min real=-2
   min complex=-2
   max real = 2
   max complex = 2
   
   Declare as Numeric (submaxRminR, submaxCminC)
   Let ( submaxRminR := var(max real) Minus (min real) )
   Let ( submaxCminC := var(max complex) Minus (min complex) )

   Dim (ancho, alto) for a NaN Array(mandel)
   Declare as Numeric(t1,t2, ta, a, b, a1, b1)
   
   Tic(t1)

   For Up ( i:=1, ancho, 1 )
      //ta=min real + ((max real-min real) * (i-1)/(ancho-1))
      Let( ta := Div(Minus 1 (i), Minus 1 (ancho)), Mul by(submaxRminR), Plus (min real) )

      For Up( j:=1, alto, 1 )
         a=ta
         //b=min complex+((maxcomplex-mincomplex)*(j-1)/(alto-1))
         Let( b := Div(Minus 1 (j), Minus 1 (alto)), Mul by( submaxCminC ), Plus (min complex) )
         a2=a
         b2=b
         k=0
         brillo=1
         While ( var(k) Is Lt (100) )
            Let ( a1 := SqrDiff (a,b) )
            now Take(2,a,b), Multiply All, and Move to (b1)
            Let ( a := var(a1) Plus (a2) )
            Let ( b := var(b1) Plus (b2) )

            If ( SqrAdd(a,b) Is Gt? (4) )
               brillo=0, and Break
            End If
            ++k
         Wend
         Take(brillo); Set Interval [j,i], then Single Put(mandel)
      Next
   Next

   Toc(t1,t2)
   Print( "TIME = ",t2, Newl )
   Token Sep(",")
   Save Matrix (mandel,"mandel.dat")
End
