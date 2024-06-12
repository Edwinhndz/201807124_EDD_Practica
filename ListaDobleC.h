#include <iostream>
#include <string>
#include "NodoAvion.h"
#include <fstream>
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
    string Busqueda(string vuelo);
    NodoA Busqueda2(string vuelo);
    void eliminarNodo1(string numeroRegistro);
    void eliminarNodo2(string numeroRegistro);
    bool Encontrado(string numeroRegistro);
    void generarReporte();
    //Getteres y Setters
    int getSize();
    void setSize(int size);
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
    nuevo->setVuelo(vuelo);
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
        int conteo = 1;
        do
        {
            nodoDato = actual->getDato();
            cout<< conteo << ". Registro: " << actual->getRegistro() << " Aerolinea: " <<  actual->getAerolinea() << " Modelo: " << actual->getModelo()
            << " Estado: " << actual->getEstado() <<endl;
            actual = actual->getSiguiente();
            conteo++;
        } while (actual != primero);
    }
};

int ListaCircular::getSize(){
    return size;
};

string ListaCircular::Busqueda(string registro){

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
            string regis = actual->getRegistro();
            bool isEqual = regis == registro;
            if(actual->getRegistro() == registro){
                return actual->getRegistro();
            }
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    return "No se encontro el registro |" + registro +"|";
};

NodoA ListaCircular::Busqueda2(string registro){

    bool encontrado = false;
    if (ListaCircular::estaVacia())
    {
        /* code */
        cout << "La lista está vacía\n" << endl;
        return *primero;
    }
    else
    {
        int nodoDato;
        NodoA *actual = primero;
        
        do
        {
            string regis = actual->getRegistro();
            bool isEqual = regis == registro;
            if(actual->getRegistro() == registro){
                encontrado = true;
            }
            actual = actual->getSiguiente();
        } while (actual != primero);
        if(encontrado){
            return *actual;
        }else{
            NodoA *nulo = new NodoA(0);
            return *nulo;
        }
    }
};

void ListaCircular::eliminarNodo1(string numeroRegistro) {

    if (ListaCircular::estaVacia()) {
        cout << "La lista está vacía" << endl;
    } else {
        NodoA* temporal = primero;
        NodoA* anterior = nullptr;
        
        do {
            if (temporal->getRegistro() == numeroRegistro) {
                if (temporal == primero) {
                    cout << "primer avion yendo a mantenimiento " << temporal->getRegistro() << endl;
                    primero = temporal->getSiguiente();
                    ultimo->setSiguiente(primero);
                } else if (temporal == ultimo) {
                    cout << "ultimo avion yendo a mantenimiento " << temporal->getRegistro() << endl;
                    ultimo = anterior;
                    ultimo->setSiguiente(primero);
                } else {
                    cout << "avion yendo a mantenimiento " << temporal->getRegistro() << endl;
                    anterior->setSiguiente(temporal->getSiguiente());
                }
                delete temporal;
                size--;
                break;
            }
            anterior = temporal;
            temporal = temporal->getSiguiente();

        } while (temporal != primero);
        if (temporal == primero) {
            cout << "No se encontro el avion" << endl;
        }
    }
};

void ListaCircular::eliminarNodo2(string numeroRegistro) {

    if (ListaCircular::estaVacia()) {
        cout << "La lista está vacía" << endl;
    } else {
        NodoA* temporal = primero;
        NodoA* anterior = nullptr;
        
        do {
            if (temporal->getRegistro() == numeroRegistro) {
                if (temporal == primero) {
                    cout << "primer avion de disponible" << temporal->getRegistro() << endl;
                    primero = temporal->getSiguiente();
                    ultimo->setSiguiente(primero);
                } else if (temporal == ultimo) {
                    cout << "ultimo avion disponible" << temporal->getRegistro() << endl;
                    ultimo = anterior;
                    ultimo->setSiguiente(primero);
                } else {
                    cout << "avion disponible " << temporal->getRegistro() << endl;
                    anterior->setSiguiente(temporal->getSiguiente());
                }
                delete temporal;
                size--;
                break;
            }
            anterior = temporal;
            temporal = temporal->getSiguiente();
            
        } while (temporal != primero);

        if(temporal == primero){
            cout << "No se encontro el avion" << endl;
        }

    }
};

bool ListaCircular::Encontrado(string registro){

    bool encontrado = false;

    if (ListaCircular::estaVacia())
    {
        /* code */
        cout << "La lista está vacía\n" << endl;
        return false;
    }
    else
    {
        int nodoDato;
        NodoA *actual = primero;
        
        do
        {
            string regis = actual->getRegistro();
            bool isEqual = regis == registro;
            if(actual->getRegistro() == registro){
                encontrado = true;
            }
            actual = actual->getSiguiente();
        } while (actual != primero);

        if(encontrado){
            return true;
        }else{
            return false;
        }
    }
};

void ListaCircular::setSize(int size){
    this->size = size;
};

void ListaCircular::generarReporte(){
    if (ListaCircular::estaVacia()){}
    else
    {
        ofstream archivo; //
        archivo.open("grafica_AvionesD.dot", ios::out);
        archivo << "digraph G { rankdir = LR; " << endl;

        int nodoDato;
        NodoA *actual = primero;
        do
        {   
            
            nodoDato = actual->getDato();
            archivo << nodoDato;
            archivo << " -> ";
            actual = actual->getSiguiente();
            if (actual == primero)
            {
                archivo << actual->getDato();
            }
            
        } while (actual != primero);

        archivo << "; }";
        archivo.close();
        system("dot -Tpng grafica_AvionesD.dot -o grafica_AvionesD.png");
        system("start grafica_LC.png");
    }
    

}

ListaCircular::~ListaCircular()
{
}