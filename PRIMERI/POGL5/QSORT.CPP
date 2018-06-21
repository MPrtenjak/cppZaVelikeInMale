#include <iostream.h>
#include <string.h>  // za delo z nizi

struct oseba {
   char *ime;
   char *priimek;
   int starost;
};

typedef oseba* kOseba;  // kazalec na osebo

typedef int (*PRIMERJAJ)(void*, void*);

void qsort(void *start, int velikost, int v_elementa, PRIMERJAJ prm)
{

   do
   {
      int   i = 0;               // števec
      int   j = velikost - 1;    // števec
      char *el = (char*)start+(j/2)*v_elementa; // izbrani element

      do
      {
         char *el_i = (char*)start+i*v_elementa;   // i-ti element
         while ( (*prm)(el_i, el) < 0 )
            { el_i += v_elementa; i++; }

         char *el_j = (char*)start+j*v_elementa;   // j-ti element
         while ( (*prm)(el_j, el) > 0 )
            { el_j -= v_elementa; j--; }

         if (i < j) {
            // zamenjaj i-ti in j-ti element
            el_i = (char*)start+i*v_elementa;
            el_j = (char*)start+j*v_elementa;
            for (int k = 0; k < v_elementa; k++) {
               char tmp = el_j[k];
               el_j[k] = el_i[k];
               el_i[k] = tmp;
               }
         }
      }
      while (++i <= --j);

      if (i == j + 3)
         { --i; ++j; }
      if (j+1 < velikost-i) {
         if (j > 0)
            qsort(start, j+1, v_elementa, prm);
         (char*)start += i*v_elementa;
         velikost -= i;
      }
      else {
         if (i < velikost-1) {
            char *start_i = (char*)start + i*v_elementa;
            qsort(start_i, velikost-i, v_elementa, prm);
            }
         velikost = j + 1;
      }
   }
   while (velikost > 1);
}

void Izpisi(kOseba o, int vel)
{
   cout << endl;
   for (int i = 0; i < vel; i++)
      cout << o[i].ime << " " << o[i].priimek << " " << o[i].starost << endl;
   cout << endl;
}

int prm1(void* a, void* b)
{
   return strcmp(kOseba(a)->ime, kOseba(b)->ime);
}

int prm2(void* a, void* b)
{
   return strcmp(kOseba(a)->priimek, kOseba(b)->priimek);
}

int prm3(void* a, void* b)
{
   return kOseba(a)->starost - kOseba(b)->starost;
}

oseba Ljudje[] = {
      { "Aleš", "Skala", 22 },
      { "Matej", "Zrimšek", 25 },
      { "Boštjan", "Aramis", 17 },
      { "Cene", "Novak", 30 },
      { "Cene", "Novak", 15 },
      { "Veronika", "Prtenjak", 1 }
};

int main()
{
   Izpisi(Ljudje, 6);

   cout << endl << endl;
   cout << "Sortiranje po imenu:" << endl;
   qsort(Ljudje, 6, sizeof(oseba), prm1);
   Izpisi(Ljudje, 6);

   cout << endl << endl;
   cout << "Sortiranje po priimku:" << endl;
   qsort(Ljudje, 6, sizeof(oseba), prm2);
   Izpisi(Ljudje, 6);

   cout << endl << endl;
   cout << "Sortiranje po starosti:" << endl;
   qsort(Ljudje, 6, sizeof(oseba), prm3);
   Izpisi(Ljudje, 6);

   return 1;
}

