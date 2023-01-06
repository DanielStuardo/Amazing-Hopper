
#include <hbasic.h>

Begin
   Dim (10,10) as Fill Array("Hola",x)
   
   Print("Array:",¶,x,¶)
   
    [5,1:2:5]Take("____"), Put(x)
    Get(x),Clear All, [6:8,7] SPut(x)
 
   //  [5,1:2:5], x="____", 
   //  Get(x),Clear All, [6:8,7], SPut(x)
 
 //   [1:5,1:5]Take("____"), SPut(x)
 //  [1:5,1:5], x="____", Clear All
   
   Print("Array:",¶,x,¶)
End

/*
[1:2:5,1:2:5]Take("____"), SPut(x)
Array:
____,Hola,____,Hola,____,Hola,____,Hola,____,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola
____,Hola,____,Hola,____,Hola,____,Hola,____,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola
____,Hola,____,Hola,____,Hola,____,Hola,____,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola
____,Hola,____,Hola,____,Hola,____,Hola,____,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola
____,Hola,____,Hola,____,Hola,____,Hola,____,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola

[1:2:5,1:2:5], x="____", Clear All
Array:
____,Hola,____,Hola,____,Hola,Hola,Hola,Hola,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola
____,Hola,____,Hola,____,Hola,Hola,Hola,Hola,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola
____,Hola,____,Hola,____,Hola,Hola,Hola,Hola,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola
Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola,Hola
Este es el correcto! ¿Por qué PUT hace otra cosa ante los mismos comandos?
FALLAN LOS INTERVALOS EN PUT!!!!!

*/
