
#include <hbasic.h>

Begin
  a1 = {}
  a2 = {}
  Take(100,"Hola",0.056,"Mundo!"), and Push All(a1)
  Take("Segundo",0,"array",~True,~False), and Push All(a2)
  Concat (a1, a2) and Print ( a2, Newl )
End
