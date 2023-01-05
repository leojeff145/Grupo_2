#pragma once

class Tiempos;
class Fecha;

#include "Fecha.h"
#include "Tiempos.h"
#include "Fecha.h"
#include <iostream>

class Persona
{
private:
	std::string cedula;
	std::string apellido;
	std::string nombre;
	Fecha edad;
	

public:
   Persona();
   ~Persona();
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   Fecha getEdad(void);
   void setEdad(Fecha newEdad);
   std::string toString();

   Tiempos** tiempos;
   Fecha** fecha;

};

