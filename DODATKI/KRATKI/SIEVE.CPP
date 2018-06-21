/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Implementacija algoritma za iskanje praštevil po metodi Eratosovega sita

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <iomanip.h>    // za setw(...) manipulator

#define TRUE   1
#define FALSE  0

const int   N = 1000;

int main()
{
   int   i, j,             // števca
         polje[N + 1];     // polje števil

   for (i = 0; i <= N; i++)
      polje[i] = TRUE;        // reèemo, da so vsa števila praštevila

   for (i = 2; i <= N/2; i++)
      for (j = 2; j <= N/i; j++)
         polje[i*j] = FALSE;     // produkt dveh števil NI PRAŠTEVILO

   for (i = 1; i <= N; i++)
      if ( polje[i] )      // èe je praštevilo ga izpiši
         cout << setw(5) << i;

   cout << endl;

   return 0;
}








