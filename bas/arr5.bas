
#include <hbasic.h>

Begin
   Cls
   Seed(1234)
   Dim (10,10) as Int Rnd Array(v,10)
   For All( v, [5:end,Add(1,1):2:end], Sqrt(Mul by(10)))
   /* opcional: usar seguidilla de instrucciones:
     For All( v, [5:end,Add(1,1):2:end], Mul by(10),~Sqrt)
   */
   //Print(v, Newl)

   w=0,Take(" ",8)
       Let ( w := LPad$(Str$(v)) )
   Locate (10,5), Print Table(w)
   //{v,10,10}print2d
   PutNewl

End
