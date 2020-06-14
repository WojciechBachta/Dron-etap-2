#ifndef SMACIERZ_HH
#define SMACIERZ_HH

//#include "rozmiar.h"
#include <iostream>
#include "SWektor.hh"
using namespace std;

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename STyp, int SWymiar>
class SMacierz {

    SWektor<STyp,SWymiar> _SkladnikiM[SWymiar];

  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:


   SWektor<STyp,SWymiar> WezWiersz(int wiersz)const{
   return _SkladnikiM[wiersz];
   }
   void ZamienWiersz(int wiersz, SWektor<STyp,SWymiar> W){
    _SkladnikiM[wiersz]=W;
   }
    const SWektor<STyp,SWymiar> & operator[] (int index) const{
    return _SkladnikiM[index];
    }
    SWektor<STyp,SWymiar> & operator[] (int index){
    return _SkladnikiM[index];
    }

    SMacierz<STyp,SWymiar> (); //jednostkowa

    SMacierz<STyp,SWymiar> operator + (const SMacierz<STyp,SWymiar> & M) const;
    SMacierz<STyp,SWymiar> operator - (const SMacierz<STyp,SWymiar> & M) const;
    SMacierz<STyp,SWymiar> operator * (const double l) const;
    SWektor<STyp,SWymiar> operator * (const SWektor<STyp,SWymiar> W) const;

    SMacierz<STyp,SWymiar> MacierzOdwrotna() const;
    SMacierz<STyp,SWymiar> operator * () const;
    STyp Wyznacznik() const;

  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */

};

template <typename STyp, int SWymiar>
 SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator * () const
{
    SMacierz<STyp,SWymiar> Wynik;
    for(int i=0; i<SWymiar; i++)
    {
        for(int j=0; j<SWymiar; j++)
        Wynik._SkladnikiM[i][j]=this->_SkladnikiM[i][j]*this->_SkladnikiM[i][j];
    }
    return Wynik;
}

template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar>::SMacierz()
{
    SWektor<STyp,SWymiar> W;
    for(int i = 0; i < SWymiar; i++)
    {
        this->_SkladnikiM[i] = W;
        this->_SkladnikiM[i][i] = 1;
    }
}

template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator + (const SMacierz<STyp,SWymiar> & M) const
{
    SMacierz<STyp,SWymiar> Wynik;
    for(int i = 0; i < SWymiar; i++)
    {
        Wynik[i] = this->_SkladnikiM[i] + M[i];
    }
    return Wynik;
}

template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator - (const SMacierz<STyp,SWymiar> & M) const
{
    SMacierz<STyp,SWymiar> Wynik;
    for(int i = 0; i < SWymiar; i++)
    {
        Wynik[i] = this->_SkladnikiM[i] - M[i];
    }
    return Wynik;
}

template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator* (const double l) const
{
    SMacierz<STyp,SWymiar> Wynik;
    for(int i = 0; i < SWymiar; i++)
    {
        Wynik[i] = this->_SkladnikiM[i] * l;
    }
    return Wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator* (const SWektor<STyp,SWymiar> W) const
{
    SWektor<STyp,SWymiar> Wynik;
    STyp tmp;
    tmp=0;

    for(int i = 0; i < SWymiar; i++)
    {
        tmp = tmp + (this->_SkladnikiM[i] * W);
        Wynik[i] = tmp;
        tmp = 0;
    }

    return Wynik;
}

template <typename STyp, int SWymiar>
  STyp SMacierz<STyp,SWymiar>::Wyznacznik() const
{
    SMacierz<STyp,SWymiar> M = *this;
    STyp Wynik;
    Wynik = M[0][0];

    for(int i = 0; i < SWymiar - 1; i++)
    {
        for(int j = 0; j < SWymiar - (i+1); j++)
        {
            M[i+j+1] = (M[i+j+1]-(M[i] * ( M[i+j+1][i] / M[i][i] )));
        }
    }

    for(int i = 1; i < SWymiar; i++) { Wynik = Wynik*M[i][i]; }

    return Wynik;
}

template <typename STyp, int SWymiar>
 SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::MacierzOdwrotna() const
{
    SMacierz<STyp,SWymiar> M = *this;
    SMacierz<STyp,SWymiar> Wynik;
    STyp liczba;
    for(int i = 0; i < SWymiar-1; i++)
    {
        for(int j = 0; j < SWymiar - (i+1); j++)
        {
            liczba = ( M[i+j+1][i] / M[i][i] );
            M[i+j+1] = M[i+j+1] - M[i] * liczba;
            Wynik[i+j+1] = Wynik[i+j+1] - Wynik[i] * liczba;
        }
    }

    for(int i = 0; i < SWymiar-1; i++)
    {
        for(int j = 0; j < SWymiar - (i+1); j++)
        {
            liczba = ( M[(SWymiar-1)-(i+j+1)][(SWymiar-1)-i] / M[(SWymiar-1)-i][(SWymiar-1)-i] );

            M[SWymiar-i-j-2] = M[SWymiar-i-j-2] - M[SWymiar-i-1] * liczba;
            Wynik[SWymiar-i-j-2] = Wynik[SWymiar-i-j-2] - Wynik[SWymiar-i-1] * liczba;
        }
    }

    for(int i = 0; i < SWymiar; i++)
    {
        Wynik[i] = Wynik[i]/M[i][i];
    }

    return Wynik;
}



/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
 template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SMacierz<STyp,SWymiar> &Mac)
{
    for(int i = 0; i < SWymiar; i++)
    {
        Strm >> Mac[i];
    }
    return Strm;
}

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
 template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SMacierz<STyp,SWymiar> &Mac)
{
    for(int i = 0; i < SWymiar; i++)
    {
        Strm << Mac[i] << "\n";
    }
    return Strm;
}


#endif
