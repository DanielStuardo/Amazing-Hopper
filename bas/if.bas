
#include <hbasic.h>

Begin
  x=10, y=0

  Cls
  Locate cursor in (2,10), then Print("Texto \LRrojo\OFF localizado en pantalla", Newl)

  doing it, If ( Is Zero?(y) and are Eq(x,10))
     Print ("Todo se cumple", Newl)
  End If

  ++y
  If ( And (Zero?(y), Eq(x,10)) )
     Print ("Todo se cumple", Newl)
  Else
     Print ("No todo se cumple", Newl)
  End If
  
  If ( Is Not Zero?(y) and ( are Eq(x,11) or( var (x) Is Eq?(10) ) ) )
     then Print ("Todo se cumple", Newl)
  Else
     Print ("No todo se cumple", Newl)
  End If
/*  Set Token("\t"), and Print Using Token ("Hola",200,~True,"Mundo!!",Newl)
  
  Set Token(",")
  t="token1,token2,token3"
  Pivot(t)
     Tkn(1), TknRepl$("Hola mundo!!")
     
     Tkn(1), TknSwap$(3)
     Flush(t)
  Print( t, Newl ) */
End

