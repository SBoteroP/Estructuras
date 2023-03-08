#include <iostream>
#include "movimientos.h"
#include "elementos.h"
#include "analisis.h"
#include "robot.h"
#include <string.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <iterator>

int main(int argc, char *argv[])
{
    // Error de ingreso de comando
    if (argc < 1)
    {
        std::cout << "El comando ingresado no se reconoce";
        return (-1);
    }
    // Declaracion de arreglos y variables

    std::vector<Movimiento> vector_mov;
    std::vector<Elemento> vector_ele;
    std::vector<Analisis> vector_ana;

    const char *ArNA[] = {"ayuda", "cargar_comandos", "cargar_elementos", "agregar_movimiento", "agregar_analisis", "agregar_elemento", "guardar", "simular_comandos", "salir", "ubicar_elementos", "en_cuadrante", "crear_mapa", "ruta_mas_larga"};
    bool *Comp = new bool;
    *Comp = false;
    // std::vector<Mesh> Figuras;
    // std::vector<Envolvente> vectEnv;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "                     ROVER DE MARTE               " << std::endl;
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
                    std::cout << "El comando 'ayuda' lista los comandos disponibles y sus llamados correctos " << std::endl;
                }
                break;
                case 1:
                {
                    std::cout << "Carga en memoria los comandos de desplazamiento contenidos en el archivo identificado por nombre_archivo " << std::endl;
                }
                break;
                case 2:
                {
                    std::cout << "Carga en memoria los datos de puntos de interés o elementos contenidos en el archivo identificado por nombre_archivo " << std::endl;
                }
                break;
                case 3:
                {
                    std::cout << "Agrega el comando de movimiento descrito a la lista de comandos del robot “Curiosity " << std::endl;
                }
                break;
                case 4:
                {
                    std::cout << "Agrega el comando de análisis descrito a la lista de comandos del robot “Curiosity” " << std::endl;
                }
                break;
                case 5:
                {
                    std::cout << "Agregar un elemento a la lista de elementos dentro del plano " << std::endl;
                }
                case 6:
                {
                    std::cout << "Guarda los valores que haya dentro de las listas de 'movimientos' , 'elementos' y 'analisis' " << std::endl;
                }
                break;
                case 7:
                {
                    std::cout << "Permite simular el resultado de los comandos de movimiento que se enviarán al robot Curiosity desde la Tierra " << std::endl;
                }
                break;
                case 8:
                {
                    std::cout << "'Salir' termina la ejecucion del programa" << std::endl;
                }
                break;
                case 9:
                {
                    std::cout << "El comando debe utilizar la información de puntos de interés almacenada en memoria para ubicarlos en una estructura de datos jerárquica adecuada, que permita luego realizar consultas geográficas sobre estos elementos" << std::endl;
                }
                break;
                case 10:
                {
                    std::cout << "El comando debe utilizar la información de puntos de interés almacenada en memoria para ubicarlos en una estructura no lineal y conectarlos entre sí teniendo en cuenta el coeficiente de conectividad dado" << std::endl;
                }
                break;
                case 11:
                {
                    std::cout << "Con el mapa ya creado, el comando permite identificar los dos componentes más alejados entre sí de acuerdo a las conexiones generadas." << std::endl;
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
                Movimiento M;
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
                    ifstream Lect("movimientos.txt");

                    // Read from the file until the end of the file is reached
                    while (!Lect.eof())
                    {
                        // Extract the three parameters using the dot operator
                        string mov, uni;
                        int mag;
                        Lect >> mov >> mag >> uni;

                        // Create a new Person struct and assign values to its members using the dot operator
                        Movimiento M;
                        M.tipo_mov = mov;
                        M.magnitud = mag;
                        M.unidad_med = uni;

                        // Add the new struct to the vector
                        vector_mov.push_back(M);
                    }

                    // Print out the contents of the vector
                    cout << "Movimiento(s) han sido cargados exitosamente" << endl;
                }
                Lect.close();
            }
        }
        break;

        case 2:
        {
            bool Apertura = true;
            if (*Contador != 2)
            {
                std::cout << "Ejecucion Incorrecta" << std::endl;
            }
            else
            {
                std::ifstream Lect2;
                Elemento E;
                // Abrir archivo y comprobar si existe
                Lect2.open(DComand[1], std::ios::in);
                if (!Lect2)
                {
                    std::cout << "\n"
                              << DComand[1] << " no se encuentra o no puede leerse" << std::endl;
                    system("Pause");
                    Apertura = false;
                }
                if (Apertura != false)
                {
                    // Leer y establecer nombre y numero de vertices en el Mesh
                    ifstream Lect2("elementos.txt");

                    // Read from the file until the end of the file is reached
                    while (!Lect2.eof())
                    {
                        // Extract the three parameters using the dot operator
                        string comp, uni;
                        int CX, CY;
                        double tam;
                        Lect2 >> comp >> tam >> uni >> CY >> CY;

                        // Create a new Person struct and assign values to its members using the dot operator
                        Elemento E;
                        E.tipo_comp = comp;
                        E.tamano = tam;
                        E.unidad_med = uni;
                        E.coordx = CX;
                        E.coordy = CY;

                        // Add the new struct to the vector
                        vector_ele.push_back(E);
                    }

                    // Print out the contents of the vector
                    cout << "Elemento(s) han sido cargados exitosamente" << endl;
                }
                Lect2.close();
            }
        }
        break;

        case 3:
        {
            if (*Contador < 4 || *Contador > 4)
            {
                std::cout << "Ejecucion Incorrecta" << std::endl;
            }
            else
            {
                int magnitud;

                std::string tipo(DComand[1]);
                magnitud = std::atoi(DComand[2]);
                std::string uni(DComand[3]);

                vector_mov.push_back(agregar_movimiento(tipo, magnitud, uni));
            }
        }
        break;

        case 4:
        {

            std::string tipo(DComand[1]);
            std::string objeto(DComand[2]);
            std::string comentario(DComand[3]);

            vector_ana.push_back(agregar_analisis(tipo, objeto, comentario));
        }
        break;

        case 5:
        {
            std::string tipo(DComand[1]);
            double d = std::stod(DComand[2]);
            std::string unidad(DComand[3]);
            int x = std::atoi(DComand[4]);
            int y = std::atoi(DComand[5]);

            vector_ele.push_back(agregar_elementos(tipo, d, unidad, x, y));
        }
        break;

        case 6:
        {
            int opcion;
            std::ofstream archivo;
            std::cout << "Seleccione el vector a guardar:\n";
            std::cout << "1. Vector de movimiento\n";
            std::cout << "2. Vector de analisis\n";
            std::cout << "3. Vector de elementos\n";
            std::cin >> opcion;

            switch (opcion)
            {
            case 1:
                archivo.open("movimientos.txt", std::ofstream::trunc);
                if (!archivo)
                {
                    std::cout << "No se pudo abrir el archivo "
                              << "movimientos.txt"
                              << " para escritura\n";
                    system("Pause");
                }

                for (const auto &Movimiento : vector_mov)
                {
                    archivo << Movimiento.tipo_mov << " " << Movimiento.magnitud << " " << Movimiento.unidad_med << "\n";
                }
                archivo.close();
                std::cout << "Vector guardado exitosamente en "
                          << "movimientos.txt"
                          << "\n";
                break;

            case 2:
                archivo.open("analisis.txt", std::ofstream::trunc);
                if (!archivo)
                {
                    std::cout << "No se pudo abrir el archivo "
                              << "analisis.txt"
                              << " para escritura\n";
                    system("Pause");
                }
                for (const auto &Analisis : vector_ana)
                {
                    archivo << Analisis.tipo << " " << Analisis.objeto << " " << Analisis.comentario << "\n";
                }
                archivo.close();
                std::cout << "Vector guardado exitosamente en "
                          << "analisis.txt"
                          << "\n";
                break;
            case 3:
                archivo.open("elementos.txt", std::ofstream::trunc);
                if (!archivo)
                {
                    std::cout << "No se pudo abrir el archivo "
                              << "elementos.txt"
                              << " para escritura\n";
                    system("Pause");
                }
                for (const auto &Elemento : vector_ele)
                {
                    archivo << Elemento.tipo_comp << " " << Elemento.tamano << " " << Elemento.unidad_med << " " << Elemento.coordx << " " << Elemento.coordy << "\n";
                }
                archivo.close();
                std::cout << "Vector guardado exitosamente en "
                          << "elementos.txt"
                          << "\n";
                break;
            default:
                std::cerr << "Opción no válida\n";
                break;
            }
            break;
        }
        case 7:
        {
            Robot R;

            int CX = std::atoi(DComand[1]);
            int CY = std::atoi(DComand[2]);

            R.setX(CX);
            R.setY(CY);

            int height, length;
            cout << "De que alto desea el mapa?: ";
            cin >> height;
            cout << "De que ancho desea el mapa?: ";
            cin >> length;
            // Create a list of lists initialized with 0s
            list<list<int>> matrix(height, list<int>(length, 0));

            auto fila_it = matrix.begin();
            for (int i = 0; i < CX; i++)
            {
                fila_it++;
            }

            auto col_it = fila_it->begin();
            for (int i = 0; i < CY; i++)
            {
                col_it++;
            }

            *col_it = 1;

            for (auto fila : matrix)
            {
                for (auto elem : fila)
                {
                    cout << elem << "\t";
                }
                cout << endl;
            }
            list<int> aux;
            auto ix = matrix.begin();
            int cont = 0;
            for (int i = 0; i < vector_mov.size(); i++)
            {
                if (vector_mov[i].getTipo_mov() == "avanzar")
                {
                    switch (R.getDireccion())
                    {
                    case 0:
                    {
                        R.setX(R.getX() + vector_mov[i].getMagnitud());
                        while (R.getX() > matrix.size())
                        {
                            matrix.push_back(aux);
                        }
                        for (int i = 0; i < vector_mov[i].getMagnitud(); i++)
                        {
                            ix++;
                        }
                        auto iy = ix->begin();
                        while (R.getY() > ix->size())
                        {
                            ix->push_back(0);
                        }
                        for (int i = 0; i < R.getY(); i++)
                        {
                            iy++;
                        }
                        cout << R.getX() << " x," << R.getY() << " y\n";
                        break;
                    }
                    case 45:
                    {
                        R.setX(R.getX() + vector_mov[i].getMagnitud());
                        while (R.getX() > matrix.size())
                        {
                            matrix.push_back(aux);
                        }
                        for (int i = 0; i < vector_mov[i].getMagnitud(); i++)
                        {
                            ix++;
                        }
                        R.setY(R.getY() + vector_mov[i].getMagnitud());
                        while (R.getY() > ix->size())
                        {
                            ix->push_back(0);
                        }
                        auto iy = ix->begin();
                        for (int i = 0; i < R.getY() + vector_mov[i].getMagnitud(); i++)
                        {
                            iy++;
                        }
                        cout << R.getX() << " x," << R.getY() << " y\n";
                        break;
                    }
                    case 90:
                    {
                        R.setY(R.getY() + vector_mov[i].getMagnitud());
                        while (R.getY() > ix->size())
                        {
                            ix->push_back(0);
                        }
                        auto iy = ix->begin();
                        for (int i = 0; i < R.getY() + vector_mov[i].getMagnitud(); i++)
                        {
                            iy++;
                        }
                        cout << R.getX() << " x," << R.getY() << " y\n";
                        break;
                    }
                    case 135:
                    {
                        R.setX(R.getX() - vector_mov[i].getMagnitud());
                        for (int i = 0; i < vector_mov[i].getMagnitud(); i++)
                        {
                            ix--;
                        }
                        R.setY(cont + vector_mov[i].getMagnitud());
                        while (R.getY() > ix->size())
                        {
                            ix->push_back(0);
                        }
                        auto iy = ix->begin();
                        for (int i = 0; i < cont + vector_mov[i].getMagnitud(); i++)
                        {
                            iy++;
                        }
                        cout << R.getX() << " x," << R.getY() << " y\n";
                        break;
                    }
                    case 180:
                    {
                        R.setX(R.getX() - vector_mov[i].getMagnitud());
                        for (int i = 0; i < vector_mov[i].getMagnitud(); i++)
                        {
                            ix--;
                        }
                        auto iy = ix->begin();
                        while (R.getY() > ix->size())
                        {
                            ix->push_back(0);
                        }
                        for (int i = 0; i < vector_mov[i].getMagnitud(); i++)
                        {
                            iy++;
                        }
                        cout << R.getX() << " x," << R.getY() << " y\n";
                        break;
                    }
                    case 225:
                    {
                        R.setX(R.getX() - vector_mov[i].getMagnitud());
                        for (int i = 0; i < vector_mov[i].getMagnitud(); i++)
                        {
                            ix--;
                        }
                        R.setY(cont - vector_mov[i].getMagnitud());
                        auto iy = ix->begin();
                        for (int i = 0; i < cont - vector_mov[i].getMagnitud(); i++)
                        {
                            iy--;
                        }
                        cout << R.getX() << " x," << R.getY() << " y\n";
                        break;
                    }
                    case 270:
                    {
                        R.setY(cont - vector_mov[i].getMagnitud());
                        auto iy = ix->begin();
                        for (int i = 0; i < cont - vector_mov[i].getMagnitud(); i++)
                        {
                            iy--;
                        }
                        cout << R.getX() << " x," << R.getY() << " y\n";
                        break;
                    }
                    case 315:
                    {
                        R.setX(R.getX() + vector_mov[i].getMagnitud());
                        while (R.getX() > matrix.size())
                        {
                            matrix.push_back(aux);
                        }
                        for (int i = 0; i < vector_mov[i].getMagnitud(); i++)
                        {
                            ix++;
                        }
                        R.setY(cont - vector_mov[i].getMagnitud());
                        auto iy = ix->begin();
                        for (int i = 0; i < cont - vector_mov[i].getMagnitud(); i++)
                        {
                            iy--;
                        }
                        cout << R.getX() << " x," << R.getY() << " y\n";
                        break;
                    }
                    default:
                        break;
                    }
                }
                if (vector_mov[i].getTipo_mov() == "girar")
                {
                    R.setDireccion(vector_mov[i].getMagnitud());
                }
            }

            int EX = vector_ele[0].getCoordx();
            int EY = vector_ele[0].getCoordy();

            int EX2 = vector_ele[1].getCoordx();
            int EY2 = vector_ele[1].getCoordy();

            int EX3 = vector_ele[2].getCoordx();
            int EY3 = vector_ele[2].getCoordy();

            int ES = vector_ele[0].getTamano();
            int ES2 = vector_ele[1].getTamano();
            int ES3 = vector_ele[2].getTamano();

            int start_i = max(0, EX);
            int end_i = min(height - 1, EX + ES - 1);
            int start_j = max(0, EY);
            int end_j = min(length - 1, EY + ES - 1);

            for (int i = 0; i < vector_ele.size(); i++)
            {
                auto itx = matrix.begin();
                EX = vector_ele[i].getCoordx();
                EY = vector_ele[i].getCoordy();

                auto fila_it = matrix.begin(); // Iterator to traverse the rows of the matrix
                for (int i = 0; i < start_i; i++)
                {
                    fila_it++; // Move the row iterator to the starting row index of the square
                }

                for (int i = start_i; i <= end_i; i++)
                {
                    auto col_it = fila_it->begin(); // Iterator to traverse the columns of the current row
                    for (int j = 0; j < start_j; j++)
                    {
                        col_it++; // Move the column iterator to the starting column index of the square
                    }
                    for (int j = start_j; j <= end_j; j++)
                    {
                        *col_it = 2; // Set the current element to 1 to paint the square
                        col_it++;    // Move to the next column
                    }
                    fila_it++; // Move to the next row
                }
            }
            for (auto& fila : matrix)
            {
                for (auto& elem : fila)
                {
                    cout << elem << "\t";
                }
                cout << endl;
            }
            // M E  Q U I E R O  M O R I R
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

            delete[] Comand;
            delete Contador;
            delete C;
            delete E;
        }
    } while (*Comp != true);

    delete Comp;
}
