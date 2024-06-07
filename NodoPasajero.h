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
    int asiento;
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
    void setEquipaje(int equipaje);

    void setDato(int dato);
    string getNacionalidad();
    void setNacionalidad(string nacionalidad);
    string getPasaporte();
    void setPasaporte(string pasaporte);
    string getVuelo();
    void setVuelo(string vuelo);
    int getAsiento();
    void setAsiento(int asiento);
    string getDestino();
    void setDestino(string destino);
    string getOrigen();
    void setOrigen(string origen);


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

void Nodo::setDato(int dato){
    this->dato = dato;
}

int Nodo::getEquipaje(){
    return this->equipaje;
}

 void Nodo::setEquipaje(int equipaje){
    this->equipaje = equipaje;
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

int Nodo::getAsiento(){
    return this->asiento;
}

void Nodo::setAsiento(int asiento){
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

Nodo::~Nodo()
{
}