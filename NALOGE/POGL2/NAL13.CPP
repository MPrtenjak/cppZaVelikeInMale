#include <iostream.h>

const char UlomkovaCrta = '/';

struct Ulomek
{
   double stevec,
          imenovalec;
};

int main()
{
   Ulomek u1, u2, rezultat;
   char   UlCrta;

   cout << "Podajte prvi ulomek : ";
   cin >> u1.stevec >> UlCrta >> u1.imenovalec;

   cout << "Podajte drugi ulomek: ";
   cin >> u2.stevec >> UlCrta >> u2.imenovalec;

   rezultat.stevec = u1.stevec*u2.imenovalec + u1.imenovalec*u2.stevec;
   rezultat.imenovalec = u1.imenovalec*u2.imenovalec;

   cout << "Rezultat je " << rezultat.stevec << UlomkovaCrta <<
         rezultat.imenovalec << endl;

   return 1;
}