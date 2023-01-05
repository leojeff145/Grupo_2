#pragma once
#include "NumCalc.h"
class ClienteTiempo
{
private:
	int numCliente;
	int tiempoLlegada;
	int tiempoEspera;
	int tiempoNoTrabajaCajero;
	int tiempoServicio;
	int tiempoSalida;
	int tiempoEntreLlegada;
public:
	ClienteTiempo();	
	~ClienteTiempo();
	
	
	//setters y getters
	int getNumCliente(void);
	void setNumCliente(int newNumCliente);
	int getTiempoLlegada(void);
	void setTiempoLlegada(int newTiempoLlegada);
	int getTiempoEspera(void);
	void setTiempoEspera(int newTiempoEspera);
	int getTiempoNoTrabajaCajero(void);
	void setTiempoNoTrabajaCajero(int newTiempoNoTrabajaCajero);
	int getTiempoServicio(void);
	void setTiempoServicio(int newTiempoServicio);
	int getTiempoSalida(void);
	void setTiempoSalida(int newTiempoSalida);
	int getTiempoEntreLlegada(void);
	void setTiempoEntreLlegada(int newTiempoEntreLlegada);
	
	
	//funciones de la clase
	void iniciarDatos(int, int, int, int, int, int, int);
	void calcularTiempos(ClienteTiempo&);
	void mostrarTiempos();
};

