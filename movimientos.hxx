#ifndef __MOVIMIENTOS__HXX__
#define __MOVIMIENTOS__HXX__

#include <vector>
#include <iostream>

//----------------------------------------------------------------------------
string Movimiento::getTipo_mov()
{
	return (tipo_mov);
}
//----------------------------------------------------------------------------
void Movimiento::setTipo_mov(string ntipo)
{
	tipo_mov = ntipo;
}
//----------------------------------------------------------------------------
int Movimiento::getMagnitud()
{
	return (magnitud);
}
//------------    ----------------------------------------------------------------
void Movimiento::setMagnitud(int nMag)
{
	magnitud = nMag;
}
//----------------------------------------------------------------------------
string Movimiento::getUnidad()
{
	return (unidad_med);
}
//----------------------------------------------------------------------------
void Movimiento::setUnidad(string nUnidad)
{
	unidad_med = unidad_med;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

Movimiento agregar_movimiento(string tipo, int magnitud, string uni)
{
	if (tipo != "avanzar" && tipo != "girar")
	{
		std::cout << "El valor de 'tipo' debe ser 'avanzar' o 'girar'" << std::endl;
		system("Pause");
	}

	if (tipo == "girar" && magnitud % 45 != 0)
	{
		std::cout << "El valor de 'magnitud' debe ser múltiplo de 45 si 'tipo' es 'girar'" << std::endl;
		system("Pause");
	}

	if (uni != "grados" && uni != "unidades")
	{
		std::cout << "El valor de 'uni' debe ser 'grados' si 'tipo' es 'girar' o 'unidades' si 'tipo' es 'avanzar'" << std::endl;
		system("Pause");
	}

	// Store the input values if everything is correct
	cout << "NUEVO MOVIMIENTO GUARDADO CON EXITO" << endl;

	Movimiento NM;
	NM.setMagnitud(magnitud);
	NM.setTipo_mov(tipo);
	NM.setUnidad(uni);

	return NM;
}
#endif
