
#include <hbasic.h>

Begin
   Dec as Numeric (T,flag,i, matches, Res,e)

   r="Utf8"
   //r="(?:[^,()]+((?:\((?>[^()]+|\((?<open>)|\)(?<-open>))*\)))*)+"
   text=0
   LoadString$("src/cosas.bas", text)
   
   flag = REG_EXTENDED

      RECompile(flag,r,T)
      Let( matches := REMatch(0,1,text,T) )
      REFree(T)
   Try
      Let( Res := MyRows(matches) )
   Catch(e)
      Res=0
      Print("No matching!", Newl)
   Finish

   For( i=1, Le( i, Res ), ++i)
      from=0, to=0, tosearch=""
      Let( from:=[i,1]Get(matches) )
      Let( to:=[i,2]Get(matches) )
      Let( tosearch:=[i,3]Get(matches) )
      Print(from, Newl,to, Newl,tosearch, Newl)
   Next

End
