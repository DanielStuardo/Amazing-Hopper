
#include <hbasic.h>

Begin
   Dim (10) as Zeros Array (x)
   
   [1:3]Take(1),SPut(x)
   [8:10]Take(2),SPut(x)
   
   Print(x,Newl)
   
   ItvSwap(x,[1:3],[8:10])
   
   Print(x,"\n\n")
   
   Dim (10,10) as Zeros Array (y)
   
   [1:3,1:3]Take(1),SPut(y)
   [6:2:10,6:2:10]Take(2),SPut(y)
   
   Print(y,Newl)
   
   ItvSwap(y,[1:5,1:5],[6:10,6:10])
   
   Print(y,Newl)
   
   //CoSwap(y,3,8)
   ColSwap(y,3:4,7:8)
   Print(y,Newl)
End
