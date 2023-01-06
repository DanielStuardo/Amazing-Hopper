
#include <hbasic.h>

#define  TOPE   10000

Begin
   Declare as Stack (x)
           as Numeric (nlen, i, ti,tf)
           
   For Up( i:=1, TOPE,1)
      NewRow(x,"Esta mañana estuve mañoso")
      NewRow(x,"La vicuña marrón se asomó por ahí")
      NewRow(x,"Los cánones son reglas no legales")
      NewRow(x,"El ñandú verde corrió por el prado")
   Next
   Let ( nlen := Length(x) )
   Tic(ti)
  // Print ("\LC",x,"\OFF\n")
   
   Iterator( i:=1, ++i, while Le(i, nlen),\
             Str2Utf8$( [i,1]Get(x) ), SPut(x)) 
   Toc(ti,tf)
   Print("\LCTiempo = ",tf," seg.\OFF",Newl)
   
   Take("Hola "), Format$("mensahe. $0 \n"), Print It
   PrintF("\LGTiempo = $0 seg.\OFF\n",tf)

  // Print ("\LG",x,"\OFF\n")
End
