#include <iostream.h>
#include "tocka.h"
#include "tocka3d.h"

int main()
{
   Tocka *polje[3];  // polj treh kazalcev na to�ke
   Tocka    T1, T2;
   Tocka3D  T3;

   // nekaj naredimo z to�kami

   polje[0] = &T1;   // postavimo 2D to�ko v polje
   polje[1] = &T2;
   polje[3] = &T3;   // postavimo 3D to�ko v polje

   return(1);
}