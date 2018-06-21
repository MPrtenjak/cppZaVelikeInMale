/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Glavna datoteka programa za sortiranje.

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>   // za tokove
#include <iomanip.h>
#include <fstream.h>
#include <stdio.h>      // za funkciji tmpnam() in remove()

#include "sort.hpp"

int  st_cet;                           // število èet
char ImeDatoteke[100 + 1],             // ime vhodne datoteke
     temp1[100 + 1], temp2[100 + 1];   // imeni zaèasnih datotek

int main()
{
   cout << "Program sortira podatke." << endl << endl;
   cout << "\t Vpišite vhodno  datoteko ... ";
   cin >> setw(100) >> ImeDatoteke;

   tmpnam(temp1);    // generira unikatno ime prve datoteke
   tmpnam(temp2);    // generira unikatno ime druge datoteke

   do {
      Distribute();
      Merge();
   } while ( st_cet > 1 );
                          
   remove(temp1);    // zbriše datoteko iz diska
   remove(temp2);    // zbriše datoteko iz diska

   return VSE_OK;
}

