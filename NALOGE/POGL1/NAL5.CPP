#include <iostream.h>

int main() {
   int dol, mera;

   cout << "Podajte dol�ino ... ";
   cin >> dol;
   cout << "Ali je dol�ina v cm (0) ali v inch-ah (1) ? ";
   cin >> mera;

   if (mera == 0)
      cout << dol << " cm je " << dol / 2.54 << " inch." << endl << endl;
   else
      cout << dol << " inch je " << dol * 2.54 << " cm." << endl << endl;

   return 1;
}

