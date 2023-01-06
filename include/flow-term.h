

// macros de control de terminal 
//   Solo puede usar argumentos atómicos, no expresiones, y en el caso de los colores,
//   dependerá del tipo de terminal. En el mío funciona.

// necesita Locate para localizar el cursor.
#defn   FILL-BOX(_C_,_H_,_W_)  #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;fillbox;
// borra hacia abajo (0), hacia arriba(1), todo(2)
#defn   CLR-SECT(_X_)          {"\033["},#ATOM#CMPLX,{"J"}, print;
// borra hacia derecha (0), hacia izquierda(1), toda la linea(2)
#defn   CLR-LINE(_X_)          {"\033["},#ATOM#CMPLX,{"K"}, print;

#define SCRLL-DOWN             {"\033D"},print;
#define SCRLL-UP               {"\033M"},print;
#defn   SET-SCRLL(_X_,_Y_)     {"\033["},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{"r"},print;
#define SCRLL-RESET            {"\033[r"},print;
#defn   NEXT-LINS(_X_)         {"\033["},#ATOM#CMPLX,{"E"},print;
#defn   PREV-LINS(_X_)         {"\033["},#ATOM#CMPLX,{"F"},print;

#defn   RESIZ-TERM(_X_,_Y_)    {"\033[8;"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{"t"},print  // cambia dimensiones del terminal
#define SIZE-TERM(_X_,_Y_)     getsizscr,mov(_X_),mov(_Y_)  // devuelve: (col, row)

#define CUR-SAVE            {"\0337"},print;
#define CUR-REST            {"\0338"},print;
#define SCR-SAVE            {"\033[?1049h\033[H"},print;
#define SCR-REST            {"\033[?1049l"},print;

#define SET-VIDEO-GRAPH(_X_)        SYS(CAT(CAT("gsettings set org.gnome.Terminal.Legacy.Profile:/org/gnome/terminal/legacy/profiles:/:b1dcc9dd-5262-4d8d-a863-c897e6d979b9/ font 'Ubuntu Mono ",STR(_X_)),"'"))
#define SET-VIDEO-TEXT              SYS("gsettings set org.gnome.Terminal.Legacy.Profile:/org/gnome/terminal/legacy/profiles:/:b1dcc9dd-5262-4d8d-a863-c897e6d979b9/ font 'Ubuntu Mono 12'")

#defn   COLOR-RGBF(_X_,_Y_,_Z_)  {"\033[38;2;"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{"m"}print;
#defn   COLOR-RGBB(_X_,_Y_,_Z_)  {"\033[48;2;"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{"m"}print;

#define CNVS-PAPER             {"\033[48;2;227;216;181m"}print;
//COLOR-RGBB(227,216,181)
#define CNVS-TERMINAL          {"\033[48;2;7;27;4m"}print;
//COLOR-RGBB(7,27,4)
#define CNVS-OLD               {"\033[48;2;60;6;19m"}print;
//COLOR-RGBB(60,6,19)
#define CNVS-OCEAN             {"\033[48;2;72;136;216m"}print;
//COLOR-RGBB(72,136,216)
#define WHITE-PEN              {"\033[38;2;255;255;255m"}print;
//COLOR-RGBF(255,255,255)
#define BLACK-PEN              {"\033[38;2;30;27;10m"}print;
//COLOR-RGBF(30,27,10)
#define AMBER-PEN              {"\033[38;2;243;135;13m"}print;
//COLOR-RGBF(243,135,13)
#define GREEN-PEN              {"\033[38;2;121;192;35m"}print;
//COLOR-RGBF(121,192,35)

// TYPO FLOW: ATRIBUTOS DE PANTALLA:

#define  GET-SIZE-TERM              ;getsizscr;
#define  SET-INVERSE-OFF            {"\033[27m"}print;
#define  SET-INVERSE                {"\INV"}print;
#define  SET-BOLD-OFF               {"\033[22m"}print;
#define  SET-BOLD                   {"\ENF"}print;
#define  SET-ITALIC-OFF             {"\033[23m"}print;
#define  SET-ITALIC                 {"\CUR"}print;
#define  SET-UNDER-LINE-OFF         {"\033[24m"}print;
#define  SET-UNDER-LINE             {"\UL"}print;

