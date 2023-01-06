
#include <hbasic.h>

#define MAX_LINE  1024

Begin
   Declare as Numeric (v,fd,i)

   Search Lines("archivo.txt",v)
   
   Print(v,Newl)
   Print(get SLinePos(v,93),Newl)
   Print(get SPosLine(v,3),Newl)
   
   Open(OPEN_READ,"archivo.txt") (fd)
   
   If Not File Error?
      Print(Str2Utf8$("Abrió bien\n"))
      i=1
      While Not Eof(fd)
         Print( get SLine$(i++,MAX_LINE,v,fd), Newl )
      Wend
   Else
      Print("Error: ",~String File Error$ ,Newl)
   End If
   Print("Size archivo.txt: ", Size File(fd),Newl)
   Close(fd)
   
   
End
