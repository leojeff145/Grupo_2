#pragma once
#include "NodoDoble.h"
#include "ClienteTiempo.h"
#include <iostream>

using namespace std;


template <typename T>
class Cola
{
private:
	NodoDoble<T>* primero;
	NodoDoble<T>* ultimo;
	int size;
public:
	Cola();
	~Cola();
	void push(T dato);
	T pop(void);
	T peek(void);
	bool isEmpty(void);
	int getSize(void);
	
	//metodos adicionales
	bool buscar(const T&) const;
	void agregarPorCola(const T&);
	void agregar(const T&, const T&);
	void eliminarPorCabeza();
	void eliminar(const T&);
	//void mostrar();
	void mostrar() const;
	void calcularPromedio(int n);
	void mostrarPromedio(float, float, float, float);
	
};

template <typename T>
Cola<T>::Cola()
{
	primero = nullptr;
	ultimo = nullptr;
	size = 0;
}

template <typename T>
Cola<T>::~Cola()
{
}

template <typename T>
void Cola<T>::push(T dato)
{
	NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
	if (primero == nullptr)
	{
		primero = nuevo;
		ultimo = nuevo;
	}
	else
	{
		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		ultimo = nuevo;
	}
	size++;
}

template <typename T>
T Cola<T>::pop(void)
{
	if (primero != nullptr)
	{
		NodoDoble<T>* aux = primero;
		primero = primero->getSiguiente();
		if (primero != nullptr)
		{
			primero->setAnterior(nullptr);
		}
		else
		{
			ultimo = nullptr;
		}
		size--;
		T dato = aux->getDato();
		delete aux;
		return dato;
	}
	else
	{
		throw "Cola vacia";
	}
}

template <typename T>
T Cola<T>::peek(void)
{
	if (primero != nullptr)
	{
		return primero->getDato();
	}
	else
	{
		throw "Cola vacia";
	}
}

template <typename T>
bool Cola<T>::isEmpty(void)
{
	return primero == nullptr;
}

template <typename T>
int Cola<T>::getSize(void)
{
	return size;
}

//metodos adicionales

template <typename T>
bool Cola<T>::buscar(const T& dato) const
{
	NodoDoble<T>* aux = primero;
	while (aux != nullptr)
	{
		if (aux->getDato() == dato)
		{
			return true;
		}
		aux = aux->getSiguiente();
	}
	return false;
}

template <typename T>
void Cola<T>::agregarPorCola(const T& dato)
{
	NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
	if (primero == nullptr)
	{
		primero = nuevo;
		ultimo = nuevo;
	}
	else
	{
		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		ultimo = nuevo;
	}
	size++;
}

template <typename T>
void Cola<T>::agregar(const T& dato, const T& dato2)
{
	NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
	if (primero == nullptr)
	{
		primero = nuevo;
		ultimo = nuevo;
	}
	else
	{
		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		ultimo = nuevo;
	}
	size++;
}

template <typename T>
void Cola<T>::eliminarPorCabeza()
{
	if (primero != nullptr)
	{
		NodoDoble<T>* aux = primero;
		primero = primero->getSiguiente();
		if (primero != nullptr)
		{
			primero->setAnterior(nullptr);
		}
		else
		{
			ultimo = nullptr;
		}
		size--;
		delete aux;
	}
	else
	{
		throw "Cola vacia";
	}
}

template <typename T>
void Cola<T>::eliminar(const T& dato)
{
	if (primero != nullptr)
	{
		NodoDoble<T>* aux = primero;
		while (aux != nullptr)
		{
			if (aux->getDato() == dato)
			{
				if (aux == primero)
				{
					primero = primero->getSiguiente();
					if (primero != nullptr)
					{
						primero->setAnterior(nullptr);
					}
					else
					{
						ultimo = nullptr;
					}
					size--;
					delete aux;
					return;
				}
				else if (aux == ultimo)
				{
					ultimo = ultimo->getAnterior();
					if (ultimo != nullptr)
					{
						ultimo->setSiguiente(nullptr);
					}
					else
					{
						primero = nullptr;
					}
					size--;
					delete aux;
					return;
				}
				else
				{
					aux->getAnterior()->setSiguiente(aux->getSiguiente());
					aux->getSiguiente()->setAnterior(aux->getAnterior());
					size--;
					delete aux;
					return;
				}
			}
			aux = aux->getSiguiente();
		}
	}
	else
	{
		throw "Cola vacia";
	}
}

template <typename T>
void Cola<T>::mostrar() const
{
	NodoDoble<ClienteTiempo>* p = primero;
	
	for (int i = 0; i < size; i++) {
		p->getDato().mostrarTiempos();
		p = p->getSiguiente();
	}
}

template <typename T>
void mostrarPromedio(float espera, float noTrabaja, float clientesEnCola, float servicio) {
	cout << "________________________________________________________" << endl;
	cout << "Promedio de tiempo de espera: " << espera << " minutos" << endl;
	cout << "Promedio de tiempo que el cajero no trabaja: " << noTrabaja << " minutos" << endl;
	cout << "Numero de clientes que esperaron en cola: " << clientesEnCola << endl;
	cout << "Promedio de tiempo de servicio: " << servicio << " minutos" << endl;
	cout << "________________________________________________________";
}

template <typename T>
void calcularPromedio(int n){
	float espera, noTrabaja, servicio;
	int clientesEnCola = 0;

	NodoDoble<ClienteTiempo>* p = primero;
	espera = p->getDato().getTiempoEspera();
	noTrabaja = p->getDato().getTiempoNoTrabajaCajero();
	servicio = p->getDato().getTiempoServicio();

	for (int i = 0; i < size; i++) {
		if (p->getDato().getTiempoEspera() > 0)
			clientesEnCola++;
		espera += p->getDato().getTiempoEspera();
		noTrabaja += p->getDato().getTiempoNoTrabajaCajero;
		servicio += p->getDato().getTiempoServicio();
		p = p->getSiguiente();
	}

	espera = espera / n;
	noTrabaja = noTrabaja / n;
	servicio = servicio / n;

	mostrarPromedio(espera, noTrabaja, clientesEnCola, servicio);
}



