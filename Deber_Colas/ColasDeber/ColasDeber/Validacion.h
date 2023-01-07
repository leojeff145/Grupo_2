#pragma once
#include <cstdlib>
#include <iostream>

using namespace std;

class Validacion
{
public:
	void mostrarFormato();
	
};


void Validacion::mostrarFormato() {
	cout << "Cliente\t" << "	Tiempo de llegada\t" << "Tiempo de espera\t" << "Tiempo que Cajero no Trabaja\t" << "Tiempo de servicio\t" << "Tiempo de salida\t" << "Tiempo entre llegadas" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
