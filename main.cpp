// g++ main.cpp -o main

#include <iostream>
#include <string>
#include "Pasajeros.h"
#include "ListaDobleC.h"
#include <fstream>

#include "json.hpp"


using json = nlohmann::json;



void CargaPasajeros(Cola *cola)
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
        string a = pasajero["nombre"];
        cout << "Nacionalidad: " << pasajero["nacionalidad"] << endl;
        string b = pasajero["nacionalidad"];
        cout << "Numero de pasaporte: " << pasajero["numero_de_pasaporte"] << endl;
        string c = pasajero["numero_de_pasaporte"];
        cout << "Vuelo: " << pasajero["vuelo"] << endl;
        string d = pasajero["vuelo"];
        cout << "Asiento: " << pasajero["asiento"] << endl;
        int e = pasajero["asiento"];
        cout << "Destino: " << pasajero["destino"] << endl;
        string f = pasajero["destino"];
        cout << "Origen: " << pasajero["origen"] << endl;
        string g = pasajero["origen"];
        cout << "Equipaje facturado: " << pasajero["equipaje_facturado"] << endl;
        int h = pasajero["equipaje_facturado"];
        cout << "-------------------------" << endl;
        cola->insertarInicio(cola->getSize(), a, b, c, d, e, f, g, h);
    }
}

void CargaAviones(ListaCircular *lista, ListaCircular *lista2)
{
    // Abrir el archivo JSON
    ifstream archivo("aviones.json");
    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo de aviones." << endl;
        return;
    }

    // Leer el contenido del archivo JSON
    json aviones;
    archivo >> aviones;

    // Recorrer los pasajeros y mostrar sus detalles
    for (const auto &avion : aviones)
    {
        cout << "Vuelo: " << avion["vuelo"] << endl;
        string a = avion["vuelo"];
        cout << "numero de registro: " << avion["numero_de_registro"] << endl;
        string b = avion["numero_de_registro"];
        cout << "Modelo: " << avion["modelo"] << endl;
        string c = avion["modelo"];
        cout << "Fabricante: " << avion["fabricante"] << endl;
        string d = avion["fabricante"];
        cout << "ano fabricante: " << avion["ano_fabricante"] << endl;
        int e = avion["ano_fabricante"];
        cout << "capacidad: " << avion["capacidad"] << endl;
        int f = avion["capacidad"];
        cout << "peso max despegue: " << avion["peso_max_despegue"] << endl;
        int g = avion["peso_max_despegue"];
        cout << "aerolinea: " << avion["aerolinea"] << endl;
        string h = avion["aerolinea"];
        cout << "Estado: " << avion["estado"] << endl;
        string i = avion["estado"];
        cout << "-------------------------" << endl;


        if(avion["estado"] == "disponible"){
            lista->insertarFinal(lista->getSize(), a, b, c, d, e, f, g, h, i);
        }else if(avion["estado"] == "mantenimiento"){
            lista2->insertarFinal(lista2->getSize(), a, b, c, d, e, f, g, h, i);
        }


        
    }
}

int main()
{
    int choice;
    int ej;
    Cola *cola = new Cola();
    ListaCircular *lista = new ListaCircular();
    ListaCircular *lista2 = new ListaCircular();
    

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
            CargaAviones(lista, lista2);
          
            //std::cin >> ej;
            //cola->insertarInicio(ej);
            break;
        case 2:
            // Code for option 2
            cout << "Carga de pasajeros" << endl;
            CargaPasajeros(cola);
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
            cout << "-------------------------" << endl;
            lista->visualizarLista();
            cout << "-------------------------" << endl;
            lista2->visualizarLista();
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




//g++ -std=c++11 -o ejec main.cpp