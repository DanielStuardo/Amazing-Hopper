#!/usr/bin/hopper

//#define  :=(__X__)    ;cpy(__X__)
//#define  =(__X__)     ;mov(__X__)
// Archivo Hopper-Basic
#include <hbasic.h>

Begin
  Dec as Alpha (dir,ot,nuevo)
      as Numeric(total archivos,t,nt)

  dir = `ls CM/*_???_*`  //renombra archivos con redes >100.
  Token Sep(Newl)
  Let ( total archivos := TotalTokens(dir))

  For Each Tkn(v := dir,total archivos)
     Print(v,"---> ",)
     Token Sep("_")
     Let( t := Str$( Val(get Token$(3,v);Copy(ot));Move(nt); Iif( Gt(nt,100),Sub(nt,100),nt ) ) )

     If ( Are Neq(t, ot))
        Let ( nuevo := TranFirst$(t,ot,v))
        Print(nuevo, Newl)
        System("mv ",v," ",nuevo)
     Else
        Print("No se renombra.\n")
     End If
     Token Sep(Newl)
     Put a Newl
  Next
End
