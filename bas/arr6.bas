
#include <hbasic.h>

Begin
   Cls
   Seed(1234)
   Dim (10,10) as Int Rnd Array(v,10)
   Print(v,Newl)
   //x=0
   Take(2,4,6),Let( v:=Sqrt(GetRows(v)) )
   
   w=0,Take(" ",8)
       Let ( w := LPad$(Str$(v)) )
   Locate (14,5), Print Table(w)
   //{v,10,10}print2d
   PutNewl

End
