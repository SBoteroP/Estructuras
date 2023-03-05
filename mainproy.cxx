#include <iostream>
#include "movimientos.h"
// #include "analisis.h"
#include <string.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Error de ingreso de comando
    if (argc < 1)
    {
        std::cout << "El comando ingresado no se reconoce";
        return (-1);
    }
    // Declaracion de arreglos y variables

    const char *ArNA[] = {"ayuda", "cargar_comandos", "cargar_elementos", "agregar_movimiento", "agregar_analisis", "agregar_elemento", "guardar", "simular_comandos", "salir", "ubicar_elementos", "en_cuadrante", "crear_mapa", "ruta_mas_larga"};
    bool *Comp = new bool;
    *Comp = false;
    // std::vector<Mesh> Figuras;
    // std::vector<Envolvente> vectEnv;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "                     ROVER DE MARTE         " << std::endl;
    std::cout << std::endl;
    std::cout << "Para consultar los comandos del sistema ingrese el comando 'ayuda'" << std::endl;
    std::cout << "Para consultar el funcionamiento de un comando ingrese 'ayuda nombre_comando'" << std::endl;
    std::cout << "Ingrese el comando de ejecucion despues del simbolo $" << std::endl;

    do
    {
        int *Contador = new int;
        int *C = new int;
        int *E = new int;
        char *DComand[5];
        char *Comand = new char[50];
        // Ingreso de comandos
        std::cout << "\n$";
        std::cin.getline(Comand, 50);
        // Transcripcion de cin a argv
        char *cmP = strtok(Comand, " ");
        *Contador = 0;
        while (cmP != NULL)
        {
            DComand[*Contador] = cmP;
            cmP = strtok(NULL, " ");
            *Contador = *Contador + 1;
        }
        // Comparacion de argv con directorio de comandos
        for (int i = 0; i < 11; i++)
        {
            if (strcmp(DComand[0], ArNA[i]) == 0)
            {
                *C = i;
            }
        }
        switch (*C)
        {
        case 0:
        {
            // Lista de comandos con sintaxis
            if (*Contador == 1)
            {
                std::cout << "Ejecucion Correcta" << std::endl;
                std::cout << std::endl;
                std::cout << "LISTA DE COMANDOS DEL PROGRAMA" << std::endl;
                std::cout << std::endl;
                std::cout << "Manejo de información" << std::endl;
                std::cout << std::endl;
                std::cout << "Comando: cargar_comandos      -----------> Syntaxis: cargar_comandos nombre_archivo " << std::endl;
                std::cout << "Comando: cargar_elementos     -----------> Syntaxis: cargar_elementos nombre_archivo " << std::endl;
                std::cout << "Comando: agregar_movimiento   -----------> Syntaxis: agregar_movimiento tipo_mov magnitud unidad_med " << std::endl;
                std::cout << "Comando: agregar_analisis     -----------> Syntaxis: agregar_analisis tipo_analisis objeto comentario " << std::endl;
                std::cout << "Comando: agregar_elemento     -----------> Syntaxis: agregar_elemento tipo_comp tamaño unidad_med coordX coordY " << std::endl;
                std::cout << "Comando: guardar              -----------> Syntaxis: guardar tipo_archivo nombre_archivo " << std::endl;
                std::cout << "Comando: simular_comandos     -----------> Syntaxis: simular_comandos coordX coordY " << std::endl;
                std::cout << "Comando: salir                -----------> Syntaxis: salir " << std::endl;
                std::cout << std::endl;
                std::cout << "Planeación de desplazamientos" << std::endl;
                std::cout << std::endl;
                std::cout << "Comando: ubicar_elementos     -----------> Syntaxis: ubicar_elementos " << std::endl;
                std::cout << "Comando: Vertice Cercano      -----------> Syntaxis: en_cuadrante coordX1 coordX2 coordY1 coordY2 " << std::endl;
                std::cout << std::endl;
                std::cout << "Recorridos entre puntos de interés" << std::endl;
                std::cout << std::endl;
                std::cout << "Comando: crear_mapa           -----------> Syntaxis: crear_mapa coeficiente_conectividad " << std::endl;
                std::cout << "Comando: ruta_mas_larga       -----------> Syntaxis: ruta_mas_larga " << std::endl;

                std::cout << std::endl;
            }
            // Ayuda especifica con un comando
            if (*Contador == 2)
            {
                std::cout << "Ejecucion Correcta" << std::endl;
                for (int i = 0; i < 11; i++)
                {
                    if (strcmp(DComand[1], ArNA[i]) == 0)
                    {
                        *E = i;
                    }
                }
                switch (*E)
                {
                case 0:
                {
                    std::cout << "Carga en memoria los comandos de desplazamiento contenidos en el archivo identificado por nombre_archivo " << std::endl;
                }
                break;
                case 1:
                {
                    std::cout << "Carga en memoria los datos de puntos de interés o elementos contenidos en el archivo identificado por nombre_archivo " << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << "Agrega el comando de movimiento descrito a la lista de comandos del robot “Curiosity " << std::endl;
                }
                case 3:
                    __k8__
                    {
                        std::cout << "El comando envolvente con parametro calcula la caja envolvente de dicho objeto ubicado en la memoria " << std::endl;
                    }
                    break;
                case 4:
                {
                    std::cout << "Agrega el comando de análisis descrito a la lista de comandos del robot “Curiosity” " << std::endl;
                }
                break;
                case 5:
                {
                    std::cout << "Guarda en el archivo nombre_archivo la información solicitada de acuerdo al tipo de archivo " << std::endl;
                }
                case 6:
                {
                    std::cout << "Permite simular el resultado de los comandos de movimiento que se enviarán al robot Curiosity desde la Tierra " << std::endl;
                }
                break;
                case 7:
                {
                    std::cout << "El comando Ruta corta identifica los índices de los vértices que conforman la ruta más corta entre los vértices dados para el objeto seleccionado " << std::endl;
                }
                break;
                case 8:
                {
                    std::cout << "El comando debe utilizar la información de puntos de interés almacenada en memoria para ubicarlos en una estructura de datos jerárquica adecuada, que permita luego realizar consultas geográficas sobre estos elementos" << std::endl;
                }
                break;
                case 9:
                {
                    std::cout << "Permite utilizar la estructura creada con el comando anterior para retornar una lista de los componentes o elementos que están dentro del cuadrante geográfico descrito por los límites de co-ordenadas en x y y." << std::endl;
                }
                break;
                case 10:
                {
                    std::cout << "El comando debe utilizar la información de puntos de interés almacenada en memoria para ubicarlos en una estructura no lineal y conectarlos entre sí teniendo en cuenta el coeficiente de conectividad dado." << std::endl;
                }
                break;
                case 11:
                {
                    std::cout << "Con el mapa ya creado, el comando permite identificar los dos componentes más alejados entre sí de acuerdo a las conexiones generada" << std::endl;
                }
                break;

                default:
                {
                    std::cout << "El comando del que se solicita ayuda no existe o no se reconoce " << std::endl;
                }
                break;
                }
            }
            if (*Contador < 1 || *Contador > 2)
            {
                std::cout << "Ejecucion Incorrecta" << std::endl;
            }
            std::cout << "Fin de la ejecucion 'Ayuda'" << std::endl;
        }
        break;
        // CARGAR COMANDOS DESDE ARCHIVO
        case 1:
        {
            bool Apertura = true;
            if (*Contador != 2)
            {
                std::cout << "Ejecucion Incorrecta" << std::endl;
            }
            else
            {

                std::ifstream Lect;
                Movimientos M;
                // Abrir archivo y comprobar si existe
                Lect.open(DComand[1], std::ios::in);
                if (!Lect)
                {
                    std::cout << "\n"
                              << DComand[1] << " no se encuentra o no puede leerse" << std::endl;
                    system("Pause");
                    Apertura = false;
                }
                if (Apertura != false)
                {
                    // Leer y establecer nombre y numero de vertices en el Mesh

                    vector<Movimiento> vector_mov;
                    string tipo_mov, unidad_med;
                    int magnitud;

                    while (Lect >> tipo_mov >> magnitud >> unidad_med)
                    {
                        Movimiento m(tipo_mov, magnitud, unidad_med);
                        vector_mov.push_back(m);
                    }
                    file.close();
                    cout << vector_mov.size() << " movimientos han sido cargados exitosamente" << endl;
                }

                Lect.close();
            }
        }

        break;
        case 2:
        {
        }
        break;
        case 3:
        {
        }
        break;
        case 4:
        {
        }
        break;
        case 5:
        {
        }
        break;
        case 6:
        {
        }
        break;
        case 7:
        {
        }
        break;
        case 8:
        {
            *Comp = true;
            std::cout << "Ejecucion Correcta" << std::endl;
            std::cout << "Salida Correcta del Sistema" << std::endl;
        }
        break;
        case 9:
        {
        }
        break;
        case 10:
        {
        }
        break;
        case 12:
        {
        }
        break;

        default:
        {
            std::cout << "El comando ingresado no se reconoce o no existe en el sistema" << std::endl;
        }
        }
        delete[] Comand;
        delete Contador;
        delete C;
        delete E;
    } while (*Comp != true);

    delete Comp;
}
