/** instruccion deviate no documentada **/
#include <hbasic.h>

Begin
  Tic( t )
  i=0
  While ( 1 )
     If KeyPressed?
        Break
     End If
     
     Deviate If( 0.05 ~= t ) {
        Print("Mensaje ",i,"!\n")
     }
     ++i
  Wend
  Print("I = ",i,Newl)
End
