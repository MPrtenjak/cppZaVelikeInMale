#include <iostream.h>
#include <string.h>  // za delo z nizi

struct oseba {
   char *ime;
   char *priimek;
   int starost;
};

typedef oseba* kOseba;  // kazalec na osebo

typedef int (*PRIMERJAJ)(void*, void*);

void bubble(void *start, int velikost, int v_elementa, PRIMERJAJ prm)
{
   for (int i = 0; i < velikost-1; i++)
      for (int j = velikost-1; i < j; j--) {
         char *el_j = (char*)start+j*v_elementa;   // j - ti element
         char *el_j1 = el_j - v_elementa;    // j-1 - ti element
         if ( (*prm)(el_j1, el_j) > 0 ) {
            // zamenjaj j - ti in (j-1) -ti element
            for (int k = 0; k < v_elementa; k++) {
               char tmp = el_j[k];
               el_j[k] = el_j1[k];
               el_j1[k] = tmp;
               }
            }
         }
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
   bubble(Ljudje, 6, sizeof(oseba), prm1);
   Izpisi(Ljudje, 6);

   cout << endl << endl;
   cout << "Sortiranje po priimku:" << endl;
   bubble(Ljudje, 6, sizeof(oseba), prm2);
   Izpisi(Ljudje, 6);

   cout << endl << endl;
   cout << "Sortiranje po starosti:" << endl;
   bubble(Ljudje, 6, sizeof(oseba), prm3);
   Izpisi(Ljudje, 6);

   return 1;
}

