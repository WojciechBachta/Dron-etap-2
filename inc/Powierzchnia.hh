#include "BrylaGeometryczna.hh"


class Powierzchnia : public BrylaGeometryczna
{
    int siatka;

public:

    Wektor3D wek;
    int return_siatka() const { return siatka; }
    Powierzchnia(int grid, double rozpietosc, double powie, double wysokosc_fal)
    {
        siatka = 0;
        for (int i = -rozpietosc / 2; i <= rozpietosc / 2; i += grid)
        {
            siatka++;
            for (int j = -rozpietosc / 2; j <= rozpietosc / 2; j += grid)
            {
                wek[0] = i;
                wek[1] = j;
                if (siatka % 2 == 0)
                {
                    wek[2] = powie;
                }
                else
                {
                    wek[2] = powie + wysokosc_fal;
                }
                Wierz.push_back(wek);
            }
        }
    }
};

std::ostream &operator<<(std::ostream &Strm, const Powierzchnia &pow)
{
    for (int i = 0; i < pow.size(); i++)
    {

        if (i % pow.return_siatka() == 0)
        {
            Strm << std::endl;
        }
        Strm << pow[i] << std::endl;
    }
    return Strm;
}
