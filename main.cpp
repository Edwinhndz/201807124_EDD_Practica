// g++ main.cpp -o main
// g++ -std=c++11 -o ejec main.cpp  
// g++ -std=c++11 -I/opt/homebrew/Cellar/graphviz/11.0.0 main.cpp -L/opt/homebrew/Cellar/graphviz/11.0.0/lib -o mainn

//g++ -std=c++11 -I/opt/homebrew/Cellar/graphviz/11.0.0/include/graphviz main.cpp -L/opt/homebrew/Cellar/graphviz/11.0.0/lib -lgvc -lcdt -o mainn

#include <iostream>
#include <string>
#include "Pasajeros.h"
#include "ListaDobleC.h"
#include "Pila.h"
#include "ListaEnlazada.h"
#include <fstream>
#include "json.hpp"
#include <sstream>
#include <cstdlib>



using json = nlohmann::json;

void CargaPasajeros(Cola *cola, Enlazada *enlazada, string pasajerosss)
{

    // Abrir el archivo JSON

    ifstream archivo(pasajerosss);
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

        if(h == 0){
            enlazada->insertarFinal(enlazada->getSize(), a, b, c, d, e, f, g, h);
        }else{
            cola->insertarInicio(cola->getSize(), a, b, c, d, e, f, g, h);
        }

        
    }
}

void CargaAviones(ListaCircular *lista, ListaCircular *lista2, string avionesss)

// void IngresoEquipaje();
{
    // Abrir el archivo JSON
    ifstream archivo(avionesss);

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
        cout << "ano fabricante: " << avion["ano_fabricacion"] << endl;
        int e = avion["ano_fabricacion"];
        cout << "capacidad: " << avion["capacidad"] << endl;
        int f = avion["capacidad"];
        cout << "peso max despegue: " << avion["peso_max_despegue"] << endl;
        int g = avion["peso_max_despegue"];
        cout << "aerolinea: " << avion["aerolinea"] << endl;
        string h = avion["aerolinea"];
        cout << "Estado: " << avion["estado"] << endl;
        string i = avion["estado"];
        cout << "-------------------------" << endl;

        if (i == "Disponible")
        {
            lista->insertarFinal(lista->getSize(), a, b, c, d, e, f, g, h, i);
        }
        else if (i == "Mantenimiento")
        {
            lista2->insertarFinal(lista2->getSize(), a, b, c, d, e, f, g, h, i);
        }
    }
};

void Commandos1(Cola *cola, ListaCircular *lista, ListaCircular *lista2)
{
    ifstream archivo("movimientos2.txt");

    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo de commandos." << endl;
        return;
    }

    string linea;

    int i = 1;
    while (getline(archivo, linea))
    {
        // Lo vamos imprimiendo

        cout << i << ".------------------------------------------" << endl;
        cout << "Una línea: ";
        cout << linea << endl;

        if(linea == ""){
            cout << "linea vacia" << endl;
        }
        else if (linea != "IngresoEquipajes;")
        {
            stringstream split(linea);
            string linea, accion, avion;
            cout << "-------------------------" << endl;
            getline(split, linea, ',');
            cout << "Commando: " << linea << "\n";
            getline(split, accion, ',');
            cout << "accion: " << accion << "\n";
            getline(split, avion, ',');
            avion.pop_back();
            cout << "avion: |" << avion << "|" << "\n";

            // cout << "Vuelo: " << lista->Busqueda(avion) << endl;

            if (accion == "Ingreso")
            {

                NodoA nodo = lista->Busqueda2(avion);

                if (nodo.getSiguiente() == nullptr)
                {
                    cout << "" << endl;
                }
                else
                {
                    lista2->insertarFinal(lista2->getSize(), nodo.getVuelo(), nodo.getRegistro(), nodo.getModelo(),
                                          nodo.getFabricante(), nodo.getAnio(), nodo.getCapacidad(), nodo.getPesoMax(), nodo.getEstado(), "mantenimiento");
                    lista->eliminarNodo1(avion);
                    
                }
            }
            else if (accion == "Salida")
            {

                NodoA nodo = lista2->Busqueda2(avion);

                if (nodo.getSiguiente() == nullptr)
                {
                    cout << "" << endl;
                }
                else
                {
                    cout << "Avion saliendo de mantenimiento: " << nodo.getRegistro() << endl;
                    lista->insertarFinal(lista->getSize(), nodo.getVuelo(), nodo.getRegistro(), nodo.getModelo(),
                                         nodo.getFabricante(), nodo.getAnio(), nodo.getCapacidad(), nodo.getPesoMax(), nodo.getEstado(), "disponible");
                    lista2->eliminarNodo2(avion);
                }
            }

            cout << "-------------------------" << endl;
            cout << "" << endl;
        }

        cout << "------------------------------------------." << i << endl;
        i++;
    }
};

