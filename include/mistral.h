

#define  »(__X__)      ;cpy(__X__)   // COPIAR SOBRE LA MARCHA
#define-a ---           ;         // ENTRE PARÉNTESIS
#define  DESDE-        ;
#define  fin            end

/* GENERICS */
#define  INTERCAMBIAR(_X_,_Y_)   ;_X_<->_Y_;
/*#define  INCREMENTAR(_X_)   ;++_X_;
#synon   INCREMENTAR        INCREMENTANDO
#define  DECREMENTAR(_X_)   ;--_X_;
#synon   DECREMENTAR        DECREMENTANDO*/
#define  PAUSAR    ;pause;
#define  CLONAR(_X_,_Y_)    {_X_};Y=0;mov(_Y_)
#define-a  LUEGODE  emptystack?,not,do{ {"No debo tener nada en memoria para continuar "},throw(1001) }
#synon   LUEGODE  POROTROLADO,APARTE,AHORABIEN,FINALMENTE
#define-a  LUEGO    emptystack?do{ {"Debo tener algo en memoria para continuar "},throw(1000) }
#synon   LUEGO    YENTONCES,ENTONCES,CONLOANTERIOR,CONTODOLOANTERIOR,YACONTINUACIÓN,ACONTINUACIÓN,YSEGUIDAMENTE,SEGUIDAMENTE,\
                  HECHOESTO,HECHOESO
//#defn    Setdecimal(_X_)        ;#IF prec(#FATOM) #ELSE ___SET_PREC___=0;#CMPLX;mov(___SET_PREC___);prec(___SET_PREC___); #EIF
//#define  Unsetdecimal           prec(-1)

////#defn    INICIALIZAR(*)          #GENCODE $$$*$$$ #LIST;#ENDGEN

/* LOGICA */
///#defn    O(x,y)
#defn    PUEDESER(_X_,_Y_)       ;#ATOM#CMPLX;#ATOM#CMPLX;or;
#synon   PUEDESER                PUEDEOCURRIR,PUEDASER,PUEDAOCURRIR
#defn    OQUIZAS(_X_)            ;#ATOM#CMPLX;or;
#synon   OQUIZAS                 OTALVEZ

#defn    EXCLUSIVAMENTE(_X_,_Y_)    ;#ATOM#CMPLX;#ATOM#CMPLX;xor;
#synon   EXCLUSIVAMENTE             SOLOESUNO,SOLOSEAUNO,SOLOUNOOCURRE,SOLOOCURREUNO,\
                                    SOLOUNOOCURRA,SOLOOCURRAUNO
#defn    OBIEN(_X_)                 ;#ATOM#CMPLX;xor;

///Y(x,y), 
#defn    SONAMBOS(_X_,_Y_)  ;#ATOM#CMPLX;#ATOM#CMPLX;and;
#synon   SONAMBOS           AMBOSSON,SEANAMBOS,AMBOSSEAN,OCURRENAMBOS,AMBOSOCURREN,\
                            OCURRANAMBOS,AMBOSOCURRAN
#defn    YADEMAS(_X_)            ;#ATOM#CMPLX;and;

#defn    NOCUMPLEQUE(_X_)       ;#ATOM#CMPLX;not;
#synon   NOCUMPLEQUE            NOOCURREQUE,NOOCURRAQUE,NOCUMPLAQUE

//
#defn    NOESIGUALA(__E__)        #IF neqto(#FATOM) #ELSE #CMPLX;neq? #EIF
#synon   NOESIGUALA               NOSEAIGUALA,ESDISTINTOA,SEADISTINTOA
#defn    ESIGUALA(__E__)          #IF eqto(#FATOM) #ELSE #CMPLX ;eq? #EIF
#synon   ESIGUALA                 SEAIGUALA 
#defn    ESMENOROIGUALA(__E__)    #IF lethan(#FATOM) #ELSE #CMPLX ;le? #EIF
#synon   ESMENOROIGUALA           SEAMENOROIGUALA
#defn    ESMAYORQUE(__E__)        #IF gthan(#FATOM) #ELSE #CMPLX;gt? #EIF 
@synon   ESMAYORQUE               SEAMAYORQUE
#defn    ESMAYOROIGUALA(__E__)    #IF gethan(#FATOM) #ELSE #CMPLX;ge? #EIF
#synon   ESMAYOROIGUALA           SEAMAYOROIGUALA
#defn    ESMENORQUE(__E__)        #IF lthan(#FATOM) #ELSE #CMPLX;lt? #EIF 
#synon   ESMENORQUE               SEAMENORQUE

//
#defn    SONARREGLOSDISTINTOS(_X_,_Y_)   #IF #ATOM #ELSE #CMPLX;#EIF #IF neqarrto(#FATOM) #ELSE #CMPLX; neqarr? #EIF
#synon   SONARREGLOSDISTINTOS            SEANARREGLOSDISTINTOS
#defn    SONARREGLOSIGUALES(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF eqarrto(#FATOM) #ELSE #CMPLX; eqarr? #EIF
#synon   SONARREGLOSIGUALES              SEANARREGLOSIGUALES
#defn    SONDISTINTOS(_X_,_Y_)           #IF #ATOM #ELSE #CMPLX;#EIF #IF neqto(#FATOM) #ELSE #CMPLX; neq? #EIF
#synon   SONDISTINTOS                    SEANDISTINTOS
#defn    SONIGUALES(_X_,_Y_)             #IF #ATOM #ELSE #CMPLX;#EIF #IF eqto(#FATOM) #ELSE #CMPLX; eq? #EIF
#synon   SONIGUALES                      SEANIGUALES
#defn    SEAMENOROIGUAL(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF lethan(#FATOM) #ELSE #CMPLX; le? #EIF
#synon   SEAMENOROIGUAL                  ESMENOROIGUAL
#defn    SEAMENOR(_X_,_Y_)               #IF #ATOM #ELSE #CMPLX;#EIF #IF lthan(#FATOM) #ELSE #CMPLX; lt? #EIF
#synon   SEAMENOR                        ESMENOR
#defn    SEAMAYOR(_X_,_Y_)               #IF #ATOM #ELSE #CMPLX;#EIF #IF gthan(#FATOM) #ELSE #CMPLX; gt? #EIF
#synon   SEAMAYOR                        ESMAYOR
#defn    SEAMAYOROIGUAL(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF gethan(#FATOM) #ELSE #CMPLX; ge? #EIF
#synon   SEAMAYOROIGUAL                  ESMAYOROIGUAL

