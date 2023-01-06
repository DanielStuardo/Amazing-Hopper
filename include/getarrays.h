
#proto i3D(_X_,_I_,_E_,_Y_,_I2_,_E2_,_Z_,_I3_,_E3_)
#proto i2D(_X_,_I_,_E_,_Y_,_I2_,_E2_)
#synon _i2D     _iplane,_ipoint

#proto i1D(_X_,_I_,_E_)
#proto 3D(_X_,_E_,_Y_,_E2_,_Z_,_E3_)
#proto 2D(_X_,_E_,_Y_,_E2_)
#synon _2D      _rplane,_rpoint

#proto 1D(_X_,_E_)

/* Acceso por dimension */
#defn  _irow(_X_,_I_,_F_) #ATOM#CMPLX,loc1,#ATOM#CMPLX,interval1,#ATOM#CMPLX,offset1,
#synon _irow              _ipag,_irange
#defn  _rrow(_X_,_F_)     #ATOM#CMPLX,loc1,#ATOM#CMPLX,offset1,
#synon _rrow              _rpag,_range
#defn  _row(_X_)          #ATOM#CMPLX,loc1,
#synon _row               _pag,_locate
//
#defn _plane(_X_,_Y_)     #ATOM#CMPLX,#ATOM#CMPLX,loc2,
#synon _plane             _point
// algunas macros especiales
// páginas impares (filas y posiciones en array)
#defn    _oddpagesfrom(_X_)  [_X_:end],{2}interval1
#synon   _oddpagesfrom       _oddrowsfrom,_oddlocatefrom
#define  _oddpages           [1:end],{2}interval1,
#synon   _oddpages           _oddrows,_oddlocate
// páginas pares  (filas y posiciones en array)
#defn    _evenpagesfrom(_X_)  [_X_:end],{2}interval1
#synon   _evenpagesfrom       _evenrowsfrom,_evenlocatefrom
#define  _evenpages           [2:end],{2}interval1, //{2}loc1,{2}interval1,{end}offset1
#synon   _evenpages           _evenrows,_evenlocate

