
#include <hbasic.h>

Begin
   Dec as Alpha (s)
   
   Take("Esto se va a imprimir\n" )
   Let (s := Tran$("-X-","O","RELATOS DEL LADO OSCURO") )
   Print("Tran$ = ", s, Newl)
   
   Let ( s:= TranFirst$("-X-","O","RELATOS DEL LADO OSCURO") )
   Print("TranFirst$ = ", s, Newl)
   
   Let ( s:= TranLast$("-X-","O","RELATOS DEL LADO OSCURO") )
   Print("TranLast$ = ", s, Newl)
   
   Let ( s:= TranTo$(3,"-X-","O","RELATOS DEL LADO OSCURO") )
   Print("TranTo$ = ", s, Newl)
   
   Let ( s:= TranToAll$(3,"-X-","O","RELATOS DEL LADO OSCURO") )
   Print("TranToAll$ = ", s, Newl)

   Let ( s:= TranFromTo$(2,2,"-X-","O","RELATOS DEL LADO OSCURO") )
   Print("TranFromTo$ = ", s, Newl)

End
