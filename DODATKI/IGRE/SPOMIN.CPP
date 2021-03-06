/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matja� Prtenjak

   NAMEN:
      Program, ki testira, koliko znakov si uporabnik lahko zapomni

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <string.h>  // deklaracije str...() funkcij
#include <stdlib.h>  // deklaracije funkcij za naklju�na �tevila

#include "zaslon.hpp"   // za delo z zaslonom

const int MAX = 80;
                 
enum TipZnakov {  // kaj si je uporabnik izbral
   stevila  = 1,
   crke     = 2,
   oboje    = 3
};

int menu()  // izpi�e menu in vrne uporabnikovo izbiro
{
   int izbira;

   do {
      BrisiZaslon(); 
      cout << endl << endl ;
      cout << "\tIzberite opcijo ...." << endl << endl;
      cout << "\t\t1. �tevila" << endl;
      cout << "\t\t2. �rke" << endl;
      cout << "\t\t3. �tevila in �rke" << endl << endl;
      cout << "\t\t4. Konec" << endl;
      cout << "\t\t==================" << endl;
      cout << "\t\t>>>> ";

      cin >> izbira;       // v toku ostane �e znak za novo vrstico
   } while (izbira < 1 || izbira > 4);

   char ch;
   cin.get(ch);      // sprazni tok

   BrisiZaslon(); 
   return izbira;
}

char naslednji(TipZnakov znak)      // vrne naslednji izbrani znak
{
   int i;   

   switch (znak) {
      case stevila:
         i = rand() % 10;     // cifer je deset
         return ('0' + i);
      case crke:
         i = rand() % 26;     // znakov je 26 (angle�kih - da ne kompliciramo)
         return ('A' + i);
      default:
         i = rand() % 36;     // �e je i < 10, bo izpisl cifor, sicer pa znak
         if (i < 10)       
            return ('0' + i);
         else
            return ('A' + i - 10);
   }
}

int main()
{
   char  Polje[MAX],    // polje z znaki
         odgovor[MAX];  // polje z znaki
   int   pozicija;      // koliko si jih je uporabnik �e zapomnil

   randomize();   // inicializira generator naklju�nih �tevil

   for(;;) {   // neskon�na zanka
      int mnu = menu(); // izpi�e menu

      if ( mnu == 4 )   // konec
         break;         // pobegne iz zanke

      pozicija = 0;
      do {
         BrisiZaslon();

         // Izmisli si naslednji znak
         Polje[pozicija] = naslednji( (TipZnakov) mnu);
         PostaviSeNaXY(40, 2);  cout << Polje[pozicija]; // izpi�i znak
         Polje[++pozicija] = '\0';              // zaklju�i niz znakov

         PostaviSeNaXY(0, 5); cout << "Ponovite celotno kombinacijo ... ";
         cin.getline(odgovor, MAX);
         
         if (pozicija > MAX - 2) break;
      } while ( stricmp(Polje, odgovor) == 0 ); // stricmp ==> 'a' == 'A'

      BrisiZaslon();
      if (pozicija > MAX - 2) 
         cout << "�e ste si zapomnili toliko znakov, mislim da goljufate!";
      else {
         cout << "Uspeli ste si zapomniti " << (pozicija - 1) << " znakov.";
         cout << endl << "Pravilno zaporedje je bilo: ";
         cout << Polje;
      }

      cout << endl << endl << "\tPitisnite <ENTER> za nadaljevanje";
      cin.getline(odgovor, MAX);
      }  // konec for

   return 1;
}                 
      


