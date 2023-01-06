#include <hbasic.h>

Begin
   Number as (X)
   Cls
   Let (X:=Actual Calendar)
   Locate(9,10),Print("Calendario Actual Mes ",Month$(DateNow$),":",Newl)
   Token Sep(" ")
   LocRow(10),Print Table(X)
   PutNewl
End
