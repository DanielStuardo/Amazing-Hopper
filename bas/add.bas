
#include <hbasic.h>

Begin

   t=0
   Take(10,5,5,10,10), Add All, and Move to (t)
   and Print( t, Newl)

   x=10,y=5,r=0
   Let( r := Add(x,y) ), Print(r,Newl)
   
   Take(x,y),Add, Move to(r), Print(r,Newl)
   
   Take(x), Added to (y), and Print It with a Newl
   Take(x), Subtracted from (y), and Print It with a Newl
   Take(x), Multiplies (y), and Print It with a Newl
   Take(x), Divides (y), and Print It with a Newl
   Take(x), Int Divides (y), and Print It with a Newl
   Take(x), Modulus of (y), and Print It with a Newl
   Take(x), Power of (y), and Print It with a Newl
   Print(Sqrt(x), Newl)
   Take(2), Rounds to (Sqrt(x)),and Print It with a Newl
End
