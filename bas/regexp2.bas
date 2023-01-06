
#include <hbasic.h>

Begin
   Dec as Numeric (T,flag,i, matches, Res,e)

   //r="M(r|s|rs)\.?\s[A-Z]\w*"
   r="(Mr|Mrs)\.?\s[A-Z]\w*"
   text="Enhorabuena, Mr. Bond! Mrs. Pings love you, and Mrs. Whitman too"
   flag = REG_EXTENDED  //BASIC
   Pivot(T)
      RECompile(flag,r)
      Let( matches := REMatch(0,5,text) ) // si segundo param es > 1, encontrá Mr. y Mrs., que no queremos.
      REFree
   Try
      Let( Res := MyRows(matches) )
   Catch(e)
      Res=0
      Print("No matching!",¶)
   Finish
   For( i=1, Le( i, Res ), ++i)
      from=0, to=0, tosearch=""
      Let( from:=[i,1]Get(matches) )
      Let( to:=[i,2]Get(matches) )
      Let( tosearch:=[i,3]Get(matches) )
      Print(from,¶,to,¶,tosearch,¶)
   Next
End
