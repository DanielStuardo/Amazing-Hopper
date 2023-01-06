
#include <hbasic.h>

Begin
   Dec as Numeric (T,flag,i, matches, Res,e)

   r="Happy"

   text="Cuando estoy \"Happy\", estoy feliz, pero cuando no estoy feliz, no estoy \"Happy.\" Lo que es penca..."

   flag = REG_EXTENDED  //BASIC
   Pivot(T)
      RECompile(flag,r)
      Let( matches := REMatch(0,1,text) ) 
      REFree
   Try
      Let( Res := MyRows(matches) )
     // Let (text := RERepl$(matches, Res, text) )
   Catch(e)
      Res=0
      Print("No matching!",¶)
   Finish
   
   For( i=Res, Gt( i, 0 ), --i)
      from=0, to=0, tosearch=""
      Let( from:=[i,1]Get(matches) )
      Let( to:=[i,2]Get(matches) )
      Let( tosearch:=[i,3]Get(matches) )
      Print(from,¶,to,¶,tosearch,¶)
   Next

End
