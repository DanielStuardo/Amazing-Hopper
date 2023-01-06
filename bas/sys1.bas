
#include <hbasic.h>

Begin
   Print ( GetEnv("LC_TIME"), Newl )
   mascara$="*.c"
   System("ls ",mascara$," -stra")
   
   d=""
   Let ( d := Execute ("ls ",mascara$," -stra") )
   Print( "Listado almacenado en variable:\n", d )
   
   Get Param (A,B,C,D)
   
   Print("Param 1 = ",A,Newl)
   Print("Param 2 = ",B,Newl)
   Print("Param 3 = ",C,Newl)
   Print("Param 4 = ",D,Newl)
End
