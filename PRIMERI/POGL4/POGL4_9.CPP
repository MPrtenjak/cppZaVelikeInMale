#include <iostream.h>
#include <math.h>

int main()
{
   float stevilo;

   for (int i = 0; i < 20; i++) {
      cout << "Podajte �tevilo ... ";
      cin >> stevilo;
      if (stevilo == 0.0)
         continue;
      cout << "    Obratna vrednost �tevila je " << 1/stevilo << endl << endl;
      }

   return 1;
}
