#include <iostream>
#include <string>
using namespace std;
#include "NodoPasajero.h"

class Cola
{
private:
    /* NECESITAMOS UNA REFERENCIA DEL PRIMER Y ÚLTIMO NODO DE LA LISTA */
    Nodo *primero;
    Nodo *ultimo;
    int size = 0;

public:
    Cola(/* args */);
    bool estaVacia();
    void insertarInicio(int dato, string name, string nacio, string pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje);
    void insertarFinal(int dato, string name, string nacio, string pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    Nodo Ultimo();
    int getSize();
    Nodo getUltimo();
    ~Cola();
};

Cola::Cola(/* args */)
{
    primero = ultimo = nullptr;
}

bool Cola::estaVacia()
{
    return (primero == nullptr) && (ultimo == nullptr);
}

void Cola::insertarInicio(int dato, string name, string nacio,
                          string pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje)
{

    Nodo *nuevo = new Nodo(dato); // Se crea el nuevo nodo

    nuevo->setNombre(name);
    nuevo->setNacionalidad(nacio);
    nuevo->setPasaporte(pasaporte);
    nuevo->setVuelo(vuelo);
    nuevo->setAsiento(asiento);
    nuevo->setDestino(destino);
    nuevo->setOrigen(origen);
    nuevo->setEquipaje(equipaje);

    if (Cola::estaVacia())
    {
        /* code */
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero); //Se enlaza el nuevo nodo al primero
        primero = nuevo; //Se verifica que el nodo creado sea el primero
    }
    Cola::size++;
}

void Cola::insertarFinal(int dato, string name, string nacio,
                          string pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje)
{

    Nodo *nuevo = new Nodo(dato); // Se crea el nuevo nodo

    nuevo->setNombre(name);
    nuevo->setNacionalidad(nacio);
    nuevo->setPasaporte(pasaporte);
    nuevo->setVuelo(vuelo);
    nuevo->setAsiento(asiento);
    nuevo->setDestino(destino);
    nuevo->setOrigen(origen);
    nuevo->setEquipaje(equipaje);
    if (Cola::estaVacia())
    {
        /* code */
        primero = ultimo = nuevo;
    }
    else
    {
        ultimo->setSiguiente(nuevo); // Se enlaza el último nodo al nuevo
        ultimo = nuevo;              // Se verfica que el nodo creado sea el último
    }
}

void Cola::eliminarInicio()
{
    if (Cola::estaVacia())
    {
        /* code */
        cout << "La lista está vacía" << endl;
    }
    else
    {
        if (primero == ultimo)
        {
            /* code */
            delete primero;
            primero = ultimo = nullptr;
        }
        else
        {
            Nodo *segundo = primero->getSiguiente();
            delete primero;
            primero = segundo;
        }
    }
}

void Cola::visualizarLista()
{
    if (Cola::estaVacia())
    {
        /* code */
        cout << "La lista está vacía\n"
             << endl;
    }
    else
    {
        string nodoDato;
        Nodo *actual = primero;

        // do{
        //     nodoDato = actual->getNombre();
        //     cout << "nombre: " << nodoDato << " Nac.:" << actual->getNacionalidad() << " Asiento:" << actual->getAsiento() << " Passaport:" << actual->getPasaporte() << " Vuelo: " << actual->getVuelo() << endl;
        //     actual = actual->getSiguiente();

        // }while (actual == ultimo);
        

        while (actual != nullptr)
        {
            /* code */
            nodoDato = actual->getNombre();
            cout << "nombre: " << nodoDato << " Nac.:" << actual->getNacionalidad() << " Asiento:" << actual->getAsiento() << " Passaport:" << actual->getPasaporte() << " Vuelo: " << actual->getVuelo() << endl;
            actual = actual->getSiguiente();
        }
    }
}

int Cola::getSize()
{
    return size;
}

void Cola::eliminarFinal()
{
    if (Cola::estaVacia())
    {
        cout << "La lista está vacía" << endl;
    }
    else
    {
        
        Nodo *temporal = primero;
        if (primero == ultimo)
        {
            /* code */
            delete primero;
            primero = ultimo = nullptr;
        }
        else
        {
            while (temporal != nullptr)
            {
                /* code */
                if (temporal->getSiguiente() == ultimo) // Si el siguiente de temporal es el último, entonces temporal es el antepenultimo
                {
                    /* code */

                    delete ultimo;
                    temporal->setSiguiente(nullptr);
                    ultimo = temporal;
                }
                temporal = temporal->getSiguiente(); // Recorriendo la lista
            }
        }
    }
    size--;
}

Nodo Cola::Ultimo()
{   
    bool encontrado = false;
    Nodo *temporal = primero;

    if (Cola::estaVacia())
    {
        /* code */
        if(primero==ultimo){
            return *primero;
        }else{
            while (temporal!=nullptr)
            {
                /* code */
                if(temporal == ultimo){
                    encontrado = true;
                    break;
                }else{
                    temporal = temporal->getSiguiente();
                }
            }
            
        }

    }
    if(encontrado){
        return *temporal;
    }else{
        Nodo *cero = new Nodo(0);
        return *cero;
    }
    

};

Nodo Cola::getUltimo()
{
    
    return *ultimo;
};

Cola::~Cola()
{
}
