#ifndef ROBOT__H__
#define ROBOT__H__

struct Robot
{
    int x;
    int y;
    int direccion = 0; // in degrees

    // Getters
    int getX();
    int getY();
    int getDireccion();

    // Setters
    void setX(int nx);
    void setY(int ny);
    void setDireccion(int ndireccion);
    void moverRobot();
    
};
#include "robot.hxx"
#endif // ROBOT_H
