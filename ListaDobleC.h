#include <iostream>
#include <string>
#include "NodoAvion.h"
using namespace std;

class ListaCircular
{
private:
    /* data */
    int size=0;
    NodoA* primero;
    NodoA* ultimo;
public:
    ListaCircular(/* args */);
    bool estaVacia();
    void insertarInicio(int dato);
    void insertarFinal(int dato, string name, string reg, string mod, string fab, int anio, int cap, 
int peso, string linea, string estado);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    //Getteres y Setters
    int getSize();
    NodoA getPrimero();
    ~ListaCircular();
};

ListaCircular::ListaCircular(/* args */)
{
    primero = nullptr;
    ultimo = nullptr;
}

bool ListaCircular::estaVacia()
{
    return (primero == nullptr) && (ultimo == nullptr);
}

void ListaCircular::insertarInicio(int dato)
{
    NodoA *nuevo = new NodoA(dato); //Se crea el nuevo nodo
    if (ListaCircular::estaVacia())
    {
        nuevo->setSiguiente(nuevo); //El primer nodo se apunta a si mismo
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero); //Se enlaza el nuevo nodo al primero
        ultimo->setSiguiente(nuevo); //Se enlaza el ultimo nodo al nuevo
        primero = nuevo; //Se verifica que el nodo creado sea el primero
    }
    
}

void ListaCircular::insertarFinal(int pos, string vuelo, string reg, string mod, string fab, int anio, int cap, 
int peso, string linea, string estado)
{

    NodoA *nuevo = new NodoA(pos);

    nuevo->setRegistro(reg);
    nuevo->setModelo(mod);
    nuevo->setFabricante(fab);
    nuevo->setAnio(anio);
    nuevo->setCapacidad(cap);
    nuevo->setPesoMax(peso);
    nuevo->setAerolinea(linea);
    nuevo->setEstado(estado);


    if (ListaCircular::estaVacia())
    {
        nuevo->setSiguiente(nuevo);
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero);
        ultimo->setSiguiente(nuevo); //Se enlaza el último nodo al nuevo
        ultimo = nuevo; //Se verfica que el nodo creado sea el último
    }
    ListaCircular::size++;
}

void ListaCircular::eliminarInicio()
{
    if (ListaCircular::estaVacia())
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
            NodoA *segundo = primero->getSiguiente();
            ultimo->setSiguiente(segundo);
            delete primero;
            primero = segundo;
        }   
    } 
}

void ListaCircular::eliminarFinal()
{
    if (ListaCircular::estaVacia())
    {
        cout << "La lista está vacía" << endl;
    }
    else{
        NodoA* temporal = primero;
        if (primero == ultimo)
        {
            /* code */
            delete primero;
            primero = ultimo = nullptr;
        }
        else{
            do
            {
                if (temporal->getSiguiente() == ultimo) //Se encontro el antepenultimo nodo
                {
                    delete ultimo;
                    temporal->setSiguiente(primero); //Se enlaza el antepenultimo nodo al primero
                    ultimo = temporal; //se verifica que temporal sea el último
                    break;
                }  
                temporal = temporal->getSiguiente();
            } while (temporal != primero);
            
        }
        
    }    
};

void ListaCircular::visualizarLista()
{
    if (ListaCircular::estaVacia())
    {
        /* code */
        cout << "La lista está vacía\n" << endl;
    }
    else
    {
        int nodoDato;
        NodoA *actual = primero;
        do
        {
            nodoDato = actual->getDato();
            cout << nodoDato << " Nombre: " << actual->getVuelo() << " Vuelo: " <<  actual->getAerolinea() << " Modelo: " << actual->getModelo()
            << " Estado: " << actual->getEstado() <<endl;
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
};

int ListaCircular::getSize(){
    return size;
};



ListaCircular::~ListaCircular()
{
}