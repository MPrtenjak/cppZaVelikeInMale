#include <iostream.h>

int main()
{
   int st, sestevek;

   cout << "Vpišite število /0 - konec/ ... ";
   cin >> st;
   sestevek = st; // seštevek je enak prvemu številu, èe je to število 0, 
        // kar pomeni konec, niè hudega, saj je zato tudi seštevek enak 0

   while (st != 0) { // ponavljaj, dokler je vpisano število razlièno od 0
      cout << "Vpišite število /0 - konec/ ... ";
      cin >> st;        // vpišite novo število
      sestevek = sestevek + st;  // seštevku prištejemo to novo število
      }

   cout << "Seštevek števil je " << sestevek << "." << endl;

   return 1;
}
