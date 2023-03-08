#ifndef ANALISIS__H__
#define ANALISIS__H__

#include <list>
#include <iostream>
#include <string>

using namespace std;

struct Analisis
{
    string tipo;
    string objeto;
    string comentario;

    string getTipo();   
    void setTipo(string nTipo);
    string getObjeto();
    void setObjeto(string nObjeto);
    string getCom();
    void setCom(string nCom);
    Analisis agregar_analisis(string tipo, string objeto, string comentario);
};

#include "analisis.hxx"
#endif