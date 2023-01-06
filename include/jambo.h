/* JAMBO */

/*
   Lenguaje de programación basado en Hopper
*/

//#define  »»(__X__)     ;mov(__X__)
//#define  »(__X__)      ;cpy(__X__)
#define  Backupto(__X__)  ;cpy(__X__)
#define-a ---           ;         // ENTRE PARÉNTESIS
#define-a  :=          ,
#define-a  ~=          ,
#define-a  Blk-                ;
#define-a  Seg-               ;
#define  TRUE                 1
#define  FALSE                0
#define  Setbreak             .ctrlc
#define  Subrutines          .locals



#define  Forgetall            ;clearstack;
#define  Forget               ;kill;
#define  Hold(__X__)        ;keep(__X__)
#define  Hold               ;keep;
#defn    Dup(__X__)           #ATOM#CMPLX;dup;
#define  Dupit                ;dup;

/* LIMPIEZA DE VARIABLES Y MARCAS */
#define  Clrmarks            ;clearinterval;//;clearmark;
#define  Clrrange            ;clearrange;
#define  Clrinterval         ;clearinterval;
#define  Clrallmarks         ;clearinterval;//;clearall;
// esto llama a GC: usese con cuidado, porque relentiza la ejecución:
#define  Clrstk              ;clearstack;
#defn    Clear(*)            #GENCODE $$$*$$$ clear(#LIST);#ENDGEN;
//
/* Saltos */
#defn    Linkgosub(*)         #GENCODE $$$*$$$ jsub(#LIST);#ENDGEN;
#defn    Gosubwhile(_E_,_X_,_Y_)    &( ) ##ENDLOOP,_E_,#LOOP:,_X_,jnt(%%ENDLOOP),\
                                         jsub(_Y_),%&, jmp(%LOOP), %ENDLOOP:,

#defn    Gosubtimes(_T_,_Y_)        &( ) #RAND, __PERFT__#RNDV__=0;#ATOM#CMPLX;minus(1);mov(__PERFT__#RNDV__); \
                                         ##ENDLOOP,#LOOP:,jsub(_Y_),__PERFT__#RNDV__--,jnz(%LOOP),\
                                         ,%&,%ENDLOOP:, %RAND
#defn    Gosubif(_E_,_L_)           ;#ATOM#CMPLX;gsub(_L_)
#define  Gosub(__X__)        jsub(__X__)
#define  Goto(__X__)         jmp(__X__)

// On 'x' gosub ( op1, op2, .... )
// On 'x' goto (lbl1, lbl2, lbl3... )
// On 'x' option ( instr1[;],instr2[;],....)
#defn    On(_X_)              ;#ATOM#CMPLX;
#defn    goto(*)            #GENCODE $$$*$$$ {#ITV}keep,eq? do{kill,jmp(#LIST)},#ENDGEN
#defn    gosub(*)           #GENCODE $$$*$$$ {#ITV}keep,eq? do{kill,jsub(#LIST),jmp(#HERE)},#ENDGEN
#defn    option(*)          #GENCODE $$$*$$$ {#ITV}keep,eq? do{kill,#LIST,jmp(#HERE)},#ENDGEN

/* DATETIME */
// suma o resta días a la fecha DD/MM/AAAA
#defn    Dateadd(_F_,_N_)         #ATOM#CMPLX;#ATOM#CMPLX;dateadd;
#define  Getdateadd               ;dateadd;
// días transcurridos entre F1 y F2:
#defn    Datediff(_F2_,_F1_)      #ATOM#CMPLX;#ATOM#CMPLX;datediff;
#define  Getdatediff              ;datediff;
// horas transcurridas entre 2 horas --> HH:MM:SS
#defn    Elaptime(_H2_,_H1_)      #ATOM#CMPLX;#ATOM#CMPLX;elaptime;
#define  Getelapsedtime       ;elaptime;
#defn    Leapyear(__X__)      #ATOM#CMPLX;date(14);
#define  Isleapyear?          ;date(14);
#defn    Timevalid(__X__)     #ATOM#CMPLX;date(19);
#define  Istimevalid?         ;date(19);
#defn    Datevalid(__X__)     #ATOM#CMPLX;date(20);
#define  Isdatevalid?         ;date(20);

#define  Datetime        ;datenow(0)
#define  Getdateandtime  ;datenow(0)
#define  Datenow         ;datenow(2)
#define  Getonlydate     ;datenow(2)
#define  Timenow         ;datenow(3)
#define  Getonlytime     ;datenow(3)

#defn    Strmonth(__X__)     #ATOM#CMPLX;date(13)  // get no aplica para funciones string $, porque se me canta el orto
#define  Getmonthasstring      ;date(13);
#defn    Daysofmonth(__X__)    #ATOM#CMPLX;date(15)
#define  Getdaysofmonth        ;date(15);
#defn    Weekofyear(__X__)      #ATOM#CMPLX;date(17)
#define  Getweekofyear         ;date(17);
#defn    Dayofyear(__X__)      #ATOM#CMPLX;date(18)
#define  Getdayofyear          ;date(18);
#defn    Strday(__X__)        #ATOM#CMPLX;date(12)
#define  Getdayasstring         ;date(12);
#defn    Day(__X__)           #ATOM#CMPLX;date(8)
#define  Getday               ;date(8);
#defn    Week(__X__)          #ATOM#CMPLX;date(17)
#define  Getweek              ;date(17);
#defn    Month(__X__)         #ATOM#CMPLX;date(7)
#define  Getmonth             ;date(7);
#defn    Year(__X__)          #ATOM#CMPLX;date(6)
#define  Getyear              ;date(6);
// sobre horas
#defn    Hours(__X__)          #ATOM#CMPLX;date(9)
#define  Gethoursoftime        ;date(9);
#defn    Minutes(__X__)        #ATOM#CMPLX;date(10)
#define  Getminutesoftime      ;date(10);
#defn    Seconds(__X__)        #ATOM#CMPLX;date(11)
#define  Getsecondsoftime     ;date(11);
#defn    Monthname(_X_)       #ATOM#CMPLX;monthname;
#defn    Dayname(_X_)         #ATOM#CMPLX;dayname;

// se declara esto aquí, porque se solapa con "getSecond" de date:
#define  Secsfrommidnight     seconds;

//
#define  Addit               ;add;
#define  Addallit            ;sumall;
#define  Mulallit            ;mulall;
#define  Multiplyallit       ;mulall;
#define  Subit               ;sub;
#define  Subtractit          ;sub;
#define  Mulit               ;mul;
#define  Multiplyit          ;mul;
#define  Divit               ;div;
#define  Divideit            ;div;
#define  Intdivit            ;idiv;
#define  Intdivideit         ;idiv;
//
#define  Addit-into(_X_)     pushvar(_X_)add;
#define  Subit-into(_X_)     pushvar(_X_)sub;
#define  Subtractit-into(_X_)     pushvar(_X_)sub;
#define  Mulit-into(_X_)     pushvar(_X_)mul;
#define  Multiplyit-into(_X_)     pushvar(_X_)mul;
#define  Divit-into(_X_)     pushvar(_X_)div;
#define  Divideit-into(_X_)     pushvar(_X_)div;
#define  Intdivit-into(_X_)     pushvar(_X_)idiv;
#define  Intdivideit-into(_X_)     pushvar(_X_)idiv;
// MATEMATICAS:
#defn    Seed(__X__)          #ATOM #CMPLX;seed;
#defn    Srand(__X__)          #ATOM #CMPLX;seed;
#defn    Sqrt(_X_)             ;#ATOM#CMPLX;sqrt;
#define  Getsqrt               ;sqrt;
#defn    Cbrt(_X_)             #ATOM #CMPLX;cbrt;
#define  Getcbrt               ;cbrt;
#defn    Ceil(_X_)             #ATOM #CMPLX;ceil;
#define  Getceil               ;ceil;
#defn    Floor(_X_)            #ATOM #CMPLX;floor;
#define  Getfloor              ;floor;
#defn    Trunc(_X_)            #ATOM #CMPLX;trunc;
#define  Truncateit            ;trunc;
#defn    Lenint(_X_)           #ATOM #CMPLX;lennum;
#define  Getlenint             ;lennum;
#defn    Int(_X_)              #ATOM #CMPLX;int;
#define  Getint                ;int;
#defn    Sign(_X_)             #ATOM #CMPLX;sign;
#define  Getsign               ;sign;
#defn    Sciformat(_X_)        #ATOM #CMPLX;sci;
#define  Getsciformat          ;sci;
#define  Getnotation?          ;getnotation?;
#defn    Fact(_X_)             #ATOM #CMPLX;fact;
#define  Getfactorial          ;fact;
#defn    Abs(_X_)              #ATOM #CMPLX;abs;
#define  Getabs                ;abs;
#defn    Exp2(_X_)             #ATOM #CMPLX;exp2;
#define  Getexp-base2          ;exp2;
#defn    Exp10(_X_)            #ATOM #CMPLX;exp10;
#define  Getexp-base10         ;exp10;
#defn    Exp(_X_)              #ATOM #CMPLX;exp;
#define  Getexp                ;exp;
#defn    Log2(_X_)             #ATOM #CMPLX;log2;
#define  Getlog-base2          ;log2;
#defn    Log10(_X_)            #ATOM #CMPLX;log10;
#define  Getlog-base10         ;log10;              
#defn    Log(_X_)              #ATOM #CMPLX;log;
#define  Getlog                ;log;
#defn    Rand(_X_)             #ATOM #CMPLX;rand;
#defn    Invsqr(_X_)           #ATOM #CMPLX;powby(2);powby(-1)
#define  Getinvsquare          ;powby(2);powby(-1)
#defn    Invcub(_X_)           #ATOM #CMPLX;powby(3);powby(-1)
#define  Getinvcube            ;powby(3);powby(-1)
#defn    Invqua(_X_)           #ATOM #CMPLX;powby(4);powby(-1)
#define  Getinvquarter         ;powby(4);powby(-1)
#defn    Inv(_X_)              #ATOM #CMPLX;powby(-1)
#define  Getinverse            ;powby(-1)
#defn    Sqr(_X_)              #ATOM #CMPLX;powby(2)
#define  Getsquare             ;powby(2)
#defn    Cub(_X_)              #ATOM #CMPLX;powby(3)
#define  Getcube               ;powby(3)
#defn    Qua(_X_)              #ATOM #CMPLX;powby(4)
#define  Getquarter            ;powby(4)
#defn    Ahalf(_X_)            #ATOM #CMPLX;divby(2)
#define  Getahalf              ;divby(2)
#defn    Athird(_X_)           #ATOM #CMPLX;divby(3)
#define  Getathird             ;divby(3)
#defn    Aquarter(_X_)         #ATOM #CMPLX;divby(4)
#define  Getaquarter           ;divby(4)

/* macros trigonométricas */
#defn    Rad(_X_)              #ATOM #CMPLX;d2r;
#define  Getradians            ;d2r;
#defn    Deg(_X_)              #ATOM #CMPLX;r2d;
#define  Getdegrees            ;rd2;
#defn    Acosh(_X_)            #ATOM #CMPLX;arccosh;
#define  Getarccosh              ;arccosh;
#define  Getacosh              ;arccosh;
#defn    Asinh(_X_)            #ATOM #CMPLX;arcsinh;
#define  Getarcsinh              ;arcsinh;
#define  Getasinh              ;arcsinh;
#defn    Atanh(_X_)            #ATOM #CMPLX;arctanh;
#define  Getarctanh              ;arctanh;
#define  Getatanh              ;arctanh;
#defn    Acos(_X_)             #ATOM #CMPLX;arccos;
#define  Getarccos               ;arccos; 
#define  Getacos               ;arccos; 
#defn    Asin(_X_)             #ATOM #CMPLX;arcsin;
#define  Getarcsin               ;arcsin;
#define  Getasin               ;arcsin;
#defn    Atan(_X_)             #ATOM #CMPLX;arctan;
#define  Getarctan               ;arctan;
#define  Getatan               ;arctan;
#defn    Cosh(_X_)             #ATOM #CMPLX;cosh;
#define  Getcosh               ;cosh;
#defn    Sinh(_X_)             #ATOM #CMPLX;sinh;
#define  Getsinh               ;sinh;
#defn    Tanh(_X_)             #ATOM #CMPLX;tanh;
#define  Gettanh               ;tanh;
#defn    Cos(_X_)              #ATOM #CMPLX;cos;
#define  Getcosine             ;cos;
#define  Getcos             ;cos;
#defn    Sin(_X_)              #ATOM #CMPLX;sin;
#define  Getsine               ;sin;
#define  Getsin               ;sin;
#defn    Tan(_X_)              #ATOM #CMPLX;tan;
#define  Gettangent            ;tan;
#define  Gettan            ;tan;

// ARITMETICAS:
// sqrdiff, sqradd, hypot se usan tal cual.
#define  Neighbourcount(_M_)     nbrc(_M_)

#defn    Sqradd(_X_,_Y_)       #ATOM #CMPLX;#ATOM #CMPLX;sqradd;
#defn    Sqrdiff(_X_,_Y_)      #ATOM #CMPLX;#ATOM #CMPLX;sqrdiff;
//#defn    Multiplyall(_X_,*)   {1};#GENCODE $$$*$$$ #ATCMLIST;mul;#ENDGEN;mov(_X_)
//#defn    Addall(_X_,*)        {0};#GENCODE $$$*$$$ #ATCMLIST;add;#ENDGEN;mov(_X_)