/* Booleanas especiales para usar en estructuras de control */
/* caso POSITIVO */
#defn   ESINFINITO(__X__)    #ATOM#CMPLX;inf?;
#synon  ESINFINITO           SEAINFINITO
#defn   ESNAN(__X__)         #ATOM#CMPLX;nan?;
#synon  ESNAN                SEANAN
#defn   TIENENAN(__X__)      #ATOM#CMPLX;stats(0),nan?
#synon  TIENENAN             TENGANAN
#defn   ESPAR(__X__)         #ATOM#CMPLX;odd?;
#synon  ESPAR                SEAPAR
#defn   ESCERO(__X__)        #ATOM#CMPLX;zero?;
#synon  ESCERO               SEACERO
#defn   ESNULO(__X__)        #ATOM#CMPLX;void?;
#synon  ESNULO               SEANULO
#defn   ESPOSITIVO(__X__)    #ATOM#CMPLX;pos?;
#synon  ESPOSITIVO           SEAPOSITIVO
#defn   ESNEGATIVO(__X__)    #ATOM#CMPLX;neg?;
#synon  ESNEGATIVO           SEANEGATIVO
#defn   ESARREGLO(__X__)     #ATOM#CMPLX;array?;
#synon  ESARREGLO            SEAARREGLO
#defn   ESNUMÉRICO(__X__)    #ATOM#CMPLX;numeric?;
#synon  ESNUMÉRICO           SEANUMÉRICO
#defn   ESCADENA(__X__)      #ATOM#CMPLX;string?;
#synon  ESCADENA             SEACADENA
#defn   ESARCHIVO(__X__)       #ATOM#CMPLX;exist?;
#synon  ESARCHIVO              SEAARCHIVO
#defn   ESDIRECTORIO(__X__)    #ATOM#CMPLX;existdir?;
#synon  ESDIRECTORIO           SEADIRECTORIO
#defn   ESVARIABLEDEENTORNO(__X__)    #ATOM#CMPLX;env?;
#synon  ESVARIABLEDEENTORNO           SEAVARIABLEDEENTORNO
#defn   ENCUENTRECUALQUIERA(__X__,__Y__)    #ATOM#CMPLX;#ATOM#CMPLX;any?;
#synon  ENCUENTRECUALQUIERA                 ENCUENTRACUALQUIERA
//   Take(num), Between?( 10::including, 100::excluding)
//  define includ, exclud ya está listo
#define INC       1
#define EXC       0
#defn   ESTÁENTRE(__I__,_X_,__F__,_Y_)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;between?;
#synon  ESTÁENTRE    ESTÉENTRE
///#defn   Betwn(__I__,__F__)      #ATOM#CMPLX;{1};#ATOM#CMPLX;{1};between?;
#defn   ENCUENTRAENTODO(__X__,__Y__)        #ATOM#CMPLX;#ATOM#CMPLX;all?;
#synon  ENCUENTRAENTODO           ENCUENTREENTODO
///#defn   Empty(__X__)            #ATOM#CMPLX;isempty;
///#define  ESTÁVACÍA                 ;isempty;
#define  HAYERRORDEARCHIVO                ;error?
#define  ESTÁLAMEMORIAOCUPADA              ;emptystack?;not;
#synon   ESTÁLAMEMORIAOCUPADA           ESTÁOCUPADALAMEMORIA
#define  ESTÁLAMEMORIAVACÍA                ;emptystack?;
#synon   ESTÁLAMEMORIAVACÍA             ESTÁVACÍALAMEMORIA
#define  SEHAPRESIONADOUNATECLA          ;kbhit?
#synon   SEHAPRESIONADOUNATECLA          SEHAYAPRESIONADOUNATECLA
#defn    TIPODELCARACTER(__X__,__Y__)            #ATOM#CMPLX;{__Y__}typechar?;
#defn    TIPODELACADENA(__X__,__Y__)             #ATOM#CMPLX;{__Y__}typestring?;
#defn    TIPOSDISTINTO(__X__,__Y__)            #ATOM#CMPLX;{__Y__}disttypestring?;
/* Take(x), Occurs In?("hola mundo!") */
#defn    OCURREEXACTAMENTEEN(__X__)                #ATOM#CMPLX;ecin?;  // requiere algo del stack
///#synon   OCURREEXACTAMENTEEN              OCURRAEXACTAMENTEEN
#defn    OCURREEN(__X__)                     #ATOM#CMPLX;cin?; 
//7#synon   OCURREEN                          OCURRAEN

// CAMBIAN VALOR LOGICO DE X:
#defn    VERDADERO(*)              #GENCODE $$$*$$$ true(#LIST);#ENDGEN
#defn    FALSO(*)                  #GENCODE $$$*$$$ false(#LIST);#ENDGEN
#defn    INVERTIR(*)          #GENCODE $$$*$$$ {#LIST};not;mov(#LIST);#ENDGEN
#define  VERDAD               1
#define  FALSO                0


/* ARITMETICA */

#defn    SUMAR(_X_,_Y_)          #IF #ATOM #ELSE #CMPLX;#EIF #IF plus(#FATOM) #ELSE #CMPLX; add; #EIF
#synon   SUMAR                   LASUMAENTRE
#defn    RESTAR(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF minus(#FATOM) #ELSE #CMPLX; sub; #EIF
#synon   RESTAR                  LARESTAENTRE
#defn    MULTIPLICAR(__X__,__Y__)      #IF #ATOM #ELSE #CMPLX;#EIF #IF mulby(#FATOM) #ELSE #CMPLX; mul; #EIF
#synon   MULTIPLICAR                   LAMULTIPLICACIÓNENTRE
#defn    ENT-DIVIDIR(_X_,_Y_)    #IF #ATOM #ELSE #CMPLX;#EIF #IF idivby(#FATOM) #ELSE #CMPLX; idiv; #EIF
#synon   ENT-DIVIDIR             LADIVISIÓNENTERAENTRE
#defn    DIVIDIR(__X__,__Y__)    #IF #ATOM #ELSE #CMPLX;#EIF #IF divby(#FATOM) #ELSE #CMPLX; div; #EIF
#synon   DIVIDIR                 LADIVISIÓNENTRE
#defn    RESTO(_X_,_Y_)          #IF #ATOM #ELSE #CMPLX;#EIF #IF module(#FATOM) #ELSE #CMPLX; mod; #EIF
#synon   RESTO                   ELRESTOENTRE
#defn    ELEVAR(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF powby(#FATOM) #ELSE #CMPLX; pow; #EIF
#synon   ELEVAR                  LAPOTENCIADE
#defn    REDONDEAR(_X_,_Y_)      #IF #ATOM #ELSE #CMPLX;#EIF #IF roundby(#FATOM) #ELSE #CMPLX; round; #EIF
#synon   REDONDEAR               ELREDONDEODE
#defn    MCD(_X_,_Y_)            #ATOM #CMPLX;#ATOM #CMPLX;gcd;
#synon   MCD                     ELMÁXIMOCOMÚNDENOMINADORENTRE
#defn    MCM(_X_,_Y_)            #ATOM #CMPLX;#ATOM #CMPLX;lcm;
#synon   MCM                     ELMÍNIMOCOMÚNMÚLTIPLOENTRE

