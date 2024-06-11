#include <iostream>
#include <string>
#include "NodoPila.h"
using namespace std;

class Pila
{
private:
    /* NECESITAMOS UNA REFERENCIA DEL PRIMER Y ÚLTIMO NODO DE LA LISTA */
    Nodop *primero;

    Nodop *ultimo;
    int size = 0;

public:
    Pila(/* args */);
    bool estaVacia();
    void insertarInicio(int dato, string name, string nacio, string pasaporte, 
string vuelo, int asiento, string destino, string origen, int equipaje);
    void insertarFinal(int dato);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    int getSize();
    ~Pila();
};

Pila::Pila(/* args */)
{
    primero = ultimo = nullptr;
}

bool Pila::estaVacia()
{
    return (primero == nullptr) && (ultimo == nullptr);
}

void Pila::insertarInicio(int dato, string name, string nacio, string pasaporte, 
string vuelo, int asiento, string destino, string origen, int equipaje)
{

    Nodop *nuevo; // Se crea el nuevo nodo
    nuevo->setPasaporte(pasaporte);
    nuevo->setNombre(name);
    nuevo->setNacionalidad(nacio);
    nuevo->setVuelo(vuelo);
    nuevo->setAsiento(asiento);
    nuevo->setDestino(destino);
    nuevo->setOrigen(origen);
    nuevo->setEquipaje(equipaje);


    if (Pila::estaVacia())
    {
        /* code */
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero); // Se enlaza el nuevo nodo al primero
        primero = nuevo;              // Se verifica que el nodo creado sea el primero
    }
    Pila::size++;
}

void Pila::eliminarInicio()
{
    if (Pila::estaVacia())
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
            Nodop *segundo = primero->getSiguiente();
            ultimo->setSiguiente(segundo);
            delete primero;
            primero = segundo;
        }   
    } 
}

void Pila::visualizarLista()
{
    if (Pila::estaVacia())
    {
        /* code */
        cout << "La lista está vacía\n" << endl;
    }
    else
    {
        string nodoDato;
        Nodop *actual = primero;
        while (actual != nullptr)
        {
            /* code */
            nodoDato = actual->getNombre();
            cout << "nombre: " << nodoDato << " Nac.:"<< actual->getNacionalidad() << " Asiento:"<< actual->getAsiento() <<
            " Passaport:" << actual->getPasaporte() <<  " Vuelo: "<< actual->getVuelo() << endl;
            actual = actual->getSiguiente();
        }
        
    }
};

int Pila::getSize(){
    return size;
};

Pila::~Pila(){

};