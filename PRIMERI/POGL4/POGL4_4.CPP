#include <iostream.h>
#include <math.h> // tu so zapisane nekatere matemati�ne konstante

float podaj(char *napis)
{
   float vrednost;

   cout << napis;
   cin >> vrednost;

   return vrednost;
}

int main()
{
   int   lik, a, b, c;

   cout << "Lik /1 - krog, 2 - pravokotnik, 3 - kvader/ ...";
   cin >> lik;

   switch (lik) {
      case 1:
         a = podaj("Radij kroga ...");
         cout << "Povr�ina kroga zna�a " << 2 * M_PI * a;
         break;
      case 2:
         a = podaj("Dol�ina pravokotnika ...");
         b = podaj("�irina pravokotnika ...");
         cout << "Povr�ina lika zna�a " << a * b;
         break;
      case 3:
         a = podaj("Dol�ina kvadra ...");
         b = podaj("�irina kvadra ...");
         c = podaj("Vi�ina kvadra ...");
         cout << "Povr�ina lika zna�a " << a * b * c;
         break;
      default:
         cout << "Tega lika ne poznam";
      }

   return 1;
}
