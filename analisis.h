#ifndef ANALISIS__H__
#define ANALISIS__H__

#include <list>
#include <iostream>
#include <string>

using namespace std;

class analisis
{
protected:
    string tipo;
    string objeto;
    string comentario;

public:
    analisis(string tipo, string objeto, string comentario);
    string getTipo();
    string geObjeto();
    string getCom();
    void setTipo(string nTipo);
    void setObjeto(string nObjeto);
    void setCom(string nCom);
    void agregar_analisis(string tipo, string objeto, string comentario);
};

#include "Analisis.hxx"
#endif