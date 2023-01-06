#!/usr/bin/hopper

// Archivo Hopper-Basic
#include <hbasic.h>

#import lib/input.bas.lib
#include include/input.h

#define getValueOf(__X__)  Token(__X__),Val(Token$(msg))   

Begin
  Token Init
  Cls
  Locate(5,1),Print(Utf8$("Ingrese dos números, separados por coma: "))
  msg=""
  LocCol(42),Let( msg := ReadString(msg))
  Token Sep(" ")
  A=0, get Value Of(1)»»(A), CLamp(-1000,1000,A)
  B=0, get Value Of(2)»»(B), CLamp(-1000,1000,B)
  Print("Suma : ")
  Take(A, B), and Add It; then Print It with a Newl
End

