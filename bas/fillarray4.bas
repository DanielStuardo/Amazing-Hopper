
#include <hbasic.h>

Begin
   Dim (10,10,3) for a Fill Array("Hola",x)
   
   first:     Print("Array:",Newl,x,Newl)
   
   second:    Def Interval [5:7,1:2:5,2], then Take("____") and Put(x)
    //Get(x),Clear All, [6:8,6:2:10,1] SPut(x)
   and then:  
   /*manteniendo el intervalo antes definido:*/ Get(x),Clear All; At Interval [6:8,6:8,1], SPut(x)
 
   //  [5,1:2:5], x="____", 
   //  Get(x),Clear All, [6:8,7], SPut(x)
 
 //   [1:5,1:5]Take("____"), SPut(x)
 //  [1:5,1:5], x="____", Clear All
   finally:
   Print ("Array:\n",x,Newl)
   
//   If( Cte ("x") Occurs In?("abcdexfghi") ) 
   If( in expression (Upper$("abcdexfghi")) Occurs It?("X") ) 
      Print ( Str2Utf8$("Encontré un match!") ), and put a Newl
   End If
   
   Take("Fin del programa\n"), and Print It
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
SOLUCION: debia usar la funcion GET_LENGTH(), que creé para esto, pero
que por AHUEONAO IN EXTREMIS no actualicé la función PUT_ARRAY.
*/
