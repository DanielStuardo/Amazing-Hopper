#include <hbasic.h>

Begin
  Tic( t )
  i=0
  While ( 1 )
     If KeyPressed?
        Break
     End If
     /*** esta instrucción no esta documentada ***/
     In Time( 0.01 ~= t, Print("Mensaje ",i,"!\n") )
     ++i
  Wend
  Print("I = ",i,Newl)
End
