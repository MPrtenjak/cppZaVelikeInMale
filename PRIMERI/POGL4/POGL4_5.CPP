#include <iostream.h>

// NEDELUJO� PROGRAM !!!!
int main()
{
   unsigned int i;

   i = 10; // inicializacija zan�ne spremenljivke
   while (i > -1) {
      cout << i << " * " << i << " = " << i * i << endl;
      i--;  // zmanj�amo i, (nekoc bi moral pasti pod 0 - NAPAKA)
      }

   return 1;
}
