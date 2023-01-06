#!/usr/bin/hopper

// Archivo Hopper-Basic
#include <hbasic.h>

Begin
  Token Init
  i=0
  For(i=0, Le(i,1),++i)

     t="A,B,C,D,E"
     Token(3), TokenRepl("-X-",t)
     Print(t, Newl)
               TokenSwap(5,t)
     Print(t, Newl)

     Token(4), TokenRepl("",t)
     Print(t, Newl)
     TokenDel(t)
     Print("[",t,"]", Newl)
     Token(1)
     TokenDel(t)
     Print(t,Newl)
  Next
  
  r={},
  Mem("a,b,c,d","e,f,g,h","i,j,k,l")Push All(r)
  Token Init, Token(3)
  Print(get Token$(r),Newl)
End