//#define  POS-INCREMENTAR(_X_)    _X_++
//#define  INCREMENTAR(_X_)        ++_X_

#defn    MÁS(_X_)                ;#IF plus(#FATOM) #ELSE #CMPLX;add; #EIF
#synon   MÁS                     SÚMELE
#defn    MENOS(_X_)              ;#IF minus(#FATOM) #ELSE #CMPLX;sub; #EIF
#synon   MENOS                   RÉSTELE
#defn    MULTIPLICADOPOR(_X_)    ;#IF mulby(#FATOM) #ELSE #CMPLX;mul; #EIF
#synon   MULTIPLICADOPOR         MULTIPLÍQUELE,POR
#defn    DIVIDIDO-ENTERO-ENTRE(_X_)  ;#IF idivby(#FATOM) #ELSE #CMPLX;idiv; #EIF
#synon   DIVIDIDO-ENTERO-ENTRE       DIVIDIDO-ENTERO-POR,DIVÍDALE-ENTERO-POR,DIVÍDALE-ENTERO-ENTRE
#defn    DIVIDIDOENTRE(_X_)      ;#IF divby(#FATOM) #ELSE #CMPLX;div; #EIF
#synon   DIVIDIDOENTRE           DIVIDIDOPOR,DIVÍDALEPOR,DIVÍDALEENTRE
#defn    MÓDULO(_X_)             ;#IF module(#FATOM) #ELSE #CMPLX;mod; #EIF
#defn    ELEVADOA(_X_)           ;#IF powby(#FATOM) #ELSE #CMPLX;pow; #EIF
#synon   ELEVADOA                ELÉVELOA
#defn    REDONDEARALDECIMAL(_X_)        ;#IF roundby(#FATOM) #ELSE #CMPLX;round;#EIF
#synon   REDONDEARALDECIMAL             REDONDEELOALDECIMAL,REDONDEADOALDECIMAL
#defn    VECES(_X_)              ;#IF mulby(#FATOM) #ELSE #CMPLX;mul; #EIF

#define  MÁSUNO(_X_)    ;plusone(_X_)
#define  MENOSUNO(_X_)    ;minusone(_X_)
#define  MÁSDOS(_X_)    ;plustwo(_X_)
#define  MENOSDOS(_X_)    ;minustwo(_X_)

#define  SÚMELOS    ;add;
#define  RÉSTELOS    ;sub;
#define  MULTÍPLIQUELOS   ;mul;
#define  DIVÍDALOS-ENTERO   ;idiv;
#define  DIVÍDALOS    ;div;

// el calculo se hace al reves x es restado desde y:
#defn    SÚMELOA(_X_)         #ATOM #CMPLX;add;
#defn    RÉSTELODE(_X_)        #ATOM #CMPLX;postfix;sub;postfix;
#defn    MULTIPLIQUEA(_X_)       #ATOM #CMPLX;mul;
#defn    DIVIDA-ENTEROA(_X_)      #ATOM #CMPLX;postfix;idiv;postfix;
#defn    DIVIDAA(_X_)          #ATOM #CMPLX;postfix;div;postfix;
#defn    MÓDULODE(_X_)       #ATOM #CMPLX;postfix;mod;postfix;
#defn    POTENCIADE(_X_)         #ATOM #CMPLX;postfix;pow;postfix;
#defn    REDONDEAA(_X_)        #ATOM #CMPLX;postfix;round;postfix;

// MATEMATICAS:
#defn    SEMILLA(__X__)    #ATOM #CMPLX;seed;

#defn    RAIZCÚB(_X_)    #ATOM #CMPLX;cbrt;
#define  CALCULARRAIZCÚBICA    ;cbrt;
#synon   CALCULARRAIZCÚBICA    OBTENERRAIZCÚBICA,CALCULESURAIZCÚBICA,OBTENGASURAIZCÚBICA,RAIZCÚBICA

#defn    RAIZ(_X_)     ;#ATOM#CMPLX;sqrt;
#define  CALCULARRAIZ     ;sqrt;
#synon   CALCULARRAIZ     OBTENERRAIZ,CALCULESURAIZ,OBTENGASURAIZ,RAIZ

#defn    TECHO(_X_)    #ATOM #CMPLX;ceil;
#define  CALCULARTECHO    ;ceil;
#synon   CALCULARTECHO    OBTENERSUTECHO,CALCULESUTECHO,OBTENGASUTECHO,TECHO

#defn    PISO(_X_)    #ATOM #CMPLX;floor;
#define  CALCULARPISO    ;floor;
#synon   CALCULARPISO    OBTENERSUPISO,CALCULESUPISO,OBTENGASUPISO,PISO

#defn    TRUNC(_X_)    #ATOM #CMPLX;trunc;
#define  TRUNCAR         ;trunc;
#define  TRÚNQUELO       ;trunc;

#defn    LONG-ENT(_X_)    #ATOM #CMPLX;lennum;
#define  CALCULARLONG-PARTEENTERA     ;lennum;
#synon   CALCULARLONG-PARTEENTERA     OBTENERLONG-PARTEENTERA,CALCULELONG-PARTEENTERA,OBTENGALONG-PARTEENTERA

#defn    ENT(_X_)    #ATOM #CMPLX;int;
#define  CALCULARPARTEENTERA    ;int;
#synon   CALCULARPARTEENTERA    OBTENERPARTEENTERA,CALCULESUPARTEENTERA,OBTENGASUPARTEENTERA,PARTEENTERA

#defn    SIGNO(_X_)     #ATOM #CMPLX;sign;
#define  CALCULARSIGNO     ;sign;
#synon   CALCULARSIGNO     OBTENERSIGNO,CALCULESUSIGNO,OBTENGASUSIGNO,SIGNO

