#include <iostream.h>

int main()
{
   int stevilo,
       rezultat;


   cout << "Podajte število ... ";
   cin >> stevilo;

   cout << endl << endl;
   rezultat = stevilo;
   for (int i = 0; i < 20; i++) {      // dvajset vrestic
      for (int j = 0; j < 10; j++) {   // deset kolon
         cout << rezultat << '\t';  // števila so loèena s tabulatorji
         rezultat += stevilo; // njegov veèkratnik
         }
      cout << endl;  // konec vrstice
   }

   return 1;
}
