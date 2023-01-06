
#include <hbasic.h>

Begin
   cFile = "tag.txt"
   fd=0,n=0,s="",v=0
   
   SearchLines(cFile,v)
   
   Open(OPEN_READ,cFile)(fd)
   Print("Posicion actual: ", GetPos(fd), Newl )
   
   Let( s := ReadLinesFromPos$(fd,5,1000) )
   Print("5 Líneas leidas:\n",s,Newl)
   
   nSavePos=0
   Let( nSavePos := GetPos(fd))
   relLine=0
   Print("Nueva posicion: ",nSavePos,Newl)
   
   Print("Linea relativa de nueva posicion: ",GetSLinePos(v,nSavePos),Copy to(relLine), Newl)
   Print("Nueva posicion obtenida a partir de la linea relativa: ", GetSPosLine(v,relLine), Newl)
   Print("Y la linea que esta ahi es:\n", GetSLine$(relLine, 1000, v, fd))
   
   SetEnd(fd)
   Let ( n:=GetPos(fd))
   Print("Posicion actual: ", n, Newl )
   Print( "EOF? = ", Eof(fd),Newl)
   Close(fd)
   
End
