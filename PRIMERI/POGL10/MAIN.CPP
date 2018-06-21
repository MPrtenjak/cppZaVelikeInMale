#include <iostream.h>
#include "tocka.h"
#include "tocka3d.h"

int main()
{
   cout << "Testiranje razreda Tocka ... " << endl;
   Tocka3D T;
   T.SetX(10.4); T.SetY(3.4);
   T.Izpisi();

   cout << "Testiranje razreda Tocka3D ... " << endl;

   Tocka3D T3D;
   T3D.SetX(10.4); T3D.SetY(3.4); T3D.SetZ(5.4);
   T3D.Izpisi();

   return(1);
}

