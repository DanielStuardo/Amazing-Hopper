
#include <hbasic.h>

Begin
  Tic( t )
  i=0
  While ( 1 )
     If KeyPressed?
        Break
     End If
     If ( LookTime(0.1 ~= t) )
        Print("Mensaje ",i,"!\n")
     End If
     
     ++i
  Wend
  Print("I = ",i,Newl)
End