void Commandos2(Pila *pila, Cola *cola, Enlazada *enlazada)
{
    ifstream archivo("movimientos2.txt");

    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo de commandos." << endl;
        return;
    }

    string linea;

    while (getline(archivo, linea))
    {
        // Lo vamos imprimiendo
        
        if (linea == "IngresoEquipajes;")
        {
            cout << "Una línea: ";
            cout << linea << endl;

            Nodo nodo = cola->getUltimo();


            //cout << nodo.getSiguiente()->getNombre() << endl;
            
            if (nodo.getSiguiente() == nullptr){ 
                
                pila->insertarInicio(pila->getSize(), nodo.getNombre(), nodo.getNacionalidad(),
                                 nodo.getPasaporte(), nodo.getVuelo(), nodo.getAsiento(), nodo.getDestino(), nodo.getOrigen(), nodo.getEquipaje());
                enlazada->insertarFinal(enlazada->getSize(), nodo.getNombre(), nodo.getNacionalidad(),
                                 nodo.getPasaporte(), nodo.getVuelo(), nodo.getAsiento(), nodo.getDestino(), nodo.getOrigen(), nodo.getEquipaje());
          
                cola->eliminarFinal();

            }             
        }
    }
    enlazada->ordenar();
};

void Pasajero(string a, Enlazada *enlazada){
   
        Nodo2 pasa = enlazada->Pasajero(a);


        if(pasa.getNombre() == ""){
            cout << "Pasajero no encontrado" << endl;
        }else{

        cout << "nombre: " << pasa.getNombre() << " Asiento:" << pasa.getAsiento() << " Vuelo: " << pasa.getVuelo() << endl;
        enlazada->generarReporte2(pasa);
        }
};
int main()
{
    int choice;
    int ej;
    Cola *cola = new Cola();
    Pila *pila = new Pila();
    ListaCircular *lista = new ListaCircular();
    ListaCircular *lista2 = new ListaCircular();
    Enlazada *enlazada = new Enlazada();
    string pasaporte;
    string avionesss;
    string pasajerosss;

    do
    {
        std::cout << std::endl;
        std::cout << "Bienvenido al sistema de carga de aviones" << std::endl;
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
            cout << "Ingrese el nombre del archivo de aviones: ";
            cin >> avionesss;
            CargaAviones(lista, lista2, avionesss);

            // std::cin >> ej;
            // cola->insertarInicio(ej);
            break;
        case 2:
            // Code for option 2
            cout << "Carga de pasajeros" << endl;
            cout << "Ingrese el nombre del archivo de pasajeros: ";
            cin >> pasajerosss;
            CargaPasajeros(cola, enlazada, pasajerosss);
            enlazada->ordenar();
            break;
        case 3:
            // Code for option 3
            cout << "Carga de movimientos" << endl;
            Commandos1(cola, lista, lista2);
            Commandos2(pila, cola, enlazada);

            break;
        case 4:
            // Code for option 4
            cout << "Consultar pasajero" << endl;
            cout << "Ingrese el numero de pasaporte: ";
            // string pasaporte;
            cin >> pasaporte;
            Pasajero(pasaporte, enlazada);
            
            break;
        case 5:
            // Code for option 5
            std::cout << "Visualizar reportes" << std::endl;
            std::cout << std::endl;
            cout << "-----------Cola--------------" << cola->getSize() << endl;
            cola->visualizarLista();
            cola->generarReporte();
            cout << "------------Aviones D-------------" << lista->getSize() << endl;
            lista->visualizarLista();
            lista->generarReporte();
            cout << endl;
            cout << "-------------Aviones M------------" << lista2->getSize() << endl;
            lista2->visualizarLista();
            lista2->generarReporte2();
            cout << endl;
            cout << "------------Pila Equipaje-------------"  << pila->getSize() << endl;
            pila->visualizarLista();
            pila->generarReporte();
            cout << endl;
            cout << "------------Pasajeros ingresados-------------" << enlazada->getSize() << endl;
            enlazada->visualizarLista();
            enlazada->generarReporte();
            break;

        case 6:
            // Code for option 6
            break;
        default:

            cout << "Elija una opcion valida." << std::endl;
            cout << std::endl;
            break;
        }

    } while (choice != 6);

    return 0;
}

// g++ -std=c++11 -o ejec main.cpp