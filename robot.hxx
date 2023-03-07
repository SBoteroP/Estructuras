#ifndef __ROBOT__HXX__
#define __ROBOT__HXX__

#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <string.h>

// Getters
int Robot::getX()
{
    return (x);
}

int Robot::getY()
{
    return (y);
}

int Robot::getDireccion()
{
    return (direccion);
}

// Setters
void Robot::setX(int nx)
{
    x = nx;
}

void Robot::setY(int ny)
{
    y = ny;
}

void Robot::setDireccion(int ndireccion)
{
    direccion = ndireccion;
}


#endif