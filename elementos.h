#ifndef ELEMENTOS__H__
#define ELEMENTOS__H__

#include <list>
#include <iostream>
#include <string>

using namespace std;

struct Elemento
{

    string tipo_comp;
    double tamano;
    string unidad_med;
    int coordx;
    int coordy;

    string getTipo_comp();
    void setTipo_comp(string nTipo);

    double getTamano();
    void setTamano(double nTam);

    string getUnidad();
    void setUnidad(string nUnidad);

    int getCoordx();
    void setCoordx(int nX);

    int getCoordy();
    void setCoordy(int nY);

    void agregar_elementos(string tipo, double tam, string unidad, int x, int y);
};

#include "elementos.hxx"
#endif