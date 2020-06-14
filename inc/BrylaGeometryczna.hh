#ifndef BRYLAGEOMETRYCZNA_HH
#define BRYLAGEOMETRYCZNA_HH
#include "Wektor3D.h"
#include "Macierz3x3.hh"
#include <vector>



class BrylaGeometryczna
{

protected:
    std::vector<Wektor3D> Wierz;
    std::string nazwa;
    Wektor3D przesun;
    Macierz3x3 MacierzZ;
    double kat;

public:

    int size() const
    {
        return (int)Wierz.size();
    }
    void set_nazwa(std::string nazwa)
    {
        this->nazwa = nazwa;
    }
    void ruch(Wektor3D przesuniecie, double kat_wznoszenia, double Kat_Obrotu)
    {
        kat += Kat_Obrotu;


        std::ifstream pliki;
        Macierz3x3 Mwznoszenia;

        kat = kat * M_PI / 180;
        MacierzZ[0][0] = cos(kat);
        MacierzZ[0][1] = -sin(kat);
        MacierzZ[0][2] = 0;
        MacierzZ[1][0] = sin(kat);
        MacierzZ[1][1] = cos(kat);
        MacierzZ[1][2] = 0;
        MacierzZ[2][0] = 0;
        MacierzZ[2][1] = 0;
        MacierzZ[2][2] = 1;

        kat_wznoszenia = kat_wznoszenia * M_PI / 180;
        Mwznoszenia[0][0] = cos(kat_wznoszenia);
        Mwznoszenia[0][1] = 0;
        Mwznoszenia[0][2] = sin(kat_wznoszenia);
        Mwznoszenia[1][0] = 0;
        Mwznoszenia[1][1] = 1;
        Mwznoszenia[1][2] = 0;
        Mwznoszenia[2][0] = -sin(kat_wznoszenia);
        Mwznoszenia[2][1] = 0;
        Mwznoszenia[2][2] = cos(kat_wznoszenia);

        pliki.open(nazwa);
        for (int i = 0; i < (int)Wierz.size(); i++)
            pliki >> Wierz[i];
        pliki.close();

        przesun = przesun + (Mwznoszenia * (MacierzZ * przesuniecie));
        for (int i = 0; i < (int)Wierz.size(); i++)
        {
            Wierz[i] = (MacierzZ * Wierz[i]) + przesun;
        }
    }

        Wektor3D operator[](int i) const
        {
            return Wierz[i];
        }
        Wektor3D &operator[](int i)
        {
            return Wierz[i];
        }
    };

#endif
