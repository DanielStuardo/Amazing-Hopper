
#define IGet(__N__,__X__)  [__N__]SGet(__X__)

#include <hbasic.h>
#define MAX_LINE  1000

Begin
   Option Stack 15
   
   Declare as Numeric ( fd, i, index, max token )
           as Numeric ( num tokens, size Column, tCells )
           as Alpha ( line )
           as Numeric ( display Left, display Right, display Center )
   
   GetParam(script, file to edit, separator)

  // get statistics of file: #lines, #total chars, line more long, and num tokens from first line.
   Token Sep( separator )
   Stat( file to edit, dats )
  
  // declare arrays to work:
   Dim ( IGet(1,dats), IGet(4,dats) ) for Fill Array("",cells)
   Clear(dats)
   MCopy ( cells, display Left, display Right, display Center )
  
  // read each line as array, get # of elements, and put into array cells: 
   //Open(OPEN_READ, file to edit ) (fd)
   Using 'OPEN_READ', Open File ( file to edit ) (fd)
   When( File Error ){ Stop }

   index=1
   While Not Eof(fd)
      Using (MAX_LINE), Read as Row from(fd) and Copy to (line); get Length, and Move to (num tokens)
      Set Interval [index, 1:num tokens]; Take( line ) and SPut(cells)
      When ( var( max token) Is Lt (num tokens) ) { max token = num tokens }
      ++index
   Wend
   Close(fd)
   
  // formatting... 
   For Up( i:=1, max token, 1 )
      Set Interval [1:end,i], and Let ( /*nMaxValue*/size Column := MaxValue( Len(Get(cells)) ) Plus(1) )
//      Take ( nMaxValue ), and Push ( maxSize )
      Let ( tCells := Get(cells) )
      LPad$( " ", size Column, tCells ), and Put(display Left)
      RPad$( " ", size Column, tCells ), and Put(display Right)
      CPad$( " ", size Column, tCells ), and Put(display Center)
   Next
   Clear(cells), Clear(tCells)
   
/*   For Up( i:=1, max token, 1 )
      Let ( size Column := QPop(maxSize) )
      Let ( tCells := [1:end,i]Get(cells) )
      LPad$( " ", size Column, tCells ), and Put(display Left)
      RPad$( " ", size Column, tCells ), and Put(display Right)
      CPad$( " ", size Column, tCells ), and Put(display Center)
   Next */
  // display:
   Token Sep ("")
   Print("Left Pad:\n", display Left, Newl, "Right Pad:\n", display Right, Newl, "Center Pad:\n", display Center,Newl)
End
