#include <iostream.h>

float SrVrednost(float *polje, int velikost)
{
   float sest = 0.0;

   for(int i = 0; i < velikost; i++)
      sest += polje[i];

   return (sest / velikost);
}

int main()
{
   float Polje[10];

   cout << "Vpišite deset realnih števil ..." << endl;

   for(int i = 0; i < 10; i++)
      cin >> Polje[i];

   cout << "Srednja vrednost števil v polju je " << SrVrednost(&Polje[0], 10) << endl;

   return 1;

}
