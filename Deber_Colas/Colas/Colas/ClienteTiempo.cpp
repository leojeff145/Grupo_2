#include "ClienteTiempo.h"
#include <iostream>

using namespace std;


ClienteTiempo::ClienteTiempo()
{
	NumCalc calculo;

	this->numCliente = 1;
	this->tiempoLlegada = calculo.numRandom(1, 25);
	this->tiempoEspera = 0;
	this->tiempoNoTrabajaCajero = 0;
	this->tiempoServicio = calculo.numRandom(1, 16);
	this->tiempoSalida = tiempoLlegada + tiempoEspera + tiempoServicio;
	this->tiempoEntreLlegada = tiempoLlegada;
}


ClienteTiempo::~ClienteTiempo()
{
}

//setters y getters
int ClienteTiempo::getNumCliente(void)
{
	return this->numCliente;
}

void ClienteTiempo::setNumCliente(int newNumCliente)
{
	this->numCliente = newNumCliente;
}

int ClienteTiempo::getTiempoLlegada(void)
{
	return this->tiempoLlegada;
}

void ClienteTiempo::setTiempoLlegada(int newTiempoLlegada)
{
	this->tiempoLlegada = newTiempoLlegada;
}

int ClienteTiempo::getTiempoEspera(void)
{
	return this->tiempoEspera;
}

void ClienteTiempo::setTiempoEspera(int newTiempoEspera)
{
	this->tiempoEspera = newTiempoEspera;
}

int ClienteTiempo::getTiempoNoTrabajaCajero(void)
{
	return this->tiempoNoTrabajaCajero;
}

void ClienteTiempo::setTiempoNoTrabajaCajero(int newTiempoNoTrabajaCajero)
{
	this->tiempoNoTrabajaCajero = newTiempoNoTrabajaCajero;
}

int ClienteTiempo::getTiempoServicio(void)
{
	return this->tiempoServicio;
}

void ClienteTiempo::setTiempoServicio(int newTiempoServicio)
{
	this->tiempoServicio = newTiempoServicio;
}

int ClienteTiempo::getTiempoSalida(void)
{
	return this->tiempoSalida;
}

void ClienteTiempo::setTiempoSalida(int newTiempoSalida)
{
	this->tiempoSalida = newTiempoSalida;
}

int ClienteTiempo::getTiempoEntreLlegada(void)
{
	return this->tiempoEntreLlegada;
}

void ClienteTiempo::setTiempoEntreLlegada(int newTiempoEntreLlegada)
{
	this->tiempoEntreLlegada = newTiempoEntreLlegada;
}

//funciones de la clase

void ClienteTiempo::iniciarDatos(int numCliente, int tiempoLlegada, int tiempoEspera, int tiempoNoTrabajaCajero, int tiempoServicio, int tiempoSalida, int tiempoEntreLlegada)
{
	this->numCliente = numCliente;
	this->tiempoLlegada = tiempoLlegada;
	this->tiempoEspera = tiempoEspera;
	this->tiempoNoTrabajaCajero = tiempoNoTrabajaCajero;
	this->tiempoServicio = tiempoServicio;
	this->tiempoSalida = tiempoSalida;
	this->tiempoEntreLlegada = tiempoEntreLlegada;
}

void ClienteTiempo::calcularTiempos(ClienteTiempo& cliente)
{
	NumCalc calculo;
	int n = cliente.getNumCliente();
	int llegadaAnterior = cliente.getTiempoLlegada();
	int salidaAnterior = cliente.getTiempoSalida();
	int entreLlegadas = cliente.getTiempoEntreLlegada();

	int llegada, espera, cajeroNoTrabaja,
		servicio, salida;

	n++;
	llegada = llegadaAnterior + calculo.numRandom(1, 25);
	espera = (calculo.numMax(salidaAnterior, llegada)) - llegada;
	servicio = calculo.numRandom(1, 16);
	salida = llegada + espera + servicio;
	cajeroNoTrabaja = (calculo.numMax(llegada, salidaAnterior)) - salidaAnterior;
	entreLlegadas = llegada;
	entreLlegadas -= llegadaAnterior;

	iniciarDatos(n, llegada, espera, cajeroNoTrabaja, servicio, salida, entreLlegadas);


}

void ClienteTiempo::mostrarTiempos() {
	cout << numCliente << "\t\t\t" << tiempoLlegada << "\t\t\t" << tiempoEspera << "\t\t\t" << tiempoNoTrabajaCajero << "\t\t\t" << tiempoServicio << "\t\t\t" << tiempoSalida << "\t\t\t" << tiempoEntreLlegada << endl;
	cout << "_____________________________________________________________________________________________________________________________________________________________" << endl;
}
