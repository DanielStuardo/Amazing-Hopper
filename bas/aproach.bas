
#include <hbasic.h>

Begin
   Dim (3,3) as Int Rnd Array(x,100)
   Dim (3,3) as Int Rnd Array(y,100)
   Compara ← 0
   Porcentaje ← 0.6
   Let( Compara := Le(x,y) )
   Print( Compara, ¶)
   Print( Compara, Aproach?( Porcentaje ),¶ )
   If ( Take(Compara), Aproach?( Porcentaje ) )
      Take("Array X es ",Mul(Porcentaje,100),"% menor o igual al array Y, aprox",¶)
   Else
      Take("Array X no se ve tan menor o igual al array Y",¶)
   End If
   Print
   Clear(x), Clear(y)
End
