/***********************************************************************
 * Module:  Tiempos.h
 * Author:  jeffe
 * Modified: martes, 20 de diciembre de 2022 20:43:50
 * Purpose: Declaration of the class Tiempos
 ***********************************************************************/

#if !defined(__Simulacion_Cola2_Tiempos_h)
#define __Simulacion_Cola2_Tiempos_h

class Tiempos
{
public:
   virtual int tiempoLlegada(void)=0;
   virtual int tiempoEspera(void)=0;
   virtual int tiempoNoTrabajaCajero(void)=0;
   virtual int tiempoServicio(void)=0;
   virtual int tiempoSalida(void)=0;
   virtual int tiempoEntreLlegada(void)=0;

protected:
private:

};

#endif