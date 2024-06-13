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
    Nodo2 Pasajero(string a);
    void ordenarPorVuelo();
    Nodo2 getPorIndice(int i);
    void ordenar();
    void swap(Nodo2 *a, Nodo2 *b);
    void generarReporte();

    void generarReporte2(Nodo2 info);
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
        nuevo->setSiguiente(primero); // Se enlaza el nuevo Nodo2 al primero
        nuevo->setAnterior(ultimo);   // Se enlaza el nuevo Nodo2 al último
        primero = nuevo;              // Se verifica que el Nodo2 creado sea el primero
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
        nuevo->setAnterior(ultimo);  // Se enlaza el nuevo Nodo2 al último
        ultimo = nuevo;              // Se verfica que el Nodo2 creado sea el último
    }
    Enlazada::size++;
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

        do
        {
            /* code */
            Nodo2Dato = actual->getNombre();
            cout << actual->getDato() << ". " << "nombre: " << Nodo2Dato << " Asiento:" << actual->getAsiento() << " Vuelo: " << actual->getVuelo() << endl;
            actual = actual->getSiguiente();
        } while (actual != nullptr);
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
        if (primero == ultimo)
        {
            return *primero;
        }
        else
        {
            while (temporal != nullptr)
            {
                /* code */
                if (temporal == ultimo)
                {
                    encontrado = true;
                    break;
                }
                else
                {
                    temporal = temporal->getSiguiente();
                }
            }
        }
    }
    if (encontrado)
    {
        return *temporal;
    }
    else
    {
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

        int vuelo = stoi(ptr1->getVuelo().erase(0, 1));
        cout << "Vuelo: " << vuelo << endl;
        int vuelo2 = stoi(ptr1->getSiguiente()->getVuelo().erase(0, 1));
        cout << "Vuelo2: " << vuelo2 << endl;

        while (ptr1->getSiguiente() != lptr)
        {
            cout << "cliclos" << endl;
            if ((vuelo > vuelo2) || (vuelo < vuelo2) || (vuelo == vuelo2 && ptr1->getAsiento() > ptr1->getSiguiente()->getAsiento()) || (vuelo == vuelo2 && ptr1->getAsiento() < ptr1->getSiguiente()->getAsiento()))
            {
                swap(ptr1, ptr1->getSiguiente());
                swapped = true;
            }
            ptr1 = ptr1->getSiguiente();
        }
        lptr = ptr1;
    } while (swapped);
}


void Enlazada::swap(Nodo2 *a, Nodo2 *b)
{
    string tempNombre = a->getNombre();
    int tempAsiento = a->getAsiento();
    string tempVuelo = a->getVuelo();
    string tempPasaporte = a->getPasaporte();
    string tempDestino = a->getDestino();
    string tempOrigen = a->getOrigen();
    int tempEquipaje = a->getEquipaje();
    string tempNacionalidad = a->getNacionalidad();

    a->setNombre(b->getNombre());
    a->setAsiento(b->getAsiento());
    a->setVuelo(b->getVuelo());
    a->setPasaporte(b->getPasaporte());
    a->setDestino(b->getDestino());
    a->setOrigen(b->getOrigen());
    a->setEquipaje(b->getEquipaje());
    a->setNacionalidad(b->getNacionalidad());


    b->setNombre(tempNombre);
    b->setAsiento(tempAsiento);
    b->setVuelo(tempVuelo);
    b->setPasaporte(tempPasaporte);
    b->setDestino(tempDestino);
    b->setOrigen(tempOrigen);
    b->setEquipaje(tempEquipaje);
    b->setNacionalidad(tempNacionalidad);
    
};

Nodo2 Enlazada::getPorIndice(int i)
{

    bool encontrado = false;
    if (estaVacia())
    {
        return *primero;
    }
    else
    {

        int nodoDato;
        Nodo2 *actual = primero;

        do
        {
            int pos = actual->getDato();

            if (actual->getDato() == i)
            {
                encontrado = true;
            }
            actual = actual->getSiguiente();
        } while (actual != primero);

        if (encontrado)
        {
            return *actual;
        }
        else
        {
            Nodo2 *nulo = new Nodo2(0);
            return *nulo;
        }
    }
};

Nodo2 Enlazada::Pasajero(string a){

    if(estaVacia()){
        return *primero;
    }else{
        Nodo2 *actual = primero;
        bool encontrado = false;
        do{
            if(actual->getPasaporte() == a){
                encontrado = true;
                break;
            }else{
            actual = actual->getSiguiente();
            }


        }while(actual != ultimo);

        if(encontrado){
            return *actual;
        }else{
            Nodo2 *nulo = new Nodo2(0);
            return *nulo;
        }
    }
};

