#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH
#include "BrylaGeometryczna.hh"
#include "Prostopadloscian.hh"
#include <iostream>

class Przeszkoda : public BrylaGeometryczna
{
    public:

    virtual bool czy_kolizja(Prostopadloscian pros)=0;
};
std::ostream &operator<<(std::ostream &Strm, const Przeszkoda &Prost)
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