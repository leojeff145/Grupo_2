#pragma once
template <typename T>
class NodoDoble
{
private:
	T dato;
	NodoDoble<T>* siguiente;
	NodoDoble<T>* anterior;
public:
	NodoDoble(T dato);
	~NodoDoble();
	T getDato(void);
	void setDato(T newDato);
	NodoDoble<T>* getSiguiente(void);
	void setSiguiente(NodoDoble<T>* newSiguiente);
	NodoDoble<T>* getAnterior(void);
	void setAnterior(NodoDoble<T>* newAnterior);
	
	template <typename T>
	friend class Cola;
};

template <typename T>
NodoDoble<T>::NodoDoble(T dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

template <typename T>
NodoDoble<T>::~NodoDoble()
{
}

template <typename T>
T NodoDoble<T>::getDato(void)
{
	return dato;
}

template <typename T>
void NodoDoble<T>::setDato(T newDato)
{
	dato = newDato;
}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getSiguiente(void)
{
	return siguiente;
}

template <typename T>
void NodoDoble<T>::setSiguiente(NodoDoble<T>* newSiguiente)
{
	siguiente = newSiguiente;
}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getAnterior(void)
{
	return anterior;
}

template <typename T>
void NodoDoble<T>::setAnterior(NodoDoble<T>* newAnterior)
{
	anterior = newAnterior;
}
