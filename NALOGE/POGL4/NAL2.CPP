#include <iostream.h>

int main()
{
   int stevilo,
       rezultat;


   cout << "Podajte �tevilo ... ";
   cin >> stevilo;

   cout << endl << endl;
   rezultat = stevilo;
   for (int i = 0; i < 20; i++) {      // dvajset vrestic
      for (int j = 0; j < 10; j++) {   // deset kolon
         cout << rezultat << '\t';  // �tevila so lo�ena s tabulatorji
         rezultat += stevilo; // njegov ve�kratnik
         }
      cout << endl;  // konec vrstice
   }

   return 1;
}
