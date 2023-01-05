#pragma once

class Fecha
{
private:
	short dia;
	short mes;
	short anio;
	
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
};

