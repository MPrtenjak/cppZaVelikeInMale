#include <iostream.h>
#include <string.h>  // za delo z nizi

class Usluzbenec {
protected:
   char *ime, *priimek;
   char *kljuc;
   double placa;

public:
   Usluzbenec(char *i, char *pr, double pl, char *kl);
   ~Usluzbenec() {
      delete ime;
      delete priimek;
      delete kljuc;
   }

   double Placa(char *klj);
   char *Ime() { return ime; }
   char *Priimek() { return priimek; }
};

Usluzbenec::Usluzbenec(char *i, char *pr, double pl, char *kl)
{
   ime = new char[ strlen(i) + 1 ];
   strcpy(ime, i);

   priimek = new char[ strlen(pr) + 1 ];
   strcpy(priimek, pr);

   placa = pl;

   kljuc = new char[ strlen(kl) + 1 ];
   strcpy(kljuc, kl);
}

double Usluzbenec::Placa(char *klj)
{
   if ( strcmp(klj, kljuc) == 0 )
      return placa;
   else
      return 0.0;
}

int main()
{
   Usluzbenec u1("Miha", "Horjul", 87890.50, "Kljuc1"),
               u2("Alen", "Kovaè", 103450.80, "Kljuc2");

   cout << "Uslužbenec u1: " << endl;
   cout << "\tIme              : " << u1.Ime() << endl;
   cout << "\tPriimek          : " << u1.Priimek() << endl;
   cout << "\tPlaèa (kljuc 1)  : " << u1.Placa("Kljuc1") << endl;
   cout << "\tPlaèa (kljuc 2)  : " << u1.Placa("Kljuc2") << endl;

   cout << endl << endl;

   cout << "Uslužbenec u2: " << endl;
   cout << "\tIme              : " << u2.Ime() << endl;
   cout << "\tPriimek          : " << u2.Priimek() << endl;
   cout << "\tPlaèa (kljuc 1)  : " << u2.Placa("Kljuc1") << endl;
   cout << "\tPlaèa (kljuc 2)  : " << u2.Placa("Kljuc2") << endl;

   return 1;
}




