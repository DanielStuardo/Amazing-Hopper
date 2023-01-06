
/*  FLOW-MATIC++ */

/* FUNCIONES */
///#define-a  ::   , no funca!
//#define-a  %                 ;postfix; // NO NECESARIO SI VA EN MAIN!, pero sí lo es si se va a usar #()
                                        //  PFIX, #hl{ ... } PFIX
#define  »»(__X__)     ;mov(__X__)
#define  »(__X__)      ;cpy(__X__)
#define-a ---           ;
#define-a  :=          ,
#define-a  ~=          ,
#define  SUBRUTINES    .locals

/*********************
   FUNCIONES LOGICAS
 *********************/

// MEM( V ) IS-EQ? (X) ==> 1,0 
#defn    IS-EQ?(__E__)        #IF eqto(#FATOM) #ELSE #CMPLX ;eq? #EIF
#defn    IS-LE?(__E__)        #IF lethan(#FATOM) #ELSE #CMPLX ;le? #EIF
#defn    IS-GT?(__E__)        #IF gthan(#FATOM) #ELSE #CMPLX;gt? #EIF 
#defn    IS-GE?(__E__)        #IF gethan(#FATOM) #ELSE #CMPLX;ge? #EIF
#defn    IS-LT?(__E__)        #IF lthan(#FATOM) #ELSE #CMPLX;lt? #EIF 
#defn    IS-NOT-EQ?(__E__)    #IF neqto(#FATOM) #ELSE #CMPLX;neq? #EIF

// EVALUAN UN UNICO ARGUMENTO:
#defn    IS-INF?(__X__)                     #ATOM#CMPLX;inf?;
#defn    IS-NAN?(__X__)                     #ATOM#CMPLX;nan?;
#defn    IS-ODD?(__X__)                     #ATOM#CMPLX;odd?;
#defn    IS-NOT-ZERO?(__X__)                    #ATOM#CMPLX;zero?;not
#defn    IS-ZERO?(__X__)                    #ATOM#CMPLX;zero?;
#defn    IS-NOT-NULL?(__X__)                #ATOM#CMPLX;void?;not;
#defn    IS-NULL?(__X__)                    #ATOM#CMPLX;void?;
#defn    IS-POS?(__X__)                     #ATOM#CMPLX;pos?;
#defn    IS-NEG?(__X__)                     #ATOM#CMPLX;neg?;
#defn    IS-ARRAY?(__X__)                   #ATOM#CMPLX;array?;
#defn    IS-NUMERIC?(__X__)                 #ATOM#CMPLX;numeric?;
#defn    IS-STRING?(__X__)                  #ATOM#CMPLX;string?;
#defn    IS-ENV-VAR?(__X__)                 #ATOM#CMPLX;env?;
#defn    IS-FILE?(__X__)                    #ATOM#CMPLX;exist?;
#defn    IS-DIR?(__X__)                     #ATOM#CMPLX;existdir?;
#defn    IS-ANY?(__X__,__Y__)               #ATOM#CMPLX;#ATOM#CMPLX;any?;
//   Take(num), Between?( 10::including, 100::excluding)
//  define includ, exclud ya está listo

#define  INCL                               1
#define  EXCL                               0
#defn    IS-BOUND-BETWEEN?(__I__,_X_,__F__,_Y_)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;between?;
#defn    IS-BETWEEN?(__I__,__F__)           #ATOM#CMPLX;{1};#ATOM#CMPLX;#ATOM#CMPLX;{1};#ATOM#CMPLX;between?;
#defn    IS-ALL?(__X__,__Y__)               #ATOM#CMPLX;#ATOM#CMPLX;all?;
#defn    IS-EMPTY?(__X__)                   #ATOM#CMPLX;isempty;
#define  IS-NOT-FILE-ERROR?                 ;error?;not;
#define  IS-FILE-ERROR?                     ;error?  // no usa memoria: consulta flag interno.
#define  IS-MEM-BUSY?                       ;emptystack?;not;
#define  IS-MEM-EMPTY?                      ;emptystack?;
#define  IS-NOT-LENGTH-ZERO?                ;length;zero?;not;
#define  IS-LENGTH-ZERO?                    ;length;zero?;
#define  KEY-PRESSED?                       ;kbhit?
#defn    IS-CHAR?(__X__,__Y__)              #ATOM#CMPLX;{__Y__}typechar?;
#defn    IS-ALL-TYPE?(__X__,__Y__)          #ATOM#CMPLX;{__Y__}typestring?;
#defn    WHERE-NOT?(__X__,__Y__)            #ATOM#CMPLX;{__Y__}disttypestring?;
/* Take(x), Occurs In?("hola mundo!") */
#defn    EXACT-OCC?(__X__)                  #ATOM#CMPLX;ecin?;  // requiere algo del stack
#defn    OCCURS?(__X__)                     #ATOM#CMPLX;cin?; 

// funciones BINARIAS:
#defn    NOT-EQ-ARR?(_X_,_Y_) #IF #ATOM #ELSE #CMPLX;#EIF #IF neqarrto(#FATOM) #ELSE #CMPLX; neqarr? #EIF
#defn    EQ-ARR?(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF eqarrto(#FATOM) #ELSE #CMPLX; eqarr? #EIF
#defn    NOT-EQ?(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF neqto(#FATOM) #ELSE #CMPLX; neq? #EIF
#defn    EQ?(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF eqto(#FATOM) #ELSE #CMPLX; eq? #EIF
#defn    LE?(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF lethan(#FATOM) #ELSE #CMPLX; le? #EIF
#defn    LT?(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF lthan(#FATOM) #ELSE #CMPLX; lt? #EIF
#defn    GT?(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF gthan(#FATOM) #ELSE #CMPLX; gt? #EIF
#defn    GE?(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF gethan(#FATOM) #ELSE #CMPLX; ge? #EIF

// CAMBIAN VALOR LOGICO DE X:
#defn    TRUE(*)              #GENCODE $$$*$$$ true(#LIST);#ENDGEN
#defn    FALSE(*)             #GENCODE $$$*$$$ false(#LIST);#ENDGEN
#defn    LOG-INV(*)           #GENCODE $$$*$$$ {#LIST};not;mov(#LIST);#ENDGEN
//#define  TRUE(_X_)            true(_X_)
//#define  FALSE(_X_)           false(_X_)
#defn    NOT(_X_)             #ATOM #CMPLX;not;

// OPERADORES LOGICOS
/*#defn    NAND(__X__,__Y__)    #ATOM#CMPLX;#ATOM#CMPLX;nand;
#defn    NOR(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;nor;
#defn    XOR(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;xor;
#defn    AND(_X_,_Y_)         #ATOM#CMPLX;#ATOM#CMPLX;and; // causa un error argument error PREPROCESO(2780) -> _CAMBIODEFINE(6816) por usar .apl. y dejar OPTIMLOG declarado después.
#defn    OR(_X_,_Y_)          #ATOM#CMPLX;#ATOM#CMPLX;or;*/
#defn    NAND(__X__,__Y__)    #ATOM#CMPLX;#ATOM#CMPLX;nand;
#defn    NOR(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;nor;

#defn    ONLY-ONE(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;xor;
#defn    XOR(_X_)                 #ATOM#CMPLX;xor;

#defn    MUST-BE(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;and;
#synon   MUST-BE                 SHOULD-BE
#defn    AND(_X_)                #ATOM#CMPLX;and;

#defn    CAN-BE(_X_,_Y_)          #ATOM#CMPLX;#ATOM#CMPLX;or;
#synon   CAN-BE                  COULD-BE
#defn    OR(_X_)                #ATOM#CMPLX;or;

/* DATETIME */
// suma o resta días a la fecha DD/MM/AAAA
#defn    DATE-ADD(_F_,_N_)         #ATOM#CMPLX;#ATOM#CMPLX;dateadd;
// días transcurridos entre F1 y F2:
#defn    DATE-DIFF(_F2_,_F1_)      #ATOM#CMPLX;#ATOM#CMPLX;datediff;
// horas transcurridas entre 2 horas --> HH:MM:SS
#defn    ELAP-TIME(_H2_,_H1_)      #ATOM#CMPLX;#ATOM#CMPLX;elaptime;
#defn    IS-LEAP-YEAR?(__X__)      #ATOM#CMPLX;date(14);
#defn    IS-TIME-VALID?(__X__)     #ATOM#CMPLX;date(19);
#defn    IS-DATE-VALID?(__X__)     #ATOM#CMPLX;date(20);

#define  DATE-TIME-STR        datenow(0)
#define  DATE-NOW-STR         datenow(2)
#define  TIME-NOW-STR         datenow(3)

#defn    MONTH-STR(__X__)     #ATOM#CMPLX;date(13)  // get no aplica para funciones string $, porque se me canta el orto
#defn    DAYS-MONTH(__X__)    #ATOM#CMPLX;date(15)
#defn    DAY-WEEK(__X__)      #ATOM#CMPLX;date(17)
#defn    DAY-YEAR(__X__)      #ATOM#CMPLX;date(18)
#defn    DAY-STR(__X__)       #ATOM#CMPLX;date(12)
#defn    DAY(__X__)           #ATOM#CMPLX;date(8)
#defn    WEEK(__X__)          #ATOM#CMPLX;date(17)
#defn    MONTH(__X__)         #ATOM#CMPLX;date(7)
#defn    YEAR(__X__)          #ATOM#CMPLX;date(6)
// sobre horas
#defn    HOUR(__X__)          #ATOM#CMPLX;date(9)
#defn    MINUTE(__X__)        #ATOM#CMPLX;date(10)
#defn    SECOND(__X__)        #ATOM#CMPLX;date(11)

// se declara esto aquí, porque se solapa con "getSecond" de date:
#define  SECS-FROM-MIDNIGHT   seconds;

// DECLARACIONES DE ARRAYS:

