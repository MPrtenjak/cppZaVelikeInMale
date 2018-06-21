/*
   Klasièni UNIX program WC - word count
*/

#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>    // za manipulatorje

#define  TRUE     1
#define  FALSE    0

main(int ArgC, char *ArgV[])
{
   long  st_vrstic   = 0,     // število vrstic v tekoèi datoteki
         st_besed    = 0,     // število besed v tekoèi datoteki
         st_znakov   = 0;     // število znakov v tekoèi datoteki

   long  skupaj_vrstic  = 0,  // skupno število vrstic (v vseh datotekah)
         skupaj_besed   = 0,  // skupno število vrstic (v vseh datotekah)
         skupaj_znakov  = 0;  // skupno število vrstic (v vseh datotekah)

   int   i = 1;   // tekoèa datoteka

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

      int   v_besedi = FALSE; // spremenljivka ima vrednost TRUE, èe se
                              // trenutno nahajamo v besedi
      unsigned char  znak;             // znak iz datoteke

      st_vrstic = st_besed = st_znakov = 0;     // števce na 0
      Vhod.get(znak);         // preberi znak
      while ( Vhod ) {        // dokler ni konec datteke
         st_znakov++;         // poveèaj števec znakov
         if (znak == '\n')       // ali je nova vrstica
            st_vrstic++;      // poveèaj števec vrstic
         if (znak == ' ' || znak == '\t' || znak == '\n')
            v_besedi = FALSE; // èe je kateri izmed teh, potem je besede konec
         else 
            if ( v_besedi == FALSE) {  // èe do sedaj nismo bili v besedi
               v_besedi = TRUE;        // to poemni da zdaj smo
               st_besed++;             // poveèaj število besed
            }

         Vhod.get(znak);               // preberi naslednji znak
      }  // konec zanke while

      cout << setw(10) << st_vrstic << setw(10) << st_besed;
      cout << setw(10) << st_znakov << "   " << ArgV[i] << endl;

      Vhod.close();     // zapri datoteko

      // poveèaj skupne števce
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
