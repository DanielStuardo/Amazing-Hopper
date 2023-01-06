
/* PIVOT: EXPRESIONES REGULARES */
// para más informacion, ver POSIX y ejemplos: REG-COMP(FLAG,EXPR)(T)
#defn    REG-COMP(_F_,_E_)           #ATOM#CMPLX;#ATOM#CMPLX;regcompile
#defn    REG-VALID(_F_,_S_,_T_)      #ATOM#CMPLX;{_T_};#ATOM#CMPLX;regvalid;
#defn    REG-MATCH(_F_,_N_,_S_,_T_)  #ATOM#CMPLX;#ATOM#CMPLX;{_T_};#ATOM#CMPLX;regmatch;
#defn    REG-FREE(_T_)               regfree(_T_)

/* CONSTANTES REGEX */
#define REG_BASIC     0
/* If this bit is set, then use extended regular expression syntax.
   If not set, then use basic regular expression syntax.  */
#define REG_EXTENDED  1

/* If this bit is set, then ignore case when matching.
   If not set, then case is significant.  */
#define REG_ICASE     2

/* If this bit is set, then anchors do not match at newline
     characters in the string.
   If not set, then anchors do match at newlines.  */
#define REG_NEWLINE   4

/* If this bit is set, then report only success or fail in regexec.
   If not set, then returns differ between not matching and errors.  */
#define REG_NOSUB     8

/* POSIX `eflags' bits (i.e., information for regexec).  */

/* If this bit is set, then the beginning-of-line operator doesn't match
     the beginning of the string (presumably because it's not the
     beginning of a line).
   If not set, then the beginning-of-line operator does match the
     beginning of the string.  */
#define REG_NOTBOL    1

/* Like REG_NOTBOL, except for the end-of-line.  */
#define REG_NOTEOL    2

/* Use PMATCH[0] to delimit the start and end of the search in the
   buffer.  */
#define REG_STARTEND  4