#defn    DIM(*)                     #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN,
#defn    AS-NAN(*)           __TMPARR__=-1,nanarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    AS-ZEROS(*)      __TMPARR__=-1,zerosarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    AS-ONES(*)       __TMPARR__=-1,onesarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    AS-EYES(*)     __TMPARR__=-1,eyesarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    AS-ALPHA(*) {""},__TMPARR__=-1,fillarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    AS-FILL(__F__,*) #ATOM#CMPLX,__TMPARR__=-1,fillarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,\
                                        cpy(#LIST);#ENDGEN,kill;
#defn    AS-INT-RAND(_M_,*)  __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),int,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;

#defn    AS-INT-LIMITED-RAND(_I_,_F_,*)    __TMPARR__=-1,randarray(__TMPARR__),mulby(1000000),__RNDLOW___=0;#ATOM#CMPLX;\
                                        cpy(__RNDLOW___);#ATOM#CMPLX;sub,mod,plus( __RNDLOW___ ),int,\
                                        #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;

#defn    AS-CEIL-RAND(_M_,*)    __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),ceil,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    AS-FLOOR-RAND(_M_,*)     __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),floor,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    AS-RAND(*)     __TMPARR__=-1,randarray(__TMPARR__),\
                                         #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    AS-VOID(*)     __TMPARR__=-1,newarray(__TMPARR__),\
                                     #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
                                     
// ARITMETICAS:
#defn    SQR-DIFF-TO(_X_)      ;sqrdiff;mov(_X_)
#defn    SQR-ADD-TO(_X_)       ;sqradd;mov(_X_)
#defn    EUCL-DIST-TO(_X_)     ;hypot;mov(_X_)

#define  MULTIPLY-ALL-TO(_X_)  ;mulall;mov(_X_)
#define  ADD-ALL-TO(_X_)       ;sumall;mov(_X_)
#defn    MULTIPLY-ALL(_X_,*)   {1};#GENCODE $$$*$$$ #ATCMLIST;mul;#ENDGEN;mov(_X_)
#defn    ADD-ALL(_X_,*)        {0};#GENCODE $$$*$$$ #ATCMLIST;add;#ENDGEN;mov(_X_)
#defn    SET-ROUND(_X_)        ;#IF prec(#FATOM) #ELSE ___SET_PREC___=0;#CMPLX;mov(___SET_PREC___);prec(___SET_PREC___); #EIF
#define  UNSET-ROUND           prec(-1)
//
#defn    ADD(__X__,__Y__)      #IF #ATOM #ELSE #CMPLX;#EIF #IF plus(#FATOM) #ELSE #CMPLX; add; #EIF
#defn    SUB(__X__,__Y__)      #IF #ATOM #ELSE #CMPLX;#EIF #IF minus(#FATOM) #ELSE #CMPLX; sub; #EIF
#defn    MUL(__X__,__Y__)      #IF #ATOM #ELSE #CMPLX;#EIF #IF mulby(#FATOM) #ELSE #CMPLX; mul; #EIF
#defn    INT-DIV(__X__,__Y__)  #IF #ATOM #ELSE #CMPLX;#EIF #IF idivby(#FATOM) #ELSE #CMPLX; idiv; #EIF
#defn    DIV(__X__,__Y__)      #IF #ATOM #ELSE #CMPLX;#EIF #IF divby(#FATOM) #ELSE #CMPLX; div; #EIF
#defn    MOD(_X_,_Y_)          #IF #ATOM #ELSE #CMPLX;#EIF #IF module(#FATOM) #ELSE #CMPLX; mod; #EIF
#defn    POW(_X_,_Y_)          #IF #ATOM #ELSE #CMPLX;#EIF #IF powby(#FATOM) #ELSE #CMPLX; pow; #EIF
#defn    ROUND(_X_,_Y_)        #IF #ATOM #ELSE #CMPLX;#EIF #IF roundby(#FATOM) #ELSE #CMPLX; round; #EIF
#defn    GCD(_X_,_Y_)          #ATOM #CMPLX;#ATOM #CMPLX;gcd;
#defn    LCM(_X_,_Y_)          #ATOM #CMPLX;#ATOM #CMPLX;lcm;

// el calculo se hace al reves x es restado desde y:
#defn    ADDED-TO(_X_)         #ATOM #CMPLX;add;
#defn    SUBTRACTED-FROM(_X_)  #ATOM #CMPLX;postfix;sub;postfix;
#defn    MULTIPLIES(_X_)       #ATOM #CMPLX;mul;
#defn    INT-DIVIDES(_X_)      #ATOM #CMPLX;postfix;idiv;postfix;
#defn    DIVIDES(_X_)          #ATOM #CMPLX;postfix;div;postfix;
#defn    MODULUS-OF(_X_)       #ATOM #CMPLX;postfix;mod;postfix;
#defn    POWER-OF(_X_)         #ATOM #CMPLX;postfix;pow;postfix;
#defn    ROUNDS-TO(_X_)        #ATOM #CMPLX;postfix;round;postfix;

//
#defn    PLUS(__X__)           ;#IF plus(#FATOM) #ELSE #CMPLX;add; #EIF
#defn    MINUS(_X_)            ;#IF minus(#FATOM) #ELSE #CMPLX;sub; #EIF
#defn    MUL-BY(_X_)           ;#IF mulby(#FATOM) #ELSE #CMPLX;mul; #EIF
#defn    INT-DIV-INTO(_X_)     ;#IF idivby(#FATOM) #ELSE #CMPLX;idiv; #EIF
#defn    DIV-INTO(_X_)         ;#IF divby(#FATOM) #ELSE #CMPLX;div; #EIF
#defn    MODULE(_X_)           ;#IF module(#FATOM) #ELSE #CMPLX;mod; #EIF
#defn    POW-BY(_X_)           ;#IF powby(#FATOM) #ELSE #CMPLX;pow; #EIF
#defn    ROUND-BY(_X_)         ;#IF roundby(#FATOM) #ELSE #CMPLX;round;#EIF
#defn    TIMES(_X_)            ;#IF mulby(#FATOM) #ELSE #CMPLX;mul; #EIF

//
#define  MINUS-ONE(__X__)      minusone(__X__);
#define  MINUS-TWO(__X__)      minustwo(__X__);
#define  PLUS-ONE(__X__)       plusone(__X__);
#define  PLUS-TWO(__X__)       plustwo(__X__);
#defn    ++(__X__)             #ATOM #CMPLX;plus(1)
#defn    --(__X__)             #ATOM #CMPLX;minus(1)

#defn    UNIFORM-RAND(_X_,_MU_,_FVAR_,*)    #RAND;_V_#RNDV=0;#GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;randarray(_V_#RNDV);\
                                            {_V_#RNDV}mulby(2);minus(1);mulby(_FVAR_);plus(1);mulby(_MU_);mov(_X_);%RAND;

// MATEMATICAS:
#defn    SRAND(__X__)          #ATOM #CMPLX;seed;
#defn    MAX(_X_,_Y_)          #ATOM #CMPLX;#ATOM #CMPLX;max;
#defn    MIN(_X_,_Y_)          #ATOM #CMPLX;#ATOM #CMPLX;min;
#defn    SQRT(_X_)             #ATOM #CMPLX;sqrt;
#defn    CBRT(_X_)             #ATOM #CMPLX;cbrt;
#defn    CEIL(_X_)             #ATOM #CMPLX;ceil;
#defn    FLOOR(_X_)            #ATOM #CMPLX;floor;
#defn    TRUNC(_X_)            #ATOM #CMPLX;trunc;
#defn    LEN-INT(_X_)          #ATOM #CMPLX;lennum;
#defn    INT(_X_)              #ATOM #CMPLX;int;
#defn    SGN(_X_)              #ATOM #CMPLX;sign;
#defn    SCI-FORMAT(_X_)       #ATOM #CMPLX;sci;
#defn    FACT(_X_)             #ATOM #CMPLX;fact;
#defn    ABS(_X_)              #ATOM #CMPLX;abs;
#defn    EXP2(_X_)             #ATOM #CMPLX;exp2;
#defn    EXP10(_X_)            #ATOM #CMPLX;exp10;
#defn    EXP(_X_)              #ATOM #CMPLX;exp;
#defn    LOG2(_X_)             #ATOM #CMPLX;log2;
#defn    LOG10(_X_)            #ATOM #CMPLX;log10;
#defn    LOG(_X_)              #ATOM #CMPLX;log;
#defn    RAND(_X_)             #ATOM #CMPLX;rand;
#defn    INV-SQR(_X_)          #ATOM #CMPLX;powby(2);powby(-1)
#defn    INV-CUB(_X_)          #ATOM #CMPLX;powby(3);powby(-1)
#defn    INV-QUA(_X_)          #ATOM #CMPLX;powby(4);powby(-1)
#defn    INV(_X_)              #ATOM #CMPLX;powby(-1)
#defn    SQR(_X_)              #ATOM #CMPLX;powby(2)
#defn    CUB(_X_)              #ATOM #CMPLX;powby(3)
#defn    QUA(_X_)              #ATOM #CMPLX;powby(4)
#defn    A-HALF(_X_)           #ATOM #CMPLX;divby(2)
#defn    A-THIRD(_X_)          #ATOM #CMPLX;divby(3)
#defn    A-QUARTER(_X_)        #ATOM #CMPLX;divby(4)

/* macros trigonométricas */
#defn    RADIAN(_X_)           #ATOM #CMPLX;d2r;
#defn    DEGREE(_X_)           #ATOM #CMPLX;r2d;
#defn    ACOSH(_X_)            #ATOM #CMPLX;arccosh;
#defn    ASINH(_X_)            #ATOM #CMPLX;arcsinh;
#defn    ATANH(_X_)            #ATOM #CMPLX;arctanh;
#defn    ACOS(_X_)             #ATOM #CMPLX;arccos;
#defn    ASIN(_X_)             #ATOM #CMPLX;arcsin;
#defn    ATAN(_X_)             #ATOM #CMPLX;arctan;
#defn    COSH(_X_)             #ATOM #CMPLX;cosh;
#defn    SINH(_X_)             #ATOM #CMPLX;sinh;
#defn    TANH(_X_)             #ATOM #CMPLX;tanh;
#defn    COS(_X_)              #ATOM #CMPLX;cos;
#defn    SIN(_X_)              #ATOM #CMPLX;sin;
#defn    TAN(_X_)              #ATOM #CMPLX;tan;

/*#define  ITGET(_X_,*)        ___i___=1;___L___=0;{_X_}length;mov(___L___);\
                             ITERA( ++___i___, LE?(___i___, ___L___),\
                                    [___i___]GET(_X_),* )
*/

// TOKENS:
#defn    TOK-SEP(__X__)           #ATOM#CMPLX;toksep;
#define  TOK-INIT                 ___TOKEN___=0;
#defn    TOK-COUNT(__X__)         ___V_827662___=0;#ATOM#CMPLX;mov(___V_827662___);totaltoken(___V_827662___);___TOKEN___=0;

#defn    TOK-GET(__V__)           {___TOKEN___};$(__V__);
#defn    TOK-REPL(__X__,__V__)    #ATOM#CMPLX;{___TOKEN___}$$(__V__);mov(__V__);gettoksep;{__V__};onechar;mov(__V__);
#defn    TOK-DEL(__V__)           {""}{___TOKEN___}$$(__V__);mov(__V__);gettoksep;{__V__};onechar;mov(__V__);
#defn    TOK-SWAP(_N_,__V__)      #ATOM#CMPLX;__T_SWP__=0;cpy(__T_SWP__);$(__V__);\
                                  {___TOKEN___};$(__V__);\
                                  {__T_SWP__}$$(__V__);mov(__V__);\
                                  {___TOKEN___}$$(__V__);mov(__V__);
#define  GET-SEP                  gettoksep;
#defn    TOK(__X__)               #ATOM#CMPLX;mov(___TOKEN___)


// PROCESO DE STRINGS:

#defn    REPLICATE(__X__,__N__)              #ATOM#CMPLX;#ATOM#CMPLX;replicate;
// Take(cadena), ReplyBy(N)
#defn    REPLY-BY(__N__)                     #IF replyby(#FATOM) #ELSE #CMPLX;replicate; #EIF

// Concatenación multiple
#defn    MCAT(__X__,*)                       #ATOM#CMPLX;#GENCODE $$$*$$$ #ATCMLIST;cat; #ENDGEN;
// concatenación
#defn    CAT(__X__,__Y__)                    #ATOM#CMPLX;#ATOM#CMPLX;cat;
#defn    +(_X_)                              #ATOM#CMPLX;cat;
// corta cadenas
#defn    CUT-RIGHT(__X__,__Y__)              #ATOM#CMPLX;#ATOM#CMPLX;rcut;
#defn    CUT-BTWN(__X__,__A__,__B__)         #RAND;__V_#RNDV=0;#ATOM#CMPLX;mov(__V_#RNDV);#ATOM#CMPLX;{__V_#RNDV}cut;mov(__V_#RNDV);\
                                             #ATOM#CMPLX;{__V_#RNDV}findat;minus(1);{1}{__V_#RNDV};copy;%RAND;
#defn    CUT(__X__,__Y__)                    #ATOM#CMPLX;#ATOM#CMPLX;cut;

#define  BASE-NAME(_X_)                      {"/"}{_X_};rcut;
#define  FULL-PATH(_X_)                      {0}{0}{""};BaseName(_X_);{_X_}transform

// Take(x,y,z,...), Join(v)
#defn    JOIN-TO(__X__)                      join(__X__);
#define  JOIN                                sjoin;
#defn    UCAS(_X_)                           #ATOM#CMPLX;upper;
#defn    LCAS(__X__)                         #ATOM#CMPLX;lower;
#defn    HEX(__X__)                          #ATOM#CMPLX;hex;
#defn    BIN(__X__)                          #ATOM#CMPLX;bin;
#defn    OCT(__X__)                          #ATOM#CMPLX;oct;
#define  BIN-SIZE(__X__)                     sizebin(__X__)
#defn    UTF8-TO-STR(__X__)                  #ATOM#CMPLX;utf8tostr;
#defn    STR-TO-UTF8(__X__)                  #ATOM#CMPLX;strtoutf8;
#defn    TRM-RIGHT(__X__)                    #ATOM#CMPLX;trimright;
#defn    TRM-LEFT(__X__)                     #ATOM#CMPLX;trimleft;
#defn    TRM(__X__)                          #ATOM#CMPLX;trim;
// Take(" ",20),PadC(var) para PadX
#defn    PAD-CENTER(__FILL__,__SIZ__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;padcenter;
#defn    PAD-LEFT(__FILL__,__SIZ__,__X__)       #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;padleft;
#defn    PAD-RIGHT(__FILL__,__SIZ__,__X__)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;padright;

#defn    TYPE(__X__)                        #ATOM#CMPLX;type;

#defn    MID(__P__,__F__,__X__)             #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;copy;
#defn    RIGHT(_X_,_V_)                     {999999999};#ATOM#CMPLX;#ATOM#CMPLX;copy;
#defn    LEFT(_X_,_V_)                      #ATOM#CMPLX;{1};#ATOM#CMPLX;copy;

#defn    SEGMNT(_X_,_I_,_F_)                ___VSEG___=0;#ATOM#CMPLX;mov(___VSEG___);clearinterval;#ATOM#CMPLX;loc1;\
                                            #ATOM#CMPLX;offset1;get(___VSEG___);clearinterval;

// busqueda de posiciones
#defn    FND-FIRST(__C__,__X__)            {1};#ATOM#CMPLX;#ATOM#CMPLX;findat;
#defn    FND-LAST(__C__,__X__)             {0};#ATOM#CMPLX;#ATOM#CMPLX;findat;
#defn    FND-AT(__AT__,__C__,__X__)        #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;findat;
#defn    FND(__S__,__X__)                  #ATOM#CMPLX;#ATOM#CMPLX;find;
#defn    CNT-AT(__SALTA__,__S__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;countat;
// switch para búsqedas con FINDAT
#define  MULTIPASS-ON            multipasson;
#define  MULTIPASS-OFF           multipassoff;

// TRANSFORMACION:
#defn    TRAN-FIRST(_S_,_R_,_X_)             {1}{1};#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
#defn    TRAN-LAST(_S_,_R_,_X_)              #RAND;___VTRNL___#RNDV=0;___REPL_TXT_=0;#ATOM#CMPLX;mov(___REPL_TXT_);\
                                             ___FIND_LAST_=0;#ATOM#CMPLX;mov(___FIND_LAST_);___AT_LAST_=0;\
                                             {___FIND_LAST_};#ATOM#CMPLX;cpy(___VTRNL___#RNDV);countat;mov(___AT_LAST_);\
                                             {___AT_LAST_}{___REPL_TXT_}{___FIND_LAST_}{___VTRNL___#RNDV}transform;%RAND;
#defn    TRAN-TO(_N_,_S_,_R_,_X_)            {1};#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
#defn    TRAN-TO-ALL(_N_,_S_,_R_,_X_)        #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
#defn    TRAN-FROM-TO(_M_,_N_,_S_,_R_,_X_)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
// Take(desde-la-ocurrencia), Tran$(...)
// Take(hasta-la-ocurrencia,desde-la-ocurrencia), Tran$(...)
// Ejemplo: reemplaza la primera ocurrencia: Take(1,1),Trans$("X","x",v)
#defn    TRAN(__R__,__S__,__X__)             {0}{0}#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;

#defn    REPL-CHR-LEFT(__C__,__R__,__X__)    #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;rleft;
#defn    REPL-CHR-RIGHT(__C__,__R__,__X__)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;rright;
#defn    REPL-CHR(__C__,__R__,__X__)         #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;rall;

#defn    REPL(_N_,_P_,__S__,__X__)           #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;replace;
#defn    INS(__P__,__C__,__X__)              #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;insert;
#defn    DEL-CHAR(__C__,__X__)               #ATOM#CMPLX;#ATOM#CMPLX;deletechar;
#defn    DEL(__P__,__C__,__X__)              #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;delete;
#defn    UNIQ-CHR(__C__,__X__)               #ATOM#CMPLX;#ATOM#CMPLX;onechar;
#defn    ONLY-CHR(__C__,__X__)               #ATOM#CMPLX;#ATOM#CMPLX;onlychar;
#define  ROT-STR-LEFT(_X_)                   [1]get(_X_):++_X_;{_X_}cat;
#define  ROT-STR-RIGHT(_X_,_Y_)              {_X_};[_Y_]get(_X_);cat;mov(_X_);--_X_;{_X_}
#defn    POS-CHR-LEFT(__C__,__X__)           {1};#ATOM#CMPLX;#ATOM#CMPLX;poschar;
#defn    POS-CHR-RIGHT(__C__,__X__)          {0};#ATOM#CMPLX;#ATOM#CMPLX;poschar;
#defn    REVER-STR(__X__)                    reverse(__X__);   // requiete una constante string
#defn    MASK(__F__,__M__,__X__)             #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;mask; 
#defn    MONEY(__DEC__,__X__)                #ATOM#CMPLX;#ATOM#CMPLX;money;
// Take(a,b,c,...) Format$(v)
#defn    FORMAT(__X__)                       #RAND;__C__#RNDV=__X__;sjoin;gettoksep;format(__C__#RNDV);%RAND;


/* PARSER HTML */
#defn    HTML-NORM(_F_,_ATR_,_CON_)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;{0}parser
#defn    HTML-VOID(_F_,_ATR_)           #ATOM#CMPLX;#ATOM#CMPLX;{"",1}parser
#defn    UNPARS(_F_)                    #ATOM#CMPLX;unparser


/******************
   INSTRUCCIONES 
 ******************/

#defn    RET(_X_)            #ATOM#CMPLX;back;
#define  RETURN              back
#synon   RETURN              RET
#define  ENDMAIN             {0}return
#synon   ENDMAIN             END,STOP
#define  NL                  "\n"
#define  TAB                 "\t"
#define  PROCEDURES          .locals
#synon   PROCEDURES          PROCS, FUNCTIONS,FUNCS, RUTINES
#define  BREAK-ON            .ctrlc
#define  STACK               .stack

#defn    DEF-FUN(_F_,*)      _F_:,#GENCODE $$$*$$$ #REVLIST=0;mov(#REVLIST);#ENDGEN;


// TAKE puede estar dentro de una instruccion con GENCODE, si se hace esta llamada:
#defn    __MEM__(*)          #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;
#define  MEM(*)              __MEM__(*)
#define  VAR(_X_)            {_X_}

#defn    DUP(__X__)          #ATOM#CMPLX;dup;
#define  DUPLICATE-IT        ;dup;
#define  DUP                 ;dup;
#define  RETAIN(__X__)       ;keep(__X__)
#define  RETAIN              ;keep;
#define  FORGET-ALL          ;clearstack;
#define  FORGET              ;kill;

/* LIMPIEZA DE VARIABLES Y MARCAS */
#define  CLR-MARK            ;clearmark;
#define  CLR-RANGE           ;clearrange;
#define  CLR-INTERVAL        ;clearinterval;
#define  SET-CLR-ALL-MARKS   ;clrmarksall;
#define  CLR-ALL-MARKS       ;clearall;

#defn    MCLEAR(*)           #GENCODE $$$*$$$ clear(#LIST);#ENDGEN;
#define  TRASH(_X_)          {0}mov(_X_);
#define  CLEAR(_X_)          clear(_X_)

// main:
#defn    DEF-MAIN(_V_,_N_)   #RAND, main:,V#RNDV=1,_V_={#VOID}, \
                             _N_=0,totalarg,mov(_N_), \
                             LOOPGETARG_#RNDV:, {[ V#RNDV ]},push(_V_),++V#RNDV,\
                             {V#RNDV,_N_},jle(LOOPGETARG_#RNDV),clear(V#RNDV),%RAND;
#define  DEF-MAIN     main:

#define  GET-PARAM-NUM(_N_)       {[_N_]};xtonum;
#define  GET-PARAM-STR(_N_)       {[_N_]};
#define  GET-TOTAL-PARAMS         totalarg;

#defn    GET-PARAMS(*)    #GENCODE $$$*$$$ #LIST=0,{[#ITV]},mov(#LIST);#ENDGEN,



/*******************************
   ITERACIONES, SALTOS Y BIFURCACIONES
 *******************************/

// LOOP( label ) ... BACK-IF...
// Aqui solo sirve salir con GOTO o JUMP-TO si se desea quebrar el bucle.
#define  LOOP(_X_)                  ;_X_:

// UN SOLO ARGUMENTO:
#defn    BACK-IF-POS(_X_,_L_)       #ATOM#CMPLX;jpos(_L_)
#defn    BACK-IF-NEG(_X_,_L_)       #ATOM#CMPLX;jneg(_L_)
#defn    BACK-IF-NOT-ZERO(_X_,_L_)  #ATOM#CMPLX;jnz(_L_)
#defn    BACK-IF-ZERO(_X_,_L_)      #ATOM#CMPLX;jz(_L_)
#defn    BACK-IF-NOT-NULL(_X_,_L_)  #ATOM#CMPLX;jnv(_L_)
#defn    BACK-IF-NULL(_X_,_L_)      #ATOM#CMPLX;jv(_L_)

// ESPECIFICOS:
#defn    BACK-IF-LE(_X_,_Y_,_L_)           #ATOM#CMPLX;#ATOM#CMPLX;jle(_L_)
#defn    BACK-IF-LT(_X_,_Y_,_L_)           #ATOM#CMPLX;#ATOM#CMPLX;jlt(_L_)
#defn    BACK-IF-GT(_X_,_Y_,_L_)           #ATOM#CMPLX;#ATOM#CMPLX;jgt(_L_)
#defn    BACK-IF-GE(_X_,_Y_,_L_)           #ATOM#CMPLX;#ATOM#CMPLX;jge(_L_)
#defn    BACK-IF-EQ(_X_,_Y_,_L_)           #ATOM#CMPLX;#ATOM#CMPLX;jeq(_L_)
#defn    BACK-IF-NOT-EQ(_X_,_Y_,_L_)       #ATOM#CMPLX;#ATOM#CMPLX;jneq(_L_)

// composicion más semantica:  LOOP( label ) ... IF-EQ(x,y) BACK-TO ( label )
#defn    IF-LE(_X_,_Y_)            #ATOM#CMPLX;#ATOM#CMPLX;le?
#defn    IF-LT(_X_,_Y_)            #ATOM#CMPLX;#ATOM#CMPLX;lt?
#defn    IF-GT(_X_,_Y_)            #ATOM#CMPLX;#ATOM#CMPLX;gt?
#defn    IF-GE(_X_,_Y_)            #ATOM#CMPLX;#ATOM#CMPLX;ge?
#defn    IF-EQ(_X_,_Y_)            #ATOM#CMPLX;#ATOM#CMPLX;eq?
#defn    IF-NOT-EQ(_X_,_Y_)            #ATOM#CMPLX;#ATOM#CMPLX;neq?

#defn    IF-POS(_X_)       #ATOM#CMPLX;pos?
#defn    IF-NEG(_X_)       #ATOM#CMPLX;neg?
#defn    IF-NOT-ZERO(_X_)  #ATOM#CMPLX;zero?;not;
#defn    IF-ZERO(_X_)      #ATOM#CMPLX;zero?
#defn    IF-NOT-NULL(_X_)  #ATOM#CMPLX;void?
#defn    IF-NULL(_X_)      #ATOM#CMPLX;void?;not;

#defn    BACK-TO(_L_)              do{jmp(_L_)}


// GEENRAL:
#defn    BACK-IF-NOT(_X_,_L_)       #ATOM#CMPLX;jnt(_L_)
#defn    BACK-IF(_X_,_L_)           #ATOM#CMPLX;jt(_L_)

// SALTOS:
#synon   BACK-IF-POS         JUMP-IF-POS,GOTO-IF-POS
#synon   BACK-IF-NEG         JUMP-IF-NEG,GOTO-IF-NEG
#synon   BACK-IF-NOT-ZERO    JUMP-IF-NOT-ZERO,GOTO-IF-NOT-ZERO
#synon   BACK-IF-ZERO        JUMP-IF-ZERO,GOTO-IF-ZERO
#synon   BACK-IF-NOT-NULL    JUMP-IF-NOT-NULL,GOTO-IF-NOT-NULL 
#synon   BACK-IF-NULL        JUMP-IF-NULL,GOTO-IF-NULL
#synon   BACK-IF-LE          JUMP-IF-LE,GOTO-IF-LE
#synon   BACK-IF-LT          JUMP-IF-LT,GOTO-IF-LT
#synon   BACK-IF-GT          JUMP-IF-GT,GOTO-IF-GT
#synon   BACK-IF-GE          JUMP-IF-GE,GOTO-IF-GE
#synon   BACK-IF-EQ          JUMP-IF-EQ,GOTO-IF-EQ
#synon   BACK-IF-NOT-EQ      JUMP-IF-NOT-EQ,GOTO-IF-NOT-EQ
#synon   BACK-IF-NOT         JUMP-IF-NOT,GOTO-IF-NOT
#synon   BACK-IF             JUMP-IF,GOTO-IF

// usan el contenido de la memoria para activar.
#defn    ON-GOTO(*)          #GENCODE $$$*$$$ {#ITV}keep,eq? do{kill,jmp(#LIST)},#ENDGEN
#defn    ON-GOSUB(*)         #GENCODE $$$*$$$ {#ITV}keep,eq? do{kill,jsub(#LIST),jmp(#HERE)},#ENDGEN
#defn    ON-OPTION(*)        #GENCODE $$$*$$$ {#ITV}keep,eq? do{kill,#LIST,jmp(#HERE)},#ENDGEN


// ITERACIONES:

#defn    ITERATE(_INC_,_REL_,*)       #RAND; _LOOP_#RNDV:;*;\  //;kbesc?do{{"infinity loop breaked"};throw(1010)};\
                                      _INC_;_REL_;jt(_LOOP_#RNDV);%RAND;

#defn    FOR(_X_,_INC_)                    &(_INC_) #LOOP:,_X_,jnt(#ENDLOOP),
#defn    WHILE(_X_)                        &( ) #LOOP:,#ATOM#CMPLX,jnt(#ENDLOOP)

#defn    PERF-UP(__V__,__TO__,__STEP__)    &(__V__+=__STEP__) #LOOP:,\
                                           {__V__}lethan(__TO__), jnt(#ENDLOOP),
#defn    PERF-DOWN(__V__,__TO__,__STEP__)  &(__V__-=__STEP__) #LOOP:,\
                                           {__V__}gethan(__TO__), jnt(#ENDLOOP),

// para cada token dentro del string. Debe definirse antes TOKSEP para indicar separador de token.
#defn    PERF-EACH-TKN(_Y_,_X_,_TT_)       #RAND, ##ENDLOOP &(++_EXPR2_#RNDV;--_EXPR_#RNDV;{_EXPR_#RNDV};jz(%%ENDLOOP)) , \
                                           _Y_="", _EXPR2_#RNDV=1, _EXPR_#RNDV=_TT_,{_TT_},jz(%%ENDLOOP),#LOOP: ,\
                                           {_EXPR2_#RNDV},$(_X_),mov(_Y_),%RAND;

// itera para cada caracter
#defn    PERF-EACH-CHR(_Y_,_X_,_LEN_)      #RAND, ##ENDLOOP &(++_EXPRI_#RNDV;--_EXPRL_#RNDV;{_EXPRL_#RNDV};jz(%%ENDLOOP)),\
                                           {_LEN_},jz(%%ENDLOOP),_Y_="", _EXPRI_#RNDV=1, _EXPRL_#RNDV=_LEN_,\
                                           #LOOP:,[_EXPRI_#RNDV]get(_X_),mov(_Y_),%RAND;

#defn    PERFORM(_LABEL_,_TIMES_,*)        #RAND, __VAR_PERF_#RNDV=0; _TIMES_;minus(1);mov(__VAR_PERF_#RNDV),#LOOP:, \
                                           #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;jsub(_LABEL_), __VAR_PERF_#RNDV--,jnz(%LOOP) %RAND;

// if-else:
#defn    ELS-COND(__X__)     jmp(%%CODEIF), %ENDIF:, #ATOM#CMPLX ,jnt(#ENDIF),
#defn    COND(__X__)         ##CODEIF, #ATOM#CMPLX , jnt(#ENDIF),
#defn    ELS                 jmp(%%CODEIF), %ENDIF:, true,jnt(#ENDIF),
#defn    CEND                %CODEIF:, %ENDIF:,

/* TRY/CATCH */
#defn    TRY                 swtrap( #CATCH ),
#defn    RAISE(_ERR_,_M_)    {_M_}, throw(_ERR_),
#defn    CATCH(_X_)          jmp(#ENDCATCH), %CATCH:, clearstack,_X_=0,gettry(_X_),  // gettry hace poptry internamente?
#defn    FREE-TRY            popcatch    // usar si se escapa de TRY con salto
#defn    FINISH              %ENDCATCH:,popcatch
#define  GET-STR-ERROR       getstrerror

/* Sswitch */
#defn    SELECT(_X_)         ##CODESW,##CODEMRK;%%MARK=0,#ATOM#CMPLX,mov(%%MARK)
#defn    BTWN(_X_,_Y_)       #ATOM#CMPLX,{%%MARK}ge?,#ATOM#CMPLX,{%%MARK}le?,and,do
#defn    EXACT-OCCURS(_X_)       {_X_}{%%MARK}ecin?,do
#defn    CASE-NOT-NEGATIVE       {%%MARK}neg?,not,do
#defn    CASE-NOT-ZERO           {%%MARK}zero?,not,do
#defn    CASE-NOT-POSTIVE        {%%MARK}pos?,not,do
#defn    CASE-NOT-NUMERIC        {%%MARK}numeric?,not,do
#defn    CASE-NOT-STRING         {%%MARK}string?,not,do
#defn    CASE-NOT-ARRAY          {%%MARK}array?,not,do
#defn    CASE-NOT-NULL           {%%MARK}void?,not,do
#defn    CASE-NEGATIVE       {%%MARK}neg?,do
#defn    CASE-ZERO           {%%MARK}zero?,do
#defn    CASE-POSTIVE        {%%MARK}pos?,do
#defn    CASE-NUMERIC        {%%MARK}numeric?,do
#defn    CASE-STRING         {%%MARK}string?,do
#defn    CASE-ARRAY          {%%MARK}array?,do
#defn    CASE-NULL           {%%MARK}void?,do
#defn    CASE(_X_)           #ATOM#CMPLX,{%%MARK}eq?,do
#defn    DEFAULT             true,do
#defn    OCCURS(_X_)         {_X_}{%%MARK}cin?,do
#defn    ON-LST(_X_)         {%%MARK}{_X_}array(1),do
#defn    EXIT                jmp(%%CODESW),
///#defn    Freeswitch          ipop(_VTMP09828),clear(_VTMP09828),
#defn    SELEND              %CODESW:,%MARK:,

// usar construccion "When( expr-L ), {   }" para hacer un pequeño desvio:
#defn    WHEN(_X_)           #ATOM#CMPLX,do

/* Quiebre condicionado de bucles FOR, WHILE y LOOP */
#defn    BREAK-IF-KEY-PRESSED kbhit?;jt(%%ENDLOOP)
#defn    BREAK-IF(__X__)     #ATOM#CMPLX,
// subgrupo instrucciones lógicas para "exit if...": BREAK-IF( V ) IS-ZERO
#defn    IS-NOT-ZERO         jnz(%%ENDLOOP)
#defn    IS-ZERO             jz(%%ENDLOOP)
#defn    IS-FALSE            jnt(%%ENDLOOP)
#defn    IS-TRUE             jt(%%ENDLOOP)
#defn    IS-NOT-NULL         jnv(%%ENDLOOP)
#defn    IS-NULL             jv(%%ENDLOOP)
#defn    IS-NEG              jneg(%%ENDLOOP)
#defn    IS-POS              jpos(%%ENDLOOP)
#defn    IS-INF              inf?,jt(%%ENDLOOP)
#defn    IS-NAN              nan?,jt(%%ENDLOOP)
#defn    HAVE-NAN            stats(0),nan?,jt(%%ENDLOOP)
#defn    IS-ENTER            eqto(13),jt(%%ENDLOOP)
#defn    IS-ESCAPE           eqto(27),jt(%%ENDLOOP)
#defn    IS-EMPTY            isempty,jt(%%ENDLOOP)
#defn    IS-NOT-FILE         exist?;not;jt(%%ENDLOOP)
#defn    IS-FILE             exist?;jt(%%ENDLOOP)
#defn    IS-NOT-DIR          existdir?;not;jt(%%ENDLOOP)
#defn    IS-DIR              existdir?;jt(%%ENDLOOP)

/* Quiebre de ciclos */
#defn    CONTINUE            %%&, jmp(%%LOOP)
#defn    BREAK               jmp(%%ENDLOOP)
#defn    WEND                %&,  jmp(%LOOP), %ENDLOOP:,
#synon   WEND                NEXT
 
/*************************
    OTRAS DEFINICIONES
 *************************/

/* environment */
#defn    SET-ENV(_V_,_X_)   #ATOM#CMPLX;{#APTFE_X_#APTFE};setenv;
#defn    NUM-ENV(_X_)       {#APTFE_X_#APTFE};getenvnum;
#defn    STR-ENV(_X_)       {#APTFE_X_#APTFE};getenv;
#defn    UNSET-ENV(_X_)     {#APTFE_X_#APTFE};unsetenv;
#defn    EXEC(_X_)          #ATOM#CMPLX;exec;
#defn    SYS(_X_)           #ATOM#CMPLX;execv;


// LISTAS
#defn    VOID(*)             #GENCODE $$$*$$$ #LIST={#VOID};#ENDGEN
#define  APND-LST(_X_)       pushall(_X_)
#define  APND-ROW(_X_)       addrow(_X_)
#defn    MPUSH(__X__,*)      #GENCODE $$$*$$$ #ATCMLIST;push(__X__); #ENDGEN;
#define  PUSH(__X__)         push(__X__)
#define  QPOP(__X__)         qpop(__X__)
#define  POP(__X__)          pop(__X__)
#define  HEAD(__X__)         head(__X__)
#define  TAIL(__X__)         tail(__X__)
#defn    LOOK(__N__,__X__)   #ATOM#CMPLX;look(__X__)
#define  NOT-EMPTY(__X__)    empty(__X__);not;
#define  EMPTY(__X__)        empty(__X__)
#defn    LENGTH(__X__)       #ATOM#CMPLX;length;


// COLUMNAS Y FILAS DE ARRAYS 2D y 3D:
#define  GET-ROWS-FROM(__X__)      getrow(__X__)
#define  GET-COLS-FROM(__X__)      getcol(__X__)
// estas dos no pueden ir dentro de Let:
#defn    CAT-ROWS(__X__,*)   #GENCODE $$$*$$$ #REVATCMLIST;#ENDGEN;catrow(__X__)
#defn    CAT-COLS(__X__,*)   #GENCODE $$$*$$$ #REVATCMLIST;#ENDGEN;catcol(__X__)
//#define  CAT-COLS(__X__)     ;catcol(__X__)
//#define  CAT-ROWS(__X__)     ;catrow(__X__)
// Las siguientes macros necesitan declarar [] con anterioridad: [n] GET-PAGE(v)
#define  GET-PAG-FROM(__X__)      getpage(__X__)
#define  PUT-PAG(__X__)      putpage(__X__)
/* Posiciones Pares y Nones en arrays */
#define  ODD-ROWS-COLS       [2:end,2:end];{2}{2}interval2;
#define  ODD-ROWS-EVEN-COLS  [2:end,1:end];{2}{2}interval2;
#define  EVEN-ROWS-COLS      [1:end,1:end];{2}{2}interval2;
#define  EVEN-ROWS-ODD-COLS  [1:end,2:end];{2}{2}interval2;
#define  ODD-ROWS            [2:end,1:end];{2}interval1;
#define  ODD-COLS            [1:end,2:end];{0}{2}interval2;
#define  ODD-POS             [2:end];{2}interval1;
#define  ODD-PAGS            [2:end];{0}{0}{2}interval3;
#define  EVEN-ROWS           [1:end,1:end];{2}interval1;
#define  EVEN-COLS           [1:end,1:end];{0}{2}interval2;
#define  EVEN-POS            [1:end];{2}interval1;
#define  EVEN-PAGS           [1:end];{0}{0}{2}interval3;

// ACCESO A ARRAYS GET Y PUT
#define BLK-                ;
#synon  BLK-                SEG-
#define CGET-CELLS(_X_)       get(_X_);clearinterval;
#defn   CPUT-CELLS(_E_,_X_)   #ATOM#CMPLX;put(_X_);clearinterval;
#define GET-CELLS(_X_)        get(_X_)
#defn   PUT-CELLS(_E_,_X_)    #ATOM#CMPLX;put(_X_)

#define  S-CGET(__X__)        ewget(__X__);clearinterval;
#define  S-GET(__X__)         ewget(__X__)
#define  CGET(_X_)            get(_X_);clearinterval;
#define  GET(_X_)             get(_X_)

#define  S-CPUT(__X__)        ewput(__X__);clearinterval;
#define  S-PUT(__X__)         ewput(__X__)
#define  CPUT(__X__)          put(__X__);clearinterval;
#define  PUT(__X__)           put(__X__)
// macros para devolver datos del array:
#define  ADIMS(__A__)         dims(__A__)
#define  AROWS(__A__)         rows(__A__)
#define  ACOLS(__A__)         cols(__A__)
#define  APAGS(__A__)         pages(__A__)

/* FUNCIONES ESPECIALES DE ARRAYS */
// estas no devuelven datos:
#defn    SEQ-SPC(__X__,__Y__,__Z__,_V_)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;keep;lthan(1);\
                                             do{{"LinSpaced: num elements < 1"}throw(2301)},seqsp(_V_)
#defn    SEQ(__X__,__Y__,__Z__,_V_)          #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;keep;lthan(1);\
                                             do{{"Sequence: num elements < 1"}throw(2301)},seq(_V_)
#defn    CLAMP(__X__,__Y__,_V_)              #ATOM#CMPLX;#ATOM#CMPLX;clamp(_V_)
#defn    RE-DIM(_X_,*)                       #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;reshape(_X_)

#defn    SAVE-MAT(_MAT_,_F_)                 #ATOM#CMPLX;#ATOM#CMPLX;save;
#defn    LOAD-MAT(_F_)                       __FILE_TO_LOAD__=0;#ATOM#CMPLX;mov(__FILE_TO_LOAD__);\
                                             {__FILE_TO_LOAD__}statsfile;{__FILE_TO_LOAD__}load;
// USING(MAX_LINE), READ-AS-ROW(fd). (FD) se coloca naturalmente
#defn    READ-AS-ROW            ;readrow
#defn    WRIT-AS-ROW(__A__)     #ATOM#CMPLX;writerow

// verifica la aproximación de un array comparado con otro:
#defn    APROACH?(_X_)          #RAND; _VAPROACH_#RNDV=0;keep;length;mov(_VAPROACH_#RNDV);xtonum;stats(0);\
                                {_VAPROACH_#RNDV};div;#ATOM#CMPLX;lt?;%RAND;

#defn    FOR-ALL(_X_,_R_,*)     clearinterval;clearrange;_R_;get(_X_);#GENCODE $$$*$$$\
                                #ATCMLIST;#ENDGEN;put(_X_);\
                                clearinterval;clearrange;
// encuentra todo lo que no sea cero o nulo, o false. EJ: find all ( Ge(r, 0x101b), rango)
#defn    FND-ALL(_R_)           #ATOM#CMPLX;cartesian;
#define  SET-RANGE(__X__)       range(__X__)

/* mapea una matriz, cambiando un valor por _X_. crea el array _Y_, con el array _V_ modificado */ 
#defn    LET-MAP(_EXPR_,_X_,_V_,_Y_)        #RAND,clear range,_Y_=_V_,#ATOM#CMPLX;cartesian,_RG_#RNDV=0,\
                                            mov(_RG_#RNDV),\
                                            range(_RG_#RNDV),_Y_=_X_,clear(_RG_#RNDV),clear range,%RAND;
/* mapea una matriz, cambiando un valor por _X_. Altera el mismo array.
   Si desea mantener el array original, respaldelo, o use LETMAP */ 
#defn    MAP(_EXPR_,_X_,_V_)                #RAND,clear range,#ATOM#CMPLX;cartesian,_RG_#RNDV=0,mov(_RG_#RNDV),\
                                            range(_RG_#RNDV),_V_=_X_,clear(_RG_#RNDV),clear range,%RAND;
#defn    SPLIT(__S__,__A__,__T__)           __TKN_SPLIT__=0;gettoksep;mov(__TKN_SPLIT__);{__T__}toksep;#ATOM#CMPLX;split(__A__);\
                                            {__TKN_SPLIT__};toksep;
// compacta un array N-DIM en uno 1D, eliminando blancos, ceros y falsos:
#defn    COMPACT(__A__)                     #ATOM#CMPLX;compact;
#defn    CART(__X__)                        #ATOM#CMPLX;cartesian;
/* FUNCIONES ESPECIALES DE ARRAYS */
// Swap de filas, columnas, paginas y rangos de intervalo:
#defn    SWAP-ROWS(_X_,_R1_,_R2_)           #RAND,clearstack,_TMP#RNDV_=0,[_R1_,1:end]get(_X_),mov(_TMP#RNDV_),\
                                            [_R2_,1:end]get(_X_),[_R1_,1:end]put(_X_),\
                                            {_TMP#RNDV_}[_R2_,1:end]put(_X_),clear(_TMP#RNDV_),clearstack,clearinterval,%RAND;

#defn    SWAP-COLS(_X_,_C1_,_C2_)           #RAND, clearstack,_TMP#RNDV_=0,[1:end,_C1_]get(_X_),mov(_TMP#RNDV_),\
                                            [1:end,_C2_]get(_X_),[1:end,_C1_]put(_X_),\
                                            {_TMP#RNDV_}[1:end,_C2_]put(_X_),clear(_TMP#RNDV_),clearstack,clearinterval,%RAND;

#defn    SWAP-PAGS(_X_,_P1_,_P2_)           #RAND, clearstack,_TMP#RNDV_=0,[_P1_]getpage(_X_),mov(_TMP#RNDV_),\
                                            [_P2_]getpage(_X_),[_P1_]putpage(_X_),\
                                            {_TMP#RNDV_}[_P2_]putpage(_X_),,clear(_TMP#RNDV_),clearstack,clearinterval,%RAND;

#defn    SWAP-INTERV(_X_,_R1_,_R2_)         #RAND,clearstack,_TMP#RNDV_=0,_R1_,get(_X_),mov(_TMP#RNDV_),\
                                            _R2_,get(_X_),_R1_,put(_X_),\
                                            {_TMP#RNDV_}_R2_,put(_X_),clear(_TMP#RNDV_),clearstack,clearinterval,%RAND;

#define  SWAP(_X_,_Y_)                      _X_<->_Y_

#defn    ENUM-ARRAY(_LISTA_,__INIT__)       #RAND, ___ENUMERATE_=0, {_LISTA_}array? do{ dims(_LISTA_),gthan(1),\
                                            do{{0}reshape(_LISTA_)},rows(_LISTA_),jmp(___EXIT_ENUM_ARRAY__#RNDV)},\
                                            {"enumerate: type mismatch - I need an array"}throw(1999),\
                                            ___EXIT_ENUM_ARRAY__#RNDV:,{__INIT__}minus(1),add,mov(___ENUMERATE_),\
                                            __ENUMLST_={#VOID}, {__INIT__},{___ENUMERATE_},{___ENUMERATE_},minus(__INIT__),plus(1),\
                                            seqsp(__ENUMLST_){_LISTA_,__ENUMLST_}catcolumn(_LISTA_),%RAND;

#defn    ENUM-STR(_STRING_,__INIT__,__TKN__)  ___ENUMERATE_=0,{"string",_STRING_}type,neq?,\
                                              do{ {"enumerate: type mismatch - I need a string"}throw(1999) },\
                                              ___OLDTKN___=0,gettoksep,mov(___OLDTKN___),{__TKN__}toksep,{_STRING_}\
                                              split(_STRING_),rows(_STRING_),{__INIT__}minus(1),add,mov(___ENUMERATE_),\
                                              __ENUMLST_={#VOID},{__INIT__,___ENUMERATE_,___ENUMERATE_},minus(__INIT__),plus(1),\
                                              seqsp(__ENUMLST_),{_STRING_,__ENUMLST_}catcolumn(_STRING_),{___OLDTKN___}toksep,

/* Arrays por funcion ARRAY de 1 dimensión (y algunas de 2) sin DEVOLUCION */
// FUNCIONES DE ARRAY
//
#defn    INSERT(__V__,__P__,__X__)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(3);
#defn    DELETE(__P__,__X__)         #ATOM#CMPLX;#ATOM#CMPLX;array(4);
#defn    RE-SIZE(__S__,__X__)        #ATOM#CMPLX;#ATOM#CMPLX;array(5);
#defn    ZAP-RANGE(_RI_,_RF_,_X_)    #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(7);
#defn    CONCAT(__AS__,__AT__)       #ATOM#CMPLX;#ATOM#CMPLX;array(6);
#defn    SORT(__X__)                 #ATOM#CMPLX;array(0);
// con devolucion
#defn    REV-SCAN(__V__,__X__)       #ATOM#CMPLX;#ATOM#CMPLX;array(2);
#defn    SCAN(__P__,__V__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(1);
#defn    SCAN-TABLE(_C_,_V_,_X_)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(8);
#defn    DISTR(_A1_,_A2_)            #ATOM#CMPLX;#ATOM#CMPLX;array(9);
#defn    MAX-VALUE(__X__)            #ATOM#CMPLX;array(10);
#defn    MIN-VALUE(__X__)            #ATOM#CMPLX;array(13);
#defn    MAX-POS(__X__)              #ATOM#CMPLX;array(11);
#defn    MIN-POS(__X__)              #ATOM#CMPLX;array(14);
#defn    MAX-ARR(_X_)                #ATOM#CMPLX;array(12);  // devuelve valor,posicion
#defn    MIN-ARR(_X_)                #ATOM#CMPLX;array(15);  // devuelve valor,posicion
#defn    MIX-ARR(_X_,_Y_)            #ATOM#CMPLX;#ATOM#CMPLX;array(16);
#defn    ROT-LEFT(_D_,_H_,_X_)       #ATOM#CMPLX;#ATOM#CMPLX;{_X_}array(17); //left rotate
#defn    ROT-RIGHT(_D_,_H_,_X_)      #ATOM#CMPLX;#ATOM#CMPLX;{_X_}array(18);
#defn    SWAP-ELEM(_P1_,_P2_,_X_)    #ATOM#CMPLX;#ATOM#CMPLX;{_X_}array(19);  // swap elementos

// ARCHIVOS:
#defn    DATA-FILE(_F_,_A_)          _A_={#VOID},#ATOM#CMPLX,statsfile,pushall(_A_)
// se usan como instrucción(,,,)(FD)
// USAR con Using(MODO), Open File (...)(fd)
#defn    USING(__X__)          #ATOM#CMPLX;
#defn    FILE-OPEN(_F_)        #ATOM#CMPLX,open
#defn    FILE-CREATE(_F_)      #ATOM#CMPLX,create
// más "humano" no necesita "using":
#defn    OPEN-INPUT(_F_)       {0};#ATOM#CMPLX,open
#defn    OPEN-OUTPUT(_F_)      {1};#ATOM#CMPLX,open
#defn    OPEN-APPEND(_F_)      {2};#ATOM#CMPLX,open
#defn    OPEN-EXCLUSIVE(_F_)   {16};#ATOM#CMPLX,open

#defn    CREATE-NORMAL(_F_)    {0};#ATOM#CMPLX,create
#defn    CREATE-READ-ONLY(_F_) {1};#ATOM#CMPLX,create
#defn    CREATE-HIDDEN(_F_)    {2};#ATOM#CMPLX,create
#defn    CREATE-SYSTEM(_F_)    {4};#ATOM#CMPLX,create

// USING(MAX_LINE), READ-LINE(FD)
#defn    READ-LINE             ;readline
#defn    READ-STR              ;readstring
#defn    WRIT-LINE(_S_)        #ATOM#CMPLX,writeline
#defn    WRIT-STR(_S_)         #ATOM#CMPLX,writestring
#define  GET-POS               {SEEK_CUR,0}seek
//  SetPos devuelve un dato al stack: debe ser asignado:
#defn    SET-POS(_N_)          {SEEK_SET},#ATOM#CMPLX,seek
#defn    SEEK(_M_,_P_)         #ATOM#CMPLX,#ATOM#CMPLX,seek

// posicionan puntero de lectura-escritura en archivo abierto: no deben ser asignados
#define  SET-BOF(_FD_)         {SEEK_SET,0}seek(_FD_),kill
#define  SET-EOF(_FD_)         {SEEK_END,0}seek(_FD_),kill
#defn    READ-LINES(_FD_,_N_,_SIZE_)   #RAND; _STR_87364="";_STMP_726345="";_I_#RNDV=_N_;_LOOP_#RNDV:;\
                                       {_SIZE_}readline(_FD_);mov(_STMP_726345);\
                                       {_STR_87364}{_STMP_726345}{"\n"}*cat;mov(_STR_87364);--_I_#RNDV;\
                                       {_I_#RNDV}jnz(_LOOP_#RNDV);{_STR_87364};%RAND;
#define  FILE-SIZE(_FD_)               _TMP_09384234=0;{SEEK_CUR}{0};seek(_FD_);mov(_TMP_09384234);\
                                       {SEEK_END}{0}seek(_FD_);{SEEK_SET}{_TMP_09384234}seek(_FD_);kill;
#define  EOF(_FD_)                     eof(_FD_)
#define  CLOSE(_FD_)                   close(_FD_)
#define  GET-STR-FILE-ERROR            fileerror

// Archivos cargado como string:
#defn    LOAD-STR(_F_,_D_)             #ATOM#CMPLX;loadstring(_D_)
#defn    SAVE-STR(_F_,_D_)             #ATOM#CMPLX;savestring(_D_)
#defn    GET-LINE(__L__,__S__)         #ATOM#CMPLX;getline(__S__)
#defn    CNT-LINES(__S__)              ;countlines(__S__);

// FUNCIONES QUE DEPENDEN DE SEARCH:
#define  GETS-LINE-POS(_V_,_N_)           __ROW_768345=0;{2}{_N_}{_V_}array(8);mov(__ROW_768345);\
                                          [__ROW_768345,1]get(_V_)
#define  GETS-POS-LINE(_V_,_N_)           __ROW_768345=0;{1}{_N_}{_V_}array(8);mov(__ROW_768345);\
                                          [__ROW_768345,2]get(_V_)
#defn    GETS-LINE(_I_,_SIZE_,_V_,_FD_)   __POS_4345=0;{SEEK_SET}{2};#ATOM#CMPLX;mov(__POS_4345);\
                                          __ROW_768345=0;[__POS_4345,1]get(_V_);{_V_}array(8);\
                                          seek(_FD_);kill;{_SIZE_}readline(_FD_)
#defn    SEARCH-LINES(_F_,_V_)            {"-r $'\n'"},#ATOM#CMPLX,search(_V_)
#defn    SEARCH(_P_,_F_,_V_)              #ATOM#CMPLX,#ATOM#CMPLX,search(_V_)

// TIME CONTROL
///#defn    DEVIATE-IF(_X_,_LIMIT_)     #ATOM#CMPLX;timer(_LIMIT_);do
#defn    IN-TIME(_X_,_LIMIT_,*)      #ATOM#CMPLX;timer(_LIMIT_);do{ * }
// hace algo si es el tiempo:
#defn    ON-TIME(_X_,_LIMIT_)          #ATOM#CMPLX;timer(_LIMIT_);do
// salta a un sub si es el tiempo:
#defn    JIT-GOSUB(_X_,_L_,_LBL_)       #ATOM#CMPLX;timer(_L_);gsub(_LBL_)
// 
#defn    IS-TIME(_X_,_LIMIT_)            ;#ATOM#CMPLX;timer(_LIMIT_); // devuelve TRUE o FALSE

// saltos libres, con y sin retorno:
#define  JUMP-TO(_X_)        jmp(_X_)
#synon   JUMP-TO             GOTO
#define  GOSUB(_X_)          jsub(_X_)  // usa RETURN o RET para volver.


#define  TIC(_X_)                    timecpu(_X_)    
#define  TOC(_X_,_Y_)                timecpu(_Y_),{_Y_}minus(_X_),clockpersec,div,mov(_Y_); //,clear(_X_)

// convierte a segundos una hora "hh:mm:ss:mm". _X_ se mete en stack.
// "seconds", sin stack, entrega los segundos desde la medianoche

#defn    SECONDS(_X_)                 #ATOM#CMPLX;seconds;
#define  SECONDS                      ;seconds;

// obtiene el tiempo transcurrido en milisegundos, entre _X_ e _Y_:
#defn    LOOK-TIME(_X_,_Y_)           #ATOM#CMPLX;timer(_Y_)
#defn    MICROSECS(_X_)               #ATOM#CMPLX;microsecs;
#defn    SEC-TO-TIME(_X_)             #ATOM#CMPLX;sectotime;
#defn    SLEEP(_X_)                   #ATOM#CMPLX;sleep;
// obtiene el tiempo transcurrido de ejecución:
#define  TIME-CPU(__X__)              timecpu(__X__)
#define  CLOCKS-PER-SEC               clockpersec;

/* BITS */
#defn    GET-BIT(__N__,__I__)      #ATOM#CMPLX;bit(__I__)
#defn    AND-BIT(__X__,__Y__)      #ATOM#CMPLX;#ATOM#CMPLX;bit(100)
#defn    XOR-BIT(__X__,__Y__)      #ATOM#CMPLX;#ATOM#CMPLX;bit(102)
#defn    OR-BIT(__X__,__Y__)       #ATOM#CMPLX;#ATOM#CMPLX;bit(101)
#defn    NOT-BIT(__X__)            #ATOM#CMPLX;bit(103)
// Take(1,2,3...),ClrBit(n)
#defn    CLR-BIT(__X__)            #ATOM#CMPLX;bit(104)
// Take(1,2,3...),SetBit(n)
#defn    SET-BIT(__X__)            #ATOM#CMPLX;bit(105)
// MissByte(LOWBYTE|HIGHBYTE, n)
#defn    MIRR-BYTE(__X__,__Y__)    #ATOM#CMPLX;#ATOM#CMPLX;bit(106)
// RotBit(LOWBYTE|HIGHBYTE, i, n)
#defn    ROT-BIT(_X_,_P_,_Y_)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;bit(107)
// ShiftR(k,n), k numero de bits
#defn    SHIFT-RIGHT(_E_,_X_)      #ATOM#CMPLX;#ATOM#CMPLX;bit(108)
#defn    SHIFT-LEFT(_E_,_X_)       #ATOM#CMPLX;#ATOM#CMPLX;bit(109)
#defn    HEX-TO-DEC(__X__)         #ATOM#CMPLX;bit(110)
#defn    OCT-TO-DEC(__X__)         #ATOM#CMPLX;bit(111)
#defn    BIN-TO-DEC(__X__)         #ATOM#CMPLX;bit(112)


/* SETS conjuntos */
// las macros son asignables:
#defn    SET-SET(__X__)            {__X__};array(0);{__X__};sets(0)  // unique
#defn    UNIQUE(__X__)             #ATOM#CMPLX;sets(0)
#define  UNIQUE                    ;sets(0)
#defn    UNION(__X__,__Y__)        {__X__}{__Y__}sets(1)
#defn    INTERSECT(_X_,_Y_)        {__X__}{__Y__}sets(2)
#defn    SIM-DIFF(_X_,_Y_)         {__X__}{__Y__}sets(4)
#defn    DIFFERENCE(_X_,_Y_)       {__X__}{__Y__}sets(3)
#defn    DISJOINT(_X_,_Y_)         {__X__}{__Y__}sets(5)
#defn    SUBSET(_X_,_Y_)           {__X__}{__Y__}sets(6)
#defn    SUPERSET(_X_,_Y_)         {__X__}{__Y__}sets(7)


/* RECORD LARGO-POSICION */
// declaracion estandar:
#defn    DECLARE                ##CODEMRK,__FLD_REC_LP=0,%%MARK="",
#defn    COMMIT(_X_)            #RAND,__PF#RNDV=0,join(__PF#RNDV),{__PF#RNDV}gettoksep;format(_X___FMT_),mov(_X_),%RAND;

// RECORD LP
#defn    AS-RECORD-LP(_X_)      _X_="";_X___FMT_=%MARK;
#defn    FIELD-STR(_X_,_S_)     {%%MARK,"$"}{__FLD_REC_LP}xtostr;cat;{":"}cat;{_S_}xtostr;cat;{"L"}cat;cat;\
                                mov(%%MARK);_X___SIZE_=_S_;_X_="";++__FLD_REC_LP
#defn    FIELD-NUM(_X_,_S_)     {%%MARK,"$"}{__FLD_REC_LP}xtostr;cat;{":"}cat;{_S_}xtostr;cat;{"R"}cat;cat;\
                                mov(%%MARK);_X___SIZE_=_S_;_X_=0;++__FLD_REC_LP
#define  GET-STRING-LP(_F_,_X_) [1:_F___SIZE_]get(_X_),trim,mov(_F_);{""}put(_X_);clearmark
#define  GET-NUM-LP(_F_,_X_)    [1:_F___SIZE_]get(_X_),trim,xtonum,mov(_F_);{""}put(_X_);clearmark

/* RECORD LARGO LIBRE */
#defn    AS-RECORD(_X_)         _X_="";_X___FMT_=%MARK;--_X___FMT_
#defn    FIELDS(*)              __SEP__FLD__=0;{36}chr;mov(__SEP__FLD__);#GENCODE $$$*$$$ {%%MARK}{__SEP__FLD__}\
                                {__FLD_REC_LP}xtostr;cat;cat;gettoksep;cat;mov(%%MARK);++__FLD_REC_LP;\
                                #LIST__TOKEN_=__FLD_REC_LP;#LIST=0;#ENDGEN;
#defn    FIELD(_X_)             {%%MARK,"$"}{__FLD_REC_LP}xtostr;cat;cat;gettoksep;cat;mov(%%MARK);++__FLD_REC_LP;\
                                _X___TOKEN_=__FLD_REC_LP;_X_=0;
#defn    MODIFY(_D_,_F_,_X_)    #ATOM#CMPLX;{_F___TOKEN_}$$(_X_);mov(_X_)
#define  GET-STRING(_X_,_Y_)    {_X___TOKEN_}$(_Y_);trim;mov(_X_)
#define  GET-NUM(_X_,_Y_)       {_X___TOKEN_}$(_Y_);xtonum;mov(_X_)

// BASICAS STRING
#defn    LEN(__X__)          #ATOM#CMPLX;len;
#defn    CHAR(__X__)         #ATOM#CMPLX;chr;
#defn    ASCII(__X__)        #ATOM#CMPLX;asc;
#defn    STR(_X_)            #ATOM#CMPLX;xtostr;
#defn    VAL(_X_)            #ATOM#CMPLX;xtonum;
#defn    BOOL(_X_)           #ATOM#CMPLX;xtobool;


/* SOCKETS */
// TCP
// Let ( fd := OpenServerTCP(5,8080) ) 
#defn    OPEN-SERVER-TCP(_N_,_P_)     #ATOM#CMPLX;#ATOM#CMPLX;socket(0);
// Let ( fdCli := OpenClientTCP("127.0.0.1", 8080) )
// acepta conexion entrante: Let ( fdCli := Accept(fd) )
#define  ACCEPT(_FD_)                 accept(_FD_)
// ejemplo:  Send(mensajeStr, fdCli) 
#defn    SEND(__C__,_FDC_)            #ATOM#CMPLX;send(_FDC_)
#defn    RECV(__SIZE__,_FDC_)         #ATOM#CMPLX;recv(_FDC_)
#defn    OPEN-CLIENT-TCP(_IP_,_P_)    #ATOM#CMPLX;#ATOM#CMPLX;socket(1);
#define  CONNECT(_FD_)                connect(_FD_)
// UDP
// Let ( fd := OpenServerUDP(8080) )
#defn    OPEN-SERVER-UDP(_P_)         #ATOM#CMPLX;socket(3);
// Let ( fdCli := OpenClientUDP("127.0.0.1", 8080) )
#defn    OPEN-CLIENT-UDP(_IP_,_P_)    #ATOM#CMPLX;#ATOM#CMPLX;socket(4);
#defn    SEND-TO(__C__,_FD_)          #ATOM#CMPLX;sendto(_FD_)
#defn    RECV-FROM(__SIZE__,_FD_)     #ATOM#CMPLX;recvfrom(_FD_)
// cierre socket
#defn    CLOSE-SOCKET(__FD__)         #ATOM#CMPLX;socket(2)

/* CALENDARIO - CALENDAR */
// genera calendario actual, y devuelve una tabla:
#define  ACTUAL-CAL                   {1}cal(0)
// genera calendario, más/menos _N_ meses:
#defn    RADIAL-CAL(_M_,_Y_,_N_)      {1}#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;__CAL_CNTE_29839__=0;\
                                      mov(__CAL_CNTE_29839__);cal(__CAL_CNTE_29839__)
// genera calendario, más _N_ meses:
#defn    CAL(_M_,_Y_,_N_)             {1}#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;plus(100);__CAL_CNTE_29839__=0;\
                                      mov(__CAL_CNTE_29839__);cal(__CAL_CNTE_29839__)

/* STATS */
#defn    SUMMATORY(__X__)      #ATOM#CMPLX;stats(0)
#defn    MULTIPLICATORY(__X__) #ATOM#CMPLX;stats(8)
#defn    GEO-MEAN(__X__)       #ATOM#CMPLX;stats(9)
#defn    HAR-MEAN(__X__)       #ATOM#CMPLX;stats(10)
#defn    MEAN(__X__)           #ATOM#CMPLX;stats(1)
#defn    STURG-CLASS(_X_)      #ATOM#CMPLX;stats(3)
#defn    BIN-CLASS(_B_,_X_)    #ATOM#CMPLX;#ATOM#CMPLX;stats(4)
#defn    CLASS(__X__)          #ATOM#CMPLX;stats(5)
#defn    ADD-SUB-SUCC(__X__)   #ATOM#CMPLX;stats(13)
#defn    SUB-ADD-SUCC(__X__)   #ATOM#CMPLX;stats(14)
// estas macros actúan sobre matrices 2D:
#defn    SUM-COL(__X__)        #ATOM#CMPLX;stats(6)
#defn    SUM-ROW(__X__)        #ATOM#CMPLX;stats(7)
#defn    MUL-COL(__X__)        #ATOM#CMPLX;stats(11)
#defn    MUL-ROW(__X__)        #ATOM#CMPLX;stats(12)

// ASIGNACIONES Y ALMACENAJE MULTIPLE
#defn    MSET(*)                #GENCODE $$$*$$$ #LIST=0;#ENDGEN
#defn    SET(_X_,_VALUE_)       _X_=_VALUE_;
#defn    MSTOR(__X__,*)         #ATOM#CMPLX,#GENCODE $$$*$$$ cpy(#REVLIST);#ENDGEN,kill,
#defn    STOR(__X__,*)          #ATOM#CMPLX,#GENCODE $$$*$$$ mov(#REVLIST);#ENDGEN,
#defn    LET(_X_,*)             #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN,mov(_X_)
// si no se cumple la expresión, no mueve y deja el dato en el stack
#defn    MOVE-IF(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);mov(_Y_);jmp(#ENDIF);%ENDIIF:;mov(_Z_);%ENDIF:
#defn    COPY-IF(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);cpy(_Y_);jmp(#ENDIF);%ENDIIF:;cpy(_Z_);%ENDIF:
// mueve un valor a una variable, si se cumple una condicion; sino, la deja intacta, pero el valor se pierde de la memoria:
// Move on( Equals(i,1), w )
#defn    MOVE-ON(_X_,_V_)       #ATOM#CMPLX;jnt(#ENDIIF);mov(_V_);jmp(#ENDIF);%ENDIIF:;kill;%ENDIF:
// copia el valor si se cumple la condicion; sino, pasa, pero el valor queda en memoria.
// .... Copy on(Equals(i,1), w), ...
#defn    COPY-ON(_X_,_V_)       #RAND;#ATOM#CMPLX;jnt(__CPY#RNDV__);cpy(_V_);__CPY#RNDV__:;%RAND

// mueve simétricamente #valores a un #de variables:
#defn    MOVE-TO(*)             #GENCODE $$$*$$$ mov(#REVLIST);#ENDGEN,
// copia un solo valor a muchas variables. Deja el valor en memoria:
#defn    COPY-TO(*)             #GENCODE $$$*$$$ cpy(#REVLIST);#ENDGEN,
//

// asigna resultado de una expresión a una variable:
#define  COPY(_X_)           cpy(_X_);
#define  BACKUP-TO(_X_)      cpy(_X_);
#define  MOVE(_X_)           mov(_X_);

// mueve simétricamente #valores a un #de variables:
#define  TO(_X_)                (_X_)
// mueve simétricamente #valores a un #de variables:
#defn    STORE(*)             #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;__MOVING__
#defn    __MOVING__(*)          #GENCODE $$$*$$$ mov(#REVLIST);#ENDGEN;

// SALIDA POR PANTALLA:
#defn    LOCATE(*)              #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;goxy;
#defn    LOC-ROW(__X__)         #ATOM#CMPLX;gox;
#defn    LOC-COL(__X__)         #ATOM#CMPLX;goy;
#define  GET-CUR-ROW(__X__)     __X__=0,cposx(__X__)
#define  GET-CUR-COL(__X__)     __X__=0,cposy(__X__)

//#defn    PRN-TABLE(__M__)       ___X___=0;cposx(___X___);___Y___=0;cposy(___Y___);\
//                                #ATOM#CMPLX;{___X___}{___Y___};print2d;
#defn    PRN-TABLE(__M__)       #ATOM#CMPLX;{___X___}{___Y___};print2d;

// imprime un string _X_ en las posiciones indicadas por un array o range:
///#defn    PRN-RANGE(_X_)         ;

#defn    PRN-IF(_X_,_Y_,_Z_)    #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:;print

#define  VPRNF(__V__,__S__,*)   MEM(*),FORMAT(__S__),mov(__V__)

#defn    PRN-TOP(_X_)           #ATOM#CMPLX;puts;
#define  PRN-TOP                ;puts;
#define  PUTS(_X_)              ;puts(_X_)

#defn    PRNF(__X__,*)          #RAND;__C__#RNDV=0;#ATOM#CMPLX;mov(__C__#RNDV);#GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;\
                                sjoin;{","}format(__C__#RNDV);print;%RAND;
#defn    PRN-USING-TOK(*)       #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;printusingtoken;
#defn    PRNL(*)                #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;{"\n"}print;
#define  PRNL                   {"\n"}print;

#defn    PRN(*)                 #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;print;
#define  PRN                    ;print;

// ENTRADA Y TECLADO:
#defn    GET-CHAR(_X_)          #RAND,pause,lastkey(_X_),{_X_}{194}{1}{207}{1}between?,do{{_X_}chr,pause,\
                                lastkey(_X_),{_X_}chr,cat,utf8tostr,jmp(__GETCHAR__#RNDV)},\
                                {_X_}chr,utf8tostr,__GETCHAR__#RNDV:,mov(_X_),kbfree,%RAND;
#defn    GETCH                  #RAND;_VCH#RNDV_=0;__GETCHAR__#RNDV:;pause;lastkey(_VCH#RNDV_);{_VCH#RNDV_}\
                                dup;{194}{1}{207}{1}between?;do{jmp(__GETCHAR__#RNDV)};kbfree;%RAND;
#defn    PUT-KEY(__X__)         #ATOM#CMPLX;keyput;
#defn    SCAN-CODE(_X_)         #RAND,lastkey(_X_),{_X_}{194}{1}{207}{1}between?,do{{_X_}chr,pause,\
                                lastkey(_X_),{_X_}chr,cat,utf8tostr,jmp(__GETCHAR__#RNDV)},\
                                {_X_}chr,utf8tostr,__GETCHAR__#RNDV:,asc,mov(_X_),kbfree,%RAND;
#define  KBD-FREE               ;kbfree;
#define  PAUSE                  ;pause;
#define  LAST-KEY(_X_)          lastkey(_X_)     //#RAND;_VCH#RNDV_=0;lastkey(_VCH#RNDV_);%RAND

/* TERMINAL BASICO */
#define  HIDE-CURSOR            {"\033[?25l"}, print;
#define  SHOW-CURSOR            {"\033[?25h"}, print;
#define  CLR-SCR                {"\033[2J\033[1;1H\n"},print;

#defn   CUR-FW(_X_)            #ATOM#CMPLX,updcol;
#defn   CUR-BW(_X_)            #ATOM#CMPLX,mulby(-1),updcol;
#defn   CUR-UP(_X_)            #ATOM#CMPLX,mulby(-1),updrow;
#defn   CUR-DOWN(_X_)          #ATOM#CMPLX,updrow;

#defn FW(_X_)                 {"\033["},#ATOM#CMPLX,{"C"}, print 
#defn BW(_X_)                 {"\033["},#ATOM#CMPLX,{"D"}, print 
#defn UP(_X_)                 {"\033["},#ATOM#CMPLX,{"A"},print
#defn DOWN(_X_)               {"\033["},#ATOM#CMPLX,{"B"},print

#defn    COLOR-FG(_X_)          {"\033[38;5;"},#ATOM#CMPLX,{"m"}print;
#defn    COLOR-BG(_X_)          {"\033[48;5;"},#ATOM#CMPLX,{"m"}print;
#defn    COLOR(_X_,_Y_)         {"\033[38;5;"},#ATOM#CMPLX,{"m"},{"\033[48;5;"},#ATOM#CMPLX,{"m"}print;

#defn    INVERSE(__X__)         {"\INV"};#ATOM#CMPLX;cat;{"\033[27m"}cat;
#defn    UNDER-LINE(__X__)      {"\UL"};#ATOM#CMPLX;cat;{"\033[24m"}cat;
#defn    ITALIC(__X__)          {"\CUR"};#ATOM#CMPLX;cat;{"\033[23m"}cat;
#defn    BOLD(__X__)            {"\ENF"};#ATOM#CMPLX;cat;{"\033[22m"}cat;


// primera llamada:
// se puede colocar dentro de otra instruccion GENCODE, solo cuando no tiene argumentos; de lo contrario, manda error.
//#defn    DO(_F_,*)           #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;jsub(_F_)
// si se hacen más llamadas dentro de DO()
//#define  CALL(_F_,*)         DO(_F_,*)

/* HIBRIDOS */
#defn    IF(_X_,_Y_,_Z_)      #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:

/* DEFINICIONES ATOMICAS DE LAS ANTERIORES FUNCIONES */
#define  TRUE                 1
#define  FALSE                0


/* CONSTANTES */

/* Creacion de archivos */
#define CREATE_NORMAL    0
#define CREATE_READONLY  1
#define CREATE_HIDDEN    2
#define CREATE_SYSTEM    4

/*
  Constantes para la apertura de archivos
*/
#define OPEN_READ        0     // solo lectura
#define OPEN_WRITE       1     // solo escritura
#define OPEN_APPEND      2     // lectura y escritura (append)
#define OPEN_EXCLUSIVE   16    // RED: solo lectura exclusivo
#define OPEN_DWRITE      32    // RED: inahbita que otro escriba
#define OPEN_DREAD       48    // RED: inhabilita que otro lea
#define OPEN_SHARED      64    // RED::comparte lectura y escritura (64+0, 64+1...)
/* FSEEK constantes */
#define SEEK_SET         0
#define SEEK_CUR         1
#define SEEK_END         2

/* bits */
#define LOWBYTE      0
#define HIGHBYTE     1

/* CONSTANTES MATEMATICAS */
#define M_SQRT2EPI     4.13273135412249293846 /* raiz cuadrada de 2*E*PI */
#define M_SQRT2PI      2.50662827463100050241 /* raiz de 2PI */
#define M_SQRT2        1.41421356237309504880 // 16887 24209 69807 85696
#define M_SQRT3        1.73205080756887729352 // 74463 41505 87236 69428
#define M_SQRT5        2.23606797749978969640 // 91736 68731 27623 54406
#define M_SQRTE        1.64872127070012814684 /* raiz cuadrada de e*/
#define M_SQRPI        9.86960440108935861883 /* pi al cuadrado */
#define M_SQRE         7.38905609893065022723 /* E al cuadrado */
#define M_E^PI         2.66514414269022518865 /* e elevado a PI*/
#define M_PI^E         22.45915771836104547342 /* PI elevado a E */
#define M_PHI          1.61803398874989484820 // 45868 34365 63811 77203
#define M_1_E          0.36787944117144232159 /* inverso de E */
#define M_E            2.7182818284590452354  /* e */
#define M_LOG2E        1.4426950408889634074  /* log_2 e */
#define M_LOG10E       0.43429448190325182765 /* log_10 e */
#define M_LN2          0.69314718055994530942 /* log_e 2 */
#define M_LN10         2.30258509299404568402 /* log_e 10 */
#define M_PI_2         1.57079632679489661923 /* pi/2 */
#define M_PI_4         0.78539816339744830962 /* pi/4 */
#define M_1_PI         0.31830988618379067154 /* 1/pi */
#define M_1_2PI        0.15915494309189533576 /* 1/2PI */
#define M_2_PI         0.63661977236758134308 /* 2/pi */
#define M_PI           3.14159265358979323846 // 26433 83279 50288 41971
#define M_TAU          6.283185307            /* TAU = 2*PI*/
#define M_2_SQRTPI     1.12837916709551257390 /* 2/sqrt(pi) */
#define M_SQRT1_2      0.70710678118654752440 /* 1/sqrt(2) */
#define M_NAN          {90}arcsin
#define M_INF          {1}divby(0)


