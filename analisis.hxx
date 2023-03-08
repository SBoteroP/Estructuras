#ifndef __ANALISIS__HXX__
#define __ANALISIS__HXX__

#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <string.h>

//----------------------------------------------------------------------------
string Analisis::getTipo()
{
	return (tipo);
}
//----------------------------------------------------------------------------
void Analisis::setTipo(string nTipo)
{
	tipo = nTipo;
}
//----------------------------------------------------------------------------
string Analisis::getObjeto()
{
	return (objeto);
}
//----------------------------------------------------------------------------
void Analisis::setObjeto(string nObjeto)
{
	objeto = nObjeto;
}
//----------------------------------------------------------------------------
string Analisis::getCom()
{
	return (comentario);
}
//----------------------------------------------------------------------------
void Analisis::setCom(string nCom)
{
	comentario = nCom;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

Analisis agregar_analisis(string tipo, string objeto, string comentario)
{
	/*
		char* start = strchr(iString, '\''); // find first occurrence of '
		if (start == nullptr) {
			cout << "Error: input string does not contain starting ' character" << endl;
			return;
		}
		start++; // move pointer to next character

		char* end = strchr(start, '\''); // find second occurrence of '
		if (end == nullptr) {
			cout << "Error: input string does not contain ending ' character" << endl;
			return;
		}

		int length = end - start; // calculate length of substring
		strncpy(oString, start, length); // copy substring to output string
		oString[length] = '\0'; // add null terminator to end of output string
	*/
	while (objeto != "roca" && objeto != "monticulo" && objeto != "duna" && objeto != "crater")
	{
		std::cout << "El tipo de objeto no es válido." << std::endl;
		system("Pause");
	}

	if (tipo != "fotografiar" && tipo != "composicion" && tipo != "perforar")
	{
		std::cout << "Error: tipo de análisis inválido" << std::endl;
		system("Pause");
	}
	/*
		while (comentario[0] != '\'' || comentario[strlen(comentario) - 1] != '\'')
		{
			std::cout << "Error: comentario debe comenzar y terminar con comilla simple" << std::endl;
		}
	*/
	std::cout << "NUEVO ANALISIS GUARDADO CON EXITO" << std::endl;

	Analisis NA;
	NA.setCom(comentario);
	NA.setObjeto(objeto);
	NA.setTipo(tipo);

	return NA;
}
#endif
