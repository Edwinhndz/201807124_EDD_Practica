#include <iostream>
using namespace std;
#include "NodoPasajero.h"

class Cola
{
private:
    /* NECESITAMOS UNA REFERENCIA DEL PRIMER Y ÚLTIMO NODO DE LA LISTA */
    Nodo *primero, *ultimo;
public:
    Cola(/* args */);
    bool estaVacia();
    void insertarInicio(int dato);
    void insertarFinal(int dato);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
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

void Cola::insertarInicio(int dato)
{
    Nodo *nuevo = new Nodo(dato); //Se crea el nuevo nodo
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
        ultimo->setSiguiente(nuevo); //Se enlaza el último nodo al nuevo
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
        int nodoDato;
        Nodo *actual = primero;
        while (actual != nullptr)
        {
            /* code */
            nodoDato = actual->getDato();
            cout << nodoDato << endl;
            actual = actual->getSiguiente();
        }
        
    }
    
}

Cola::~Cola()
{
}