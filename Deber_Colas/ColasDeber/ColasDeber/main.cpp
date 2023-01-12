
/*                                  Universidad de las Fuerzas Armadas "ESPE"
* Simulador cola
* ALumno: Carvajal Adali, Gonzaga Javier, Gualotuña Richie, Leon William, Obando Leonardo, Quintana Wendy, Teran Francisco
* 16 / 12 / 2022
* 19 / 12 / 2022
* 7999 Estructura de datos
*/


#include <iostream>
#include <cstdlib>
#include "Cola.h"
#include "TiempoCliente.h"
#include "Validacion.h"
#include <ctime>

using namespace std;

int main()
{
	
	cout << "			TIEMPOS DE LOS CLIENTES" << endl << endl;

	int n;
	cout << "Ingresar numero de clientes: "; 
	n = ingresar_DatosEnteros();
	cout << endl;

	Validacion val;
	val.mostrarFormato();
	srand(time(0));
	TiempoCliente cliente;
	Cola clientes;
	Cola promedio;


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

