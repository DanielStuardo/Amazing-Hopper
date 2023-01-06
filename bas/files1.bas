
#include <hbasic.h>

#define MAX_LINE  1024

Begin
   fd=0
   Open(OPEN_READ,"archivo.txt") (fd)
   If Not File Error?
      Print(Str2Utf8$("Abrió bien\n"))
      w=0, Let ( w := ReadRow(MAX_LINE) (fd) )
      Print("Linea leida: ",w,Newl,"Tipo:",Type$(w),Newl)
   Else
      Print("Error: ",~String File Error$ ,Newl)
   End If
   Close(fd)
   
End