void Enlazada::generarReporte(){
    if (Enlazada::estaVacia()){
        cout << "La lista está vacía\n" << endl;
        return;
    }
    else
    {
        ofstream archivo; //
        archivo.open("grafica_Atendidos.dot", ios::out);
        archivo << "digraph G { " << endl << "rankdir = LR;" << endl << "label=\"Lista Enlazada\";" << "bgcolor=grey "<< endl 
        <<"subgraph cluster_top_floor{" << endl << "bgcolor=wheat; " << endl;
        archivo << "label=\"Pasajeros con equipaje ingresado\";"<< endl;

        string nodoDato;
        Nodo2 *actual = primero;
        int conteo = 0;

        do
        {   
            //cout << getSize() << endl;
            nodoDato = actual->getNombre();
            archivo <<"nodo"<< conteo << "[ shape=cds , fontcolor=aliceblue , style=filled , color=chocolate , label=\"Nombre: " <<nodoDato << ", Pasaporte:" 
            << actual->getPasaporte() << "\"]" <<endl;
            //archivo << " -> ";
            actual = actual->getSiguiente();
            
            conteo++;
        } while (conteo != size);

        archivo << "nul" << "[ shape=cds , fontcolor=aliceblue , style=filled , color=chocolate , label=\"Null \"]" <<endl;
        archivo << "nul2" << "[ shape=cds , fontcolor=aliceblue , style=filled , color=chocolate , label=\"Null \"]" <<endl;

        int sizee = 0;

        //primeros enlazados ->
         do{

            //cout << "do2 " << endl;
            if(sizee +1 == size){
                archivo << "nodo" << sizee;
            }else{
                archivo << "nodo" << sizee << " -> ";
            }
            
            sizee++;
        }while(sizee != size);



        int sizee2 = size-1;


        archivo <<";" << endl;

        archivo << "nodo" << (size-1) << " -> " << "nul" << endl;

        //segundos enlazados <-
        do{

            //cout << "do2 " << endl;
            if(sizee-1 == 0){
                archivo << "nodo" << (sizee-1) << ";" <<endl;
            }else{
                archivo << "nodo" << (sizee-1) << " -> ";
            }
            sizee--;
        }while(sizee != 0);

        archivo << "nodo0 -> nul2" ;
        archivo << ";" << endl <<"}" << endl << "}";
        archivo.close();
        system("dot -Tpng grafica_Atendidos.dot -o grafica_Atendidos.png");
        system("open grafica_Atendidos.png");
    }

};

void Enlazada::generarReporte2(Nodo2 info){

    if (Enlazada::estaVacia()){
        cout << "La lista está vacía\n" << endl;
        return;
    }
    else
    {
        ofstream archivo; //
        archivo.open("grafica_Pasajero.dot", ios::out);
        archivo << "digraph G { " << endl << "rankdir = LR;" << endl << "label=\"Lista Enlazada\";" << "bgcolor=grey "<< endl 
        <<"subgraph cluster_top_floor{" << endl << "bgcolor=wheat; " << endl;
        archivo << "label=\"Pasajero Buscado\";"<< endl;

      
  
        archivo <<"nodo[ shape=cds , fontcolor=aliceblue , style=filled , color=chocolate , label=\"Nombre: " << info.getNombre() << ", Pasaporte:" 
        << info.getPasaporte() << "\"]" <<endl;
        
        archivo << "nodo" << endl;
        archivo << ";" << endl <<"}" << endl << "}";
        archivo.close();
        system("dot -Tpng grafica_Pasajero.dot -o grafica_Pasajero.png");
        system("open grafica_Pasajero.png");
        
    }
};

void Enlazada::ordenar()
{
    if (!primero || primero->getSiguiente() == primero)
    {
        return;
    }

    bool cambio;

    int ciclo2 = 0;
    do
    {
        cambio = false;
        Nodo2 *actual = primero;
        Nodo2 *siguiente = actual->getSiguiente();
       

        // cout << "Vuelo: " << vuelo  << " Asiento:" << actual->getAsiento() << endl;
        // cout << "Vuelo2: " << vuelo2 << " Asiento:" << siguiente->getAsiento() << endl;


        int ciclio = 0;
        do
        {
            
            if (ciclio == size-1)
            {
                break;
            }
            else
            {
                Nodo2 *siguiente = actual->getSiguiente();
                int vuelo = stoi(actual->getVuelo().erase(0, 1));
                int vuelo2 = stoi(siguiente->getVuelo().erase(0, 1));
                // cout << "Vuelo: " << vuelo  << " Asiento:" << actual->getAsiento() << endl;
                // cout << "Vuelo2: " << vuelo2 << " Asiento:" << siguiente->getAsiento() << endl;

                if ((vuelo > vuelo2) ||
                    (vuelo == vuelo2 && actual->getAsiento() > siguiente->getAsiento()))
                {
                    // Intercambiar los datos de los nodos
                    int tempVuelo = vuelo;
                    int tempAsiento = actual->getAsiento();
                    vuelo = vuelo2;
                    swap(actual, siguiente);
                }
                
                actual = actual->getSiguiente();
                
                ciclio++;
            }

        } while (ciclio < size);
        ciclo2++;
    } while (ciclo2 < size);
};




Enlazada::~Enlazada(){};
