#include <iostream.h>
#include <math.h>

struct Podatki {
   double pod[5];    // razlièni možni podatki
};

class Lik {
public:
   Lik() {}
   Lik(Podatki &) {}

   virtual void Set(Podatki &p) = 0;
   virtual double Obseg() = 0;
   virtual double Ploscina() = 0;
   virtual char*  Ime() = 0;
};

// V pod[0] je zapisan radij
class Krog : public Lik {
protected:
   double radij;

public:
   Krog() { radij = 0; }
   Krog(Podatki &p) { radij = p.pod[0]; }

   void Set(Podatki &p) { radij = p.pod[0]; }

   double Obseg() { return 2*M_PI*radij; }
   double Ploscina() { return M_PI*radij*radij; }
   char* Ime() { return "Krog"; }
};

// V pod[0] je zapisana dolžina
// V pod[1] pa širina
class Pravokotnik : public Lik {
protected:
   double dolzina, sirina;

public:
   Pravokotnik() { dolzina = sirina  = 0; }
   Pravokotnik(Podatki &p)
      { dolzina = p.pod[0]; sirina = p.pod[1]; }

   void Set(Podatki &p)
      { dolzina = p.pod[0]; sirina = p.pod[1]; }

   double Obseg() { return 2*(dolzina + sirina); }
   double Ploscina() { return dolzina*sirina; }
   char* Ime() { return "Pravokotnik"; }
};

/*

      3D objekte bomo spoynali po tem, da imajo v imenu predpono 3D

*/
class Krogla : public Krog {
public:
   Krogla() : Krog() {}
   Krogla(Podatki &p) : Krog(p) {}

   double Obseg() { return 4*M_PI*radij*radij; }   // površina
   double Ploscina() { return 4/3*M_PI*radij*radij*radij; } // prostornina
   char* Ime() { return "3D Krogla"; }
};

// višina je zapisana v pod[2]
class Kvader : public Pravokotnik {
   double visina;

public:
   Kvader() : Pravokotnik() { visina = 0; }
   Kvader(Podatki &p) : Pravokotnik(p) { visina = p.pod[2]; }

   void Set(Podatki &p)
      { Pravokotnik::Set(p); visina = p.pod[2]; }

   double Obseg()    // površina
      { return 2*( dolzina*sirina + dolzina*visina + sirina*visina ); }
   double Ploscina() { return dolzina*sirina*visina; }   // prostornina
   char* Ime() { return "3D Kvader"; }
};

int main()
{
   Lik   *liki[10];
   char  lik;
   Podatki p;

   for(int i = 0; i < 4; i++)
   {
      cout << "Izberite lik [#" << (i+1) << "] ... " << endl;
      cout << "\t [K] Krog, [P] Pravokotnik, [R] Krogla, [V] Kvader : ";
      cin >> lik;
      switch (lik) {
         case 'k':
         case 'K':
            cout << "\t\t Radij kroga ...";
            cin >> p.pod[0];
            liki[i] = new Krog(p);
            break;
         case 'p':
         case 'P':
            cout << "\t\t Dolžina pravokotnika ...";
            cin >> p.pod[0];
            cout << "\t\t Širina  pravokotnika ...";
            cin >> p.pod[1];
            liki[i] = new Pravokotnik(p);
            break;
         case 'r':
         case 'R':
            cout << "\t\t Radij krogle ...";
            cin >> p.pod[0];
            liki[i] = new Krogla(p);
            break;
         case 'v':
         case 'V':
            cout << "\t\t Dolžina kvadra ...";
            cin >> p.pod[0];
            cout << "\t\t Širina  kvadra ...";
            cin >> p.pod[1];
            cout << "\t\t Višina  kvadra ...";
            cin >> p.pod[2];
            liki[i] = new Kvader(p);
            break;
         default:
            p.pod[0] = 0.0;
            liki[i] = new Krog(p);
      }
   }

   char *ime;
   for(i = 0; i < 4; i++)
   {
      ime = liki[i]->Ime();
      if ( ime[0] == '3' && ime[1] == 'D' )  // imamo 3D lik
      {
         cout << "3D Lik [#" << (i+1) << "] je " << (char*) (ime+3) << endl;
         cout << "\t Njegova površina je " << liki[i]->Obseg() <<
            ", prostornina pa " << liki[i]->Ploscina() << "." << endl;
      }
      else  // 2D lik
      {
         cout << "Lik [#" << (i+1) << "] je " << ime << endl;
         cout << "\t Njegov obseg je " << liki[i]->Obseg() <<
            ", plošèina pa " << liki[i]->Ploscina() << "." << endl;
      }

   }

   return 1;
}








