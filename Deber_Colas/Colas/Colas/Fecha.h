/***********************************************************************
 * Module:  Fecha.h
 * Author:  jeffe
 * Modified: martes, 20 de diciembre de 2022 20:43:50
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/

#if !defined(__Simulacion_Cola2_Fecha_h)
#define __Simulacion_Cola2_Fecha_h

class Fecha
{
public:
   Fecha();
   ~Fecha();
   short getDia(void);
   void setDia(short newDia);
   short getMes(void);
   void setMes(short newMes);
   short getAnio(void);
   void setAnio(short newAnio);
   short calcEdad(Fecha fechNacimiento);

protected:
private:
   short dia;
   short mes;
   short anio;


};

#endif