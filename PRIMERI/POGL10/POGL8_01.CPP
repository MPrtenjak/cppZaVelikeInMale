#include <iostream.h>
#include "tocka.h"
#include "tocka3d.h"

int main()
{
   Tocka *polje[3];  // polj treh kazalcev na toèke
   Tocka    T1, T2;
   Tocka3D  T3;

   // nekaj naredimo z toèkami

   polje[0] = &T1;   // postavimo 2D toèko v polje
   polje[1] = &T2;
   polje[3] = &T3;   // postavimo 3D toèko v polje

   return(1);
}