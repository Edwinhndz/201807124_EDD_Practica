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
    int size=0;
public:
    Cola(/* args */);
    bool estaVacia();
    void insertarInicio(int dato, string name, string nacio, string pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje);
    void insertarFinal(int dato);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    int getSize();
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


    Nodo *nuevo = new Nodo(dato); //Se crea el nuevo nodo
     
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

void Cola::insertarFinal(int dato)
{
    Nodo *nuevo = new Nodo(dato);
    if (Cola::estaVacia())
    {
        /* code */
        primero = ultimo = nuevo;
    }
    else
    {
        ultimo->setSiguiente(nullptr); //Se enlaza el último nodo al nuevo
        ultimo = nuevo; //Se verfica que el nodo creado sea el último
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
        cout << "La lista está vacía\n" << endl;
    }
    else
    {
        string nodoDato;
        Nodo *actual = primero;
        while (actual != nullptr)
        {
            /* code */
            nodoDato = actual->getNombre();
            cout << "nombre: " << nodoDato << " Nac.:"<< actual->getNacionalidad() << " Asiento:"<< actual->getAsiento() <<
            " Passaport:" << actual->getPasaporte() <<  " Vuelo: "<< actual->getVuelo() << endl;
            actual = actual->getSiguiente();
        }
        
    }
    
}

int Cola::getSize(){
    return size;
}

Cola::~Cola()
{
}

