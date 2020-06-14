#include <iostream>
#include <fstream>
#include <iomanip>
#include "lacze_do_gnuplota.hh"
#include <string>
#include <cassert>
#include <unistd.h>
#include "Wektor3D.h"
#include "Prostopadloscian.hh"
#include "Powierzchnia.hh"
using namespace std;

int main()
{

  PzG::LaczeDoGNUPlota Lacze;

  ofstream pliki;
  Wektor3D w;

  Prostopadloscian pros(10, 10, 10);
  Powierzchnia pow(10, 60, 50, 10);
  Powierzchnia dno(10, 40, -10, 0);

  pros.set_nazwa("bryly/orginal.dat");

  pliki.open("bryly/fale.dat");
  pliki << pow;
  pliki.close();
  pliki.open("bryly/dno.dat");
  pliki << dno;
  pliki.close();
  pliki.open("bryly/pros.dat");
  pliki << pros;
  pliki.close();
  pliki.open("bryly/orginal.dat");
  pliki << pros;
  pliki.close();

  Lacze.DodajNazwePliku("bryly/pros.dat");
  Lacze.DodajNazwePliku("bryly/dno.dat");
  Lacze.DodajNazwePliku("bryly/fale.dat");
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();
  Lacze.UstawZakresX(-40, 100);
  Lacze.UstawZakresY(-90, 90);
  Lacze.UstawZakresZ(-20, 90);

  Lacze.UstawRotacjeXZ(40, 60);
  char opcja;
  int wartosc;
  double kat_wznoszenia;
  Lacze.Rysuj();
cout<<"r-ruch, o-obrot, m-menu"<<endl;
  while (true)
  {
      cout<<"Podaj opcje"<<endl;
    cin >> opcja;
    switch (opcja)
    {
    case 'r':

      cout<<"Podaj droge"<<endl;
      cin >> wartosc;
          cout<<"Podaj kat wznoszenia"<<endl;
      cin >> kat_wznoszenia;
      for (int i = 0; i < wartosc; i++)
      {
        w[0] = 1;
        pros.ruch(w, kat_wznoszenia, 0);
        pliki.open("bryly/pros.dat");
        pliki << pros;
        pliki.close();
        usleep(100000);
        Lacze.Rysuj();

      }
      break;
    case 'o':
    cout<<"Podaj kat obrotu"<<endl;
      cin >> wartosc;
      for (int i = 0; i < wartosc; i++)
      {
        w[0] = 0;
        pros.ruch(w, 0, 1);
        pliki.open("bryly/pros.dat");
        pliki << pros;
        pliki.close();
        usleep(200000);
        Lacze.Rysuj();

      }
      break;
    case 'm':

      break;
    case 'k':
    return 0;
    }
  }


}
