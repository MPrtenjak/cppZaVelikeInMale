#include <iostream.h>
#include <stdlib.h>  // deklaracija funkcije exit
#include <math.h>    // deklaracija sqrt

typedef void (*kFun)(int&);

void vnos(int &stevilo)
{
   cout << "Vpisite število ...";
   cin >> stevilo;
}

void izpis(int &stevilo)
{
   cout << "Število " << stevilo << " je deljivo z naslednjimi stevili :";
   
   cout << endl << endl;
   for (int i = 1; i <= sqrt(stevilo); i++)
      if (!(stevilo % i))
         cout << "      " << i << "      " << stevilo/i << endl;

   cout << endl; endl;
}

void konec(int &) // glava mora ustrezati!
{
   exit(1);
}

void menu()
{
   cout << endl << endl;
   cout << "         1. Vnos" << endl;
   cout << "         2. Izpis" << endl;
   cout << "         3. Konec" << endl;
   cout << endl << endl;
}

int main()
{
   kFun polje[] = { &vnos, &izpis, &konec };
   int izbira, stevilo;

   for(;;)  { // neskoncna zanka
      menu();
      cin >> izbira;

      if (izbira > 0 && izbira < 4)
         (*polje[izbira-1])(stevilo);  // polje se zacne z 0, zato -1 !!
      }
}

