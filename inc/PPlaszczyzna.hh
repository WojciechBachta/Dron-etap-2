#ifndef PPLASZCZYZNA_HH
#define PPLASZCZYZNA_HH
#include "Przeszkoda.hh"

#include <iostream>

class PPlaszczyzna : public Przeszkoda
{
     double szerokosc; double dlugosc; double wysokosc;
    public:
PPlaszczyzna(double szerokosc, double dlugosc, double wysokosc)
{
   Wierz.resize(8);
  this->szerokosc=szerokosc;
  this->dlugosc=dlugosc;
  this->wysokosc=wysokosc;
    for (int i = 0; i < 8; i++) 
    {
        Wierz[i][0] -= szerokosc/2;
                Wierz[i][1] -= dlugosc/2;
                        Wierz[i][2] -= wysokosc/2;
    }

    Wierz[1][0] += szerokosc;

    Wierz[2][1] += dlugosc;

    Wierz[3][0] += szerokosc;
    Wierz[3][1] += dlugosc;

    Wierz[4][1] += dlugosc;
    Wierz[4][2] += wysokosc;

    Wierz[5][0] += szerokosc;
    Wierz[5][1] += dlugosc;
    Wierz[5][2] += wysokosc;

    Wierz[6][2] += wysokosc; 

    Wierz[7][0] += szerokosc;
    Wierz[7][2] += wysokosc;

}
        bool czy_kolizja(Prostopadloscian pros)
    {
      if( pros.get_prze()[0]+10>przesun[0]-szerokosc &&pros.get_prze()[0]+10<przesun[0]+szerokosc)
      if( pros.get_prze()[1]+10>przesun[1]-dlugosc &&pros.get_prze()[1]+10<przesun[1]+dlugosc)
      if( pros.get_prze()[2]+10>przesun[2]-wysokosc &&pros.get_prze()[2]+10<przesun[2]+wysokosc)
        return true;

      return false;
      
        
    }
};

#endif