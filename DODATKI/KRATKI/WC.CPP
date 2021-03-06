/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matja� Prtenjak

   NAMEN:
      �tetje vrstic, besed in znakov

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>    // za manipulatorje

#define  TRUE     1
#define  FALSE    0

main(int ArgC, char *ArgV[])
{
   long  st_vrstic   = 0,     // �tevilo vrstic v teko�i datoteki
         st_besed    = 0,     // �tevilo besed v teko�i datoteki
         st_znakov   = 0;     // �tevilo znakov v teko�i datoteki

   long  skupaj_vrstic  = 0,  // skupno �tevilo vrstic (v vseh datotekah)
         skupaj_besed   = 0,  // skupno �tevilo vrstic (v vseh datotekah)
         skupaj_znakov  = 0;  // skupno �tevilo vrstic (v vseh datotekah)

   int   i = 1;   // teko�a datoteka

   cout << setw(10) << "vrstice" << setw(10) << "besede";
   cout << setw(10) << "znaki" << "   " << "datoteka" << endl;
   cout << setw(10) << "--------" << setw(10) << "--------";
   cout << setw(10) << "--------" << "   " << "--------" << endl;

   while (i < ArgC) {
      ifstream Vhod( ArgV[i] );
      if ( !Vhod ) {
         cout << setw(30) << " " << "   Ne morem odpreti datoteke " << ArgV[i];
         cout << endl;
         i++;              // poskusi z naslednjo datoteko
         continue;
      }

      int   v_besedi = FALSE; // spremenljivka ima vrednost TRUE, �e se
                              // trenutno nahajamo v besedi
      unsigned char  znak;             // znak iz datoteke

      st_vrstic = st_besed = st_znakov = 0;     // �tevce na 0
      Vhod.get(znak);         // preberi znak
      while ( Vhod ) {        // dokler ni konec datteke
         st_znakov++;         // pove�aj �tevec znakov
         if (znak == '\n')       // ali je nova vrstica
            st_vrstic++;      // pove�aj �tevec vrstic
         if (znak == ' ' || znak == '\t' || znak == '\n')
            v_besedi = FALSE; // �e je kateri izmed teh, potem je besede konec
         else 
            if ( v_besedi == FALSE) {  // �e do sedaj nismo bili v besedi
               v_besedi = TRUE;        // to poemni da zdaj smo
               st_besed++;             // pove�aj �tevilo besed
            }

         Vhod.get(znak);               // preberi naslednji znak
      }  // konec zanke while

      cout << setw(10) << st_vrstic << setw(10) << st_besed;
      cout << setw(10) << st_znakov << "   " << ArgV[i] << endl;

      Vhod.close();     // zapri datoteko

      // pove�aj skupne �tevce
      skupaj_vrstic += st_vrstic;
      skupaj_besed += st_besed;
      skupaj_znakov += st_znakov;

      i++;     // naslednja datoteka
   }  // konec zunanje zanke while

   if (ArgC > 2) {
      cout << setw(10) << "========" << setw(10) << "========";
      cout << setw(10) << "========" << "   " << "========" << endl;

      cout << setw(10) << skupaj_vrstic << setw(10) << skupaj_besed;
      cout << setw(10) << skupaj_znakov << "   " << "VSOTA" << endl;
   }

   return 0;
}
