#include <iostream.h>

int main()
{
   int i;      // i je celo število
   int *ki; // ki pa kazalec na celo število (zato ima spredaj znak *)

   i = 5;      // i-ju priredimo 5
   ki = &i; // ki je kazalec na i, zato je njegova vrednost lokacija
         // spremenljivke i v spominu. Da dostopi do lokacije,x
         // mora uporabiti operator &, ki vrne lokacijo spremenljivke.

   cout << " Vrednost spremenljivke i  je " << i << endl;
   cout << " Vrednost kazalca       ki je " << ki << endl << endl;
   cout << " Spremenljivka i  se nahaja na lokaciji " << &i << endl;
   cout << " Kazalec       ki se nahaja na lokaciji " << &ki << endl << endl;
   cout << " Vrednost na lokaciji, kamor kaže kazalce ki je " << *ki << endl << endl;

   (*ki) = (*ki) + 1;

   cout << " Vrednost spremenljivke i  je " << i << endl;

   return 1;
}
