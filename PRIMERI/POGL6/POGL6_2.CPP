#include <iostream.h>

#define SIRINA 10
#define VISINA 20
#define PLOSCINA  VISINA*SIRINA

int main()
{
   cout << "Plo��ina pravokotnika s stranicama " << SIRINA;
   cout << " in " << VISINA << " zna�a " << PLOSCINA << " cm2." << endl;

//#define SIRINA  30 - NAPAKA, redefinicija

#undef SIRINA
#define SIRINA 30

   cout << "Plo��ina pravokotnika s stranicama " << SIRINA;
   cout << " in " << VISINA << " zna�a " << PLOSCINA << " cm2." << endl;

   return 1;
}
