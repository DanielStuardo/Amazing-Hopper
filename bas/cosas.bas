#!/usr/bin/hopper

// Archivo Hopper-Basic
#include <hbasic.h>

//#defn Right$(_X_,_V_)  {999999999};#ATOM#CMPLX;#ATOM#CMPLX;copy;
//#defn Left$(_X_,_V_)   #ATOM#CMPLX;{1};#ATOM#CMPLX;copy;
//#synon Upper$          UCase$
//#synon Lower$          LCase$

#define TranArrayUtf8$(__X__)   ___i___=0,___nLen___=0,\
                                Let ( ___nLen___ := Length(__X__) )\
                                Iterator( ___i___:=1, ++___i___, while Le(___i___, ___nLen___),\
                                          Utf8$( [___i___]Get(__X__) ), SPut(__X__) )

#define TranColumnUtf8$(__X__,__C__)   ___i___=0,___nLen___=0,\
                                Let ( ___nLen___ := MyRows(__X__) )\
                                Iterator( ___i___:=1, ++___i___, while Le(___i___, ___nLen___),\
                                          Utf8$( [___i___,__C__]Get(__X__) ), SPut(__X__) )

#define TranRowUtf8$(__X__,__R__)   ___i___=0,___nLen___=0,\
                                Let ( ___nLen___ := MyCols(__X__) )\
                                Iterator( ___i___:=1, ++___i___, while Le(___i___, ___nLen___),\
                                          Utf8$( [__R__,___i___]Get(__X__) ), SPut(__X__) )

//#defn MultiPush(__X__,*)    #GENCODE $$$*$$$ #ATCMLIST;push(__X__); #ENDGEN;

//#defn Segment$(_X_,_I_,_F_)  ___VSEG___=0;#ATOM#CMPLX;mov(___VSEG___);clearinterval;#ATOM#CMPLX;loc1;\
//                             #ATOM#CMPLX;offset1;get(___VSEG___);clearinterval;
//#define    Segm$(_X_,_I_,_F_)   [_I_:_F_]get(_X_)

//#define-a  »»(__X__) ;mov(__X__)
//#define-a  »(__X__)  ;cpy(__X__)

 
Begin
   s="María tenía un corderito que tenía prisa"
   Print ( Utf8$( Right$(  FindFirst("tenía",s), s ) ), Newl )
   
   Print ( Utf8$( Left$(  FindLast("tenía",s)Minus(1), s ) ), Newl )
   and Print ( Utf8$( UCase$( s )), Newl )
   
   t = {}
   now Memorize (s,s,s,s,s), Push All(t)
   m=0
   // Let( m:= Right$(  FindFirst("tenía",t), t ) )
   // con Porcion=1000 me ahorro el array de anchos, porque "copy" no tiene problemas con eso.
   Let( m:= Mid$( 1000,FindFirst("tenía",t),t ))
   Token Sep( Newl )
   Print (m, Newl )

  /* convierte el array de string a utf8 */
   Tran Array Utf8$(m)
   
   Save Matrix(m,"loki.txt")

   Print( BtwnCut$(s," "," "), Newl, s,Newl )
   Print( Utf8$( [ Add(6,1):11]SGet(s) ), Newl)
   ss=0
 //  Print( Utf8$( Segm$( cte("María tenía un corderito");Copy(ss),7,11) ), Newl) // aqui hay un error feo: descubrir!
 //  el error es Invalid argument, y es porque ese chorizo se mete dentro de get, y get solo recibe una variable.
   Print( Utf8$( Segm$( s,7,11) ), Newl)
   Print( Utf8$( Segment$( cte("María tenía un corderito")»(ss),7,11) ), Newl) // Ok!
   e=0
   Print( Utf8$( Segment$( UCase$(ss)»(ss), FindFirst(" ",ss)Plus(1) » (e), var(e)Plus(4) )), Newl)
   Print( Utf8$( Segment$( ss, FindFirst(" ",ss) Plus(1) » (e), #(e+4) )), Newl)
   Put a Newl

   Print( Sinh(0.5), Newl )
   Print( #( (exp(0.5)-exp(-0.5))/2 ), Newl )
   Print( #( 0.5 <= 10 ), Newl )

   Print( Get If ( #( (0.5*4) <= 10 ), "Es menor!\n", "No es menor\n" ))
   then Print If ( #( (0.5*4) <= 10 ), "Es menor!\n", "No es menor\n" )

   Let ( s := Get If ( #( (0.5*4) <= 10 ), "Es menor!\n", "No es menor\n" ) ), and Print ( s )
   Take If ( #( (0.5*4) <= 10 ), "Es menor!\n", "No es menor\n" ); now Print It

   w={},Multi Push(w,10,20,30,40,50,UCase$(t),60,70,80,90,100)
   n=0,Let( n:= Length(w)) 
   For Each(v, w, n )
      Print( v , Newl )
   Next
End