#defn    Setdecimal(_X_)        ;#IF prec(#FATOM) #ELSE ___SET_PREC___=0;#CMPLX;mov(___SET_PREC___);prec(___SET_PREC___); #EIF
#define  Unsetdecimal           prec(-1)
//

#defn  Add-into(__X__,__Y__,__Z__)    #IF #ATOM #ELSE #CMPLX;#EIF #IF pushvar(__Z__)plus(#FATOM) #ELSE #CMPLX; pushvar(__Z__)add; #EIF
#defn  Sub-into(__X__,__Y__,__Z__)    #IF #ATOM #ELSE #CMPLX;#EIF #IF pushvar(__Z__)minus(#FATOM) #ELSE #CMPLX; pushvar(__Z__)sub; #EIF
#defn  Mul-into(__X__,__Y__,__Z__)    #IF #ATOM #ELSE #CMPLX;#EIF #IF pushvar(__Z__)mulby(#FATOM) #ELSE #CMPLX; pushvar(__Z__)mul; #EIF
#defn  Div-into(__X__,__Y__,__Z__)    #IF #ATOM #ELSE #CMPLX;#EIF #IF pushvar(__Z__)divby(#FATOM) #ELSE #CMPLX; pushvar(__Z__)div; #EIF
#defn  iDiv-into(__X__,__Y__,__Z__)    #IF #ATOM #ELSE #CMPLX;#EIF #IF pushvar(__Z__)idivby(#FATOM) #ELSE #CMPLX; pushvar(__Z__)idiv; #EIF
#defn  Mod-into(__X__,__Y__,__Z__)    #IF #ATOM #ELSE #CMPLX;#EIF #IF pushvar(__Z__)module(#FATOM) #ELSE #CMPLX; pushvar(__Z__)mod; #EIF
#defn  Pow-into(__X__,__Y__,__Z__)    #IF #ATOM #ELSE #CMPLX;#EIF #IF pushvar(__Z__)powby(#FATOM) #ELSE #CMPLX; pushvar(__Z__)pow; #EIF
#defn  Round-into(__X__,__Y__,__Z__)    #IF #ATOM #ELSE #CMPLX;#EIF #IF pushvar(__Z__)roundby(#FATOM) #ELSE #CMPLX; pushvar(__Z__)round; #EIF
#defn  Gcd-into(__X__,__Y__,__Z__)    #ATOM #CMPLX;#ATOM #CMPLX;pushvar(__Z__)gcd;
#defn  Lcm-into(_X_,_Y_,_Z_)          #ATOM #CMPLX;#ATOM #CMPLX;pushvar(_Z_)lcm;
//
#defn    Add(__X__,__Y__)      #IF #ATOM #ELSE #CMPLX;#EIF #IF plus(#FATOM) #ELSE #CMPLX; add; #EIF
///#defn    Add(*)                {0};#GENCODE $$$*$$$ #ATCMLIST;add;#ENDGEN
#defn    Sub(__X__,__Y__)      #IF #ATOM #ELSE #CMPLX;#EIF #IF minus(#FATOM) #ELSE #CMPLX; sub; #EIF
#defn    Mul(__X__,__Y__)      #IF #ATOM #ELSE #CMPLX;#EIF #IF mulby(#FATOM) #ELSE #CMPLX; mul; #EIF
///#defn    Mul(*)                {1};#GENCODE $$$*$$$ #ATCMLIST;mul;#ENDGEN
#defn    Intdiv(__X__,__Y__)   #IF #ATOM #ELSE #CMPLX;#EIF #IF idivby(#FATOM) #ELSE #CMPLX; idiv; #EIF
#defn    Div(__X__,__Y__)      #IF #ATOM #ELSE #CMPLX;#EIF #IF divby(#FATOM) #ELSE #CMPLX; div; #EIF
#defn    Mod(_X_,_Y_)          #IF #ATOM #ELSE #CMPLX;#EIF #IF module(#FATOM) #ELSE #CMPLX; mod; #EIF
#defn    Pow(_X_,_Y_)          #IF #ATOM #ELSE #CMPLX;#EIF #IF powby(#FATOM) #ELSE #CMPLX; pow; #EIF
#defn    Round(_X_,_Y_)        #IF #ATOM #ELSE #CMPLX;#EIF #IF roundby(#FATOM) #ELSE #CMPLX; round; #EIF
#defn    Gcd(_X_,_Y_)          #ATOM #CMPLX;#ATOM #CMPLX;gcd;
#defn    Lcm(_X_,_Y_)          #ATOM #CMPLX;#ATOM #CMPLX;lcm;
#defn    ++(__X__)             #ATOM #CMPLX;plus(1)
#defn    --(__X__)             #ATOM #CMPLX;minus(1)

#define  Plusone(_X_)          ;plusone(_X_)
#define  Minusone(_X_)         ;minusone(_X_)
#define  Plustwo(_X_)          ;plustwo(_X_)
#define  Minustwo(_X_)         ;minustwo(_X_)
#defn    Neg(_X_)              #ATOM #CMPLX;neg;

#defn  Intdivinto(_X_)       #IF idivby(#FATOM) #ELSE #CMPLX; idiv; #EIF //;idivby(_X_)
#defn  Divinto(_X_)          #IF divby(#FATOM) #ELSE #CMPLX; div; #EIF //;divby(_X_)
#defn  Plus(_X_)             #IF plus(#FATOM) #ELSE #CMPLX; add; #EIF //;plus(_X_)
#defn  Minus(_X_)            #IF minus(#FATOM) #ELSE #CMPLX; sub; #EIF //;minus(_X_)
#defn  Mulby(_X_)            #IF mulby(#FATOM) #ELSE #CMPLX; mul; #EIF //;mulby(_X_)
#defn  Powby(_X_)            #IF powby(#FATOM) #ELSE #CMPLX; pow; #EIF //;powby(_X_)
#defn  Module(_X_)           #IF module(#FATOM) #ELSE #CMPLX; mod; #EIF
#defn  Roundby(_X_)          #IF roundby(#FATOM) #ELSE #CMPLX; round; #EIF //;roundby(_X_)
#defn  Times(_X_)            ;#ATOM#CMPLX;mul;

// plus(), minus(), module(), roundby(), powby(), etc, se usan tal cual.

// el calculo se hace al reves x es restado desde y:
///#defn    addedto(_X_)           #ATOM #CMPLX;add;
///#defn    subtractedfrom(_X_)    #ATOM #CMPLX;postfix;sub;postfix;

// funciones BINARIAS:
#defn    Noteqarr(_X_,_Y_)  #IF #ATOM #ELSE #CMPLX;#EIF #IF neqarrto(#FATOM) #ELSE #CMPLX; neqarr? #EIF
#synon   Noteqarr           Notequalarrays
#define  Arenotequalarrays?        ;neqarr?
#defn    Eqarr(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF eqarrto(#FATOM) #ELSE #CMPLX; eqarr? #EIF
#synon   Eqarr              Equalarrays
#define  Areequalarrays?           ;eqarr?
#defn    Noteq(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF neqto(#FATOM) #ELSE #CMPLX; neq? #EIF
#synon   Noteq              Notequals,Distinct
#define  Notequals?               ;neq?
#defn    Eq(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF eqto(#FATOM) #ELSE #CMPLX; eq? #EIF
#synon   Eq                 Equals
#define  Areequals?               ;eq?
#defn    Leq(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF lethan(#FATOM) #ELSE #CMPLX; le? #EIF
#synon   Leq                Lessequal
#define  Lessequal?               ;le? 
#defn    Less(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF lthan(#FATOM) #ELSE #CMPLX; lt?; #EIF
#define  Less?                    ;lt?;
#defn    Geq(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF gethan(#FATOM) #ELSE #CMPLX; ge? #EIF
#synon   Geq                  Greaterequal
#define  Greaterequal?            ;ge? 
#defn    Greater(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF gthan(#FATOM) #ELSE #CMPLX; gt? #EIF
#define  Greater?                 ;gt? 
//
#defn    Iseq(__E__)        #IF eqto(#FATOM) #ELSE #CMPLX ;eq? #EIF
#defn    Isleq(__E__)        #IF lethan(#FATOM) #ELSE #CMPLX ;le? #EIF
#defn    Isgt(__E__)        #IF gthan(#FATOM) #ELSE #CMPLX;gt? #EIF 
#defn    Isgeq(__E__)        #IF gethan(#FATOM) #ELSE #CMPLX;ge? #EIF
#defn    Islt(__E__)        #IF lthan(#FATOM) #ELSE #CMPLX;lt?; #EIF 
#defn    Isnoteq(__E__)    #IF neqto(#FATOM) #ELSE #CMPLX;neq? #EIF

#synon   Iseq           Isequalto
#synon   Isleq          Islessequalto
#synon   Isgt           Isgreaterthan
#synon   Isgeq          Isgreaterequalto
#synon   Islt           Islessthan
#synon   Isnoteq        Isnotequalto

#defn    This(_X_)       ;#ATOM#CMPLX;
#defn    Comparedto(_X_)  ;#ATOM#CMPLX;
#synon   Comparedto        Respectto 
#define  Arenotequals?     ;neq?;
#define  Arenotequals      ;neq?;
#define  Isless?           ;lt?;
#define  Isless            ;lt?;
#define  Isnotless?        ;lt?;not;
#define  Isnotless         ;lt?;not;
#define  Isgreater?        ;gt?;
#define  Isgreater         ;gt?;
#define  Isnotgreater?     ;gt?;not;
#define  Isnotgreater      ;gt?;not;
#define  Islessorequal?        ;le?;
#define  Islessorequal         ;le?;
#define  Isnotlessorequal?     ;le?;not;
#define  Isnotlessorequal      ;le?;not;
#define  Isgreaterorequal?     ;ge?;
#define  Isgreaterorequal      ;ge?;
#define  Isnotgreaterorequal?  ;ge?;not;
#define  Isnotgreaterorequal   ;ge?;not;

/* Booleanas especiales para usar en estructuras de control */
/* caso POSITIVO */
#defn   Inf(__X__)              #ATOM#CMPLX;inf?;
#define Isinf?                   ;inf?
#defn   Nan(__X__)              #ATOM#CMPLX;nan?;
#define Isnan?                   ;nan?
#defn   Even(__X__)              #ATOM#CMPLX;even?;
#define Iseven?                   ;even?
#defn   Notzero(__X__)             #ATOM#CMPLX;zero?;not; // positivo o negativo
#define Isnotzero?                  ;zero?;not;
#defn   Zero(__X__)             #ATOM#CMPLX;zero?;
#define Iszero?                  ;zero?
#defn   Null(__X__)             #ATOM#CMPLX;void?;
#define Isnull?                  ;void?
#defn   Notpositive(__X__)         #ATOM#CMPLX;npos?;  // negativo o 0
#define Isnotpositive?                   ;npos?;
#defn   Positive(__X__)         #ATOM#CMPLX;pos?;
#define Ispositive?                   ;pos?
#defn   Notnegative(__X__)         #ATOM#CMPLX;nneg?; // positivo o 0
#define Isnotnegative?                   ;nneg?;
#defn   Negative(__X__)         #ATOM#CMPLX;neg?;
#define Isnegative?                   ;neg?
#defn   Array(__X__)            #ATOM#CMPLX;array?;
#define Isarray?                 ;array?  // sirve para "var(X) Is Array?
#defn   Numeric(__X__)          #ATOM#CMPLX;numeric?;
#define Isnumeric?               ;numeric?
#defn   String(__X__)           #ATOM#CMPLX;string?;
#define Isstring?                ;string?
#defn   Envvar(__X__)           #ATOM#CMPLX;env?;
#define Isenvvar?                ;env?
#defn   Any(__X__,__Y__)        #ATOM#CMPLX;#ATOM#CMPLX;any?;
//   Take(num), Between?( 10::including, 100::excluding)
//  define includ, exclud ya está listo

#defn   Bndbetwn(__I__,_X_,__F__,_Y_)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;between?;
#defn   Betwnincluding(__I__,__F__)      #ATOM#CMPLX;{1};#ATOM#CMPLX;{1};between?;
#defn   Betwnexcluding(__I__,__F__)      #ATOM#CMPLX;{0};#ATOM#CMPLX;{0};between?;

#defn   Bndoutofrange(__I__,_X_,__F__,_Y_)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;outbetween?;
#defn   Outofrangeincluding(__I__,__F__)       #ATOM#CMPLX;{1};#ATOM#CMPLX;{1};outbetween?;
#defn   Outofrangeexcluding(__I__,__F__)       #ATOM#CMPLX;{0};#ATOM#CMPLX;{0};outbetween?;
#defn   All(__X__,__Y__)        #ATOM#CMPLX;#ATOM#CMPLX;all?;
///#defn   Empty(__X__)            #ATOM#CMPLX;isempty;
#define  Isempty?                 ;isempty;
#define  Fileerror?                ;error?
#define  Stackbusy?                       ;emptystack?;not;
#define  Stackempty?                      ;emptystack?;
#define  Keypressed?                       ;kbhit?

