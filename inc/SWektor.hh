#ifndef SWEKTOR_HH
#define SWEKTOR_HH

//#include "rozmiar.h"
#include <iostream>
//#include <iomainp>
using namespace std;
#include <cmath>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename STyp, int SWymiar>
class SWektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */

    STyp _SkladnikiW[SWymiar];


  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */


   public:


    STyp Wez(unsigned int index)const {
        return _SkladnikiW[index];
    }
    void Zamien(unsigned int index, STyp wartosc){
        _SkladnikiW[index]=wartosc;
    }

    STyp operator[](int Ind) const {return _SkladnikiW[Ind];}
    STyp& operator[](int Ind) {return _SkladnikiW[Ind];}

    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &W) const;
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &W) const;
    SWektor<STyp,SWymiar> operator * ( STyp Z) ;
    
    STyp operator * (const SWektor<STyp,SWymiar> &W) const;
    SWektor<STyp,SWymiar> operator / (STyp Z) const;
   

    //STyp dlugosc() const;


};

template <typename STyp, int SWymiar>
    SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &W) const
    {
        SWektor<STyp,SWymiar> Wynik;
        for(int i=0; i<SWymiar; i++)
        {
            Wynik._SkladnikiW[i] = this->_SkladnikiW[i] + W._SkladnikiW[i];
        }
        return Wynik;
    }

template <typename STyp, int SWymiar>
    SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> & W) const
      {
        SWektor<STyp,SWymiar> Wynik;
        for(int i=0; i<SWymiar; i++)
        {
            Wynik._SkladnikiW[i] = this->_SkladnikiW[i] - W._SkladnikiW[i];
        }
        return Wynik;
    }


template <typename STyp, int SWymiar>
    SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (STyp Z) 
    {

        SWektor<STyp,SWymiar> Wynik;
        for(int i=0; i<SWymiar; i++)
        {
            Wynik._SkladnikiW[i] = this->_SkladnikiW[i] * Z;
        }
        return Wynik;
    }



template <typename STyp, int SWymiar>
    STyp SWektor<STyp,SWymiar>::operator * (const SWektor<STyp,SWymiar> &W) const
    {
        STyp Wynik;
        for(int i=0; i<SWymiar; i++)
        {
            Wynik = Wynik + this->_SkladnikiW[i] * W._SkladnikiW[i];
        }
        return Wynik;
    }

template <typename STyp, int SWymiar>
    SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator / (STyp Z) const
    {
        SWektor<STyp,SWymiar> Wynik;
        for(int i=0; i<SWymiar; i++)
        {
            Wynik._SkladnikiW[i] = this->_SkladnikiW[i] /Z;
        }
        return Wynik;
    }

 

/*
template <typename STyp, int SWymiar>
    STyp SWektor<STyp,SWymiar>::dlugosc() const
      {
          STyp wynik;
          for(int i = 0; i < SWymiar; i++)
          {
              wynik = wynik + (this->_SkladnikiW[i]*this->_SkladnikiW[i]);
          }
          return sqrt(wynik);
    return wynik;
      }
*/




/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp,SWymiar> &Wek)
    {
        for(int i = 0; i < SWymiar; i++)
        {
            Strm >> Wek[i];
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
std::ostream& operator << (std::ostream &Strm, const SWektor<STyp,SWymiar> &Wek)
    {
        Strm  << Wek.Wez(0);
        for(int i=1; i<SWymiar; i++)
        {
            Strm << " " << Wek.Wez(i);
        }
       
        return Strm;
    }


#endif