//#defn    Sciformat(_X_)        #ATOM #CMPLX;sci;
//#define  Getsciformat          ;sci;
#defn    FACT(_X_)    #ATOM #CMPLX;fact;
#define  CALCULARFACTORIAL     ;fact;
#synon   CALCULARFACTORIAL     OBTENERFACTORIAL,CALCULESUFACTORIAL,OBTENGASUFACTORIAL,FACTORIAL

#defn    VALABS(_X_)     #ATOM #CMPLX;abs;
#define  CALCULARVALORABSOLUTO     ;abs;
#synon   CALCULARVALORABSOLUTO     OBTENERVALORABSOLUTO,CALCULESUVALORABSOLUTO,OBTENGASUVALORABSOLUTO,VALORABSOLUTO

#defn    EXP2(_X_)     #ATOM #CMPLX;exp2;
#define  CALCULAREXPONENCIALBASE-2    ;exp2;
#synon   CALCULAREXPONENCIALBASE-2    OBTENEREXPONENCIALBASE-2,CALCULESUEXPONENCIALBASE-2,OBTENGASUEXPONENCIALBASE-2,\
                                      EXPONENCIALBASE-2

#defn    EXP10(_X_)    #ATOM #CMPLX;exp10;
#define  CALCULAREXPONENCIALBASE-10    ;exp10;
#synon   CALCULAREXPONENCIALBASE-10    OBTENEREXPONENCIALBASE-10,CALCULESUEXPONENCIALBASE-10,OBTENGASUEXPONENCIALBASE-10,\
                                      EXPONENCIALBASE-10

#defn    EXP(_X_)    #ATOM #CMPLX;exp;
#define  CALCULAREXPONENCIAL    ;exp;
#synon   CALCULAREXPONENCIAL    OBTENEREXPONENCIAL,CALCULESUEXPONENCIAL,OBTENGASUEXPONENCIAL,EXPONENCIAL

#defn    LOG2(_X_)    #ATOM #CMPLX;log2;
#define  CALCULARLOGARITMOBASE-2   ;log2;
#synon   CALCULARLOGARITMOBASE-2   OBTENERLOGARITMOBASE-2,CALCULESULOGARITMOBASE-2,OBTENGASULOGARITMOBASE-2,LOGARITMOBASE-2

#defn    LOG10(_X_)     #ATOM #CMPLX;log10;
#define  CALCULARLOGARITMOBASE-10   ;log10;
#synon   CALCULARLOGARITMOBASE-10   OBTENERLOGARITMOBASE-10,CALCULESULOGARITMOBASE-10,OBTENGASULOGARITMOBASE-10,\
                                    LOGARITMOBASE-10
             
#defn    LOG(_X_)     #ATOM #CMPLX;log;
#define  CALCULARLOGARITMO   ;log;
#synon   CALCULARLOGARITMO   OBTENERLOGARITMO,CALCULESULOGARITMO,OBTENGASULOGARITMO,LOGARITMO

#defn    ALEAT(_X_)     #ATOM #CMPLX;rand;
#defn    INVCUAD(_X_)     #ATOM #CMPLX;powby(2);powby(-1)
#define  CALCULARINVERSOCUADRADO    ;powby(2);powby(-1)
#synon   CALCULARINVERSOCUADRADO    OBTENERINVERSOCUADRADO,CALCULESUINVERSOCUADRADO,OBTENGASUINVERSOCUADRADO,\
                                    INVERSOCUADRADO

#defn    INVCÚB(_X_)     #ATOM #CMPLX;powby(3);powby(-1)
#define  CALCULARINVERSOCÚBICO   ;powby(3);powby(-1)
#synon   CALCULARINVERSOCÚBICO   OBTENERINVERSOCÚBICO,CALCULESUINVERSOCÚBICO,OBTENGASUINVERSOCÚBICO,INVERSOCÚBICO

#defn    INVCUAR(_X_)    #ATOM #CMPLX;powby(4);powby(-1)
#define  CALCULARINVERSOALACUARTA    ;powby(4);powby(-1)
#synon   CALCULARINVERSOALACUARTA    OBTENERINVERSOALACUARTA,CALCULESUINVERSOALACUARTA,OBTENGASUINVERSOALACUARTA,\
                                     INVERSOALACUARTA

#defn    INVERSO(_X_)     #ATOM #CMPLX;powby(-1)
#define  CALCULARINVERSO    ;powby(-1)
#synon   CALCULARINVERSO    OBTENERINVERSO,CALCULESUINVERSO,OBTENGASUINVERSO,INVERSO

#defn    CUAD(_X_)    #ATOM #CMPLX;powby(2)
#define  CALCULARCUADRADO    ;powby(2)
#synon   CALCULARCUADRADO    OBTENERCUADRADO,CALCULESUCUADRADO,OBTENGASUCUADRADO,ALCUADRADO

#defn    CUBO(_X_)    #ATOM #CMPLX;powby(3)
#define  CALCULARCUBO   ;powby(3)
#synon   CALCULARCUBO   OBTENERCUBO,CALCULESUCUBO,OBTENGASUCUBO,ALCUBO

#defn    CUAR(_X_)    #ATOM #CMPLX;powby(4)
#define  CALCULARCUARTAPOTENCIA   ;powby(4)
#synon   CALCULARCUARTAPOTENCIA   OBTENERCUARTAPOTENCIA,CALCULESUCUARTAPOTENCIA,OBTENGASUCUARTAPOTENCIA,ALACUARTA

#defn    MEDIO(_X_)    #ATOM #CMPLX;divby(2)
#define  CALCULARUNMEDIO    ;divby(2)
#synon   CALCULARUNMEDIO    OBTENERUNMEDIO,CALCULELAMITAD,OBTENGALAMITAD,UNMEDIO

#defn    TERCIO(_X_)    #ATOM #CMPLX;divby(3)
#define  CALCULARUNTERCIO   ;divby(3)
#synon   CALCULARUNTERCIO   OBTENERUNTERCIO,CALCULEUNTERCIO,OBTENGAUNTERCIO,UNTERCIO

#defn    CUARTO(_X_)    #ATOM #CMPLX;divby(4)
#define  CALCULARUNCUARTO   ;divby(4)
#synon   CALCULARUNCUARTO   OBTENERUNCUARTO,CALCULEUNCUARTO,OBTENGAUNCUARTO,UNCUARTO

