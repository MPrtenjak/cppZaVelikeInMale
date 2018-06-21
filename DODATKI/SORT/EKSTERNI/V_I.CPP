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

// V_I.cpp vsebuje tudi vunkcije za interno uporabo
void PrepisiCeto(ifstream &vhod, ofstream &izhod, TIP_PODATKA &naslednji)
{
   TIP_PODATKA stari;

   do {
      izhod << naslednji << " ";
      stari = naslednji;
      vhod >> naslednji;
   } while ( vhod && !manjsi(naslednji, stari) );

   st_cet++;
}

/*
   Zlivanje datotek
*/
void Merge()
{
   ifstream Vhod1(temp1);
   ifstream Vhod2(temp2);
   ofstream Izhod(ImeDatoteke);

   if ( !Vhod1 || !Vhod2 )
      { cerr << "Ne morem odpreti zaèasnih datotek!"; exit(VHODNA_DATOTEKA); }
   if ( !Izhod )
      { cerr << "Ne morem odpreti datoteke!"; exit(IZHODNA_DATOTEKA); }

   TIP_PODATKA podatek1, podatek2, stari;

   st_cet = 0;
   Vhod1 >> podatek1;
   Vhod2 >> podatek2;

   while ( Vhod1 && Vhod2 ) {
      if ( manjsi(podatek1, podatek2) ) { 
         Izhod << podatek1 << " "; 
         stari = podatek1;
         Vhod1 >> podatek1; 
         if ( !Vhod1 || manjsi(podatek1, stari) )
            PrepisiCeto(Vhod2, Izhod, podatek2);
         }
      else {
         Izhod << podatek2 << " "; 
         stari = podatek2;
         Vhod2 >> podatek2;
         if ( !Vhod2 || manjsi(podatek2, stari) )
            PrepisiCeto(Vhod1, Izhod, podatek1);
         }
   }

   while ( Vhod1 ) PrepisiCeto(Vhod1, Izhod, podatek1);
   while ( Vhod2 ) PrepisiCeto(Vhod2, Izhod, podatek2);

   Vhod1.close();
   Vhod2.close();
   Izhod.close();
}

void Distribute()
{
   ofstream Izhod1(temp1);
   ofstream Izhod2(temp2);
   ifstream Vhod(ImeDatoteke);

   if ( !Izhod1 || !Izhod2 )
      { cerr << "Ne morem odpreti zaèasnih datotek!"; exit(IZHODNA_DATOTEKA); }
   if ( !Vhod )
      { cerr << "Ne morem odpreti datoteke!"; exit(VHODNA_DATOTEKA); }

   TIP_PODATKA podatek;

   Vhod >> podatek;
   while ( Vhod ) {
      PrepisiCeto(Vhod, Izhod1, podatek);
      if ( !Vhod ) 
         break;
      PrepisiCeto(Vhod, Izhod2, podatek);
   }

   Izhod1.close();
   Izhod2.close();
   Vhod.close();
}

