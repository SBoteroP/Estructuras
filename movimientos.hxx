#ifndef __MOVIMIENTOS__HXX__
#define __MOVIMIENTOS__HXX__


//----------------------------------------------------------------------------
int Movimiento::getTipo_mov()
{
	return(Tipo_mov);
}
//----------------------------------------------------------------------------
void Movimiento::setTipo_mov(string tipo_mov)
{
	tipo_mov = tipo_mov;
}
//----------------------------------------------------------------------------
int Magnitud::geMagnitud()
{
	return(Magnitud);
}
//------------    ----------------------------------------------------------------
void Magnitud::setMagnitud(int magnitud)
{
	magnitud = magnitud;
}
//----------------------------------------------------------------------------
int Unidad::getUnidad()
{
	return(Unidad);
}
//----------------------------------------------------------------------------
void Unidad::setUnidad(int Punto)
{
	Unidad = Unidad;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
 void agregar_movimiento(string tipo,double magnitud,string unidad);
{
	PuntoR3 = Punto;
}

#endif