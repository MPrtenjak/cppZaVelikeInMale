/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matja� Prtenjak

   NAMEN:
      Implementacija algoritma za iskanje pra�tevil po metodi Eratosovega sita

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
   int   i, j,             // �tevca
         polje[N + 1];     // polje �tevil

   for (i = 0; i <= N; i++)
      polje[i] = TRUE;        // re�emo, da so vsa �tevila pra�tevila

   for (i = 2; i <= N/2; i++)
      for (j = 2; j <= N/i; j++)
         polje[i*j] = FALSE;     // produkt dveh �tevil NI PRA�TEVILO

   for (i = 1; i <= N; i++)
      if ( polje[i] )      // �e je pra�tevilo ga izpi�i
         cout << setw(5) << i;

   cout << endl;

   return 0;
}








