#pragma once
#include "Nodo.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class Type>
class Lista {
protected:
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
	void agregar(const Type&, const Type&);
	void eliminarPorCabeza();
	void pop();
	void eliminar(const Type&);
	int getSize();
	
	void mostrar();
};

template <class Type>
Lista<Type>::Lista() {
	this->inicio = NULL;
	this->fin = NULL;
	this->size = 0;
}

template <class Type>
bool Lista<Type>::buscar(const Type& dato) const {
	Nodo<Type>* aux = inicio;
	while (aux != NULL) {
		if (aux->dato == dato) {
			return true;
		}
		aux = aux->siguiente;
	}
	return false;
}

template <class Type>
bool Lista<Type>::estaVacia() {
	return inicio == NULL;
}

template <class Type>
void Lista<Type>::mostrar() {
	Nodo<Type>* aux = inicio;
	while (aux != NULL) {
		cout << aux->dato << " ";
		aux = aux->siguiente;
	}
	cout << endl;
}

template <class Type>
void Lista<Type>::push(const Type& dato) {
	nuevoNodo = new Nodo<Type>(dato);
	if (estaVacia()) {
		inicio = nuevoNodo;
		fin = nuevoNodo;
	}
	else {
		nuevoNodo->siguiente = inicio;
		inicio->anterior = nuevoNodo;
		inicio = nuevoNodo;
	}
	size++;
}

template <class Type>
void Lista<Type>::agregarPorCola(const Type& dato) {
	nuevoNodo = new Nodo<Type>(dato);
	if (estaVacia()) {
		inicio = nuevoNodo;
		fin = nuevoNodo;
	}
	else {
		fin->siguiente = nuevoNodo;
		nuevoNodo->anterior = fin;
		fin = nuevoNodo;
	}
	size++;
}

template <class Type>
void Lista<Type>::agregar(const Type& nuevoDato, const Type& dato) {
	nuevoNodo = new Nodo<Type>(nuevoDato);
	nuevoNodo->siguiente = NULL;

	Nodo<Type>* p;
	Nodo<Type>* q;
	p = inicio;
	q = inicio->siguiente;
	if (estaVacia()) {
		cout << "Por favor agregar por cabeza o por cola antes: " << endl;
	}
	else {
		bool encontrado = false;
		while (!encontrado) {
			if (p->dato == dato) {
				encontrado = true;
				if (q == inicio) {
					p->siguiente = nuevoNodo;
					nuevoNodo->anterior = p;
					nuevoNodo->siguiente = inicio;
					fin = nuevoNodo;
				}
				else {
					p->siguiente = nuevoNodo;
					nuevoNodo->anterior = p;
					nuevoNodo->siguiente = q;
					q->anterior = nuevoNodo;
				}
			}
			else {
				p = q;
				q = q->siguiente;
			}
		}
	}
	size++;
}

template <class Type>
void Lista<Type>::eliminarPorCabeza() {
	if (estaVacia()) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		Nodo<Type>* aux = inicio;
		inicio = inicio->siguiente;
		delete aux;
		size--;
	}
}

template <class Type>
void Lista<Type>::pop() {
	if (estaVacia()) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		Nodo<Type>* aux = inicio;
		inicio = inicio->siguiente;
		delete aux;
		size--;
	}
}

template <class Type>
void Lista<Type>::eliminar(const Type& datoBuscado) {

	Nodo<Type>* p;
	Nodo<Type>* q;
	p = inicio;
	q = inicio->siguiente;
	bool encontrado = false;
	if (inicio == NULL) {
		cout << "No se puede borrar una lista vacia" << endl;
	}
	else {
		while (!encontrado) {
			if (q->dato == datoBuscado) {
				encontrado = true;
				if (q->siguiente = inicio) {
					p->siguiente = inicio;
					fin = p;
				}
				else {
					p->siguiente = q->siguiente;
					q->siguiente->anterior = p;
				}
			}
			else {
				p = q;
				q = q->siguiente;
			}
		}
		delete q;
	}
	size--;
}

template <class Type>
int Lista<Type>::getSize() {
	return size;
}


