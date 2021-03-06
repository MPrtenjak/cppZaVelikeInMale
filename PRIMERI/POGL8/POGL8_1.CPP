#include <iostream.h>
#include <math.h> // za matemati�ne funkcije

#define MAX_ELEM  100   // najve�je �tevilo elementov

inline float Kvadrat(float a) // vrinjena funkcija
{
   return (a*a); // za izra�un kvadrata
}

float AritmSredina(float *podatki, int stevilo)
{
   float skupaj = 0.0;  // sestevek je 0.0

   for (int i = 0; i < stevilo; i++)   // za�ni pri prvem
      skupaj += podatki[i];   // podatku in vse se�tej

   return ( skupaj / stevilo );
}

float StrdOdstopanje(float *podatki, int stevilo, float AritmSred)
{
   float kv_odst = 0.0; // se�tevek kvadratov odstopnja

   for (int i = 0; i < stevilo; i++)
      kv_odst += Kvadrat( (podatki[i] - AritmSred) );

   return ( sqrt(kv_odst / (stevilo - 1)) );
}

int main()
{
   int stevilo;
   float podatki[MAX_ELEM];

   cout << "Podajte vhodne podatke ... " << endl;
   cout << "\t Koliko je vhodnih podatkov? ";
   cin >> stevilo;

   for (int i = 0; i < stevilo; i++) {
      cout << "\t Podajte " << (i+1) << ". podatek ... ";
      cin >> podatki[i];
      }

   float aritm_sred = AritmSredina(podatki, stevilo);
   float std_odst = StrdOdstopanje(podatki, stevilo, aritm_sred);

   cout << endl << endl;
   cout << "Aritmeti�na sredina ..... " << aritm_sred << endl;;
   cout << "Standardno odstopanje ... " << std_odst << endl;

   return(0);
}

