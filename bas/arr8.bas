
#include <hbasic.h>

Begin
   Cls  // quite esto si quiere usar pipe a un archivo
   //set Seed(1234)
   Dim (10,10) as Int Rnd Array(10,v)
   Print(v,Newl)

   // modo correcto de H-Basic para trabajar con arrays:
   pivote=0,Let( pivote := [10,10]SGet(v) )
   //Mul( Sqrt([1:5,1:5]Get(v)), pivote ),Plus(1000),SPut(v) 
   // cuando se trabajan con rangos persistentes, se puede hacer esto:
   i=3
   Set Interval [1:5,1:++(++(i))],Mul( Sqrt(Get(v)), pivote ),Plus(1000),then SPut(v) 

   w=0, Let ( w := LPad$(" ",8,Str$(v)) )
   Locate (14,5), Print Table(w)  //// quite esto si quiere usar pipe a un archivo
   //Print(w,Newl)
   
   then Put a Newl
 //  PrevLines(5)
End
