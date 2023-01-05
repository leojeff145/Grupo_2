#pragma once
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
