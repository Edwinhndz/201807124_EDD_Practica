#include <iostream>
#include <string>
using namespace std;

class Nodo
{
private:
    /* data */
    int dato;
    string nombre;
    string nacionalidad;
    string pasaporte;
    string vuelo;
    string asiento;
    string destino;
    string origen;
    int equipaje;
    
    Nodo *siguiente;
public:
    Nodo(int dato);
    Nodo *getSiguiente();
    void setSiguiente(Nodo *siguiente);
    int getDato();
    int getEquipaje();
    string getNombre();
    void setNombre(string nombre);
    string getNacionalidad();
    void setNacionalidad(string nacionalidad);
    string getPasaporte();
    void setPasaporte(string pasaporte);
    string getVuelo();
    void setVuelo(string vuelo);
    string getAsiento();
    void setAsiento(string asiento);
    string getDestino();
    void setDestino(string destino);
    string getOrigen();
    void setOrigen(string origen);
    void setEquipaje(int equipaje);
    

    void setDato(int dato);
    ~Nodo();
};

Nodo::Nodo(int dato)
{
    this->dato = dato;
    this->siguiente = nullptr;
}

Nodo* Nodo::getSiguiente(){
    return this->siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente){
    this->siguiente = siguiente;
}

int Nodo::getDato(){
    return this->dato;
}

int Nodo::getEquipaje(){
    return this->equipaje;
}

string Nodo::getNombre(){
    return this->nombre;
}

void Nodo::setNombre(string nombre){
    this->nombre = nombre;
}

string Nodo::getNacionalidad(){
    return this->nacionalidad;
}

void Nodo::setNacionalidad(string nacionalidad){
    this->nacionalidad = nacionalidad;
}

string Nodo::getPasaporte(){
    return this->pasaporte;
}

void Nodo::setPasaporte(string pasaporte){
    this->pasaporte = pasaporte;
}

string Nodo::getVuelo(){
    return this->vuelo;
}

void Nodo::setVuelo(string vuelo){
    this->vuelo = vuelo;
}

string Nodo::getAsiento(){
    return this->asiento;
}

void Nodo::setAsiento(string asiento){
    this->asiento = asiento;
}

string Nodo::getDestino(){
    return this->destino;
}

void Nodo::setDestino(string destino){
    this->destino = destino;
}

string Nodo::getOrigen(){
    return this->origen;
}

void Nodo::setOrigen(string origen){
    this->origen = origen;
}

void Nodo::setEquipaje(int equipaje){
    this->equipaje = equipaje;
}


Nodo::~Nodo()
{
}