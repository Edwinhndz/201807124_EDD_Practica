#include <iostream>
#include <string>
#include "Nodo2.h"
#include <fstream>
using namespace std;

class Enlazada
{
private:
    /* NECESITAMOS UNA REFERENCIA DEL PRIMER Y ÚLTIMO Nodo2 DE LA LISTA */
    Nodo2 *primero;
    Nodo2 *ultimo;
    int size = 0;

public:
    Enlazada(/* args */);
    bool estaVacia();
    void insertarInicio(int dato, string name, string nacio, string pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje);
    void insertarFinal(int dato, string name, string nacio, string pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    Nodo2 Ultimo();
    int getSize();
    Nodo2 getUltimo();
    void ordenarPorVuelo();
    void Ordenar();
    void swap(Nodo2 *a, Nodo2 *b);
    ~Enlazada();
};

Enlazada::Enlazada()
/* args */
{
    primero = ultimo = nullptr;
}

bool Enlazada::estaVacia()
{
    return (primero == nullptr) && (ultimo == nullptr);
}

void Enlazada::insertarInicio(int dato, string name, string nacio,
                          string pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje)
{

    Nodo2 *nuevo = new Nodo2(dato); // Se crea el nuevo Nodo2

    nuevo->setNombre(name);
    nuevo->setNacionalidad(nacio);
    nuevo->setPasaporte(pasaporte);
    nuevo->setVuelo(vuelo);
    nuevo->setAsiento(asiento);
    nuevo->setDestino(destino);
    nuevo->setOrigen(origen);
    nuevo->setEquipaje(equipaje);

    if (Enlazada::estaVacia())
    {
        /* code */
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero); //Se enlaza el nuevo Nodo2 al primero
        primero = nuevo; //Se verifica que el Nodo2 creado sea el primero
    }
    Enlazada::size++;
}

void Enlazada::insertarFinal(int dato, string name, string nacio,
                          string pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje)
{

    Nodo2 *nuevo = new Nodo2(dato); // Se crea el nuevo Nodo2

    nuevo->setNombre(name);
    nuevo->setNacionalidad(nacio);
    nuevo->setPasaporte(pasaporte);
    nuevo->setVuelo(vuelo);
    nuevo->setAsiento(asiento);
    nuevo->setDestino(destino);
    nuevo->setOrigen(origen);
    nuevo->setEquipaje(equipaje);
    if (Enlazada::estaVacia())
    {
        /* code */
        primero = ultimo = nuevo;
    }
    else
    {
        ultimo->setSiguiente(nuevo); // Se enlaza el último Nodo2 al nuevo
        ultimo = nuevo;              // Se verfica que el Nodo2 creado sea el último
    }
}

void Enlazada::eliminarInicio()
{
    if (Enlazada::estaVacia())
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
            Nodo2 *segundo = primero->getSiguiente();
            delete primero;
            primero = segundo;
        }
    }
}

void Enlazada::visualizarLista()
{
    if (Enlazada::estaVacia())
    {
        /* code */
        cout << "La lista está vacía\n"
             << endl;
    }
    else
    {
        string Nodo2Dato;
        Nodo2 *actual = primero;

        // do{
        //     Nodo2Dato = actual->getNombre();
        //     cout << "nombre: " << Nodo2Dato << " Nac.:" << actual->getNacionalidad() << " Asiento:" << actual->getAsiento() << " Passaport:" << actual->getPasaporte() << " Vuelo: " << actual->getVuelo() << endl;
        //     actual = actual->getSiguiente();

        // }while (actual == ultimo);
        

        while (actual != nullptr)
        {
            /* code */
            Nodo2Dato = actual->getNombre();
            cout << "nombre: " << Nodo2Dato  << " Asiento:" << actual->getAsiento() << " Vuelo: " << actual->getVuelo() << endl;
            actual = actual->getSiguiente();
        }
    }
}

