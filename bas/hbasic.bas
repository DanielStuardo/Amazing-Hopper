
#include <hbasic.h>

#import  lib/read.com.lib
#include include/read.h


#defn up(_X_)                 {"\033["},#ATOM#CMPLX,{"A"},print
#defn down(_X_)               {"\033["},#ATOM#CMPLX,{"B"},print

Begin
  Option Ctrl+C
  Option Stack 15
  
  Params(argv,argc)
  
  Dim (10,10) as Int Rnd Array(w,100),
  Number as ( a, nlen )
    
  Cls, //  Pause
  Locate (1,5),Print("Este es un mensaje = ")
  //Let ( a:= Mul(2,Add(10,5)) )
//  Let ( a:= #( (10+5)*2) )
  Let ( a := Add(10,5);Mul by(2);Sub to(100) )
  Print(a)
  For Up( i:=1, 10, 1 )
    Locate( #(i+3), 5), Print("I=",i)
  Next

  For Down( i:=10, 1, 1 )
//     Locate( Add(i,3), 15), Print("I=",i)
     Locate( {i}Plus(3), 15), Print("I=",i)
  Next
  Locate(15,1), 
  CurX(nRow), CurY(nCol)
  Print("Actual ROW=",nRow," Actual COL=",nCol, Newl)
  
  Prepare Data(DATA)
  v = 0
  Let ( nlen := Len Data)
  For Up ( i:=1, nlen, 1 )
     Read(v)
     Print(v,",")
  Next
  Locate(16,0)
  i=0
  While ( #( (i<=9) ) )
     Print( [ Add(i,Sub(2,1)),1:2:end]get(w), Newl)
     ++i
  Wend
  
  s="Cadena a procesar"
  At (28,5),Print( Mid$(Len(s),Sub(11,1),s), Newl )
  
  #DefFn  calcula2(__X__,__Y__)
  #DefFn  calcula(__X__,__Y__)

  x=10, y=20
  PutNewl
  Print(Newl, _calcula(x, Add(y,5)),Newl )
  Print(Newl, _calcula2(x, Add(y,5)),Newl )
  
  x=1
  Switch( x )
     Case (2) {
        Print("Es un 2")
        Exit
     }Case(3){
        Print("Es un 3"), Exit
     }Case(1){
        Print("Es un 1")
     }
  End Switch
  PutNewl
  For Up( i:=1, argc, 1)
     Print("Argumento ",i," = ",[i]get(argv),Newl)
  Next
  
/*  msg="", Locate(25,10)
  Print ( Read String(msg),Newl)
  */
  For(i=0;j=100, lAnd(Le(i,Add(99,1)),Gt(j,0)), ++i;--j)
     Print("I=",i,", J=",j,Newl)
  Next
  PutNewl
/*  For(i=0;j=10, Le(i,10),And(Gt(j,0)), ++i;--j)
     Print("I=",i,", J=",j,Newl)
  Next*/
  Div(100,4), Plus(3), Sqr, Print,PutNewl
  msg="Juanito labrador"
  Print( [ Find(" ",msg)Plus(1):end] get(msg), Newl)
  Print( Mid$( Len(msg),Find(" ",msg)Plus(1),msg), Newl)
  Print( Str2Utf8$("María tenía un corderito"), Newl)
  
  v=-1, Take(v)
  If Positive?
     Take(v," Es positivo",Newl)
  Else
     Take(v," No es positivo",Newl)
  End If
  Print
  
  Goto(fin)

DATA:
  
  Data (10,20,30,40,50,60,70,80,90,100)
  Data (101,102,103,104,105,106,107,108,109,110)
  back
  
fin:
  Stop

Subrutines

calcula(x,y)
  Let (x := Add(x,y) )
Return(x)

calcula2(x,y)
  Add(x,y)
Return

