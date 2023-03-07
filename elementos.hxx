#ifndef __ELEMENTOS__HXX__
#define __ELEMENTOS__HXX__

#include <vector>
#include <list>
#include <iostream>
#include <string>

double Elemento::getTamano()
{
	return (tamano);
}
//----------------------------------------------------------------------------
void Elemento::setTamano(double nTam)
{
	tamano = nTam;
}
//----------------------------------------------------------------------------
string Elemento::getTipo_comp()
{
	return (tipo_comp);
}
//----------------------------------------------------------------------------
void Elemento::setTipo_comp(string nTipo)
{
	tipo_comp = nTipo;
}
//----------------------------------------------------------------------------
string Elemento::getUnidad()
{
	return (unidad_med);
}
//----------------------------------------------------------------------------
void Elemento::setUnidad(string nUnidad)
{
	unidad_med = nUnidad;
}
//----------------------------------------------------------------------------
int Elemento::getCoordx()
{
	return (coordx);
}
//----------------------------------------------------------------------------
void Elemento::setCoordx(int nX)
{
	coordx = nX;
}
//----------------------------------------------------------------------------
int Elemento::getCoordy()
{
	return (coordy);
}
//----------------------------------------------------------------------------
void Elemento::setCoordy(int nY)
{
	coordy = nY;
}
//----------------------------------------------------------------------------

Elemento agregar_elementos(string tipo, double tam, string unidad, int x, int y)
{
	while (tipo != "roca" && tipo != "monticulo" && tipo != "duna" && tipo != "crater")
	{
		std::cout << "El tipo de componente no es válido." << std::endl;
		system("Pause");
	}

	// Verificar unidad_med
	while (unidad != "unidades")
	{
		std::cout << "La unidad de medida no es válida." << std::endl;
		system("Pause");
	}

	// Store the input values if everything is correct
	cout << "NUEVO ELEMENTO GUARDADO CON EXITO" << endl;

	Elemento NE;
	NE.setTipo_comp(tipo);
	NE.setTamano(tam);
	NE.setUnidad(unidad);
	NE.setCoordx(x);
	NE.setCoordy(y);

	return NE;
}

#endif // __ELEMENTOS__HXX__
