#include <hbasic.h>

#proto ___Select___Item___(__R__,__C__)
#context-free  get width forward table
   i=0,sw=0
   Move to(sw)  // consume el Take
   For Down( i:=nCol,IniCDisplay,1)
      At Interval [1,IniCDisplay:i]
      If ( Summatory(Len(SGet(display))),Plus(i) Is Le?( sizey ) )
         Let (TopeCDisplay := i)
         Let (y := Iif( Eq(sw,1), TopeCDisplay, IniCDisplay ))
         Break
      End If
      Clear All
   Next
   Locate(Sub(sizex,2),0),Print("Tope seleccionado: ",TopeCDisplay,Newl)
   Clear All
   Return\\

#context-free  get width backward table
   i=0
   For Up( i:=IniCDisplay,nCol,1)
      At Interval [1,i:nCol]
      If ( Summatory(Len(SGet(display))),Plus(i) Is Lt? ( sizey ) )
         Let (IniCDisplay := i)
         Break
      End If
   Next
   Clear All
   Return\\

Begin
   Declare as Stack(celdas,maxSize)
           as Numeric(sizex,sizey,display,tmpdisplay,nLen)
           as Numeric(nMaxValue)
           as Numeric(i,j,nRow,nCol)
           as Alpha(linea)
           as Numeric(x,y)
           as True(swDisplay, ajuste de Celda)

   GetParam(script,archivo a editar,p2)
   
   If ( Eq?(p2,"-a"))
      False(ajuste de Celda)
   End If
   
   //Let (celdas:=LoadMatrix("tratamientos.txt"))
   Let (celdas:=Load Matrix(archivo a editar))
   get SizeTerm(sizey,sizex)
   
   Let ( nRow := MyRows(celdas))
   Let ( nCol := MyCols(celdas))

   Let ( display := Str$(celdas))
   For Up( i:=1,nCol,1)
      Define Interval [1:end,i], and Let (nMaxValue := MaxValue( Len(SGet(display)) ) Plus(1) )
      Mem ( Get If ( ajuste de Celda, nMaxValue, Get If(Le?( nMaxValue, 9 ),9,nMaxValue) ) )
      Push(maxSize)
   Next

   For Up( i:=1,nCol,1)
      Take(" ",QPop(maxSize)), LPad$( [1:end,i]Get(display) ), and SPut(display)
   Next
   Clear All

   Let ( linea := Utf8$(Chr$(205)),Reply by(sizey) )
   Cls

   /*lines head y bottom*/
   Locate(3,0),Print(linea,Newl)
   Locate(Sub(sizex,3),0),Print(linea,Newl)

   /*determinar ancho de tabla para visualizacion*/
   TopeCDisplay=nCol
   IniCDisplay=1
   Take(1),get width forward table
   
   /*determinar alto de tabla*/
   TopeRDisplay=0
   IniRDisplay=1
   Let (TopeRDisplay := Iif( Gt?(nRow, Sub(sizex,7)), Sub(sizex,7), nRow ) )
   HeighPage=TopeRDisplay
   cntHeighPage=HeighPage
   
   Token Sep("|")

   /*select cell*/
   x=1,y=1
   tmpdisplay = display
   ____Select___Item___(x,y)

   /*print table*/
   While(1)
      If ( swDisplay )
         Locate(4,3), FillBox(" ",Sub(sizex,7), sizey) 
         At Interval [IniRDisplay:TopeRDisplay,IniCDisplay:TopeCDisplay],Print Table (display)
         Clear All
      End If
      c=0,Let( c := GetCh )
      display = tmpdisplay
      If Key Forward(c)
         If ( Lt(y,nCol) )
            ++y
            If ( Gt(y,TopeCDisplay) )
               ++IniCDisplay
               ++TopeCDisplay
               Take(1), get width forward table
            End If
         End If

      Else If Key Back(c)
         If ( Gt( y,1 ) )
            --y
            If( Lt(y,IniCDisplay) )
               --IniCDisplay
               --TopeCDisplay
               With(2), get width forward table  // si pongo Tak(0),queda 0 en stack y no sé por qué
            End If
         End If
      Else If Key Up(c)
         If ( Gt(x,1) )
            --x
            If ( Lt(x, IniRDisplay)) 
               --IniRDisplay
               --TopeRDisplay
            End If
         End If
      Else If Key Down(c)
         If ( Lt(x,nRow))
            ++x
            If ( Gt(x, TopeRDisplay) )
               ++IniRDisplay
               ++TopeRDisplay
            End If
         End If
      Else If Key (c, K_PGDN)
         For Up(i:=1,HeighPage,1)
            PutKey(K_DOWN)
         Next
         False(swDisplay)
      Else If Key (c, K_PGUP)
         For Up(i:=1,HeighPage,1)
            PutKey(K_UP)
         Next
         False(swDisplay)
      Else If Key (c, K_END)
         If ( Are Eq?(y,nCol) )
            x=nRow
            Let( IniRDisplay:= Iif( Gt(nRow, Sub(sizex,7)), Sub(nRow, sizex) Plus(8), 1 ) )
            TopeRDisplay=nRow
         End If
         y = nCol, IniCDisplay=1, TopeCDisplay=nCol
         get width backward table
      Else If Key (c, K_HOME)
         If ( Eq(y,1) )
            x=1
            IniRDisplay=1
            Let (TopeRDisplay := Iif( Gt(nRow, Sub(sizex,7)), Sub(sizex,7), nRow ) )
         End If
         y=1, IniCDisplay=1, TopeCDisplay=nCol
         Take(2),get width forward table
      Else If Key Escape(c)
         Break
      End If
      If ( Not(swDisplay) )
         --cntHeighPage
         If ( Zero?(cntHeighPage) )
            cntHeighPage = HeighPage
            True(swDisplay)
         End If
      Else
         ____Select___Item___(x,y)
      End If
      
   Wend

   Clear(display),Clear(celdas), Clear(maxSize)
End
Subrutines
___Select___Item___(x,y)
   Item=0
   Let (Item:=[x,y]Get(display))
   Token Sep(""),Take("\BGW\BK",Item,"\OFF"),SJoin$,SPut(display),Token Sep("|")
Return
