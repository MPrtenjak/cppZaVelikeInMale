#include <iostream.h>

int main()
{
   int velikost,        // velikost piramide
       zvezdice = 1,    // število zvezdic
       presledki;       // šteevilo presledkov


   cout << "Podajte velikost piramide ... ";
   cin >> velikost;

   presledki = velikost;
   for (int i = 0; i < velikost; i++) {
      for (int j = 0; j < presledki; j++)
         cout << " ";   // presledki
      for (j = 0; j < zvezdice; j++)
         cout << "*";   // zvezdice
      zvezdice += 2;    // v naslednji vrstici bodo dve zvezdici veè
      presledki--;      // v naslednji vrstici bo en presledek manj
      cout << endl;     // skok v novo vrstico
   }

   return 1;
}


