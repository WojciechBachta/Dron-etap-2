#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
#include "BrylaGeometryczna.hh"
#include <iostream>

class Prostopadloscian : public BrylaGeometryczna
{

public:
    Prostopadloscian(double szerokosc, double dlugosc, double wysokosc)
    {
        Wierz.resize(8);
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

};
std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian &Prost)
{
    for (int i = 0; i < Prost.size(); i++)
    {
        if(i%2==0)
        {
            Strm<<std::endl;
        }
        Strm << Prost[i] << std::endl;
    }
    Strm<<std::endl;
    Strm << Prost[0] << std::endl;
    Strm << Prost[1] << std::endl;
    return Strm;
}

#endif
