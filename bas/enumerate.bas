
#include <hbasic.h>

#enum   100, FUCCIA, ROSADO, NARANJA, VERDELIMON, \
        10, ROJO, AZUL, VERDE, AMARILLO

Begin
   Dec as Stack (l)
       as Alpha (s)
       as Numeric (m)
  
 /* Crea una matriz de 2x4 elementos */
   New Row(l, "Java","C","C++","Xu")
   New Row(l, "Hopper","Brain Fuck","Pascal","C#")

 /* La macro ENUM ARRAY enumera matrices de 1, 2 y 3 dimensiones, porque
    internamente las convierte en un vector. */
   Canvas Ocean, White Pencil, Cls
   m = l
   EnumArray(l,10)
   Print("Array original:",Newl,m,Newl,Dup It)
   Print("Array enumerado:",Newl,l,Newl)

   Let ( s := Str2Utf8$("María tenía un corderito Ñoño") )
   Token Sep(" ")
   EnumString (s,0)
   Token Sep(",")
   Print("String enumerado:",Newl,s,Newl)
   
   Print("Una constante ENUM (AMARILLO) = ",AMARILLO,Newl)
   Print("Una constante ENUM (VERDE) = ",VERDE,Newl)
   Print("Una constante ENUM (VERDELIMON) = ",VERDELIMON,Newl)
End
