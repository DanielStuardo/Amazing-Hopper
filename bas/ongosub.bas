
#include <hbasic.h>

Begin
  
  n=3,fail=0
  Take(n), On Gosub (et1, et2, et3) // si no es ninguna de las opciones, deja "n" en stack.
  If Mem Busy?
     Move(fail),Print("La opcion fallida fue: ",fail,Newl)
  End If
 
  n=3
  Take(n), On Option ( ++n, --n, n+=10, n-=10 )
  If Not Mem Empty?
     Move(fail),Print("La opcion fallida fue: ",fail,Newl)
  End If
  Print(".",n,Newl)
  Goto(salir)
 
et1:
  Print("HOLA!,",n,Newl), Back
 
et2:
  Print("CHAO!,",n,Newl), Back

et3:
  Print("LOCO!",n,Newl),Back

salir:
End
