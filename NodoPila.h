#include <iostream>
#include <string>
using namespace std;

class Nodop
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
    
    Nodop *siguiente;
public:
    Nodop(int dato);
    Nodop *getSiguiente();
    void setSiguiente(Nodop *siguiente);
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


    ~Nodop();
};

Nodop::Nodop(int dato)
{
    this->dato = dato;
    this->siguiente = nullptr;
}

Nodop* Nodop::getSiguiente(){
    return this->siguiente;
}

void Nodop::setSiguiente(Nodop *siguiente){
    this->siguiente = siguiente;
}

int Nodop::getDato(){
    return this->dato;
}

void Nodop::setDato(int dato){
    this->dato = dato;
}

int Nodop::getEquipaje(){
    return this->equipaje;
}

 void Nodop::setEquipaje(int equipaje){
    this->equipaje = equipaje;
 }

string Nodop::getNombre(){
    return this->nombre;
}

void Nodop::setNombre(string nombre){
    this->nombre = nombre;
}

string Nodop::getNacionalidad(){
    return this->nacionalidad;
}

void Nodop::setNacionalidad(string nacionalidad){
    this->nacionalidad = nacionalidad;
}

string Nodop::getPasaporte(){
    return this->pasaporte;
}

void Nodop::setPasaporte(string pasaporte){
    this->pasaporte = pasaporte;
}

string Nodop::getVuelo(){
    return this->vuelo;
}

void Nodop::setVuelo(string vuelo){
    this->vuelo = vuelo;
}

int Nodop::getAsiento(){
    return this->asiento;
}

void Nodop::setAsiento(int asiento){
    this->asiento = asiento;
}

string Nodop::getDestino(){
    return this->destino;
}

void Nodop::setDestino(string destino){
    this->destino = destino;
}

string Nodop::getOrigen(){
    return this->origen;
}

void Nodop::setOrigen(string origen){
    this->origen = origen;
}

Nodop::~Nodop()
{
}