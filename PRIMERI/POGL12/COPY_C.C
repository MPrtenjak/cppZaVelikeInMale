#include <stdio.h>
#include <stdlib.h>

void Napaka(char *s1, char *s2)  /* C ne pozna rezervnih parametrov! */
{
   fprintf(stderr, "%s %s\n",s1 ,s2);  
   exit(2);
}

int main(int ArgC, char *ArgV[])
{
   FILE *Vhod, *Izhod;  /* v jeziku C moramo */
   char c;              /* vse spremenljivke našteti na vrhu funkcije */

   if (ArgC != 3)
      Napaka("Napaèno število argumentov", ""); /* ni rezervnih parametrov */

   Vhod = fopen(ArgV[1], "r");   /* prva datoteka je vhodna */
   if (!Vhod)
      Napaka("Ne morem odpreti vhodne datoteke", ArgV[1]);

   Izhod = fopen(ArgV[2], "w");  /* druga datoteka je izhodna */
   if (!Izhod)
      Napaka("Ne morem odpreti izhodne datoteke", ArgV[2]);

   fscanf(Vhod, "%c", &c);
   while ( !feof(Vhod) ) {
      fprintf(Izhod, "%c", c);
      fscanf(Vhod, "%c", &c);
      }

   printf("Datoteki sta prepisani \n");

   return 1;
}
