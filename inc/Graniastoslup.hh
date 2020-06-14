#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH
#include "BrylaGeometryczna.hh"
#include <iostream>

class Graniastoslup : public BrylaGeometryczna
{
double kat_rotacji;
public:

Graniastoslup(Wektor3D srodek, double promien)
{
   Wektor3D tmp;

this->srodek=srodek;
    for (int i = 0; i >=-360; i-=60) 
    {
		tmp[2] = srodek[2] + promien*cos(i*M_PI/180);
		tmp[1] = srodek[1] + promien*sin(i*M_PI/180);
		tmp[0] = srodek[0] + 5;
		Wierz.push_back(tmp);

		tmp[2] = srodek[2] + promien*cos(i*M_PI/180);
		tmp[1] = srodek[1] + promien*sin(i*M_PI/180);
		tmp[0] = srodek[0];
		Wierz.push_back(tmp);
	}

	tmp[2] = srodek[2];
	tmp[1] = srodek[1];
	tmp[0] = srodek[0] + 5;
	Wierz.push_back(tmp);

	tmp[2] = srodek[2];
	tmp[1] = srodek[1];
	tmp[0] = srodek[0];
	Wierz.push_back(tmp);

}



};
std::ostream &operator<<(std::ostream &Strm, const Graniastoslup &Gra)
{
    for (int i = 0; i < Gra.size(); i++)
    {
        if(i%2==0)
        {
            Strm<<std::endl;
        }
        Strm << Gra[i] << std::endl;
    }
    Strm<<std::endl;
    Strm << Gra[0] << std::endl;
    Strm << Gra[1] << std::endl;
    return Strm;
}

#endif