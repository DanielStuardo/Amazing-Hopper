
#include <hbasic.h>

Begin
   Dec as Numeric (T,flag,i, matches, Res,e)

   r="(?<!RT\s)@\S+"
   text="@tony I am so over @got and @sarah is live to me"
   flag = REG_BASIC
   Pivot(T)
      RECompile(flag,r)
      Let( matches := REMatch(0,10,text) )
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
