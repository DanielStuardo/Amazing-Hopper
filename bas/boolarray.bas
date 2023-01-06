
#include <hbasic.h>

Begin
  v=0,True(v), Dim(10,10) as Fill Array(v,w)
  
  Print(w, Newl)
  
  Dim(10,10) as Ones Array(c)
  Let( c:= Bool(c) )
  Print(c,Newl)
  Clear All
End
