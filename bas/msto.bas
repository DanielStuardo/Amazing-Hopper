

/*#define  ↓  // altgr + u
#define  « ,   // altgr + z
#define  » ,   // altgr + x
#define  ½  0.5 // altgr + 5 
*/
#include <hbasic.h>

Begin
   Dec as Alpha (a,µ,c)
   
   s ← "María tenía un corderito"
   MSto ( Str2Utf8$(Mid$(5,Add(Find(" ",s),1),s)) → a → µ → c )
   Print("\"A\"=",a,Str2Utf8$("\nµ="),µ,"\nC=",c, ¶ ) 
   
End
