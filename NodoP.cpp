#include <string>
using namespace std;


class NodoPasajero
{
public:
    /* data */
    
    std::string  nombre;
    std::string  nacionalidad;
    std::string pasaporte;
    std::string  vuelo;
    std::string  asiento;  
    std::string  destino;
    std::string  origen;
    int equipaje;
    NodoPasajero *siguiente;

    NodoPasajero(std::string name, std::string nacio, std::string passapor, std::string vuelo, std::string asiento, std::string dest, std::string org, int equipaje);
    NodoPasajero();
};

