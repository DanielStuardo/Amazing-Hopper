#!/usr/bin/hopper

// Archivo Hopper-Basic
#include <hbasic.h>

#import lib/input.bas.lib
#include include/input.h

Begin
  Token Init
  Cls
  Locate(5,1),Print(Utf8$("Ingrese dos números, separados por coma: "))
  msg=""
  LocCol(42),Let( msg := ReadString(msg))
  Token Sep(" ")
  Print("Suma : ", Token(1),Val(Token$(msg)) Plus (Token(2),Val(Token$(msg))), Newl)
End
