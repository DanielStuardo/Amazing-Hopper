
#include <hbasic.h>

Begin
   
   Dim (10,10) as Int Rnd Array(v,10)
   w=v  /* respaldo */
   Print(v, Newl)
   rango=0, Let ( rango := Find All( Ge(v,7) ) )
   Put Range(rango)
   v = 0
   Clear Range
   Print(v, Newl)

   Clear(rango), Let ( rango := Find All( Not(Ge(w,7) )) )
   Put Range(rango)
   w = 0
   Clear Range
   Print(w, Newl)
End
