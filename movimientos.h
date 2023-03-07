#ifndef MOVIMIENTOS__H__
#define MOVIMIENTOS__H__

#include <list>
#include <iostream>
#include <string>

using namespace std;

struct Movimiento
{
    string tipo_mov;
    int magnitud;
    string unidad_med;

    string getTipo_mov();
    string getUnidad();
    int getMagnitud();
    void setTipo_mov(string nTipo);
    void setMagnitud(int nMag);
    void setUnidad(string nUnidad);
    Movimiento agregar_movimiento(string tipo, int magnitud, string uni);
};

#include "movimientos.hxx"
#endif