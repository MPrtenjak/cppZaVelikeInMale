#include <iostream.h>
#include <math.h> // v math.h so deklarirane mnoge funkcije in konstante

int main()
{
   double fi = 0.0, rad;
   cout << "Kot\t\tsinus kota\t\tkosinus kota" << endl;

   while (fi < 90) { // izpisemo vse kote od 0 - 90 stopinj
      rad = fi / 90 * M_PI_2; // Pretvorimo stopinje v radiane, ker
      // vse funkcije operirajo z radiani. M_PI_2 je konstanta, definirana
      // v math.h in predstavlja PI/2. (Vse konstante so natancne na 20 mest!)
      cout << fi << "\t\t" << sin(rad) << "\t\t" << cos(rad) << endl;
      fi++; // naslednja stopinja
      }

   return 0;
}
