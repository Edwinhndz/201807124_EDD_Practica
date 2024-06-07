#include <iostream>
#include <string>
using namespace std;

class Nodo
{
private:
    /* data */
    int dato;
    string nombre;
    string registro;
    string modelo;
    string fabricante;
    int anio;
    int capacidad;
    int pesoMax;
    string aerolinea;
    string estado;


    Nodo *anterior;
    Nodo *siguiente;
public:
    Nodo(int dato);
    Nodo *getSiguiente();
    Nodo *getAnterior();
    void setSiguiente(Nodo *siguiente);
    void setAnterior(Nodo *anterior);
    int getDato();
    void setDato(int dato);

    string getNombre();
    void setNombre(string nombre);
    string getRegistro();
    void setRegistro(string registro);
    string getModelo();
    void setModelo(string modelo);
    string getFabricante();
    void setFabricante(string fabricante);
    int getAnio();
    void setAnio(int anio);
    int getCapacidad();
    void setCapacidad(int capacidad);
    int getPesoMax();
    void setPesoMax(int pesoMax);
    string getAerolinea();
    void setAerolinea(string linea);
    string getEstado();
    void setEstado(string estado);

    ~Nodo();
};

Nodo::Nodo(int dato)
{
    this->dato = dato;
    this->anterior = nullptr;
    this->siguiente = nullptr;
}

int Nodo::getDato(){
    return this->dato;
}

void Nodo::setDato(int dato){
    this->dato = dato;
}

string Nodo::getNombre(){
    return this->nombre;
}

void Nodo::setNombre(string nombre){
    this->nombre = nombre;
}

string Nodo::getRegistro(){
    return this->registro;
}

void Nodo::setRegistro(string registro){
    this->registro = registro;
}

string Nodo::getModelo(){
    return this->modelo;
}

void Nodo::setModelo(string modelo){
    this->modelo = modelo;
}

string Nodo::getFabricante(){
    return this->fabricante;
}

void Nodo::setFabricante(string fabricante){
    this->fabricante = fabricante;
}

int Nodo::getAnio(){
    return this->anio;
}

void Nodo::setAnio(int anio){
    this->anio = anio;
}

int Nodo::getCapacidad(){
    return this->capacidad;
}

void Nodo::setCapacidad(int capacidad){
    this->capacidad = capacidad;
}

int Nodo::getPesoMax(){
    return this->pesoMax;
}

void Nodo::setPesoMax(int pesoMax){
    this->pesoMax = pesoMax;
}

string Nodo::getAerolinea(){
    return this->aerolinea;
}

void Nodo::setAerolinea(string aerolinea){
    this->aerolinea = aerolinea;
}

string Nodo::getEstado(){
    return this->estado;
}

void Nodo::setEstado(string estado){
    this->estado = estado;
}


Nodo* Nodo::getSiguiente(){
    return this->siguiente;
}

Nodo* Nodo::getAnterior(){
    return this->anterior;
}

void Nodo::setSiguiente(Nodo *siguiente){
    this->siguiente = siguiente;
}

void Nodo::setAnterior(Nodo *anterior){
    this->anterior = anterior;
}

int Nodo::getDato(){
    return this->dato;
}


Nodo::~Nodo()
{
}