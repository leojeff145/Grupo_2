#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <random>
#include <cctype>
#include <regex>
#include <iomanip>
#include <sstream>
#include <cfloat>
#include <Windows.h>
#include <conio.h>

using namespace std;

class Validacion
{
public:
	void mostrarFormato();
	int ingresar_DatosEnteros();
	
};


void Validacion::mostrarFormato() {
	cout << "Cliente\t" << "	Tiem de llegada\t" << "Tiem de espera\t" << "Tiem que Cajero no Trabaja\t" << "Tiem de servicio\t" << "Tiem de salida\t" << "Tiem entre llegadas" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

static int ingresar_DatosEnteros()
{
	char* dato = new char[10], c;
	int i = 0;
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			dato[i++] = c;
		}
		else if (c == 8 || c == 127) {
			printf("\b \b");
			dato[i--] = 0;
		}
	}
	dato[i] = '\0';
	return atoi(dato);
}
