#pragma once
#include "ListaDoble.h"
#include "Empleado.h"
#include "Validacion.h"

template <typename T>
class ControlRegistro
{
public:
	void registrarEmpleado();
	
	
	ListaDoble<Empleado> leerClientes();
	void guardarEmpleado(Empleado empleado);
	
};

template<typename T>
void registrarEmpleado() {
	std::string cedula;
	std::string nombres;
	std::string apellidos;
	std::string cargo;

	std::cout << "Registrar cliente:" << std::endl << std::endl;
	cout << "Ingrese Apellidos: ";
	apellidos = Validacion::leer_cadena_regex("", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");
	cout << "Ingrese Nombres: ";
	nombres = Validacion::leer_cadena_regex("", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");
	cout << "Ingrese Cargo: ";
	cargo = Validacion::leer_cadena_regex("", "^[a-zA-Z]{2,}(\\s[a-zA-Z]{2,})?$");

	auto clientes = leerClientes();

	do {
		cout << "Ingresar Cedula: ";
		cedula = Validacion::leer_cadena_regex("", "^[0-9]{10}$");

		if (!Validacion::cedula_valida(cedula)) {
			cout << "Cedula invalida" << endl;
			continue;
		}

		auto encontrado = clientes.buscar([cedula](Empleado c) {
			return c.get_cedula() == cedula;
			});

		if (encontrado) {
			cout << "Cedula ya registrada" << endl;
			continue;
		}

		break;
	} while (true);

	Empleado cliente(cedula, nombres, apellidos, cargo);
	guardarEmpleado(cliente);
	cout << "Datos guardados";
}

template<typename T>
ListaDoble<Empleado> leerClientes() {
	ListaDoble<Empleado> clientes;

	Validacion::leer_lineas("EmpleadosLC.txt", [&](std::string linea, ListaDoble<std::string> columnas) {
		std::string cedula = columnas.obtenerNodo(0)->get_dato();
	std::string nombres = columnas.obtenerNodo(1)->get_dato();
	std::string apellidos = columnas.obtenerNodo(2)->get_dato();
	std::string cargo = columnas.obtenerNodo(3)->get_dato();

	Empleado cliente(cedula, nombres, apellidos, cargo);
	clientes.insertarFinal(cliente);
		});

	return clientes;	
}

template<typename T>
void guardarEmpleado(Empleado empleado){
	auto clientes = leerClientes();
	std::ofstream archivo("EmpleadosLC.txt", std::ios::trunc);

	clientes.recorrer([&](Empleado c) {
		archivo << c.toString() << std::endl;
		});

	archivo << cliente.toString() << std::endl;
	archivo.close();
}






	
	
	
	

