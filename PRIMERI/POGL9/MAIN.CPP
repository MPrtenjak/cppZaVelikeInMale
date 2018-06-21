#include <iostream.h>
#include "tocka.h"

int main()
{
   cout << "Testiranje razreda Tocka ... " << endl;

   Tocka T;
   T.SetX(10.4); T.SetY(3.4);
   T.Izpisi();

   return(1);
}
