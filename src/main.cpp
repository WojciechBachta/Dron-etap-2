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
#include "Graniastoslup.hh"
#include "PPlaszczyzna.hh"
#include "PPret.hh"
#include "PProstopadloscienna.hh"

using namespace std;

int main()
{

  PzG::LaczeDoGNUPlota Lacze;
std::vector<Przeszkoda*> tab;
tab.push_back(new PPlaszczyzna(10,10,0));
tab.push_back(new PPret(10,0,0));
tab.push_back(new PProstopadloscienna(10,10,30));  
Wektor3D wp;
  for(int i=0; i<3; i++)
  {
    wp[0]=rand()%20+20;
  tab[i]->ruch(wp, 0, rand()%350);
  }
  ofstream pliki;
  Wektor3D w;
Graniastoslup *sw[2];
  Prostopadloscian pros(10, 10, 10);
  sw[0]=new Graniastoslup(pros[0],5);
    sw[1]=new Graniastoslup(pros[2],5);
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
 pliki.open("bryly/sw1.dat");
  pliki << *sw[0];
  pliki.close();
   pliki.open("bryly/sw2.dat");
  pliki << *sw[1];
  pliki.close();
     pliki.open("bryly/p1.dat");
  pliki << *tab[0];
  pliki.close();
     pliki.open("bryly/p2.dat");
  pliki << *tab[1];
  pliki.close();
     pliki.open("bryly/p3.dat");
  pliki << *tab[2];
  pliki.close();
    Lacze.DodajNazwePliku("bryly/sw1.dat");
      Lacze.DodajNazwePliku("bryly/sw2.dat");
  Lacze.DodajNazwePliku("bryly/pros.dat");
  Lacze.DodajNazwePliku("bryly/dno.dat");
  Lacze.DodajNazwePliku("bryly/fale.dat");
    Lacze.DodajNazwePliku("bryly/p1.dat");
      Lacze.DodajNazwePliku("bryly/p2.dat");
        Lacze.DodajNazwePliku("bryly/p3.dat");
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
      cout<<"podaj opcje"<<endl;
    cin >> opcja;
    switch (opcja)
    {
    case 'r':

      cout<<"podaj droge"<<endl;
      cin >> wartosc;
          cout<<"podaj kat wznoszenia"<<endl;
      cin >> kat_wznoszenia;
      for (int i = 0; i < wartosc; i++)
      {

        for (int j = 0; j < 3; j++)
        {
           if(tab[j]->czy_kolizja(pros))
           i=wartosc;
        }
        w[0] = 1;
        pros.ruch(w, kat_wznoszenia, 0);
         sw[0]->ruch(w, kat_wznoszenia, 0);
         sw[1]->ruch(w, kat_wznoszenia, 0);
        pliki.open("bryly/pros.dat");
        pliki << pros;
        pliki.close();
         pliki.open("bryly/sw1.dat");
  pliki << *sw[0];
  pliki.close();
   pliki.open("bryly/sw2.dat");
  pliki << *sw[1];
  pliki.close();

        usleep(100000);
        Lacze.Rysuj();

      }
      break;
    case 'o':
    cout<<"podaj akt obrotu"<<endl;
      cin >> wartosc;
      for (int i = 0; i < wartosc; i++)
      {
        w[0] = 0;
        pros.ruch(w, 0, 1);
            sw[0]->ruch(w, 0, 1);
                sw[1]->ruch(w, 0, 1);
        pliki.open("bryly/pros.dat");
        pliki << pros;
        pliki.close();
         pliki.open("bryly/sw1.dat");
  pliki << *sw[0];
  pliki.close();
   pliki.open("bryly/sw2.dat");
  pliki << *sw[1];
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
