// g++ main.cpp -o main
#include "json.hpp"
#include <iostream>
#include <string>
#include "Pasajeros.h"
#include <fstream>
using json = nlohmann::json;

// #include "NodoP.cpp"

int main()
{
    int choice;
    int ej;
    Cola *cola = new Cola();
    

    do
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Carga de aviones" << std::endl;
        std::cout << "2. Carga de pasajeros" << std::endl;
        std::cout << "3. Carga de movimientos" << std::endl;
        std::cout << "4. Consultar pasajero" << std::endl;
        std::cout << "5. Visualizar reportes" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Elije una opcion (1-6): ";
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            std::cout << "Carga de aviones" << std::endl;
            std::cout << "Agergar nodo" << std::endl;
            CargaPasajeros();
            //std::cin >> ej;
            //cola->insertarInicio(ej);
            break;
        case 2:
            // Code for option 2
            break;
        case 3:
            // Code for option 3
            break;
        case 4:
            // Code for option 4
            break;
        case 5:
            // Code for option 5
            std::cout << "Visualizar reportes" << std::endl;
            std::cout << std::endl;
            cola->visualizarLista();
            break;
        case 6:
            // Code for option 6
            break;
        default:

            std::cout << "Elija una opcion valida." << std::endl;
            std::cout << std::endl;
            break;
        }

    } while (choice != 6);

    return 0;
}

void CargaPasajeros()
{
    std::cout << "SELECCIONASTE LA OPCION PARA LA CARGAR DE AVIONES " << endl;

    // Abrir el archivo JSON
    ifstream archivo("p.json");
    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo de aviones." << endl;
        return;
    }

    // Leer el contenido del archivo JSON
    json pasajeros;
    archivo >> pasajeros;

    // Recorrer los pasajeros y mostrar sus detalles
    for (const auto &pasajero : pasajeros)
    {
        cout << "Nombre: " << pasajero["nombre"] << endl;
        cout << "Nacionalidad: " << pasajero["nacionalidad"] << endl;
        cout << "Numero de pasaporte: " << pasajero["numero_de_pasaporte"] << endl;
        cout << "Vuelo: " << pasajero["vuelo"] << endl;
        cout << "Asiento: " << pasajero["asiento"] << endl;
        cout << "Destino: " << pasajero["destino"] << endl;
        cout << "Origen: " << pasajero["origen"] << endl;
        cout << "Equipaje facturado: " << pasajero["equipaje_facturado"] << endl;
        cout << "-------------------------" << endl;
    }
}
