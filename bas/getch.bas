
#include <hbasic.h>

Begin
   x=0
   While ( 1 )
      Let( x:=GetCh )
      Print(x," = ", Chr$(x),Newl)
      Exit If (x) Is Escape
   Wend
/*   PutKey(KUP)
   Print("Presione una tecla con o sin acentos...",Newl)
   x=0,
   //GetCh,  //Join$(x)
   Let( x := GetCh )
   Print(x,Newl)
   clear(x)
   jsub(prueba)
   PutKey(KUP)
   Print("Presione una tecla con o sin acentos...",Newl)
   x=0,
   //GetCh,  //Join$(x)
   Let( x := GetCh )
   Print(x,Newl)
   
   Print("Presione otra tecla con o sin acentos...",Newl)
   clear(x),x=0
   PutKey(KDOWN)
   GetChar(x),
   Print("Caracter = ",Asc(x),Newl)
  /// Let ( x:=Chr$(x))
   Print(x," Len = ",Len(x),Newl)
   Print(Str2Utf8$(x)," Len (sobre caracter sin UTF8) = ",Len(x),Newl)
   Let (x:=Str2Utf8$(x))
   Let (x:=Cat$("1",x))
   Print(x," Len = ",Len(x),Newl)
   Print(Newl, Str2Utf8$("Conclusión: UTF8 mejor usarlo para despliegue"),Newl)
   jmp(sale)
prueba:
   back */
sale:
End
