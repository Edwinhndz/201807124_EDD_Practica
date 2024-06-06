
#include <string>
#include "NodoP.cpp"
#include <iostream>

struct Cola {
    public:
    void insertarNodo(int dato);
    void desplegarCola();
    NodoPasajero *primero;

    Cola(){
        primero = NULL;
    };

};


void Cola::insertarNodo(int dato){
	NodoPasajero* nuevo = new NodoPasajero();
	cout << " Ingrese el dato del nuevo Nodo: ";
	nuevo->asiento = dato;

	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
	}else{
		nuevo->siguiente = NULL;
	}
	cout << endl << " Nodo Ingresado " << endl << endl;
}

void Cola::desplegarCola(){
	NodoPasajero *actual = new NodoPasajero();
	actual = primero;
	if(primero!=NULL){
		while(actual!=NULL){
			cout << endl << " " << actual->asiento;
			actual = actual->siguiente;
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
}