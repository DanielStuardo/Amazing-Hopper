
#include <hbasic.h>

Begin
   Token Sep( "$" )
   Stat( "sample.txt", dats )
   Token Sep(",")
   Print ( dats, Newl )
End
