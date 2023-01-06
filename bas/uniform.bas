
#include <hbasic.h>

Begin
   x=0,nCol=5
   UniformRand(x,1,0.25,10,Add(nCol,1))
   Print("Variable Uniforme Aleatoria:",¶,x,¶)
   Clear(x)
End
