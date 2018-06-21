/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Glavna datoteka programa za sortiranje.

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>   // za tokove
#include <iomanip.h>
#include <time.h>       // za merjenje èasa

#include "sort.hpp"

TIP_PODATKA    *Podatek;
int            Kolicina;

/*
   SORTIRANJE Z MEHURÈKI   - BUBBLE SORT
*/
void bubble()
{
   for (int i = 0; i < Kolicina; i++)
      for (int j = i + 1; j < Kolicina; j++)
         if ( manjsi(Podatek[j], Podatek[i]) )
            zamenjaj(Podatek[j], Podatek[i]);
}

/*
   SORTIRANJE S STRESANJEM - SHAKE SORT
*/
void shake()
{
   TIP_PODATKA *levi = Podatek,                 // levi rob
               *desni = Podatek + Kolicina - 1, // desni rob
               *start = Podatek;                // zaèetek

   do {
      for (TIP_PODATKA *p = levi; p < desni; p++)
         if ( manjsi(*(p+1), *p) )
            { zamenjaj(*p, *(p+1)); start = p; }

      desni = start;
      for (p = desni; p > levi; p--)
         if ( manjsi(*p, *(p-1)) )
            { zamenjaj(*p, *(p-1)); start = p; }

      levi = start;
   } while (levi < desni);
}

/*
   SORTIRANJE Z VSTAVLJANJEM - INSSORT
*/
void inssort()
{
   for (int i = 0; i < Kolicina; i++) {
      int k = i;                          
      TIP_PODATKA min = Podatek[k];

      for (int j = i + 1; j < Kolicina; j++)
         if ( manjsi(Podatek[j], min) )
            { k = j; min = Podatek[k]; }
      Podatek[k] = Podatek[i];
      Podatek[i] = min;
   }
}

/*
   HITRO SORTIRANJE - QuickSort

   Ker je algoritem rekurziven, funkcija potrebuje parametre!
*/
void quicksort(TIP_PODATKA *p, int velikost)
{
   do {
      int i = 0, j = velikost - 1;
      TIP_PODATKA x = p[ j/2 ];

      do {
         while ( manjsi(p[i], x) ) i++;
         while ( manjsi(x ,p[j]) ) j--;

         if (i < j) zamenjaj(p[i], p[j]);
      } while (++i <= --j);

      if ( i == j + 3 ) { --i; ++j; }

      if ( j + 1 < velikost - i ) {
         if ( j > 0 )   quicksort(p, j+1);
         p += i; velikost -= i;
      }
      else {
         if ( i < velikost - 1 ) quicksort(p + i, velikost - i);
         velikost = j + 1;
      }
   } while ( velikost > 1 );
}

int main()
{
   char vhod[100 + 1], izhod[100 + 1];
   int izbor;

   cout << "Program sortira podatke." << endl << endl;
   cout << "\t Vpišite vhodno  datoteko ... ";
   cin >> setw(100) >> vhod;
   cout << "\t Vpišite izhodno datoteko ... ";
   cin >> setw(100) >> izhod;

   preberi(vhod);

   cout << endl;
   cout << "Izberite algoritem: " << endl;
   cout << "\t [1] Sortiranje z mehurèki" << endl;
   cout << "\t [2] Sortiranje s stresanjem" << endl;
   cout << "\t [3] Sortiranje z vstavljanjem" << endl;
   cout << "\t [4] Hitro sortiranje" << endl;
   cout << "\t -----------------------------" << endl;
   cout << "\t > ";
   cin >> izbor;

   time_t start = time(NULL); // sistemski èas
   switch (izbor) {
      case 1  :   bubble();      break;
      case 2  :   shake();    break;
      case 3  :   inssort();     break;
      case 4  :   quicksort(Podatek, Kolicina);    break;
      default :   bubble();
   }
   time_t end = time(NULL);   // sistemski èas
   double razlika = difftime(end, start); // razlika èasov

   cout << endl << endl;
   cout << " Za sortiranje sem porabil " << razlika << " sekund."<< endl;

   zapisi(izhod);

   return VSE_OK;
}

