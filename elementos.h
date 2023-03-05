#ifndef ELEMENTOS__H__
#define ELEMENTOS__H__

#include <list>
#include <iostream>
#include <string>

using namespace std;

class Elemento
{
protected:
    string tipo_comp;
    double tamano = 0;
    string unidad_med;
    int coordx;
    int coordy;

public:
    Elemento(string tipo, double tam, string unidad, int x, int y);
    string getTipo_comp();
    double geTamano();
    string getUnidad();
    int getCoordx();
    int getCoordy();
    void setTipo_comp(string nTipo);
    void setTamano(string nTam);
    void setUnidad(string nUnidad);
    void setCoordx(int nX);
    void setCoordy(int nY);
    void agregar_elementos(string tipo, double tam, string unidad, int x, int y);
    void cargar_elementos();
};

#include "Elementos.hxx"
#endif