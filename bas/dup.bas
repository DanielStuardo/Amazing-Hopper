#!/usr/bin/hopper

//#define-a  Ofxv(__X__)           (__X__)
//#defn    Ofexpression(__X__) ( #ATOM#CMPLX )

// Archivo Hopper-Basic
#include <hbasic.h>

/* Observación: mientras más natural en la forma de programar
   más se escribe: se pierde consición, pero se gana en
   comprensión */

Begin
   set Token(",")
   
   get Sqrt of (10), and Print It, Put a Newl
   Sqrt of (10), and Print It, then Put a Newl
   get a Quarter of(100), and Print It
   Put a Newl
   Mem(10), get Sqrt, Duplicate It, and Print It Using Token
   Put a Newl
   Duplicate( Sqrt(10)), and Print It Using Token
   Put a Newl
   Mem( Sqrt(10)), Duplicate It, and Print It Using Token
   Put a Newl
   Print Using Token( Duplicate(Sqrt(10) ), Newl)
   
End
