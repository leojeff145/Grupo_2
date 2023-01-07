#include "Calculo.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;


int Calculo::random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int Calculo::max(int a, int b) {
	if (a > b)
		return a;
	if (b > a)
		return b;
}

void mostrarFormato() {

	cout << "Cliente\t" << "	Tiempo de llegada\t" << "Tiempo de espera\t" << "Tiempo que Cajero no Trabaja\t" << "Tiempo de servicio\t" << "Tiempo de salida\t" << "Tiempo entre llegadas" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}