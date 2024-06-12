#include <iostream>
#include <string>
using namespace std;

class Nodo2
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
    
    Nodo2 *siguiente;
    Nodo2 *anterior;
public:
    Nodo2(int dato);
    Nodo2 *getSiguiente();
    void setSiguiente(Nodo2 *siguiente);
    Nodo2 *getAnterior();
    void setAnterior(Nodo2 *anterior);
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


    ~Nodo2();
};

Nodo2::Nodo2(int dato)
{
    this->dato = dato;
    this->siguiente = nullptr;
}

Nodo2* Nodo2::getSiguiente(){
    return this->siguiente;
}

void Nodo2::setSiguiente(Nodo2 *siguiente){
    this->siguiente = siguiente;
}

Nodo2* Nodo2::getAnterior(){
    return this->anterior;
}
void Nodo2::setAnterior(Nodo2 *anterior){
    this->anterior = anterior;
}

int Nodo2::getDato(){
    return this->dato;
}

void Nodo2::setDato(int dato){
    this->dato = dato;
}

int Nodo2::getEquipaje(){
    return this->equipaje;
}

 void Nodo2::setEquipaje(int equipaje){
    this->equipaje = equipaje;
 }

string Nodo2::getNombre(){
    return this->nombre;
}

void Nodo2::setNombre(string nombre){
    this->nombre = nombre;
}

string Nodo2::getNacionalidad(){
    return this->nacionalidad;
}

void Nodo2::setNacionalidad(string nacionalidad){
    this->nacionalidad = nacionalidad;
}

string Nodo2::getPasaporte(){
    return this->pasaporte;
}

void Nodo2::setPasaporte(string pasaporte){
    this->pasaporte = pasaporte;
}

string Nodo2::getVuelo(){
    return this->vuelo;
}

void Nodo2::setVuelo(string vuelo){
    this->vuelo = vuelo;
}

int Nodo2::getAsiento(){
    return this->asiento;
}

void Nodo2::setAsiento(int asiento){
    this->asiento = asiento;
}

string Nodo2::getDestino(){
    return this->destino;
}

void Nodo2::setDestino(string destino){
    this->destino = destino;
}

string Nodo2::getOrigen(){
    return this->origen;
}

void Nodo2::setOrigen(string origen){
    this->origen = origen;
}

Nodo2::~Nodo2()
{
}