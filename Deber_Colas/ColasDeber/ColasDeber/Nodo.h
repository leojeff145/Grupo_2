#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

template <class Type>
class Nodo {
private:
	Type dato;
	Nodo<Type>* siguiente;
	Nodo<Type>* anterior;
public:

	Nodo() = default;
	Nodo(Type);

	template <class Type>
	friend class Lista;
	friend class Cola;

};

template <class Type>
Nodo<Type>::Nodo(Type dato) {
	this->dato = dato;	
}

