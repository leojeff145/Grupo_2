
#include <iostream>
#include <cstdlib>
#include "Cola.h"
#include "ClienteTiempo.h"
#include "Validacion.h"
#include <ctime>

int main() {
	cout << "			TIEMPOS DE LOS CLIENTES" << endl << endl;

	int n;
	cout << "Ingrese el numero de clientes: ";
	n = Validacion::ingresar_DatosEnteros();
	Validacion::mostrarFormato();
	srand(time(0));
	ClienteTiempo cliente;
	Cola<ClienteTiempo> clientes;
	Cola<ClienteTiempo> promedio;

	clientes.push(cliente);
	clientes.mostrar();
	clientes.pop();

	promedio.push(cliente);

	for (int i = 0; i < n - 1; i++) {
		cliente.calcularTiempos(cliente);
		clientes.push(cliente);
		clientes.mostrar();
		clientes.pop();
		promedio.push(cliente);
	}
	cout << endl;
	promedio.calcularPromedio(n);
	
	
	return 0;
}