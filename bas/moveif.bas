#!/usr/bin/hopper

// Archivo Hopper-Basic
#include <hbasic.h>

Begin
  Declare as Numeric(v)
  w=0
  Get If( are Eq(v,1) ,500,"Hola Mundo!")  // dejo "Hola mundo" en el stack...
  Move If( ~True, v, w); then Print '"V=",v, Newl, "W=",w, Newl'
  
  Gosub(imprime)
End

Subrutines

imprime:
  Print("Cuna publicitaria\n"), then Return

