/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matja� Prtenjak

   NAMEN:
      Prebere in zapi�e podatke v datoteko.

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>   // za tokove
#include <fstream.h>
#include <stdlib.h>     // za exit()...

#include "sort.hpp"

/*

   Prvi vhodni podatek je �TEVILKA, KI POVE KOLIKO PODATKOV SE NAHAJA V
   DATOTEKI. Za njo pa so zapisani podatki, ki so lo�eni s presledki,
   tabulatorji znaki za novo vrstico!

*/
void preberi(char *datoteka)
{
   ifstream Vhod(datoteka);
   if ( !Vhod ) {
      cerr << "Na morem odpreti daototeke " << datoteka << "." << endl;
      exit(VHODNA_DATOTEKA);
   }

   Vhod >> Kolicina; // prebere �tevilo podatkov

   Podatek = new TIP_PODATKA[ Kolicina ]; // rezerviramo prostor
   if ( !Podatek ) {
      cerr << "Problemi s spominom." << endl;
      exit(PREMALO_SPOMINA);
      }

   for (int i = 0; i < Kolicina; i++) {
      if (!Vhod)  {
         Kolicina = i -1 ; // �e je manj podatkov oz. je bil podatek o koli�ini
         break;            // napa�en.
      }
      Vhod >> Podatek[i];
   }

   Vhod.close();
}

/*

   Prvi vhodni podatek je �TEVILKA, KI POVE KOLIKO PODATKOV SE NAHAJA V
   DATOTEKI. Za njo pa so zapisani podatki (vsak v svoji vrstici).

*/
void zapisi(char *datoteka)
{
   ofstream Izhod(datoteka);
   if ( !Izhod ) {
      cerr << "Na morem odpreti daototeke " << datoteka << "." << endl;
      exit(IZHODNA_DATOTEKA);
   }

   Izhod << Kolicina << endl; // zapi�e �tevilo podatkov

   for (int i = 0; i < Kolicina; i++) {
      Izhod << Podatek[i] << endl;
   }

   Izhod.close();

   delete [] Podatek;
}


