// Archivo header C
#proto cruxlinebox(_T_,_L_,_TB_)
#proto horzlinebox(_T_,_L_,_B_,_TB_)
#proto vertlinebox(_T_,_L_,_R_,_TB_)
#proto box(_T_,_L_,_B_,_R_,_TB_)
#proto corner(_T_,_L_,_B_,_R_,_TB_)

//#define _initbox   __doubleCorner={},{186,205,201,200,187,188,204,185,203,202}addrow(__doubleCorner),{0}reshape(__doubleCorner),\
//                   __singleCorner={},{179,196,218,192,191,217,195,180,194,193}addrow(__singleCorner),{0}reshape(__singleCorner),\
//                   __DoubsingCorner={},{186,196,214,211,183,189,199,182,210,208}addrow(__DoubsingCorner),{0}reshape(__DoubsingCorner),\
//                   __SingDoubCorner={},{186,196,218,192,191,217,198,181,209,207}addrow(__SingDoubCorner),{0}reshape(__SingDoubCorner)

#define _initbox   __doubleCorner={},{186,205,201,200,187,188,204,185,203,202,206}pushall(__doubleCorner),\
                   __singleCorner={},{179,196,218,192,191,217,195,180,194,193,197}pushall(__singleCorner),\
                   __DoubsingCorner={},{186,196,214,211,183,189,199,182,210,208,215}pushall(__DoubsingCorner),\
                   __SingDoubCorner={},{186,196,218,192,191,217,198,181,209,207,216}pushall(__SingDoubCorner)

#define DOUBLE_SINGLE  "DS"
#define SINGLE_DOUBLE  "SD"
#define DOUBLE  "D"
#define SINGLE  "S"
#define colorcanvas(_X_)  {"\BG_X_"},home,{"\OFF\n"},print

