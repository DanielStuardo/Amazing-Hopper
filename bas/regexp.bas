
#include <hbasic.h>

Begin
   Dec as Numeric (T,flag,i, matches, Res)

   r="[A-Z]{1,2}[0-9][0-9A-Z]? +[0-9][A-Z]{2}"
   text="We are at SN12 7NY for this course and AF25 9ZZ plis"
   flag = REG_EXTENDED
   Pivot(T)
      RECompile(flag,r)
      Let( matches := REMatch(0,10,text) )
      REFree
   Let( Res := MyRows(matches) )
   For( i=1, Le( i, Res ), ++i)
      from=0, to=0, tosearch=""
      Let( from:=[i,1]Get(matches) )
      Let( to:=[i,2]Get(matches) )
      Let( tosearch:=[i,3]Get(matches) )
      Print(from,¶,to,¶,tosearch,¶)
   Next

End
