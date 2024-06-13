#include <iostream>
#include <string>
#include "NodoPila.h"
#include <fstream>
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
    void insertarFinal(int dato, string name, string nacio, string pasaporte,
                       string vuelo, int asiento, string destino, string origen, int equipaje);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    int getSize();
    void generarReporte();
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

void Pila::insertarInicio(int dato, string name, string nacio,
                          string pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje)
{

    Nodop *nuevo = new Nodop(dato); // Se crea el nuevo nodo

    nuevo->setNombre(name);
    nuevo->setNacionalidad(nacio);
    nuevo->setPasaporte(pasaporte);
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
        nuevo->setSiguiente(primero); //Se enlaza el nuevo nodo al primero
        primero = nuevo; //Se verifica que el nodo creado sea el primero
    }
    cout << "Se insertó el pasajero: " << name << endl;
    Pila::size++;
}

void Pila::insertarFinal(int dato, string name, string nacio, string pasaporte,
                         string vuelo, int asiento, string destino, string origen, int equipaje)
{

    Nodop *nuevo = new Nodop(dato); // Se crea el nuevo nodo
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
        nuevo->setSiguiente(nuevo);
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero);
        ultimo->setSiguiente(nuevo); //Se enlaza el último nodo al nuevo
        ultimo = nuevo; //Se verfica que el nodo creado sea el último
    }
};

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
        cout << "La lista está vacía\n"
             << endl;
    }
    else
    {
        string nodoDato;
        Nodop *actual = primero;

        // do
        // {
        //     nodoDato = actual->getNombre();
        //     cout << "nombre: " << nodoDato << " Nac.:" << actual->getNacionalidad() << " Asiento:" << actual->getAsiento() << " Passaport:" << actual->getPasaporte() << " Vuelo: " << actual->getVuelo() << endl;
        //     actual = actual->getSiguiente();

        // } while (actual == ultimo);

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

int Pila::getSize()
{
    return size;
};

void Pila::generarReporte(){
    if (Pila::estaVacia()){
        cout << "La lista está vacía no se genera reporte" << endl;
        return;
    }
    else
    {
        ofstream archivo; //
        archivo.open("grafica_Pila.dot", ios::out);
        archivo << "digraph G { " << endl << "rankdir = TB;" << endl << "label=\"Pila\";" << "bgcolor=grey "<< endl 
        <<"subgraph cluster_top_floor{" << endl << "bgcolor=wheat; " << endl;
        archivo << "label=\"Equipaje\";"<< endl;

        string nodoDato;
        Nodop *actual = primero;
        int conteo = 0;

        do
        {   
            //cout << getSize() << endl;
            nodoDato = actual->getNombre();
            archivo <<"nodo"<< conteo << "[ shape=box3d  , fontcolor=aliceblue , style=filled , color=dodgerblue , label=\"Nombre: " <<nodoDato << ", Pasaporte:" 
            << actual->getPasaporte() << " Equipaje:" << actual->getEquipaje() << " Asiento:" << actual->getAsiento() 
            << " Nacionalidad:" << actual->getNacionalidad()<< " Origen:" << actual->getOrigen() << " Destino:"<< actual->getDestino() << "\"]" <<endl;
            //archivo << " -> ";
            actual = actual->getSiguiente();
            
            conteo++;
        } while (conteo != size);

        int sizee = 0;

        //  do{

        //     //cout << "do2 " << endl;
        //     if(sizee == size){
        //         //archivo << "nodo" << sizee  << " -> ";
        //     }else{
        //         archivo << "nodo" << sizee << " -> ";
        //     }
        //     sizee--;
        // }while(sizee != 0);
        do{

            //cout << "do2 " << endl;

            if(sizee == size -1){
                archivo << "nodo" << sizee;
            }else{

                archivo << "nodo" << sizee << " -> ";
            }
            sizee++;
        }while(size != sizee);

        archivo << ";" << endl <<"}" << endl << "}";
        archivo.close();
        system("dot -Tpng grafica_Pila.dot -o grafica_Pila.png");
        system("open grafica_Pila.png");
    }
    

};

Pila::~Pila(){

};