#define  Isempty                 ;isempty;
#define  Fileerror                ;error?
#define  Stackbusy                       ;emptystack?;not;
#define  Stackempty                      ;emptystack?;
#define  Keypressed                       ;kbhit?
#define  Stacksize                     ;sizestack;

#defn    Typechar(__X__,__Y__)            #ATOM#CMPLX;{__Y__}typechar?;
#defn    Alltype(__X__,__Y__)             #ATOM#CMPLX;{__Y__}typestring?;
#defn    Wherenot(__X__,__Y__)            #ATOM#CMPLX;{__Y__}disttypestring?;
/* Take(x), Occurs In?("hola mundo!") */
#defn    Occursexactlyin(__X__)                #ATOM#CMPLX;ecin?;  // requiere algo del stack
#defn    Occursin(__X__)                     #ATOM#CMPLX;cin?; 

// CAMBIAN VALOR LOGICO DE X:
#defn    True(*)              #GENCODE $$$*$$$ true(#LIST);#ENDGEN
#defn    False(*)             #GENCODE $$$*$$$ false(#LIST);#ENDGEN
#defn    Opposite(*)            #GENCODE $$$*$$$ {#LIST};not;mov(#LIST);#ENDGEN

// OPERADORES LOGICOS
/*#defn    Nand(__X__,__Y__)    #ATOM#CMPLX;#ATOM#CMPLX;nand;
#defn    Nor(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;nor;
#defn    Xor(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;xor;
#defn    And(_X_,_Y_)         #ATOM#CMPLX;#ATOM#CMPLX;and; // causa un error argument error PREPROCESO(2780) -> _CAMBIODEFINE(6816) por usar .apl. y dejar OPTIMLOG declarado después.
#defn    Or(_X_,_Y_)          #ATOM#CMPLX;#ATOM#CMPLX;or;
#defn    Not(_X_)             #ATOM #CMPLX;not;
*/
#defn    Nand(__X__,__Y__)    #ATOM#CMPLX;#ATOM#CMPLX;nand;
#defn    Nor(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;nor;

#defn    Onlyone(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;xor;
#defn    Xor(_X_)           #ATOM#CMPLX;xor;

#defn    Mustbe(__X__,__Y__)    #ATOM#CMPLX;#ATOM#CMPLX;and;
#synon   Mustbe              Shouldbe
#defn    And(_X_)           #ATOM#CMPLX;and;

#defn    Canbe(_X_,_Y_)          #ATOM#CMPLX;#ATOM#CMPLX;or;
#synon   Canbe               Couldbe
#defn    Or(_X_)          #ATOM#CMPLX;or;
#defn    Not(_X_)             #ATOM #CMPLX;not;

//

/* environment */
// Set(valor),Export( ENVAR )
#defn   Export(_X_)         {#APTFE_X_#APTFE};setenv;
#defn   Setenv(_V_,_X_)     #ATOM#CMPLX;{#APTFE_X_#APTFE};setenv;
#defn   Modenv(_V_,_X_)     #ATOM#CMPLX;/*{#APTFE_X_#APTFE};unsetenv;*/{#APTFE_X_#APTFE};setenv;
// Let( x := Evar(ANIMALES)
#defn   Nenv(_X_)            {#APTFE_X_#APTFE};getenvnum;
#defn   Senv(_X_)            {#APTFE_X_#APTFE};getenv;
#defn   Unset(_X_)           {#APTFE_X_#APTFE};unsetenv;
#defn   Execute(_X_)          #ATOM#CMPLX;exec;
#defn   System(_X_)          #ATOM#CMPLX;execv;

// LISTAS
#defn    Void(*)             ;#GENCODE $$$*$$$ #LIST={#VOID};#ENDGEN
#define  Apndlist(_X_)       ;pushall(_X_)
#define  Appendtolist(_X_)   ;pushall(_X_)
//#define  Appendtoutf8list(_X_)  ;strtoutf8;

#define  Apndrow(_X_)        ;addrow(_X_)
#define  Appendrowto(_X_)    ;addrow(_X_)
#defn    Multipush(__X__,*)      #GENCODE $$$*$$$ #ATCMLIST;push(__X__); #ENDGEN;

#define  Push(_X_)           ;push(_X_)
#define  QPop(_X_)           ;qpop(_X_)
#define  Pop(_X_)            ;pop(_X_)
#define  Head(_X_)           ;head(_X_)
#define  Tail(_X_)           ;tail(_X_)
#define  Look(_X_)           ;look(_X_)
#define  Empty(_X_)          ;empty(_X_)
#defn    Length(__X__)       #ATOM#CMPLX;length;
#define  Getlength           ;length;

// COLUMNAS Y FILAS DE ARRAYS 2D y 3D:
// 
#define  Getrowsfrom(_X_)       ;getrow(_X_)
#define  Getcolumnsfrom(_X_)       ;getcol(_X_)
// Las siguientes macros necesitan declarar [] con anterioridad: [n] GET-PAGE(v)
#define  Getpagesfrom(_X_)      ;getpage(_X_)

#define  Deletecolumnsfrom(_X_)    ;delcols(_X_)
#define  Deleterowsfrom(_X_)       ;delrows(_X_)
#define  Deletepagesfrom(_X_)      ;delpags(_X_)

#define  Insertcolumnsinto(_X_)    ;inscols(_X_)
#define  Insertrowsinto(_X_)       ;insrows(_X_)
#define  Insertpagesinto(_X_)     ;inspags(_X_)

#defn    Catrows(__X__,*)      #GENCODE $$$*$$$ #REVATCMLIST;#ENDGEN;catrow(__X__)
#defn    Catcolumns(__X__,*)   #GENCODE $$$*$$$ #REVATCMLIST;#ENDGEN;catcol(__X__)
//#define  Catrow(_X_)        ;catrow(_X_)  // concatena en modo fila
//#define  Catcol(_X_)        ;catcol(_X_)  // concatena en modo columna

// Las siguientes macros necesitan declarar [] con anterioridad: [n] GET-PAGE(v)
#define  Putpage(__X__)     ;putpage(__X__)


/* Posiciones Pares y Nones en arrays */
#define  Selectevenrows-cols       [2:end,2:end];{2}{2}interval2;
#define  Selectevenrows-oddcols   [2:end,1:end];{2}{2}interval2;
#define  Selectoddrows-cols      [1:end,1:end];{2}{2}interval2;
#define  Selectoddrows-evencols   [1:end,2:end];{2}{2}interval2;
#define  Selectevenrows           [2:end,1:end];{2}interval1;
#define  Selectevencols           [1:end,2:end];{0}{2}interval2;
#define  Selectevenpos            [2:end];{2}interval1;
#define  Selectevenpages          [2:end];{0}{0}{2}interval3;
#define  Selectoddrows          [1:end,1:end];{2}interval1;
#define  Selectoddcols          [1:end,1:end];{0}{2}interval2;
#define  Selectoddpos           [1:end];{2}interval1;
#define  Selectoddpages         [1:end];{0}{0}{2}interval3;


// obtiene desde una celda particula, borrando intervalos

#defn    Ofcell-into(_X_,_V_)      #IF pushvar(_V_);ewget(#FATOM); #ELSE #RAND,__MVP__#RNDV=0;\
                                  #CMPLX;mov(__MVP__#RNDV);pushvar(_V_);ewget(__MVP__#RNDV);%RAND #EIF

#defn    Ofcellof(_X_)        #IF ewget(#FATOM);clearinterval; #ELSE #RAND,__MVP__#RNDV=0;\
                              #CMPLX;mov(__MVP__#RNDV);ewget(__MVP__#RNDV);clearinterval;%RAND #EIF
// obtiene desde una celda, sin borrar intervalos
#defn    Ofcell(_X_)          #IF ewget(#FATOM); #ELSE #RAND,__MVP__#RNDV=0;\
                              #CMPLX;mov(__MVP__#RNDV);ewget(__MVP__#RNDV); %RAND #EIF
// obtiene desde un rango, borrando los intervalos

#defn    Of-into(_X_,_V_)      #IF pushvar(_V_);get(#FATOM);clearinterval; #ELSE #RAND,__MVP__#RNDV=0;\
                              #CMPLX;mov(__MVP__#RNDV);pushvar(_V_);get(__MVP__#RNDV);clearinterval;%RAND #EIF
#defn    Of(_X_)              #IF get(#FATOM);clearinterval; #ELSE #RAND,__MVP__#RNDV=0;\
                              #CMPLX;mov(__MVP__#RNDV);get(__MVP__#RNDV);clearinterval;%RAND #EIF
// obtene desde un rango, tenga o no coordenadas:
#define  Get-into(_X_,_V_)     pushvar(_V_);get(_X_)
#define  Get(_X_)             get(_X_)

// pone en una celda particular, borrando los intervalos
#define   Putcellto(_X_)        ;ewput(_X_);clearinterval;
// pone en una celda particular.
#define   Putcell(_X_)          ;ewput(_X_)
// pone en las coordenadas particulares de __X__; borra los intervalos después
#define  Putto(__X__)         put(__X__);clearinterval;
// pone en __X__, tenga o no coordenadas.
#define  Put(__X__)           put(__X__)

// macros para devolver datos del array:
#define  Dims(__A__)         dims(__A__)
#define  Rows(__A__)         rows(__A__)
#define  Cols(__A__)         cols(__A__)
#define  Pags(__A__)         pages(__A__)
/* FUNCIONES ESPECIALES DE ARRAYS */
// estas no devuelven datos:
//#defn    Seqspaced(__X__,__Y__,__Z__,_V_)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;keep;lthan(1);\
//                                             do{{"Seqspaced: num elements < 1"}throw(2301)},seqsp(_V_)

#defn    Seqspaced(__X__,__Y__,__Z__,_V_)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;seqsp(_V_)

//#defn    Getsequence(__X__,__Y__,__Z__)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;keep;lthan(1);\
//                                             do{{"Sequence: num elements < 1"}throw(2301)},seq(-1)

#defn    Getsequence(__X__,__Y__,__Z__)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;seq(-1)
                                             
//#defn    Sequence(__X__,__Y__,__Z__,_V_)          #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;keep;lthan(1);\
//                                             do{{"Sequence: num elements < 1"}throw(2301)},seq(_V_)
#defn    Sequence(__X__,__Y__,__Z__,_V_)          #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;seq(_V_)

#defn    Clamp(__X__,__Y__,_V_)              #ATOM#CMPLX;#ATOM#CMPLX;clamp(_V_)
#defn    Redim(_X_,*)                       #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;reshape(_X_)

#defn    Savematrix(_MAT_,_F_)                 #ATOM#CMPLX;#ATOM#CMPLX;save;
#defn    Loadmatrix(_F_)                       __FILE_TO_LOAD__=0;#ATOM#CMPLX;mov(__FILE_TO_LOAD__);\
                                             {__FILE_TO_LOAD__}statsfile;{__FILE_TO_LOAD__}load;
#defn    Loadmatrixto(_F_,_V_)               __FILE_TO_LOAD__=0;#ATOM#CMPLX;mov(__FILE_TO_LOAD__);\
                                             {__FILE_TO_LOAD__}statsfile;{__FILE_TO_LOAD__}pushvar(_V_);load;
// USING(MAX_LINE), READ-AS-ROW(fd). (FD) se coloca naturalmente
#defn    Readasrow            ;readrow
#defn    Writeasrow(__A__)     #ATOM#CMPLX;writerow

