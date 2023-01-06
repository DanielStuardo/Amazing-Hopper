
#include <hbasic.h>

Begin
  Dec as Alpha (s)
  Let (s := Cat$("RELATOS DEL ","LADO OSCURO") )
  Print("MSG = ",s,¶)
  
  Take("RELATOS DEL ")+(Lower$("LADO OSCURO")), Move(s)
  Print("MSG = ",s,¶)

  Take("RELATOS DEL ")+(Lower$("LADO "))+("\BGW\BKOSCURO\OFF"), Move(s)
  Print("MSG = ",s,¶)

//  NO SE PUEDE PONER UN TAKE DENTRO DE UN LET, PORQUE AMBOS SON PRIMARIAS:  
//  Let( s:= Take("RELATOS DEL ")+(Lower$("LADO "))+("\BGW\BKOSCURO\OFF") )
//  Print("MSG = ",s,¶)
  
  s=""
  MCat$(s := "Relatos", " ", "del"," ", "Lado"," ", "Oscuro",":", Str$(++(Len("supercalifragidistico"))) )
  Print("MSG = ",s,¶)
End
