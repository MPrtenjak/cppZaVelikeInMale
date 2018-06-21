#include <iostream.h>
#include <math.h> // tu so zapisane nekatere matematiène konstante

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
         cout << "Površina kroga znaša " << 2 * M_PI * a;
         break;
      case 2:
         a = podaj("Dolžina pravokotnika ...");
         b = podaj("Širina pravokotnika ...");
         cout << "Površina lika znaša " << a * b;
         break;
      case 3:
         a = podaj("Dolžina kvadra ...");
         b = podaj("Širina kvadra ...");
         c = podaj("Višina kvadra ...");
         cout << "Površina lika znaša " << a * b * c;
         break;
      default:
         cout << "Tega lika ne poznam";
      }

   return 1;
}
