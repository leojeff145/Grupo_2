#pragma once
#include "Nodo.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class Type>
class Lista {
private:
	Nodo<Type>* inicio;
	Nodo<Type>* fin;
	Nodo<Type>* nuevoNodo;
	int size;
public:
	Lista();
	bool buscar(const Type&) const;
	bool estaVacia();
	void push(const Type&);
	void agregarPorCola(const Type&);
	void agregar(const Type&);
	void eliminarPorCabeza();
	void pop();
	void eliminar(const Type&);
	int getSize();
	
	void mostrar();
};

template <class Type>
Lista<Type>::Lista() {
	inicio = NULL;
	fin = NULL;
	size = 0;
}