// verifica la aproximación de un array comparado con otro:
#defn    Aproach(_X_)          #RAND; _VAPROACH_#RNDV=0;keep;length;mov(_VAPROACH_#RNDV);xtonum;stats(0);\
                                {_VAPROACH_#RNDV};div;#ATOM#CMPLX;lt?;%RAND;

#defn    Forall(_X_,_R_,*)     clearinterval;clearrange;_R_;get(_X_);#GENCODE $$$*$$$\
                                #ATCMLIST;#ENDGEN;put(_X_);\
                                clearinterval;clearrange;

#define  Setrange(__X__)       range(__X__)
#define  Memrange              range(-1)
#define  Getrange              range(-1)

/* mapea una matriz, cambiando un valor por _X_. crea el array _Y_, con el array _V_ modificado */ 
#defn    Letmap(_EXPR_,_X_,_V_,_Y_)        #RAND,clear range,_Y_=_V_,#ATOM#CMPLX;cartesian,_RG_#RNDV=0,\
                                            mov(_RG_#RNDV),\
                                            range(_RG_#RNDV),_Y_=_X_,Trash(_RG_#RNDV),clear range,%RAND;
/* mapea una matriz, cambiando un valor por _X_. Altera el mismo array.
   Si desea mantener el array original, respaldelo, o use LETMAP */ 
#defn    Map(_EXPR_,_X_,_V_)                #RAND,clear range,#ATOM#CMPLX;cartesian,_RG_#RNDV=0,mov(_RG_#RNDV),\
                                            range(_RG_#RNDV),_V_=_X_,clear(_RG_#RNDV),clear range,%RAND;
#defn    Split(__S__,__A__,__T__)           __TKN_SPLIT__=0;gettoksep;mov(__TKN_SPLIT__);{__T__}toksep;#ATOM#CMPLX;split(__A__);\
                                            {__TKN_SPLIT__};toksep;
// compacta un array N-DIM en uno 1D, eliminando blancos, ceros y falsos:
#define  Compact-into(__A__,__NA__)           {__A__}pushvar(__NA__);compact;
#defn    Compact(__A__)                      #ATOM#CMPLX;compact;
#defn    Cartes(__X__)                        #ATOM#CMPLX;cartesian;
#synon   Cartes                             Cartesian
/* FUNCIONES ESPECIALES DE ARRAYS */
// Swap de filas, columnas, paginas y rangos de intervalo:

#defn    Swaprows(_X_,_R1_,_R2_)           #RAND,clearstack,_TMP#RNDV_=0,[_R1_,1:end]get(_X_),mov(_TMP#RNDV_),\
                                            [_R2_,1:end]get(_X_),[_R1_,1:end]put(_X_),\
                                            {_TMP#RNDV_}[_R2_,1:end]put(_X_),clear(_TMP#RNDV_),clearstack,clearinterval,%RAND;

#defn    Swapcols(_X_,_C1_,_C2_)           #RAND, clearstack,_TMP#RNDV_=0,[1:end,_C1_]get(_X_),mov(_TMP#RNDV_),\
                                            [1:end,_C2_]get(_X_),[1:end,_C1_]put(_X_),\
                                            {_TMP#RNDV_}[1:end,_C2_]put(_X_),clear(_TMP#RNDV_),clearstack,clearinterval,%RAND;

#defn    Swappags(_X_,_P1_,_P2_)           #RAND, clearstack,_TMP#RNDV_=0,[_P1_]getpage(_X_),mov(_TMP#RNDV_),\
                                            [_P2_]getpage(_X_),[_P1_]putpage(_X_),\
                                            {_TMP#RNDV_}[_P2_]putpage(_X_),,clear(_TMP#RNDV_),clearstack,clearinterval,%RAND;

#defn    Swapintv(_X_,_R1_,_R2_)         #RAND,clearstack,_TMP#RNDV_=0,_R1_,get(_X_),mov(_TMP#RNDV_),\
                                            _R2_,get(_X_),_R1_,put(_X_),\
                                            {_TMP#RNDV_}_R2_,put(_X_),clear(_TMP#RNDV_),clearstack,clearinterval,%RAND;
   
#defn    Aenum(_LISTA_,__INIT__)       #RAND, ___ENUMERATE_=0, {_LISTA_}array? do{ dims(_LISTA_),gthan(1),\
                                            do{{0}reshape(_LISTA_)},rows(_LISTA_),jmp(___EXIT_ENUM_ARRAY__#RNDV)},\
                                            {"Aenum: type mismatch - I need an array"}throw(1999),\
                                            ___EXIT_ENUM_ARRAY__#RNDV:,{__INIT__}minus(1),add,mov(___ENUMERATE_),\
                                            __ENUMLST_={#VOID}, {__INIT__},{___ENUMERATE_},{___ENUMERATE_},minus(__INIT__),plus(1),\
                                            seqsp(__ENUMLST_){_LISTA_,__ENUMLST_}catcolumn(_LISTA_),%RAND;

#defn    Strenum(_STRING_,__INIT__,__TKN__)  ___ENUMERATE_=0,{"string",_STRING_}type,neq?,\
                                              do{ {"Strenum: type mismatch - I need a string"}throw(1999) },\
                                              ___OLDTKN___=0,gettoksep,mov(___OLDTKN___),{__TKN__}toksep,{_STRING_}\
                                              split(_STRING_),rows(_STRING_),{__INIT__}minus(1),add,mov(___ENUMERATE_),\
                                              __ENUMLST_={#VOID},{__INIT__,___ENUMERATE_,___ENUMERATE_},minus(__INIT__),plus(1),\
                                              seqsp(__ENUMLST_),{_STRING_,__ENUMLST_}catcolumn(_STRING_),{___OLDTKN___}toksep,


/* Arrays por funcion ARRAY de 1 dimensión (y algunas de 2) sin DEVOLUCION */
// FUNCIONES DE ARRAY
//
#defn    Dump(_X_)                 #ATOM#CMPLX;dumparray;
#define  Dumpit                    ;dumparray;
#defn    aIns(__V__,__P__,__X__)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(3);
#defn    aDel(__P__,__X__)         #ATOM#CMPLX;#ATOM#CMPLX;array(4);
#defn    aResize(__S__,__X__)        #ATOM#CMPLX;#ATOM#CMPLX;array(5);
#defn    aZap(_RI_,_RF_,_X_)    #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(7);
#defn    aCat(__AS__,__AT__)       #ATOM#CMPLX;#ATOM#CMPLX;array(6);
#defn    aSort(__X__)                 #ATOM#CMPLX;array(0);
#define  aSort                        ;array(0);
// con devolucion
#defn    aRevscan(__V__,__X__)       #ATOM#CMPLX;#ATOM#CMPLX;array(2);
#defn    aScan(__P__,__V__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(1);
#defn    aScantbl(_C_,_V_,_X_)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(8);
#defn    aDistrib(_A1_,_A2_)            #ATOM#CMPLX;#ATOM#CMPLX;array(9);
#defn    aMaxval(__X__)            #ATOM#CMPLX;array(10);
#defn    aMinval(__X__)            #ATOM#CMPLX;array(13);
#defn    aMaxpos(__X__)              #ATOM#CMPLX;array(11);
#defn    aMinpos(__X__)              #ATOM#CMPLX;array(14);
#defn    aMax(_X_)                 #ATOM#CMPLX;array(12);  // devuelve valor,posicion
#defn    aMin(_X_)                 #ATOM#CMPLX;array(15);  // devuelve valor,posicion
#defn    aMix(_X_,_Y_)             #ATOM#CMPLX;#ATOM#CMPLX;array(16);
#defn    aLrot(_D_,_H_,_X_)        #ATOM#CMPLX;#ATOM#CMPLX;{_X_}array(17); //left rotate
#defn    aRrot(_D_,_H_,_X_)        #ATOM#CMPLX;#ATOM#CMPLX;{_X_}array(18);
#defn    aSwap(_P1_,_P2_,_X_)      #ATOM#CMPLX;#ATOM#CMPLX;{_X_}array(19);  // swap elementos

// max y min simples
#defn    Max(_X_,_Y_)          #ATOM #CMPLX;#ATOM #CMPLX;max;
#defn    Min(_X_,_Y_)          #ATOM #CMPLX;#ATOM #CMPLX;min;

// TOKENS:
#defn    Toksep(__X__)           #ATOM#CMPLX;toksep;
#define  Tokinit                 ___TOKEN___=0;
#defn    Tokcount(__X__)         ___V_827662___=0;#ATOM#CMPLX;mov(___V_827662___);totaltoken(___V_827662___);___TOKEN___=0;

#defn    Tokget(__V__)           {___TOKEN___};$(__V__);
#defn    Tokrepla(__X__,__V__)    #ATOM#CMPLX;{___TOKEN___}$$(__V__);mov(__V__);gettoksep;{__V__};onechar;mov(__V__);
#defn    Tokdel(__V__)           {""}{___TOKEN___}$$(__V__);mov(__V__);gettoksep;{__V__};onechar;mov(__V__);
#defn    Tokswap(_N_,__V__)      #ATOM#CMPLX;__T_SWP__=0;cpy(__T_SWP__);$(__V__);\
                                  {___TOKEN___};$(__V__);\
                                  {__T_SWP__}$$(__V__);mov(__V__);\
                                  {___TOKEN___}$$(__V__);mov(__V__);
#define  Getsep                  ;gettoksep;
#defn    Toksel(__X__)               #ATOM#CMPLX;mov(___TOKEN___)


// PROCESO DE STRINGS:

#defn    Replic(__X__,__N__)     #ATOM#CMPLX;#ATOM#CMPLX;replicate;
// Take(cadena), ReplyBy(N)
#defn    Replyby(__N__)      #IF replyby(#FATOM) #ELSE #CMPLX;replicate; #EIF

// Concatenación multiple
#defn    Multicat(_X_,*)      #ATOM#CMPLX;#GENCODE $$$*$$$ #ATCMLIST;cat; #ENDGEN
#defn    Cat(_X_,_Y_)      #ATOM#CMPLX;#ATOM#CMPLX;cat;

// corta cadenas
#defn    Cutr(__X__,__Y__)              #ATOM#CMPLX;#ATOM#CMPLX;rcut;
#defn    Cutbetwn(__X__,__A__,__B__)         #RAND;__V_#RNDV=0;#ATOM#CMPLX;mov(__V_#RNDV);#ATOM#CMPLX;{__V_#RNDV}cut;mov(__V_#RNDV);\
                                             #ATOM#CMPLX;{__V_#RNDV}findat;minus(1);{1}{__V_#RNDV};copy;%RAND;
#defn    Cut(__X__,__Y__)                    #ATOM#CMPLX;#ATOM#CMPLX;cut;

#define  Basename(_X_)                      {"/"}{_X_};rcut;
#define  Fullpath(_X_)                      {0}{0}{""};BaseName(_X_);{_X_}transform

// Take(x,y,z,...), Join(v)
#defn    Jointo(__X__)                       join(__X__);
#define  Joinit                              sjoin;
#defn    Ucase(_X_)                           #ATOM#CMPLX;upper;
#define  Douppercase                          ;upper;
#define  Doupper                           ;upper;
#defn    Lcase(__X__)                         #ATOM#CMPLX;lower;
#define  Dolowercase                        ;lower;
#define  Dolower                        ;lower;
#defn    Hex(__X__)                          #ATOM#CMPLX;hex;
#define  Dohexadecimal                    ;hex;
#define  Dohexa                    ;hex;
#define  Dohex                    ;hex;
#defn    Bin(__X__)                          #ATOM#CMPLX;bin;
#define  Dobinary                          ;bin;
#define  Dobin                          ;bin;
#defn    Oct(__X__)                          #ATOM#CMPLX;oct;
#define  Dooctal                         ;oct;
#define  Binsize(__X__)                     sizebin(__X__)
#defn    Ansi(__X__)                  #ATOM#CMPLX;utf8tostr;
#define  Doansi                      ;utf8tostr;
#defn    Utf8(__X__)                  #ATOM#CMPLX;strtoutf8;
#define  Doutf8                      ;strtoutf8;
#defn    Rtrim(__X__)                    #ATOM#CMPLX;trimright;
#define  Dorighttrim                   ;trimright;
#define  Dortrim                   ;trimright;
#defn    Ltrim(__X__)                     #ATOM#CMPLX;trimleft;
#define  Dolefttrim                     ;trimleft;
#define  Doltrim                     ;trimleft;
#defn    Trim(__X__)                          #ATOM#CMPLX;trim;
#define  Dotrim                      ;trim;
// Take(" ",20),PadC(var) para PadX
#defn    Cpad(__FILL__,__SIZ__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;padcenter;
#defn    Lpad(__FILL__,__SIZ__,__X__)       #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;padleft;
#defn    Rpad(__FILL__,__SIZ__,__X__)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;padright;

#defn  Justleft(_X_,_V_)   {" "};#ATOM#CMPLX;#ATOM#CMPLX;padright;
#defn  Justright(_X_,_V_)   {" "};#ATOM#CMPLX;#ATOM#CMPLX;padleft;
#defn  Justcenter(_X_,_V_)   {" "};#ATOM#CMPLX;#ATOM#CMPLX;padcenter;

#defn    Type(__X__)                        #ATOM#CMPLX;type;
#define  Gettype                           ;type;

#defn    Mid(__P__,__F__,__X__)             #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;copy;
#defn    Right(_X_,_V_)                     {999999999};#ATOM#CMPLX;#ATOM#CMPLX;copy;
#defn    Left(_X_,_V_)                      #ATOM#CMPLX;{1};#ATOM#CMPLX;copy;

// busqueda de posiciones
#defn    Firstfind(__C__,__X__)            {1};#ATOM#CMPLX;#ATOM#CMPLX;findat;
#defn    Lastfind(__C__,__X__)             {0};#ATOM#CMPLX;#ATOM#CMPLX;findat;
#defn    Atfind(__AT__,__C__,__X__)        #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;findat;
#defn    Find(__S__,__X__)                  #ATOM#CMPLX;#ATOM#CMPLX;find;
#defn    Countat(__SALTA__,__S__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;countat;
// switch para búsqedas con FINDAT
#define  Multipasson            ;multipasson;
#define  Multipassoff           ;multipassoff;
#define  Setmultipass           ;multipasson;
#define  Unsetmultipass         ;multipassoff;

// TRANSFORMACION:
#defn    Firsttran(_S_,_R_,_X_)             {1}{1};#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
#defn    Lasttran(_S_,_R_,_X_)              #RAND;___VTRNL___#RNDV=0;___REPL_TXT_=0;#ATOM#CMPLX;mov(___REPL_TXT_);\
                                             ___FIND_LAST_=0;#ATOM#CMPLX;mov(___FIND_LAST_);___AT_LAST_=0;\
                                             {___FIND_LAST_};#ATOM#CMPLX;cpy(___VTRNL___#RNDV);countat;mov(___AT_LAST_);\
                                             {___AT_LAST_}{___REPL_TXT_}{___FIND_LAST_}{___VTRNL___#RNDV}transform;%RAND;
#defn    Tranto(_N_,_S_,_R_,_X_)            {1};#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
#defn    Trantoend(_N_,_S_,_R_,_X_)        #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
#defn    Tranfromto(_M_,_N_,_S_,_R_,_X_)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
// Take(desde-la-ocurrencia), Tran$(...)
// Take(hasta-la-ocurrencia,desde-la-ocurrencia), Tran$(...)
// Ejemplo: reemplaza la primera ocurrencia: Take(1,1),Trans$("X","x",v)
#defn    Tran(__R__,__S__,__X__)             {0}{0}#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;

#defn    Lreplacechar(__C__,__R__,__X__)    #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;rleft;
#defn    Rreplacechar(__C__,__R__,__X__)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;rright;
#defn    Replacechar(__C__,__R__,__X__)         #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;rall;

#defn    Strreplace(_N_,_P_,__S__,__X__)           #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;replace;
#defn    Strinsert(__P__,__C__,__X__)              #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;insert;
#defn    Chardel(__C__,__X__)               #ATOM#CMPLX;#ATOM#CMPLX;deletechar;
#defn    Strdel(__P__,__C__,__X__)              #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;delete;
#defn    Onechar(__C__,__X__)               #ATOM#CMPLX;#ATOM#CMPLX;onechar;
#defn    Onlychar(__C__,__X__)               #ATOM#CMPLX;#ATOM#CMPLX;onlychar;
#define  Lrotat(_X_)                   [1]get(_X_):++_X_;{_X_}cat;
#define  Rrotat(_X_,_Y_)              {_X_};[_Y_]get(_X_);cat;mov(_X_);--_X_;{_X_}
#defn    Lcharpos(__C__,__X__)           {1};#ATOM#CMPLX;#ATOM#CMPLX;poschar;
#defn    Rcharpos(__C__,__X__)          {0};#ATOM#CMPLX;#ATOM#CMPLX;poschar;
#defn    Strreverse(__X__)                    reverse(__X__);   // requiete una constante string
#defn    Mask(__F__,__M__,__X__)             #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;mask; 
#defn    Money(__DEC__,__X__)                #ATOM#CMPLX;#ATOM#CMPLX;money;
// Take(a,b,c,...) Format$(v)
#defn    Format(__X__)                       #RAND;__C__#RNDV=__X__;sjoin;gettoksep;format(__C__#RNDV);%RAND;


/* PARSER HTML */
#defn    Htmlfld(_F_,_ATR_,_CON_)       #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;{0}parser
#defn    Htmlvfld(_F_,_ATR_)            #ATOM#CMPLX;#ATOM#CMPLX;{"",1}parser
#defn    Unpars(_F_)                    #ATOM#CMPLX;unparser

/* PIVOT: EXPRESIONES REGULARES */
// para más informacion, ver POSIX y ejemplos:
#defn    CRegex(_F_,_E_,_T_)        #ATOM#CMPLX;#ATOM#CMPLX;regcompile(_T_)    
#defn    VRegex(_F_,_S_,_T_)        #ATOM#CMPLX;{_T_};#ATOM#CMPLX;regvalid;
#defn    MRegex(_F_,_N_,_S_,_T_)    #ATOM#CMPLX;#ATOM#CMPLX;{_T_};#ATOM#CMPLX;regmatch;
#defn    FreeRE(_T_)                regfree(_T_)

// ARCHIVOS:
#defn    Datafile(_F_,_A_)          _A_={#VOID},#ATOM#CMPLX,statsfile,pushall(_A_)
// se usan como instrucción(,,,)(FD)
// USAR con Using(MODO), Open File (...)(fd)
#defn    Using(__X__)          #ATOM#CMPLX;
//#defn    FILE-OPEN(_F_)        #ATOM#CMPLX,open
#defn    Createfile(_F_)      #ATOM#CMPLX,create
// más "humano" no necesita "using":
#defn    Openin(_F_)       {0};#ATOM#CMPLX,open
#defn    Openout(_F_)      {1};#ATOM#CMPLX,open
#defn    Openapnd(_F_)      {2};#ATOM#CMPLX,open
#defn    Openexcl(_F_)   {16};#ATOM#CMPLX,open

#defn    Createnormal(_F_)    {0};#ATOM#CMPLX,create
#defn    Createreadonly(_F_)   {1};#ATOM#CMPLX,create
#defn    Createhidden(_F_)    {2};#ATOM#CMPLX,create
#defn    Createsystem(_F_)    {4};#ATOM#CMPLX,create

// USING(MAX_LINE), READ-LINE(FD)
#define  Readline(_FD_)       ;readline(_FD)
//#define  Readlineto(_FD_,_V_) ;pushvar(_V_)readline(_FD_)
#define  Readstr              ;readstring
#defn    Writeline(_S_)        #ATOM#CMPLX,writeline
#defn    Writestr(_S_)         #ATOM#CMPLX,writestring
#define  Getpos               {SEEK_CUR,0}seek
//  SetPos devuelve un dato al stack: debe ser asignado:
#defn    Setpos(_N_)          {SEEK_SET},#ATOM#CMPLX,seek
#defn    Seek(_M_,_P_)         #ATOM#CMPLX,#ATOM#CMPLX,seek

// posicionan puntero de lectura-escritura en archivo abierto: no deben ser asignados
#define  Set-BOF(_FD_)         {SEEK_SET,0}seek(_FD_),kill
#define  Set-EOF(_FD_)         {SEEK_END,0}seek(_FD_),kill
#defn    Readlines(_FD_,_N_,_SIZE_)   #RAND; _STR_87364="";_STMP_726345="";_I_#RNDV=_N_;_LOOP_#RNDV:;\
                                       {_SIZE_}readline(_FD_);mov(_STMP_726345);\
                                       {_STR_87364}{_STMP_726345}{"\n"}*cat;mov(_STR_87364);--_I_#RNDV;\
                                       {_I_#RNDV}jnz(_LOOP_#RNDV);{_STR_87364};%RAND;
#define  Fsize(_FD_)               _TMP_09384234=0;{SEEK_CUR}{0};seek(_FD_);mov(_TMP_09384234);\
                                       {SEEK_END}{0}seek(_FD_);{SEEK_SET}{_TMP_09384234}seek(_FD_);kill;
#define  Eof(_FD_)                     eof(_FD_)
#define  Close(_FD_)                   close(_FD_)
#define  Getmsgfileerror            fileerror

// Archivos cargado como string:
#defn    Strload(_F_,_D_)             #ATOM#CMPLX;loadstring(_D_)
#defn    Strsave(_F_,_D_)             #ATOM#CMPLX;savestring(_D_)
#defn    Getline(__L__,__S__)         #ATOM#CMPLX;getline(__S__)
#defn    Countlines(__S__)              ;countlines(__S__);

// FUNCIONES QUE DEPENDEN DE SEARCH:
#define  Sgetlinepos(_V_,_N_)           __ROW_768345=0;{2}{_N_}{_V_}array(8);mov(__ROW_768345);\
                                          [__ROW_768345,1]get(_V_)
#define  Sgetposline(_V_,_N_)           __ROW_768345=0;{1}{_N_}{_V_}array(8);mov(__ROW_768345);\
                                          [__ROW_768345,2]get(_V_)
#defn    Sgetlines(_I_,_SIZE_,_V_,_FD_)   __POS_4345=0;{SEEK_SET}{2};#ATOM#CMPLX;mov(__POS_4345);\
                                          __ROW_768345=0;[__POS_4345,1]get(_V_);{_V_}array(8);\
                                          seek(_FD_);kill;{_SIZE_}readline(_FD_)
#defn    Searchlines(_F_,_V_)            {"-r $'\n'"},#ATOM#CMPLX,search(_V_)
#defn    Search(_P_,_F_,_V_)              #ATOM#CMPLX,#ATOM#CMPLX,search(_V_)

// TIME CONTROL

#define  Tic(_X_)                    timecpu(_X_)    
#define  Toc(_X_,_Y_)                timecpu(_Y_),{_Y_}minus(_X_),clockpersec,div,mov(_Y_) //,clear(_X_)

// convierte a segundos una hora "hh:mm:ss:mm". _X_ se mete en stack.
// "seconds", sin stack, entrega los segundos desde la medianoche

#defn    Secondsfrom(_X_)            #ATOM#CMPLX;seconds;
#define  Getsecondsofit              ;seconds;

// obtiene el tiempo transcurrido en milisegundos, entre _X_ e _Y_:
///#defn    LOOK-TIME(_X_,_Y_)           #ATOM#CMPLX;timer(_Y_)
#defn    Microsecs(_X_)               #ATOM#CMPLX;microsecs;
#defn    Sectotime(_X_)             #ATOM#CMPLX;sectotime;
#defn    Sleep(_X_)                   #ATOM#CMPLX;sleep;
// obtiene el tiempo transcurrido de ejecución:
#define  Timecpu(__X__)              timecpu(__X__)
#define  Clockspersec             ;clockpersec;
// devuelve Y si es el tiempo, sino, devuelve Z
///#defn    Seliftime(_X_,_LIMIT,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:
// hace algo si es el tiempo:
#defn    Ontime(_X_,_LIMIT_)          #ATOM#CMPLX;timer(_LIMIT_);do
// salta a un sub si es el tiempo:
//#defn    Jitgosub(_X_,_L_,_LBL_)       #ATOM#CMPLX;timer(_L_);gosub(_LBL_)
// 
#defn    Istime(_X_,_L_)            ;#ATOM#CMPLX;timer(_L_); // devuelve TRUE o FALSE

/* BITS */
#defn    Bitget(__N__,__I__)      #ATOM#CMPLX;bit(__I__)
#defn    Bitand(__X__,__Y__)      #ATOM#CMPLX;#ATOM#CMPLX;bit(100)
#defn    Bitxor(__X__,__Y__)      #ATOM#CMPLX;#ATOM#CMPLX;bit(102)
#defn    Bitor(__X__,__Y__)       #ATOM#CMPLX;#ATOM#CMPLX;bit(101)
#defn    Bitnot(__X__)            #ATOM#CMPLX;bit(103)
// Take(1,2,3...),ClrBit(n)
#defn    Bitclr(__X__)            #ATOM#CMPLX;bit(104)
// Take(1,2,3...),SetBit(n)
#defn    Bitset(__X__)            #ATOM#CMPLX;bit(105)
// MissByte(LOWBYTE|HIGHBYTE, n)
#defn    Mirrbyte(__X__,__Y__)    #ATOM#CMPLX;#ATOM#CMPLX;bit(106)
// RotBit(LOWBYTE|HIGHBYTE, i, n)
#defn    Bitrotat(_X_,_P_,_Y_)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;bit(107)
// ShiftR(k,n), k numero de bits
#defn    Rshift(_E_,_X_)      #ATOM#CMPLX;#ATOM#CMPLX;bit(108)
#defn    Lshift(_E_,_X_)       #ATOM#CMPLX;#ATOM#CMPLX;bit(109)
#defn    Hextodec(__X__)         #ATOM#CMPLX;bit(110)
#define  Dohexadecimaltodecimal   ;bit(110)
#define  Dohexatodec   ;bit(110)
#defn    Octtodec(__X__)         #ATOM#CMPLX;bit(111)
#define  Dooctaltodecimal        ;bit(111)
#define  Doocttodec        ;bit(111)
#defn    Bintodec(__X__)         #ATOM#CMPLX;bit(112)
#define  Dobinarytodecimal       ;bit(112)
#define  Dobintodec       ;bit(112)


/* SETS conjuntos */
// las macros son asignables:
#defn    Setset(__X__)            {__X__};array(0);{__X__};sets(0)  // unique
#defn    Unique(__X__)             #ATOM#CMPLX;sets(0)
#defn    Union(__X__,__Y__)        {__X__}{__Y__}sets(1)
#defn    Intersect(__X__,__Y__)        {__X__}{__Y__}sets(2)
#defn    Simdiff(__X__,__Y__)         {__X__}{__Y__}sets(4)
#defn    Diff(__X__,__Y__)       {__X__}{__Y__}sets(3)
// devuelven T o F
#defn    Disjoint(__X__,__Y__)         {__X__}{__Y__}sets(5)
#define  Aredisjoint?               ;sets(5)
#defn    Subset(__X__,__Y__)           {__X__}{__Y__}sets(6)

// This 'v' compared to 'w' Is subset?
#define  Issubset?                 ;sets(6)
#defn    Issubsetof(__X__)           {__X__}sets(6)
#defn    Superset(__X__,__Y__)       {__X__}{__Y__}sets(7)
#define  Issuperset?                 ;sets(7)
#defn    Issupersetof(__X__)         {__X__}sets(7)


/* RECORD LARGO-POSICION */
// declaracion estandar:
#defn    Declare                ##CODEMRK,__FLD_REC_LP=0,%%MARK="",
#defn    Commit(_X_)            #RAND,__PF#RNDV=0,join(__PF#RNDV),{__PF#RNDV}gettoksep;format(_X___FMT_),mov(_X_),%RAND;

// RECORD LP
#defn    asrecord-LP(_X_)      _X_="";_X___FMT_=%MARK;
#defn    Fldstr(_X_,_S_)     {%%MARK,"$"}{__FLD_REC_LP}xtostr;cat;{":"}cat;{_S_}xtostr;cat;{"L"}cat;cat;\
                                mov(%%MARK);_X___SIZE_=_S_;_X_="";++__FLD_REC_LP
#defn    Fldnum(_X_,_S_)     {%%MARK,"$"}{__FLD_REC_LP}xtostr;cat;{":"}cat;{_S_}xtostr;cat;{"R"}cat;cat;\
                                mov(%%MARK);_X___SIZE_=_S_;_X_=0;++__FLD_REC_LP
#define  Getstr-LP(_F_,_X_) [1:_F___SIZE_]get(_X_),trim,mov(_F_);{""}put(_X_);clearinterval;//clearmark
#define  Getnum-LP(_F_,_X_)    [1:_F___SIZE_]get(_X_),trim,xtonum,mov(_F_);{""}put(_X_);clearinterval//clearmark

/* RECORD LARGO LIBRE */
#defn    asrecord(_X_)         _X_="";_X___FMT_=%MARK;--_X___FMT_
#defn    Flds(*)              __SEP__FLD__=0;{36}chr;mov(__SEP__FLD__);#GENCODE $$$*$$$ {%%MARK}{__SEP__FLD__}\
                                {__FLD_REC_LP}xtostr;cat;cat;gettoksep;cat;mov(%%MARK);++__FLD_REC_LP;\
                                #LIST__TOKEN_=__FLD_REC_LP;#LIST=0;#ENDGEN;
#defn    Fld(_X_)             {%%MARK,"$"}{__FLD_REC_LP}xtostr;cat;cat;gettoksep;cat;mov(%%MARK);++__FLD_REC_LP;\
                                _X___TOKEN_=__FLD_REC_LP;_X_=0;
#defn    Modif(_D_,_F_,_X_)    #ATOM#CMPLX;{_F___TOKEN_}$$(_X_);mov(_X_)
#define  Getstr(_X_,_Y_)    {_X___TOKEN_}$(_Y_);trim;mov(_X_)
#define  Getnum(_X_,_Y_)       {_X___TOKEN_}$(_Y_);xtonum;mov(_X_)

// BASICAS STRING
#defn    Len(__X__)          #ATOM#CMPLX;len;
#define  Getlen              ;len;
#defn    Chr(__X__)          #ATOM#CMPLX;chr;
#define  Getchr              ;chr;
#defn    Asc(__X__)        #ATOM#CMPLX;asc;
#define  Getascii            ;asc;
#defn    Str(_X_)            #ATOM#CMPLX;xtostr;
#define  Tostr               ;xtostr;
#defn    Val(_X_)            #ATOM#CMPLX;xtonum;
#define  Toval               ;xtonum;
#defn    Bool(_X_)           #ATOM#CMPLX;xtobool;
#define  Tobool              ;xtobool;

/* SOCKETS */
// TCP
// Let ( fd := OpenServerTCP(5,8080) ) 
#defn    Opensrv-TCP(_N_,_P_)     #ATOM#CMPLX;#ATOM#CMPLX;socket(0);
// Let ( fdCli := OpenClientTCP("127.0.0.1", 8080) )
// acepta conexion entrante: Let ( fdCli := Accept(fd) )
#define  Accept(_FD_)                 accept(_FD_)
// ejemplo:  Send(mensajeStr, fdCli) 
#defn    Send(__C__,_FDC_)            #ATOM#CMPLX;send(_FDC_)
#defn    Recv(__SIZE__,_FDC_)         #ATOM#CMPLX;recv(_FDC_)
#defn    Opencli-TCP(_IP_,_P_)    #ATOM#CMPLX;#ATOM#CMPLX;socket(1);
#define  Connect(_FD_)                connect(_FD_)
// UDP
// Let ( fd := OpenServerUDP(8080) )
#defn    Opensvr-UDP(_P_)         #ATOM#CMPLX;socket(3);
// Let ( fdCli := OpenClientUDP("127.0.0.1", 8080) )
#defn    Opencli-UDP(_IP_,_P_)    #ATOM#CMPLX;#ATOM#CMPLX;socket(4);
#defn    Sendto(__C__,_FD_)          #ATOM#CMPLX;sendto(_FD_)
#defn    Recvfrom(__SIZE__,_FD_)     #ATOM#CMPLX;recvfrom(_FD_)
// cierre socket
#defn    Closesock(__FD__)         #ATOM#CMPLX;socket(2)

/* CALENDARIO - CALENDAR */
// genera calendario actual, y devuelve una tabla:
#define  Getactualcal                   {1}cal(0)
#define  Getactualcalendar              {1}cal(0)
// genera calendario, más/menos _N_ meses:
#defn    Radialcal(_M_,_Y_,_N_)      {1}#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;__CAL_CNTE_29839__=0;\
                                      mov(__CAL_CNTE_29839__);cal(__CAL_CNTE_29839__)
// genera calendario, más _N_ meses:
#defn    Cal(_M_,_Y_,_N_)             {1}#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;plus(100);__CAL_CNTE_29839__=0;\
                                      mov(__CAL_CNTE_29839__);cal(__CAL_CNTE_29839__)
#synon   Cal             Calendar


/* STATS */
#defn    Summatory(__X__)      #ATOM#CMPLX;stats(0)
#define  Getsummatory          ;stats(0)
#defn    Multiplicatory(__X__) #ATOM#CMPLX;stats(8)
#define  Getmultiplicatory      ;stats(8)
#defn    Geometricmean(__X__)       #ATOM#CMPLX;stats(9)
#define  Getgeometricmean       ;stats(9)
#defn    Harmonicmean(__X__)       #ATOM#CMPLX;stats(10)
#define  Getharmonicmean        ;stats(10)
#defn    Mean(__X__)           #ATOM#CMPLX;stats(1)
#define  Getmean               ;stats(1)
#defn    Sturgesclass(_X_)      #ATOM#CMPLX;stats(3)
#define  Getsturgesclass       ;stats(3)
#defn    Binclass(_B_,_X_)    #ATOM#CMPLX;#ATOM#CMPLX;stats(4)
#define  Getbinclass           ;stats(4)
#defn    Class(__X__)          #ATOM#CMPLX;stats(5)
#define  Getclass             ;stats(5)
#defn    Add-subsucc(__X__)   #ATOM#CMPLX;stats(13)
#define  Getadd-subsuccession   ;stats(13)
#defn    Sub-addsucc(__X__)   #ATOM#CMPLX;stats(14)
#define  Getsub-addsuccession   ;stats(14)
// estas macros actúan sobre matrices 2D:
#defn    Sumcols(__X__)        #ATOM#CMPLX;stats(6)
#define  Getsumcolumns            ;stats(6)
#defn    Sumrows(__X__)        #ATOM#CMPLX;stats(7)
#define  Getsumrows            ;stats(7)
#defn    Mulcols(__X__)        #ATOM#CMPLX;stats(11)
#define  Getmulcolumns            ;stats(11)
#defn    Mulrows(__X__)        #ATOM#CMPLX;stats(12)
#define  Getmulrows            ;stats(12)


// DECLARACIONES DE ARRAYS:
#defn    Dim(*)                     #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN,
#defn    asnan(*)           __TMPARR__=-1,nanarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    aszeros(*)      __TMPARR__=-1,zerosarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    asones(*)       __TMPARR__=-1,onesarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    aseyes(*)     __TMPARR__=-1,eyesarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    asalpha(*)     {""},__TMPARR__=-1,fillarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    asfill(__F__,*)  #ATOM#CMPLX,__TMPARR__=-1,fillarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,\
                                        cpy(#LIST);#ENDGEN,kill;
#defn    asintlimitedrand(_I_,_F_,*)    __TMPARR__=-1,randarray(__TMPARR__),mulby(1000000),__RNDLOW___=0;#ATOM#CMPLX;\
                                        cpy(__RNDLOW___);#ATOM#CMPLX;sub,mod,plus( __RNDLOW___ ),int,\
                                        #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;

#defn    asintrand(_M_,*)        __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),int,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;

#defn    asceilrand(_M_,*)    __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),ceil,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    asfloorrand(_M_,*)     __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),floor,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    asrand(*)     __TMPARR__=-1,randarray(__TMPARR__),\
                                         #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    asvoid(*)     __TMPARR__=-1,newarray(__TMPARR__),\
                                     #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
                                     
//
#defn    Iterator(_INC_,_REL_,*)  #RAND; _LOOP_#RNDV:;*;\
                                  _INC_;_REL_;jt(_LOOP_#RNDV);%RAND;
#defn    When(_X_)                #ATOM#CMPLX,do


// Ciclos for especiales:

#defn   Foreachtoken(_Y_,_X_,_TT_)                 #RAND, ##ENDLOOP &(++_EXPR2_#RNDV;--_EXPR_#RNDV;{_EXPR_#RNDV};jz(%%ENDLOOP)) , \
                                                 _Y_="", _EXPR2_#RNDV=1, _EXPR_#RNDV=_TT_,{_TT_},jz(%%ENDLOOP),#LOOP: ,\
                                                 {_EXPR2_#RNDV},$(_X_),mov(_Y_),%RAND

// itera para cada caracter
#defn   Foreachchar(_Y_,_X_,_LEN_)                #RAND, ##ENDLOOP &(++_EXPRI_#RNDV;--_EXPRL_#RNDV;{_EXPRL_#RNDV};jz(%%ENDLOOP)),\
                                                 {_LEN_},jz(%%ENDLOOP),_Y_="", _EXPRI_#RNDV=1, _EXPRL_#RNDV=_LEN_,\
                                                 #LOOP:,[_EXPRI_#RNDV]get(_X_),mov(_Y_),%RAND

// para cada elemento del array. se debe hacer reshape antes de este FOR
#defn   Foreach(_V_,_ARR_,_LEN_)                 #RAND,##ENDLOOP &(--_IND_#RNDV, {_IND_#RNDV}jz(%%ENDLOOP)),\
                                                 _IND_#RNDV=_LEN_,_V_=0,#LOOP:,[_IND_#RNDV]ewget(_ARR_),mov(_V_),%RAND


// funciona Continue: Loop if( cond )/ Back
#defn    Loopif(_X_)              &( ) ##ENDLOOP,#LOOP:,#ATOM#CMPLX,jnt(%%ENDLOOP)
#synon   Loopif                  Loopwhile

// funciona Continue! Loop for( And( Leq(i,100), Not(Zero(h)) ), ++i;h-=2 ) / Next o Back
//#defn    Loopfor(_X_,_Y_,_Z_)     &(_Z_) _X_,#LOOP:,_Y_,jnt(#ENDLOOP),
#defn    Loopfor(_X_,_Y_,_Z_)      &(_Z_) _X_,##ENDLOOP,#LOOP:,_Y_,jnt(%%ENDLOOP),

#defn    Looptimes(_T_)          #RAND,&(__PERFT__#RNDV__--), __PERFT__#RNDV__=0;#ATOM#CMPLX;minus(1);mov(__PERFT__#RNDV__); \
                                 ##ENDLOOP,{__PERFT__#RNDV__},jz(%%ENDLOOP),#LOOP:,  %RAND

// Continue puede entrar en un loop infinito!: Loop / Back if( expr ) is...
#defn    Loop                     &( ) ##ENDLOOP #LOOP:,

#defn    Backif(_X_)             #ATOM#CMPLX;
#defn    istrue                  %&,jt(%LOOP),%ENDLOOP:,
#defn    isfalse                 %&,jnt(%LOOP),%ENDLOOP:,
#defn    isnotzero               %&,jnz(%LOOP),%ENDLOOP:,
#defn    iszero                  %&,jz(%LOOP),%ENDLOOP:,
#defn    isnotnull               %&,jnv(%LOOP),%ENDLOOP:,
#defn    isnull                  %&,jv(%LOOP),%ENDLOOP:,
#defn    ispositive              %&,jpos(%LOOP),%ENDLOOP:,
#defn    isnegative              %&,jneg(%LOOP),%ENDLOOP:,
#defn    isnotpositive           %&,jnpos(%LOOP),%ENDLOOP:,
#defn    isnotnegative           %&,jnneg(%LOOP),%ENDLOOP:,
/*
   Loop

   Back if less-equal(X,Y)
   Back if less(X,Y) 
   Back if greater-equal(X,Y)
   Back if greater(X,Y)
   Back if not-equal(X,Y)
   Back if equal(X,Y)
*/
#defn    Backifless-equal(_X_,_Y_)      %&,#ATOM#CMPLX;#ATOM#CMPLX;jle(%LOOP),%ENDLOOP:,
#defn    Backifless(_X_,_Y_)            %&,#ATOM#CMPLX;#ATOM#CMPLX;jlt(%LOOP),%ENDLOOP:,
#defn    Backifgreater-equal(_X_,_Y_)   %&,#ATOM#CMPLX;#ATOM#CMPLX;jge(%LOOP),%ENDLOOP:,
#defn    Backifgreater(_X_,_Y_)         %&,#ATOM#CMPLX;#ATOM#CMPLX;jgt(%LOOP),%ENDLOOP:,
#defn    Backifequal(_X_,_Y_)           %&,#ATOM#CMPLX;#ATOM#CMPLX;jeq(%LOOP),%ENDLOOP:,
#defn    Backifnotequal(_X_,_Y_)        %&,#ATOM#CMPLX;#ATOM#CMPLX;jneq(%LOOP),%ENDLOOP:,

#defn    Backifnotover            %&, jnz(%LOOP), %ENDLOOP:,
#defn    Back                     %&, jmp(%LOOP), %ENDLOOP:,

// para cerrar Loop:
#defn    Until(_X_)               %& ,#ATOM#CMPLX, jnt(%LOOP), %ENDLOOP:
#defn    While(_X_)               %& ,#ATOM#CMPLX, jt(%LOOP), %ENDLOOP:

// si X se cumple, deja el valor en Y, de lo contrario, en Z:
#defn    Moveif(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);mov(_Y_);jmp(#ENDIF);%ENDIIF:;mov(_Z_);%ENDIF:
// idem a Move if(), pero el valor copiado queda en memoria:
#defn    Copyif(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);cpy(_Y_);jmp(#ENDIF);%ENDIIF:;cpy(_Z_);%ENDIF:
// mueve un valor a una variable, si se cumple una condicion; sino, la deja intacta, pero el valor se pierde de la memoria:
// Move on( Equals(i,1), w )
#defn    Moveon(_X_,_V_)       #ATOM#CMPLX;jnt(#ENDIIF);mov(_V_);jmp(#ENDIF);%ENDIIF:;kill;%ENDIF:
// copia el valor si se cumple la condicion; sino, pasa, pero el valor queda en memoria.
// .... Copy on(Equals(i,1), w), ...
#defn    Copyon(_X_,_V_)       #RAND;#ATOM#CMPLX;jnt(__CPY#RNDV__);cpy(_V_);__CPY#RNDV__:;%RAND
#defn    Seton(_X_,_V_)       #RAND;#ATOM#CMPLX;jnt(__CPY#RNDV__);#ATOM#CMPLX;__CPY#RNDV__:;%RAND
//

#defn   Setif(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:
#defn   Getif(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:

// mueve simétricamente #valores desde el stack a un #de variables:
#defn    Moveto(*)             #GENCODE $$$*$$$ mov(#REVLIST);#ENDGEN,
#defn    Initzero(*)           #GENCODE $$$*$$$ #REVLIST=0;#ENDGEN,
#defn    Initialize(_V_,*)     ;#ATOM#CMPLX; #GENCODE $$$*$$$ #LIST=0;cpy(#LIST);#ENDGEN,kill;
#defn    Init(*)               #GENCODE $$$*$$$ #REVLIST=0,mov(#REVLIST);#ENDGEN,
// copia un solo valor a muchas variables. Deja el valor en memoria:
#defn    Copyto(*)             #GENCODE $$$*$$$ cpy(#REVLIST);#ENDGEN,

// mueve simétricamente #valores a un #de variables.
// Esto debe estar declarado después de todas las declaraciones que terminen en xxxto()
#define  Into(_X_)                (_X_)

//  Move(1, "hola", Add(10,-1)), Into (x,mesg,suma)
// mueve simétricamente #valores a un #de variables:
#defn    Move(*)             #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;__MOVING__
#defn    __MOVING__(*)          #GENCODE $$$*$$$ mov(#REVLIST);#ENDGEN;

// copia un solo valor a muchas variables. QUITA EL valor DE LA memoria:
// Copy ( 10 ) Into ( x,y,z,w )
#defn    Copy(*)              #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;__COPYING__
#defn    __COPYING__(*)         #GENCODE $$$*$$$ cpy(#REVLIST);#ENDGEN;kill;

/* mover grupos de datos al stack o a una variable */
#defn  Getpositivesfrom(_X_)     #ATOM#CMPLX;getpositive(-1)
#defn  Getnegativesfrom(_X_)     #ATOM#CMPLX;getnegative(-1)
#defn  Getnonzeroesfrom(_X_)     #ATOM#CMPLX;getnonzero(-1)
#defn  Getnonvoidfrom(_X_)       #ATOM#CMPLX;getnonvoid(-1)

#defn  Movepositivesfrom(_X_)    #ATOM#CMPLX;getpositive
#defn  Movenegativesfrom(_X_)    #ATOM#CMPLX;getnegative
#defn  Movenonzeroesfrom(_X_)    #ATOM#CMPLX;getnonzero
#defn  Movenonvoidfrom(_X_)      #ATOM#CMPLX;getnonvoid

// asigna resultado de una expresión a una variable:
#defn    Letlist(_X_,*)         #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN,pushall(_X_)
#defn    Letrow(_X_,*)          #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN,addrow(_X_)
#defn    Let(_X_,*)             #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN,mov(_X_)
#defn    Sel(_X_,_Y_,_Z_)        #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:

#defn    ElseIf(__X__)           jmp(%%CODEIF), %ENDIF:, #ATOM#CMPLX, jnt(#ENDIF),
#defn    If(__X__)            ##CODEIF, #ATOM#CMPLX, jnt(#ENDIF),
#defn    Else                 jmp(%%CODEIF), %ENDIF:, true,jnt(#ENDIF),
#defn    EndIf                %CODEIF:, %ENDIF:,

/* Extensiones de IF */
#defn Evaluate(*)                  #GENCODE $$$*$$$ option#ITV=0;#ATCMLIST;\
                                   mov(option#ITV);#ENDGEN;

#defn Ifalloptionsaretrue(*)       ##CODEIF,{1},#GENCODE $$$*$$$ #ATCMLIST;\
                                   and;#ENDGEN;jnt(#ENDIF)

#defn Ifalloptionsarefalse(*)      ##CODEIF,{0},#GENCODE $$$*$$$ #ATCMLIST;\
                                   or;#ENDGEN;jt(#ENDIF)

#defn Ifsomeoptionaretrue(*)       ##CODEIF,{0},#GENCODE $$$*$$$ #ATCMLIST;\
                                   or;#ENDGEN;jnt(#ENDIF)

#defn Ifonlyoneoptionistrue(*)     ##CODEIF,{0},#GENCODE $$$*$$$ #ATCMLIST;\
                                   xor;#ENDGEN;jnt(#ENDIF)

#defn Ifonlyoneoptionisfalse(*)    ##CODEIF,{0},#GENCODE $$$*$$$ #ATCMLIST;\
                                   xor;#ENDGEN;jt(#ENDIF)
/*****/
#defn Ifallaretrue(*)              ##CODEIF,{1},#GENCODE $$$*$$$ option#ITV=0;#ATCMLIST;\
                                   cpy(option#ITV);and;#ENDGEN;jnt(#ENDIF)
// It is the case than
#defn Aretrue(*)                   jmp(%%CODEIF), %ENDIF:, {1}, #GENCODE $$$*$$$ #ATCMLIST;\
                                   and;#ENDGEN;jnt(#ENDIF),

#defn Itistrue(_X_)                jmp(%%CODEIF), %ENDIF:, {_X_}, jnt(#ENDIF),

/*****/
#defn Ifallarefalse(*)             ##CODEIF,{0},#GENCODE $$$*$$$ option#ITV=0;#ATCMLIST;\
                                   cpy(option#ITV);or;#ENDGEN;jt(#ENDIF)
// It is not the case than
#defn Arefalse(*)                  jmp(%%CODEIF), %ENDIF:, {0}, #GENCODE $$$*$$$ #ATCMLIST;\
                                   or;#ENDGEN;jt(#ENDIF),

#defn Itisfalse(_X_)               jmp(%%CODEIF), %ENDIF:, {_X_}, jt(#ENDIF),
/*****/

#defn Ifsomearetrue(*)             ##CODEIF,{0},#GENCODE $$$*$$$ option#ITV=0;#ATCMLIST;\
                                   cpy(option#ITV);or;#ENDGEN;jnt(#ENDIF)

/*****/
#defn Ifonlyoneistrue(*)           ##CODEIF,{0},#GENCODE $$$*$$$ option#ITV=0;#ATCMLIST;\
                                   cpy(option#ITV);xor;#ENDGEN;jnt(#ENDIF)

#defn Onlyoneistrue(*)             jmp(%%CODEIF), %ENDIF:, {0}, #GENCODE $$$*$$$ #ATCMLIST;\
                                   xor;#ENDGEN;jnt(#ENDIF),
/*****/
#defn Ifonlyoneisfalse(*)          ##CODEIF,{0},#GENCODE $$$*$$$ option#ITV=0;#ATCMLIST;\
                                   cpy(option#ITV);xor;#ENDGEN;jt(#ENDIF)

#defn Onlyoneisfalse(*)            jmp(%%CODEIF), %ENDIF:, {0}, #GENCODE $$$*$$$ #ATCMLIST;\
                                   xor;#ENDGEN;jt(#ENDIF),

/* OPTIMIZACIONES EXPRESIONES LOGICAS DENTRO DE IF */
#defn    notpositivejump        ;jnpos(%%CODEIF)
#defn    notnegativejump        ;jnneg(%%CODEIF)
#defn    positivejump        ;jpos(%%CODEIF)
#defn    negativejump        ;jneg(%%CODEIF)
#defn    truejump        ;jt(%%CODEIF)
#defn    nottruejump        ;jnt(%%CODEIF)
#defn    notzerojump        ;jnz(%%CODEIF)
#defn    zerojump        ;jz(%%CODEIF)
#defn    notnulljump        ;jnv(%%CODEIF)
#defn    nulljump        ;jv(%%CODEIF)
#defn    greaterjump        ;jgt(%%CODEIF)
#defn    greater-equaljump        ;jge(%%CODEIF)
#defn    lessjump        ;jlt(%%CODEIF)
#defn    less-equaljump        ;jle(%%CODEIF)
#defn    notequalsjump        ;jneq(%%CODEIF)
#defn    equaljump        ;jeq(%%CODEIF)

/* TRY/CATCH */
#defn    Try                 swtrap( #CATCH ),
#defn    Raise(_ERR_,_M_)    {_M_}, throw(_ERR_),
#defn    Catch(_X_)          jmp(#ENDCATCH), %CATCH:, clearstack,_X_=0,gettry(_X_),  // gettry hace poptry internamente?
#defn    Freetry             popcatch    // usar si se escapa de TRY con salto
#defn    Finish              %ENDCATCH:,popcatch
#define  Getmsgexception     ;getstrerror;
/* Sswitch */
#defn    Switch(_X_)         ##CODESW,##CODEMRK;%%MARK=0,#ATOM#CMPLX,mov(%%MARK)
#defn    Casenotnegative       {%%MARK}nneg?,do
#defn    Casenotzero           {%%MARK}zero?,not,do
#defn    Casenotpositive        {%%MARK}npos?,do
#defn    Casenotnumeric        {%%MARK}numeric?,not,do
#defn    Casenotstring         {%%MARK}string?,not,do
#defn    Casenotarray          {%%MARK}array?,not,do
#defn    Casenotnull           {%%MARK}void?,not,do
#defn    Casenegative       {%%MARK}neg?,do
#defn    Casezero           {%%MARK}zero?,do
#defn    Casepositive        {%%MARK}pos?,do
#defn    Casenumeric        {%%MARK}numeric?,do
#defn    Casestring         {%%MARK}string?,do
#defn    Casearray          {%%MARK}array?,do
#defn    Casenull           {%%MARK}void?,do
#defn    Case(_X_)           #ATOM#CMPLX,{%%MARK}eq?,do
#defn    Default             true,do
#defn    Betwn(_X_,_Y_)       #ATOM#CMPLX,{%%MARK}ge?,#ATOM#CMPLX,{%%MARK}le?,and,do
#defn    Outbetwn(_X_,_Y_)    #ATOM#CMPLX,{%%MARK}le?,#ATOM#CMPLX,{%%MARK}ge?,and,do
#defn    Occursexactlyhere(_X_)       {%%MARK}{_X_}ecin?,do
#defn    Occurshere(_X_)         {%%MARK}{_X_}cin?,do
#defn    Occursexactly(_X_)    {_X_}{%%MARK}ecin?,do  // en switxh="ABCD", Exac occurs 'B'
#defn    Occurs(_X_)         {_X_}{%%MARK}cin?,do
#defn    Onlist(_X_)         {%%MARK}{_X_}array(1),do
#defn    Exitifnotzero(_X_)    ;#ATOM#CMPLX;jnz(%%CODESW)
#defn    Exitifzero(_X_)       ;#ATOM#CMPLX;jz(%%CODESW)
#defn    Exitiffalse(_X_)      ;#ATOM#CMPLX;jnt(%%CODESW)
#defn    Exitiftrue(_X_)       ;#ATOM#CMPLX;jt(%%CODESW)
#defn    Exitifnotnull(_X_)    ;#ATOM#CMPLX;jnv(%%CODESW)
#defn    Exitifnull(_X_)       ;#ATOM#CMPLX;jv(%%CODESW)
#defn    Exitifnegative(_X_)        ;#ATOM#CMPLX;jneg(%%CODESW)
#defn    Exitifpositive(_X_)        ;#ATOM#CMPLX;jpos(%%CODESW)
#defn    Exitifnotnegative(_X_)        ;#ATOM#CMPLX;jnneg(%%CODESW)
#defn    Exitifnotpositive(_X_)        ;#ATOM#CMPLX;jnpos(%%CODESW)
#defn    Exitif(_X_)         ;#ATOM#CMPLX;jt(%%CODESW),
#defn    Exit                jmp(%%CODESW),
///#defn    Freeswitch          ipop(_VTMP09828),clear(_VTMP09828),
#defn    Endswitch           %CODESW:,%MARK:,

/* Quiebre de ciclos */
/* Quiebre condicionado de bucles FOR, WHILE y LOOP */
//#defn    BREAK-IF-KEY-PRESSED kbhit?;jt(%%ENDLOOP)
//#defn    BREAK-IF(__X__)     #ATOM#CMPLX,
// subgrupo instrucciones lógicas para "exit if...": BREAK-IF( V ) IS-ZERO
#defn    Breakifnotzero(_X_)    ;#ATOM#CMPLX;jnz(%%ENDLOOP)
#defn    Breakifzero(_X_)       ;#ATOM#CMPLX;jz(%%ENDLOOP)
#defn    Breakiffalse(_X_)      ;#ATOM#CMPLX;jnt(%%ENDLOOP)
#defn    Breakiftrue(_X_)       ;#ATOM#CMPLX;jt(%%ENDLOOP)
#defn    Breakifnotnull(_X_)    ;#ATOM#CMPLX;jnv(%%ENDLOOP)
#defn    Breakifnull(_X_)       ;#ATOM#CMPLX;jv(%%ENDLOOP)
#defn    Breakifnegative(_X_)        ;#ATOM#CMPLX;jneg(%%ENDLOOP)
#defn    Breakifpositive(_X_)        ;#ATOM#CMPLX;jpos(%%ENDLOOP)
#defn    Breakifnotnegative(_X_)        ;#ATOM#CMPLX;jnneg(%%ENDLOOP)
#defn    Breakifnotpositive(_X_)        ;#ATOM#CMPLX;jnpos(%%ENDLOOP)
#defn    Breakif(_X_)           ;#ATOM#CMPLX;jt(%%ENDLOOP)
//
#defn    Continueif(_X_)       %%&, #ATOM#CMPLX;jt(%%LOOP)
#defn    Continueifnotzero(_X_)       %%&, #ATOM#CMPLX;jnz(%%LOOP)
#defn    Continueifzero(_X_)       %%&, #ATOM#CMPLX;jz(%%LOOP)
#defn    Continueiffalse(_X_)       %%&, #ATOM#CMPLX;jnt(%%LOOP)
#defn    Continueiftrue(_X_)       %%&, #ATOM#CMPLX;jt(%%LOOP)
#defn    Continueifnotnull(_X_)       %%&, #ATOM#CMPLX;jnv(%%LOOP)
#defn    Continueifnull(_X_)       %%&, #ATOM#CMPLX;jv(%%LOOP)
#defn    Continueifnegative(_X_)       %%&, #ATOM#CMPLX;jneg(%%LOOP)
#defn    Continueifnotnegative(_X_)       %%&, #ATOM#CMPLX;jnneg(%%LOOP)
#defn    Continueifpositive(_X_)       %%&, #ATOM#CMPLX;jpos(%%LOOP)
#defn    Continueifnotpositive(_X_)       %%&, #ATOM#CMPLX;jnpos(%%LOOP)

#defn    Continue            %%&, jmp(%%LOOP)
#defn    Break               jmp(%%ENDLOOP)
#defn    Next                 %&,  jmp(%LOOP), %ENDLOOP:,
//
/* OPTIMIZACION DENTRO DE EXPRESIONES LOGICAS en loops */
#defn    notpositiveexit        ;jnpos(%%ENDLOOP)
#defn    notnegativeexit        ;jnneg(%%ENDLOOP)
#defn    positiveexit        ;jpos(%%ENDLOOP)
#defn    negativeexit        ;jneg(%%ENDLOOP)
#defn    trueexit        ;jt(%%ENDLOOP)
#defn    nottrueexit        ;jnt(%%ENDLOOP)
#defn    notzeroexit        ;jnz(%%ENDLOOP)
#defn    zeroexit        ;jz(%%ENDLOOP)
#defn    notnullexit        ;jnv(%%ENDLOOP)
#defn    nullexit        ;jv(%%ENDLOOP)
#defn    greaterexit        ;jgt(%%ENDLOOP)
#defn    greater-equalexit        ;jge(%%ENDLOOP)
#defn    lessexit        ;jlt(%%ENDLOOP)
#defn    less-equalexit        ;jle(%%ENDLOOP)
#defn    notequalsexit        ;jneq(%%ENDLOOP)
#defn    equalexit        ;jeq(%%ENDLOOP)
/*********/
//
#defn    Locate(_X_,_Y_)        ;#ATOM#CMPLX;#ATOM#CMPLX;goxy;
#defn    Locrowif(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;gox;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;gox;%ENDIF:
#defn    Loccolif(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;goy;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;goy;%ENDIF:
#defn    Locrow(_X_)            ;#ATOM#CMPLX;gox;
#defn    Loccol(_X_)            ;#ATOM#CMPLX;goy;

/* imprime la tabla entera, o lo indicado por [], pero siempre es 2d */
/*#defn   Printtable(__M__)       ___X___=0;cposx(___X___);___Y___=0;cposy(___Y___);\
                                #ATOM#CMPLX;{___X___}{___Y___};print2d;*/
#defn   Printtable(__M__)       #ATOM#CMPLX;print2d;
#defn   Printtableif(_EXP_,_M1_,_M2_)    #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;\
                                         #ATOM#CMPLX;%ENDIF: print2d;
#define Printthistable            ;print2d;
#defn   Drawtable(__M__)       #ATOM#CMPLX;drwtbl;
#define Drawthistable             ;drwtbl;

#defn   vPrintf(__V__,__S__,*)   #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;Format(__S__),mov(__V__)

#defn    Printf(__X__,*)        #RAND;__C__#RNDV=0;#ATOM#CMPLX;mov(__C__#RNDV);#GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;\
                                sjoin;{","}format(__C__#RNDV);print;%RAND;
#defn    Printusingsep(*)           #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;printusingtoken;

#defn    Printif(_X_,_Y_,_Z_)    #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:;print

#defn    Printnl(*)                #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;{"\n"}print;
#defn    Echonl(*)                #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;{"\n"}echo;
#defn    Echo(*)                  #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;echo;
#define  Prnl                   {"\n"}print
#defn    Print(*)                 #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;print;
#define  Printit                 ;print;
#define  Echoit                   ;echo;
#define  Echo                     ;echo;
#define  Print                    ;print;
#defn    Printtop(_X_)           #ATOM#CMPLX;puts;
#define  Printtop               ;puts;
#define  Puts(_X_)              ;puts(_X_)
//
// ENTRADA Y TECLADO:
#defn    Getchar(_X_)          #RAND,pause,lastkey(_X_),{_X_}{194}{1}{207}{1}between?,do{{_X_}chr,pause,\
                                lastkey(_X_),{_X_}chr,cat,utf8tostr,jmp(__GETCHAR__#RNDV)},\
                                {_X_}chr,utf8tostr,__GETCHAR__#RNDV:,mov(_X_),kbfree,%RAND;
#defn    Getch                  #RAND;_VCH#RNDV_=0;__GETCHAR__#RNDV:;pause;lastkey(_VCH#RNDV_);{_VCH#RNDV_}\
                                dup;{194}{1}{207}{1}between?;do{jmp(__GETCHAR__#RNDV)};kbfree;%RAND;
#defn    Putkey(__X__)         #ATOM#CMPLX;keyput;
#defn    Scancode(_X_)         #RAND,lastkey(_X_),{_X_}{194}{1}{207}{1}between?,do{{_X_}chr,pause,\
                                lastkey(_X_),{_X_}chr,cat,utf8tostr,jmp(__GETCHAR__#RNDV)},\
                                {_X_}chr,utf8tostr,__GETCHAR__#RNDV:,asc,mov(_X_),kbfree,%RAND;
#define  Pause                  ;pause;
#define  Keyboardfree           ;kbfree;
#define  Lastkey(_X_)           lastkey(_X_) //  #RAND;_VCH#RNDV_=0;lastkey(_VCH#RNDV_);%RAND

/* TERMINAL BASICO */
#define  Cursoroff            {"\033[?25l"}, print;
#define  Hidecursor            {"\033[?25l"}, print;
#define  Cursoron            {"\033[?25h"}, print;
#define  Showcursor            {"\033[?25h"}, print;
#define  Cls                {"\033[2J\033[1;1H\n"},print;

/* GRAFICOS - TEXTO */
#defn Drawacircle(_X1_,_Y1,_RADIUS_)  #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;circle;
#defn Drawaline(_X1_,_Y1,_X2_,_Y2_)  #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;line;
#define Draw(_X_)  draw(_X_)
#defn Drawapoligon(_X_,_Y_,_N_,_R_)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;poligon;

#defn    Fillbox(_C_,_H_,_W_)  #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;fillbox;

#defn    Colorfore(_X_)          {"\033[38;5;"},#ATOM#CMPLX,{"m"}print;
#defn    Colorback(_X_)          {"\033[48;5;"},#ATOM#CMPLX,{"m"}print;
#defn    Color(_X_,_Y_)         {"\033[38;5;"},#ATOM#CMPLX,{"m"},{"\033[48;5;"},#ATOM#CMPLX,{"m"}print;

#defn   RGB-fore(_X_,_Y_,_Z_)  {"\033[38;2;"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{"m"}print;
#defn   RGB-back(_X_,_Y_,_Z_)  {"\033[48;2;"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{"m"}print;

/*
#define Setvideograph(_X_)    System(Cat("gsettings set org.gnome.Terminal.Legacy.Profile:/org/gnome/terminal/legacy/profiles:/:b1dcc9dd-5262-4d8d-a863-c897e6d979b9/ font 'Ubuntu Mono ",Str(_X_),"'"))
#define Setvideotext          System("gsettings set org.gnome.Terminal.Legacy.Profile:/org/gnome/terminal/legacy/profiles:/:b1dcc9dd-5262-4d8d-a863-c897e6d979b9/ font 'Ubuntu Mono 12'")
*/

#define Canvas-paper             {"\033[48;2;227;216;181m"}print;
#define Canvas-term          {"\033[48;2;7;27;4m"}print;
#define Canvas-old               {"\033[48;2;60;6;19m"}print;
#define Canvas-ocean             {"\033[48;2;72;136;216m"}print;
#define White-pen             {"\033[38;2;255;255;255m"}print;
#define Black-pen             {"\033[38;2;30;27;10m"}print;
#define Amber-pen             {"\033[38;2;243;135;13m"}print;
#define Green-pen             {"\033[38;2;121;192;35m"}print;

#defn    Inverse(__X__)         {"\INV"};#ATOM#CMPLX;cat;{"\033[27m"}cat;
#defn    Underline(__X__)      {"\UL"};#ATOM#CMPLX;cat;{"\033[24m"}cat;
#defn    Italic(__X__)          {"\CUR"};#ATOM#CMPLX;cat;{"\033[23m"}cat;
#defn    Bold(__X__)            {"\ENF"};#ATOM#CMPLX;cat;{"\033[22m"}cat;

//
//#defn    Init(*)               #GENCODE $$$*$$$ #LIST=0;#ENDGEN
#defn    Trash(*)              #GENCODE $$$*$$$ {0}mov(#LIST);#ENDGEN
#defn    Set(*)                #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;
#defn    ___SETLIST___(*)      {"\033"} #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;mklist;
#synon   ___SETLIST___         Setlist
#define  ___LIST___(*)              {"\033"} *;mklist;
#synon   ___LIST___            List

#defn    invar(_X_)            ;#ATOM#CMPLX;
#synon   invar                 var,incte,cte,inexpression,expression

//

#define  Argnum(_N_)       {[_N_]};xtonum;
#synon   Argnum            Getargnumeric
#define  Argstr(_N_)       {[_N_]};
#synon   Argstr            Getargstring
#define  Gettotalargs      totalarg;

#defn    Params(*)                 #GENCODE $$$*$$$ #LIST=0,{[#ITV]},mov(#LIST);#ENDGEN,
                                   // #GENCODE $$$*$$$ #LIST=[#ITV];#ENDGEN,
#defn    Args(*)                  #GENCODE $$$*$$$ #REVLIST=0,mov(#REVLIST);#ENDGEN,

#defn    Define(_F_,*)       _F_:,#GENCODE $$$*$$$ #REVLIST=0;mov(#REVLIST);#ENDGEN;

#defn    Main(_V_,_N_)   #RAND, main:,V#RNDV=1,_V_={#VOID}, \
                             _N_=0,totalarg,mov(_N_), \
                             LOOPGETARG_#RNDV:, {[ V#RNDV ]},push(_V_),++V#RNDV,\
                             {V#RNDV,_N_},jle(LOOPGETARG_#RNDV),clear(V#RNDV),%RAND;

#define  Main               main:
#defn    End-Return(_X_)    ;#ATOM#CMPLX;return
#define  End-Return         emptystack?do{{0}};return
#define  End                emptystack?do{{0}};return
#define  Stop               {0}return
#defn    Return(_X_)        ;#ATOM#CMPLX;back
#define  Return             ;back
#define  Setstack           .stack

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

/* CONSTANTES REGEX */
#define REG_BASIC     0
#define REG_EXTENDED  1
#define REG_ICASE     2
#define REG_NEWLINE   4
#define REG_NOSUB     8
#define REG_NOTBOL    1
#define REG_NOTEOL    2
#define REG_STARTEND  4

/* TECLAS 
   PARA UNA LISTA MAS COMPLETA: KEYS.H
*/
#define KUP        5
#define KDOWN     24
#define KLEFT     19
#define KRIGHT     4
#define KESCAPE   27
#define KRETURN   13

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