int Enlazada::getSize()
{
    return size;
}

void Enlazada::eliminarFinal()
{
    if (Enlazada::estaVacia())
    {
        cout << "La lista está vacía" << endl;
    }
    else
    {
        
        Nodo2 *temporal = primero;
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

Nodo2 Enlazada::Ultimo()
{   
    bool encontrado = false;
    Nodo2 *temporal = primero;

    if (Enlazada::estaVacia())
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
        Nodo2 *cero = new Nodo2(0);
        return *cero;
    }
    

};

Nodo2 Enlazada::getUltimo()
{
    
    return *ultimo;
};

void Enlazada::ordenarPorVuelo()
{
    if (estaVacia())
    {
        cout << "La lista está vacía" << endl;
        return;
    }

    bool swapped;
    Nodo2 *ptr1;
    Nodo2 *lptr = nullptr;

    do
    {
        swapped = false;
        ptr1 = primero;

        int vuelo =stoi(ptr1->getVuelo().erase(0, 1));  
        cout << "Vuelo: " << vuelo << endl; 
        int vuelo2 = stoi(ptr1->getSiguiente()->getVuelo().erase(0, 1));
        cout << "Vuelo2: " << vuelo2 << endl;

        while (ptr1->getSiguiente() != lptr)
        {
            cout << "cliclos" << endl;
            if ((vuelo > vuelo2) || (vuelo < vuelo2) ||(vuelo ==vuelo2 && ptr1->getAsiento() > ptr1->getSiguiente()->getAsiento()) || (vuelo ==vuelo2 && ptr1->getAsiento() < ptr1->getSiguiente()->getAsiento()))
            {
                swap(ptr1, ptr1->getSiguiente());
                swapped = true;
            }
            ptr1 = ptr1->getSiguiente();
        }
        lptr = ptr1;
    } while (swapped);
}

void Enlazada::Ordenar(){
    if (estaVacia())
    {
        cout << "La lista está vacía" << endl;
        return;
    }

    bool swapped;
    Nodo2 *ptr1=primero;
    Nodo2 *lptr = ultimo;
    int index =0;
    while (ptr1 != lptr){

        int vuelo =stoi(ptr1->getVuelo().erase(0, 1));  
        cout << "Vuelo: " << vuelo << endl; 
        int vuelo2 = stoi(ptr1->getSiguiente()->getVuelo().erase(0, 1));
        cout << "Vuelo2: " << vuelo2 << endl;

        if(vuelo > vuelo2){
            swap(ptr1, ptr1->getSiguiente());
            ptr1 = ptr1->getSiguiente();
        }else if (vuelo < vuelo2){
            swap(ptr1, ptr1->getSiguiente());
            ptr1 = ptr1->getSiguiente();    
        }else if((vuelo == vuelo2) && (ptr1->getAsiento() > ptr1->getSiguiente()->getAsiento())){
            swap(ptr1, ptr1->getSiguiente());
            ptr1 = ptr1->getSiguiente();
        }else if((vuelo == vuelo2) && (ptr1->getAsiento() < ptr1->getSiguiente()->getAsiento())){
            swap(ptr1, ptr1->getSiguiente());
        }else if((vuelo == vuelo2) && (ptr1->getAsiento() == ptr1->getSiguiente()->getAsiento())){
            cout << "iguales error" << endl;
            break;
        }else{
            
        }
        
    } 
    

};

void Enlazada::swap(Nodo2 *a, Nodo2 *b)
{
    string tempNombre = a->getNombre();
    int tempAsiento = a->getAsiento();

    string tempVuelo =  a->getVuelo();

    a->setNombre(b->getNombre());
    a->setAsiento(b->getAsiento());
    a->setVuelo(b->getVuelo());

    b->setNombre(tempNombre);
    b->setAsiento(tempAsiento);
    b->setVuelo(tempVuelo);
}




Enlazada::~Enlazada()
{
}