/* macros trigonométricas */
#defn    RADIÁN(_X_)           #ATOM #CMPLX;d2r;
#defn    GRADO(_X_)            #ATOM #CMPLX;r2d;
#defn    ACOSH(_X_)            #ATOM #CMPLX;arccosh;
#defn    ASENH(_X_)            #ATOM #CMPLX;arcsinh;
#defn    ATANH(_X_)            #ATOM #CMPLX;arctanh;
#defn    ACOS(_X_)             #ATOM #CMPLX;arccos;
#defn    ASEN(_X_)             #ATOM #CMPLX;arcsin;
#defn    ATAN(_X_)             #ATOM #CMPLX;arctan;
#defn    COSH(_X_)             #ATOM #CMPLX;cosh;
#defn    SENH(_X_)             #ATOM #CMPLX;sinh;
#defn    TANH(_X_)             #ATOM #CMPLX;tanh;
#defn    COS(_X_)              #ATOM #CMPLX;cos;
#defn    SEN(_X_)              #ATOM #CMPLX;sin;
#defn    TAN(_X_)              #ATOM #CMPLX;tan;

/* DECLARACIONES DE ARRAYS */
//      NUEVO ARREGLO (10,10) CON CEROS PARA (X)
//      NUEVO ARREGLO( tamaño fijo ) ALEATORIO PARA ( aFijo )
#defn    RESERVAR(*)                     #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN,
#defn    POSICIONESNANPARA(*)           __TMPARR__=-1,nanarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    POSICIONESCONCEROSPARA(*)      __TMPARR__=-1,zerosarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    POSICIONESCONUNOSPARA(*)       __TMPARR__=-1,onesarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    POSICIONESIDENTIDADPARA(*)     __TMPARR__=-1,eyesarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#defn    POSICIONESALFANUMÉRICASPARA(*) {""},__TMPARR__=-1,fillarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    POSICIONESRELLENASCON(__F__,*) #ATOM#CMPLX,__TMPARR__=-1,fillarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,\
                                        cpy(#LIST);#ENDGEN,kill;
#defn    POSICIONESALEATORIASENTERAS(_M_,*)  __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),int,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
                                             
#defn    POSICIONESALEATORIASTECHO(_M_,*)    __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),ceil,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    POSICIONESALEATORIASPISO(_M_,*)     __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),floor,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    POSICIONESALEATORIASPARA(*)     __TMPARR__=-1,randarray(__TMPARR__),\
                                         #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn    POSICIONESVACÍASPARA(*)     __TMPARR__=-1,newarray(__TMPARR__),\
                                     #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;

/* CADENAS */
// Take(" ",20),PadC(var) para PadX
//#defn    CENTRAR(__SIZ__,__X__)     {" "};#ATOM#CMPLX;#ATOM#CMPLX;padcenter;
//#defn    JUSTIFICARALAIZQUIERDA(__SIZ__,__X__)      {" "};#ATOM#CMPLX;#ATOM#CMPLX;padleft;
//#defn    JUSTIFICARALADERECHA(__SIZ__,__X__)      {" "};#ATOM#CMPLX;#ATOM#CMPLX;padright;

// TOKENS:
#defn    ESTABLECERNUEVOSEPARADOR(__X__)     #ATOM#CMPLX;toksep;
#define  INICIARTOKENS     ___TOKEN___=0;
#defn    CONTARTOKENS(__X__)    ___V_827662___=0;#ATOM#CMPLX;mov(___V_827662___);totaltoken(___V_827662___);___TOKEN___=0;

#defn    OBTENERTOKEN(__V__)     {___TOKEN___};$(__V__);
#defn    REEMPLAZARTOKEN(__X__,__V__)    #ATOM#CMPLX;{___TOKEN___}$$(__V__);mov(__V__);gettoksep;{__V__};onechar;mov(__V__);
#defn    BORRARTOKEN(__V__)    {""}{___TOKEN___}$$(__V__);mov(__V__);gettoksep;{__V__};onechar;mov(__V__);
#defn    INTERCAMBIARTOKENS(_N_,__V__)      #ATOM#CMPLX;__T_SWP__=0;cpy(__T_SWP__);$(__V__);\
                                  {___TOKEN___};$(__V__);\
                                  {__T_SWP__}$$(__V__);mov(__V__);\
                                  {___TOKEN___}$$(__V__);mov(__V__);
#define  OBTENERSEPARADORACTIVO     gettoksep;
#defn    TOKEN(__X__)     #ATOM#CMPLX;mov(___TOKEN___)

/* SISTEMA */
#defn    PETICIÓN(_X_)   #ATOM#CMPLX;exec;
#defn    SISTEMA(_X_)    #ATOM#CMPLX;execv;

/* LISTAS */

#define  AÑADIRALISTA(_X_)    ;pushall(_X_)
#synon   AÑADIRALISTA     AÑADAALISTA
#define  AÑADIRUNAFILAA(_X_)    ;addrow(_X_)
#synon   AÑADIRUNAFILAA    AÑADAUNAFILAA

#define  METEREN(_X_)     ;push(_X_)
#synon   METEREN    METAEN
#define  SACARELPRIMERODESDE(_X_)     ;qpop(_X_)
#synon   SACARELPRIMERODESDE   SAQUEELPRIMERODESDE
#define  SACARELÚLTIMODESDE(_X_)    ;pop(_X_)
#synon   SACARELÚLTIMODESDE   SAQUEELÚLTIMODESDE 
#define  VERELPRIMERODE(_X_)    ;head(_X_)
#synon   VERELPRIMERODE    VEAELPRIMERODE
#define  VERELÚLTIMODE(_X_)    ;tail(_X_)
#synon   VERELÚLTIMODE    VEAELÚLTIMODE

#defn    VERNODO(_N_,_X_)     #ATOM#CMPLX;look(_X_)
#define  ESTÁVACÍO(_X_)    ;empty(_X_)
#synon   ESTÁVACÍO      ESVACÍA,SEAVACÍA
#defn    ELEMENTOSTOTALESDE(__X__)    #ATOM#CMPLX;length;
#define  OBTENERNÚMERODEELEMENTOSTOTALES    ;length;
// COLUMNAS Y FILAS DE ARRAYS 2D y 3D:
#define  OBTENERFILASDE(__X__)      ;getrow(__X__)
#define  OBTENERCOLUMNASDE(__X__)      ;getcol(__X__)
// estas dos no pueden ir dentro de Let:
#defn    UNIRFILASEN(__X__)   ;catrow(__X__)
#defn    UNIRCOLUMNASEN(__X__)   ;catcol(__X__)
// Las siguientes macros necesitan declarar [] con anterioridad: [n] GET-PAGE(v)
#define  OBTENERPÁGINADE(__X__)      getpage(__X__)
#synon   OBTENERPÁGINADE     OBTENGAPÁGINADE
#define  POBLARPÁGINAEN(__X__)      putpage(__X__)
#synon   POBLARPÁGINAEN      PUEBLEPÁGINAEN

// macros para devolver datos del array:
#define  DIMENSIÓN(__A__)     dims(__A__)
#define  FILAS(__A__)      rows(__A__)
#define  COLUMNAS(__A__)     cols(__A__)
#define  PÁGINAS(__A__)     pages(__A__)

// manipulacion de arrays
#define  OBTENERCELDASDE(_X_)   get(_X_)
#synon   OBTENERCELDASDE     OBTENGACELDASDE
#define  POBLARCELDASDE(_X_)    put(_X_)
#synon   POBLARCELDASDE      PUEBLECELDASDE

/* LIMPIEZA DE VARIABLES */
#define  LIMPIARINTERVALOS      ;clearinterval
#define  LIMPIARRANGOS     ;clearrange
#define  LIMPIARMARCAS     ;clearmark;
#define  LIMPIARTODASLASMARCAS    ;clearall;
#defn    LIMPIAR(*)     #GENCODE $$$*$$$ clear(#LIST);#ENDGEN;
#defn    RESETEAR(*)     {0}#GENCODE $$$*$$$ keep,mov(#LIST);#ENDGEN;kill;


/* ESTRUCTURAS DE CONTROL */
#defn    ITERADOR(_INC_,_REL_,*)  #RAND; _LOOP_#RNDV:;*;\
                                  _INC_;_REL_;jt(_LOOP_#RNDV);%RAND;

#defn    HACERMIENTRAS(__X__)              &( ) #LOOP:,#OPTIMLOG,#ATOM#CMPLX,#OPTIMLOG,jnt(#ENDLOOP)
// ESPECIAL "PARA":
#defn    DETENERCUANDO(_X_)               #OPTIMLOG;_X_;#OPTIMLOG;jt
//#defn    DETENERCUANDOSEANEGATIVO(_X_)    #OPTIMLOG;_X_;#OPTIMLOG;jneg
#defn    SEGUIRSI(_X_)                    #OPTIMLOG;_X_;#OPTIMLOG;jnt
#defn    HACERPARA(_X_,_Y_,_Z_)            &(_Z_) _X_,#LOOP:,_Y_(#ENDLOOP),

// para cada token dentro del string. Debe definirse antes TOKSEP para indicar separador de token.
#defn    HACERPARACADATOKEN(_Y_,_X_,_TT_)       #RAND, ##ENDLOOP &(++_EXPR2_#RNDV;--_EXPR_#RNDV;{_EXPR_#RNDV};jz(%%ENDLOOP)) , \
                                           _Y_="", _EXPR2_#RNDV=1, _EXPR_#RNDV=_TT_,{_TT_},jz(%%ENDLOOP),#LOOP: ,\
                                           {_EXPR2_#RNDV},$(_X_),mov(_Y_),%RAND;
// cada token extraído queda en memoria
#defn    PARACADATOKEN(_X_,_TT_)    #RAND, ##ENDLOOP &(++_EXPR2_#RNDV;--_EXPR_#RNDV;{_EXPR_#RNDV};jz(%%ENDLOOP)) , \
                                    _EXPR2_#RNDV=1, _EXPR_#RNDV=_TT_,{_TT_},jz(%%ENDLOOP),#LOOP: ,\
                                    {_EXPR2_#RNDV},$(_X_) %RAND;

// itera para cada caracter
#defn    HACERPARACADACARACTER(_Y_,_X_,_LEN_)      #RAND, ##ENDLOOP &(++_EXPRI_#RNDV;--_EXPRL_#RNDV;{_EXPRL_#RNDV};jz(%%ENDLOOP)),\
                                           {_LEN_},jz(%%ENDLOOP),_Y_="", _EXPRI_#RNDV=1, _EXPRL_#RNDV=_LEN_,\
                                           #LOOP:,[_EXPRI_#RNDV]get(_X_),mov(_Y_),%RAND;
//  cada caracter queda en memoria:
#defn    PARACADACARACTER(_X_,_LEN_)   #RAND, ##ENDLOOP &(++_EXPRI_#RNDV;--_EXPRL_#RNDV;{_EXPRL_#RNDV};jz(%%ENDLOOP)),\
                                       {_LEN_},jz(%%ENDLOOP),_EXPRI_#RNDV=1, _EXPRL_#RNDV=_LEN_,\
                                       #LOOP:,[_EXPRI_#RNDV]get(_X_) %RAND;


#defn    SIGUIENTE    %&,jmp(%LOOP),%ENDLOOP:,

#defn    HACER               &( )  #LOOP: ##ENDLOOP
#defn    HASTAQUE(__X__)         %& ,#OPTIMLOG,#ATOM#CMPLX,#OPTIMLOG, jnt(%LOOP), %ENDLOOP:
#defn    MIENTRAS(__X__)         %& ,#OPTIMLOG,#ATOM#CMPLX,#OPTIMLOG, jt(%LOOP), %ENDLOOP:

/* Quiebre condicionado de bucles FOR, WHILE y REPEAT*/
// subgrupo instrucciones lógicas para "exit if...": exit if 'v' is zero
#defn    SALIRSINOESCERO(__X__)        #ATOM#CMPLX,jnz(%%ENDLOOP)
#defn    SALIRSIESCERO(__X__)        #ATOM#CMPLX,jz(%%ENDLOOP)
#defn    SALIRSIESFALSO(__X__)        #ATOM#CMPLX,jnt(%%ENDLOOP)
#defn    SALIRSIESVERDADERO(__X__)        #ATOM#CMPLX,jt(%%ENDLOOP)
#defn    SALIRSINOESNULO(__X__)        #ATOM#CMPLX,jnv(%%ENDLOOP)
#defn    SALIRSIESNULO(__X__)        #ATOM#CMPLX,jv(%%ENDLOOP)
#defn    SALIRSIESNEGATIVO(__X__)        #ATOM#CMPLX,jneg(%%ENDLOOP)
#defn    SALIRSIESPOSITIVO(__X__)        #ATOM#CMPLX,jpos(%%ENDLOOP)
#defn    SALIRSIESINFINITO(__X__)        #ATOM#CMPLX,inf?,jt(%%ENDLOOP)
#defn    SALIRSIESNAN(__X__)        #ATOM#CMPLX,nan?,jt(%%ENDLOOP)
#defn    SALIRSITIENENAN(__X__)        #ATOM#CMPLX,stats(0),nan?,jt(%%ENDLOOP)
#defn    SALIRSIESTECLAENTER(__X__)        #ATOM#CMPLX,eqto(13),jt(%%ENDLOOP)
#defn    SALIRSIESTECLAESCAPE(__X__)        #ATOM#CMPLX,eqto(27),jt(%%ENDLOOP)
#defn    SALIRSIESTÁVACÍO(__X__)        #ATOM#CMPLX,isempty,jt(%%ENDLOOP)

/* otros bucles */
#defn    ITERAR                     &( ) ##ENDLOOP #LOOP:,

// ESPECIFICOS:
#defn    CONTINUARSIESMENOROIGUAL(_X_,_Y_)     #ATOM#CMPLX;#ATOM#CMPLX;jle(%LOOP),%ENDLOOP:,
#defn    CONTINUARSIESMENOR(_X_,_Y_)           #ATOM#CMPLX;#ATOM#CMPLX;jlt(%LOOP),%ENDLOOP:,
#defn    CONTINUARSIESMAYOROIGUAL(_X_,_Y_)     #ATOM#CMPLX;#ATOM#CMPLX;jge(%LOOP),%ENDLOOP:,
#defn    CONTINUARSIESMAYOR(_X_,_Y_)           #ATOM#CMPLX;#ATOM#CMPLX;jgt(%LOOP),%ENDLOOP:,
#defn    CONTINUARSISONIGUALES(_X_,_Y_)        #ATOM#CMPLX;#ATOM#CMPLX;jeq(%LOOP),%ENDLOOP:,
#defn    CONTINUARSISONDISTINTOS(_X_,_Y_)      #ATOM#CMPLX;#ATOM#CMPLX;jneq(%LOOP),%ENDLOOP:,

#defn    CONTINUARSI(_X_)    #ATOM#CMPLX;
#defn    ESVERDADERO     jt(%LOOP),%ENDLOOP:,
#defn    ESFALSO    jnt(%LOOP),%ENDLOOP:,
#defn    NOESCERO     jnz(%LOOP),%ENDLOOP:,
#defn    ESCERO    jz(%LOOP),%ENDLOOP:,
#defn    NOESNULO     jnv(%LOOP),%ENDLOOP:,
#defn    ESNULO    jv(%LOOP),%ENDLOOP:,
#defn    ESPOSITIVO     jpos(%LOOP),%ENDLOOP:,
#defn    ESNEGATIVO     jneg(%LOOP),%ENDLOOP:,

/* Quiebre de ciclos */
#defn    CONTINUAR     %%&, jmp(%%LOOP)
#defn    QUEBRAR      jmp(%%ENDLOOP)

/* SELECCION EN UNA LINEA */
#defn    ELEGIRSI(_X_,_Y_,_Z_)        #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:

/* TRY/CATCH */
#defn    INTENTAR                     swtrap( #CATCH ),
#defn    LEVANTARERROR(_ERR_,_M_)     {_M_}, throw(_ERR_),
#defn    EXCEPCIÓN(_X_)               jmp(#ENDCATCH), %CATCH:, clearstack,_X_=0,gettry(_X_),  // gettry hace poptry internamente?
#defn    LIBERARINTENTO               popcatch    // usar si se escapa de TRY con salto
#defn    FINDELINTENTO                %ENDCATCH:,popcatch
#define  MENSAJEDEERROR               ;getstrerror;
//
#defn    SINOSI(__X__)           jmp(%%CODEIF), %ENDIF:, #OPTIMLOG, #ATOM#CMPLX ,#OPTIMLOG, jnt(#ENDIF),
#defn    SI(__X__)            ##CODEIF, #OPTIMLOG, #ATOM#CMPLX ,#OPTIMLOG, jnt(#ENDIF),
#defn    SINO                 jmp(%%CODEIF), %ENDIF:, true,jnt(#ENDIF),
#defn    FINSI                %CODEIF:, %ENDIF:,

/* Sswitch */
#defn    SELECCIONARCUANDO(_X_)    ##CODESW,##CODEMRK;%%MARK=0,#ATOM#CMPLX,mov(%%MARK)
#defn    SEA(_X_)     #ATOM#CMPLX,{%%MARK}eq?,do
#defn    ESTÉDENTRODE(_X_,_Y_)    #ATOM#CMPLX,{%%MARK}ge?,#ATOM#CMPLX,{%%MARK}le?,and,do
#defn    OCURRAEXACTAMENTEEN(_X_)    {_X_}{%%MARK}ecin?,do
#defn    OCURRAEN(_X_)    {_X_}{%%MARK}cin?,do
#defn    ESTÉENLALISTA(_X_)    {%%MARK}{_X_}array(1),do
#defn    SALIR     jmp(%%CODESW),
///#defn    Freeswitch          ipop(_VTMP09828),clear(_VTMP09828),
#defn    FINDESELECCIÓN    %CODESW:,%MARK:,

// DESVIO DE EJECUCION:
#defn    CUANDO(_X_)    #ATOM#CMPLX,do


/* ENCABEZADOS DE PROGRAMA Y PROCEDIMIENTOS */
#define  SUBRUTINAS     .locals
#define  SEPUEDEABORTAR    .ctrlc
#define  TAMAÑODEMEMORIA    .stack
#defn    RETORNAR(_X_)    #ATOM#CMPLX;back;
#define  RETORNAR     back
#define  FINALIZAR     {0}return
#synon   FINALIZAR     ABORTAR,FIN
#define  NL   "\n"
#define  TAB    "\t"
#define  TABULAR  {"\t"}
#define  NUEVALÍNEA  {"\n"}

#defn    INICIAR(_V_,_N_)     #RAND, main:,V#RNDV=1,_V_={#VOID}, \
                             _N_=0,totalarg,mov(_N_), \
                             LOOPGETARG_#RNDV:, {[ V#RNDV ]},push(_V_),++V#RNDV,\
                             {V#RNDV,_N_},jle(LOOPGETARG_#RNDV),clear(V#RNDV),%RAND;
#synon   INICIAR             INICIO,INICIECON
#define  INICIAR:            main:
#define  INICIO:             main:
#defn    PARÁMETROS(*)       #GENCODE $$$*$$$ #LIST=0,{[#ITV]},mov(#LIST);#ENDGEN,
#define  RECIBIRPARÁMETRONUMÉRICO(_N_)       {[_N_]};xtonum;
#define  RECIBIRPARÁMETROALFANUMÉRICO(_N_)       {[_N_]};
#define  TOTALDEPARÁMETROS   totalarg;
#define  HAYPARÁMETROS?      totalarg,{1},gt?,do

#defn    FUNCIÓN(_F_,*)      _F_:,#GENCODE $$$*$$$ #REVLIST=0;mov(#REVLIST);#ENDGEN;
#synon   FUNCIÓN             PROCEDIMIENTO

#defn    LLAMARUNAOPCIÓN(*)       #GENCODE $$$*$$$ {#ITV}keep,eq? do{kill,jsub(#LIST),jmp(#HERE)},#ENDGEN
#defn    REALIZARUNAOPCIÓN(*)       #GENCODE $$$*$$$ {#ITV}keep,eq? do{kill,#LIST,jmp(#HERE)},#ENDGEN
#define  EJECUTAR(__X__)      jsub(__X__)
#synon   EJECUTAR            CALCULAR,PROCESAR

/* manejo de memoria */
#defn    DUPLICAR(__X__)     ;#ATOM#CMPLX;dup;
#define  DUPLICARESTO        ;dup;
#define  DUPUPLICAR          ;dup;
#define  RETENER(__X__)      ;keep(__X__)
#define  RETENER             ;keep;
#define  OLVIDARTODO         ;clearstack;
#define  OLVIDAR             ;kill;

// METER DATOS EN MEMORIA
#defn    TOMAR(*)            #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;
#synon   TOMAR               CONESTO,CON,ESTO
#define  VAR(_X_)            {_X_}
#synon   VAR                 CTE

// si no se cumple la expresión, no mueve y deja el dato en el stack
#defn    GUARDARSI(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);mov(_Y_);jmp(#ENDIF);%ENDIIF:;mov(_Z_);%ENDIF:
#defn    COPIARSI(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);cpy(_Y_);jmp(#ENDIF);%ENDIIF:;cpy(_Z_);%ENDIF:
// mueve un valor a una variable, si se cumple una condicion; sino, la deja intacta, pero el valor se pierde de la memoria:
// Move on( Equals(i,1), w )
#defn    GUARDARSOLOSI(_X_,_V_)       #ATOM#CMPLX;jnt(#ENDIIF);mov(_V_);jmp(#ENDIF);%ENDIIF:;kill;%ENDIF:
// copia el valor si se cumple la condicion; sino, pasa, pero el valor queda en memoria.
// .... Copy on(Equals(i,1), w), ...
#defn    COPIARSOLOSI(_X_,_V_)       #RAND;#ATOM#CMPLX;jnt(__CPY#RNDV__);cpy(_V_);__CPY#RNDV__:;%RAND

// ASIGNAR Y COPIAR
#define  COPIEEN(_X_)           ;cpy(_X_)
#synon   COPIEEN                RESPALDEEN,HAGAUNACOPIAEN

// MUEVE SIMETRICAMENTE VALORES EN MEMORIA, A LA(S) VARIABLES:
#defn    GUARDAREN(*)           #GENCODE $$$*$$$ mov(#REVLIST);#ENDGEN,
#synon   GUARDAREN              DEJAREN
// copia un solo valor a muchas variables. QUITA EL valor DE LA memoria:
#defn    COPIAREN(*)            #GENCODE $$$*$$$ cpy(#REVLIST);#ENDGEN,kill;
#synon   COPIAREN               RESPALDAREN

// mueve simétricamente #valores a un #de variables:
#define  EN(_X_)                (_X_)
// mueve simétricamente #valores a un #de variables:
#defn    GUARDAR(*)             #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;__MOVING__
#synon   GUARDAR                DEJAR
#defn    __MOVING__(*)          #GENCODE $$$*$$$ mov(#REVLIST);#ENDGEN;

// copia un solo valor a muchas variables. QUITA EL valor DE LA memoria:
#defn    COPIAR(*)              #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;__COPYING__
#synon   COPIAR                 RESPALDAR
#defn    __COPYING__(*)         #GENCODE $$$*$$$ cpy(#REVLIST);#ENDGEN;kill;

/* entrada y salida */

#defn    UBICARFILA(_X_)    ;#ATOM#CMPLX;gox;
#defn    UBICARCOLUMNA(_X_)    ;#ATOM#CMPLX;goy;
#defn    UBICAR(_X_,_Y_)    ;#ATOM#CMPLX;#ATOM#CMPLX;goxy;

#defn    IMPRIMIRTABLA(__M__)       #ATOM#CMPLX;{___X___}{___Y___};print2d;
#defn    IMPRIMIRFORMATO(__X__,*)   #RAND;__C__#RNDV=0;#ATOM#CMPLX;mov(__C__#RNDV);#GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;\
                                    sjoin;{","}format(__C__#RNDV);print;%RAND;
#defn    IMPRIMIRCONSEPARADOR(*)    #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;printusingtoken;
#defn    IMPRIMIRCONSALTO(*)     #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;{"\n"}print;
#define  IMPRIMIRCONSALTO        {"\n"}print;
#define  SALTAR      {"\n"}print
#defn    IMPRIMIRSI(_X_,_Y_,_Z_)    #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:;print
#defn    IMPRIMIR(*)     #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;print;
#define  IMPRIMIRESTO(_X_)     ;puts(_X_)
#define  IMPRIMIRESTOÚLTIMO    ;puts;
#define  IMPRIMIR    ;print;

// ENTRADA Y TECLADO:
#defn    CAPTURARCARACTEREN(_X_)   #RAND,pause,lastkey(_X_),{_X_}{194}{1}{207}{1}between?,do{{_X_}chr,pause,\
                                   lastkey(_X_),{_X_}chr,cat,utf8tostr,jmp(__GETCHAR__#RNDV)},\
                                   {_X_}chr,utf8tostr,__GETCHAR__#RNDV:,mov(_X_),kbfree,%RAND;
#defn    CAPTURARTECLA    #RAND;_VCH#RNDV_=0;__GETCHAR__#RNDV:;pause;lastkey(_VCH#RNDV_);{_VCH#RNDV_}\
                          dup;{194}{1}{207}{1}between?;do{jmp(__GETCHAR__#RNDV)};kbfree;%RAND;
#defn    PONERTECLA(__X__)    #ATOM#CMPLX;keyput;
#defn    OBTENERCÓDIGODETECLA(_X_)   #RAND,lastkey(_X_),{_X_}{194}{1}{207}{1}between?,do{{_X_}chr,pause,\
                                     lastkey(_X_),{_X_}chr,cat,utf8tostr,jmp(__GETCHAR__#RNDV)},\
                                     {_X_}chr,utf8tostr,__GETCHAR__#RNDV:,asc,mov(_X_),kbfree,%RAND;
/* EOF*/
