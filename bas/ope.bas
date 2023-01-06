
//#define  →  ,  // altGr + i
#include <hbasic.h>

Begin
   Declare as Numeric (x,y)
           as Alpha (s,w)
           as False (b)
  //  @ł€¶ŧ←↓→→
   Sto ( Take(10,400 → Plus(100)) , x, y)

   Let ( x := Add(y, 100), Mulby ( Sub(y, 200) ) )
   Print("X=",x,Newl)
   For Up( x:=0 → 10, 1)
      Print("X=",x, ¶ )
   Next

   Print("Valor Booleano: ",b," invertido: ",Not(b),¶)
   True(b)
   Print("Ahora b: ",b, ¶)
   b <-> x
   Print("Ahora b: ",b, ¶)
   s="Hola mundo", w="Nada"
   Print(s, ¶,w, ¶)
End
