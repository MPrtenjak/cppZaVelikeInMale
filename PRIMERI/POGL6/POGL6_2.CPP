#include <iostream.h>

#define SIRINA 10
#define VISINA 20
#define PLOSCINA  VISINA*SIRINA

int main()
{
   cout << "Plošèina pravokotnika s stranicama " << SIRINA;
   cout << " in " << VISINA << " znaša " << PLOSCINA << " cm2." << endl;

//#define SIRINA  30 - NAPAKA, redefinicija

#undef SIRINA
#define SIRINA 30

   cout << "Plošèina pravokotnika s stranicama " << SIRINA;
   cout << " in " << VISINA << " znaša " << PLOSCINA << " cm2." << endl;

   return 1;
}
