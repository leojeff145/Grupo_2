/***********************************************************************
 * Module:  Persona.h
 * Author:  jeffe
 * Modified: martes, 20 de diciembre de 2022 20:43:50
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__Simulacion_Cola2_Persona_h)
#define __Simulacion_Cola2_Persona_h

class Tiempos;
class Fecha;

#include <Fecha.h>

class Persona
{
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

   Tiempos** tiempos;
   Fecha** fecha;

protected:
private:
   std::string cedula;
   std::string apellido;
   std::string nombre;
   Fecha edad;


};

#endif