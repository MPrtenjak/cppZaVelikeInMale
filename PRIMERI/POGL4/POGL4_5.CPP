#include <iostream.h>

// NEDELUJOÈ PROGRAM !!!!
int main()
{
   unsigned int i;

   i = 10; // inicializacija zanène spremenljivke
   while (i > -1) {
      cout << i << " * " << i << " = " << i * i << endl;
      i--;  // zmanjšamo i, (nekoc bi moral pasti pod 0 - NAPAKA)
      }

   return 1;
}
