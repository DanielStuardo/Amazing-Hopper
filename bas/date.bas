#!/usr/bin/hopper

// Archivo Hopper-Basic
#include <hbasic.h>

Begin
   get Year of( DateNow$ ), and Print It
   Put a Newl
   Year of(DateNow$), and Print It
   Put a Newl
   
   Year(DateNow$), Print It
   Put a Newl
   
   Take( DateNow$ ), get Year, and Print It, Put a Newl
   Take( DateNow$ ), Year, and Print It, Put a Newl
   
   Print ( Year of( DateNow$ ), Newl )
   Print ( Year( DateNow$ ), Newl )

   get Seconds From Midnight, and Print It
   Put a Newl
   Print ( Seconds From Midnight, Newl)
   
   Print ( TimeNow$, Newl)
   get Second of ( TimeNow$ ), and Print It  // extrae la parte segundo de una hora HH:MM:SS:MM
   Put a Newl
   Print ( Seconds of(TimeNow$), Newl)
 //  set Range
End
