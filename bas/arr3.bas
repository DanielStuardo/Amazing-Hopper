
#include <hbasic.h>

Begin
   
   v=0
   [2:end,2:end]
   Let ( v := LoadMat("archivo.txt") )
   
   Print (v,Newl)
End
