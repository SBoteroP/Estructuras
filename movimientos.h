#ifndef MOVIMIENTOS__H__
#define MOVIMIENTOS__H__

#include <list>
#include <iostream>
#include <string>

using namespace std;

class Movimiento
{
protected:
    string tipo_mov;
    int magnitud;
    string unidad_med;
    
public: 
    Movimiento(string tipo,int magnitud, string unidad);
    string getTipo_mov();  
    string getUnidad();  
    int geMagnitud();
    void setTipo_mov(string nTipo);
    void setMagnitud(string nMag);
    void setUnidad(string nUnidad);  
    void agregar_movimiento(string tipo,double magnitud,string unidad);
};

#include "movimientos.hxx"
#endif