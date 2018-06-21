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

int main()
{
   Lik   *liki[10];
   char  lik;
   Podatki p;

   for(int i = 0; i < 10; i++)
   {
      cout << "Izberite lik [#" << (i+1) << "] ... " << endl;
      cout << "\t [K] Krog, [P] Pravokotnik : ";
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
         default:
            p.pod[0] = 0.0;
            liki[i] = new Krog(p);
      }
   }

   for(i = 0; i < 10; i++)
   {
      cout << "Lik [#" << (i+1) << "] je " << liki[i]->Ime() << endl;
      cout << "\t Njegov obseg je " << liki[i]->Obseg() <<
            ", plošèina pa " << liki[i]->Ploscina() << "." << endl;
   }

   return 1;
}








