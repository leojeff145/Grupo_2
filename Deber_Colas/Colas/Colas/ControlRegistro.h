#pragma once
#include "Persona.h"
#include "Cola.h"
#include "Validacion.h"
class ControlRegistro
{
public:
	void registrarPersona();	
	Cola<Persona> leerPersonas();
	void guardarPersonas(Cola<Persona> persona);
	
	
};

