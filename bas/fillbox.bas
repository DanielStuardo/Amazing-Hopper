
#include <hbasic.h>

Begin
   Cls
   Number as(Maxrow,Maxcol)
   GetSizeTerm(Maxcol,Maxrow)
    //FillBox(Str2Utf8$(Chr$(177)),Maxrow,Maxcol)
   Locate(5,5), FillBox(Str2Utf8$(Chr$(177)),25,50), PutNewl
   Save Screen
   Rest Screen
   BackGround(69),Locate(10,10),FillBox(" ",10,35)
   PutNewl
   pause
   Rest Screen
   //c=0,Let( c := Str2Utf8$(Chr$(178)) )
   //Print(c,," Len=",Len(c),Newl)
   //Locate(1,1),FillBox(c,Maxrow,Maxcol)
End
