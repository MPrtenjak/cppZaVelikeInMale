#include <iostream.h>

int main()
{
   int   i;       // spremenljivka
   int   &ri = i; // referenca spremenljivke i

   i = 6;
   cout << "Spremenljivka i  = " << i << endl;
   cout << "Referenca     ri = " << ri << endl << endl;

   ri = 8;
   cout << "Spremenljivka i  = " << i << endl;
   cout << "Referenca     ri = " << ri << endl << endl;

   return 1;
}
