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

   cout << "Vpi�ite deset realnih �tevil ..." << endl;

   for(int i = 0; i < 10; i++)
      cin >> Polje[i];

   cout << "Srednja vrednost �tevil v polju je " << SrVrednost(&Polje[0], 10) << endl;

   return 1;

}
