

#include <hbasic.h>

Begin
  Dec as Numeric (i,col)
  //Canvas Ocean, White Pencil
  set Canvas Terminal, Amber Pencil
  Bold,Cls
  Italic,Print("Lista de colores [0-255]:",Newl),Italic Off
  col=1
  For (i=0, while var(i)Is Le(255), ++i)
     Foreground(i),Print(LPad$(" ",4,Str$(i)))
     ++col, 
     When( Gt(col,16) ){ col=1, Put a Newl }
  Next
  put Pause
  Bold Off
  set Color(Add(229,1);Minus(29),Sub(238,18)),Print("Hola mundo!\OFF\n")
  
  set RGBF(178,255,51), RGBB(60,6,19), Print("Hola mundo!\n")

  Print("\OFFHola mundo!\n")

  Color(124,231),Print("Hola mundo!!!\OFF\n")
  Print( "\CF123m\CB237m","Hola mundo!\OFF\n")
End
