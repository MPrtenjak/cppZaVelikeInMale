#include <iostream.h>
#include <string.h>  // za delo z nizi

#define KLJUC "fdskjl"

class Usluzbenec {
protected:
   char *ime, *priimek;
   double placa;

public:
   Usluzbenec(char *i, char *pr, double pl);
   ~Usluzbenec() {
      delete ime;
      delete priimek;
   }

   double Placa(char *kljuc);
   char *Ime() { return ime; }
   char *Priimek() { return priimek; }
};

Usluzbenec::Usluzbenec(char *i, char *pr, double pl)
{
   ime = new char[ strlen(i) + 1 ];
   strcpy(ime, i);

   priimek = new char[ strlen(pr) + 1 ];
   strcpy(priimek, pr);

   placa = pl;
}

double Usluzbenec::Placa(char *kljuc)
{
   if ( strcmp(kljuc, KLJUC) == 0 )
      return placa;
   else
      return 0.0;
}

int main()
{
   Usluzbenec u1("Miha", "Horjul", 87890.50),
               u2("Alen", "Kovaè", 103450.80);

   cout << "Uslužbenec u1: " << endl;
   cout << "\tIme     : " << u1.Ime() << endl;
   cout << "\tPriimek : " << u1.Priimek() << endl;
   cout << "\tPlaèa   : " << u1.Placa("fdskjl") << endl;

   cout << endl << endl;

   cout << "Uslužbenec u2: " << endl;
   cout << "\tIme     : " << u2.Ime() << endl;
   cout << "\tPriimek : " << u2.Priimek() << endl;
   cout << "\tPlaèa   : " << u2.Placa("FDSKJL") << endl; // NAPAÈEN KLJUÈ

   return 1;
}




