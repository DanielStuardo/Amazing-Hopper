
#include <hbasic.h>

Begin
   Dim(20) as Int Rnd Array(v,10)
   Print (v,Newl)
   
   ReDim(v,4,5)
   Print (v,Newl)
End
