/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Prebere in zapiše podatke v datoteko.

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>   // za tokove
#include <fstream.h>
#include <stdlib.h>     // za exit()...

#include "sort.hpp"

/*

   Prvi vhodni podatek je ŠTEVILKA, KI POVE KOLIKO PODATKOV SE NAHAJA V
   DATOTEKI. Za njo pa so zapisani podatki, ki so loèeni s presledki,
   tabulatorji znaki za novo vrstico!

*/
void preberi(char *datoteka)
{
   ifstream Vhod(datoteka);
   if ( !Vhod ) {
      cerr << "Na morem odpreti daototeke " << datoteka << "." << endl;
      exit(VHODNA_DATOTEKA);
   }

   Vhod >> Kolicina; // prebere število podatkov

   Podatek = new TIP_PODATKA[ Kolicina ]; // rezerviramo prostor
   if ( !Podatek ) {
      cerr << "Problemi s spominom." << endl;
      exit(PREMALO_SPOMINA);
      }

   for (int i = 0; i < Kolicina; i++) {
      if (!Vhod)  {
         Kolicina = i -1 ; // èe je manj podatkov oz. je bil podatek o kolièini
         break;            // napaèen.
      }
      Vhod >> Podatek[i];
   }

   Vhod.close();
}

/*

   Prvi vhodni podatek je ŠTEVILKA, KI POVE KOLIKO PODATKOV SE NAHAJA V
   DATOTEKI. Za njo pa so zapisani podatki (vsak v svoji vrstici).

*/
void zapisi(char *datoteka)
{
   ofstream Izhod(datoteka);
   if ( !Izhod ) {
      cerr << "Na morem odpreti daototeke " << datoteka << "." << endl;
      exit(IZHODNA_DATOTEKA);
   }

   Izhod << Kolicina << endl; // zapiše število podatkov

   for (int i = 0; i < Kolicina; i++) {
      Izhod << Podatek[i] << endl;
   }

   Izhod.close();

   delete [] Podatek;
}


