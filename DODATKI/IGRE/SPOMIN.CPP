/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Program, ki testira, koliko znakov si uporabnik lahko zapomni

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <string.h>  // deklaracije str...() funkcij
#include <stdlib.h>  // deklaracije funkcij za nakljuèna števila

#include "zaslon.hpp"   // za delo z zaslonom

const int MAX = 80;
                 
enum TipZnakov {  // kaj si je uporabnik izbral
   stevila  = 1,
   crke     = 2,
   oboje    = 3
};

int menu()  // izpiše menu in vrne uporabnikovo izbiro
{
   int izbira;

   do {
      BrisiZaslon(); 
      cout << endl << endl ;
      cout << "\tIzberite opcijo ...." << endl << endl;
      cout << "\t\t1. Števila" << endl;
      cout << "\t\t2. Èrke" << endl;
      cout << "\t\t3. Števila in èrke" << endl << endl;
      cout << "\t\t4. Konec" << endl;
      cout << "\t\t==================" << endl;
      cout << "\t\t>>>> ";

      cin >> izbira;       // v toku ostane še znak za novo vrstico
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
         i = rand() % 26;     // znakov je 26 (angleških - da ne kompliciramo)
         return ('A' + i);
      default:
         i = rand() % 36;     // èe je i < 10, bo izpisl cifor, sicer pa znak
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
   int   pozicija;      // koliko si jih je uporabnik že zapomnil

   randomize();   // inicializira generator nakljuènih števil

   for(;;) {   // neskonèna zanka
      int mnu = menu(); // izpiše menu

      if ( mnu == 4 )   // konec
         break;         // pobegne iz zanke

      pozicija = 0;
      do {
         BrisiZaslon();

         // Izmisli si naslednji znak
         Polje[pozicija] = naslednji( (TipZnakov) mnu);
         PostaviSeNaXY(40, 2);  cout << Polje[pozicija]; // izpiši znak
         Polje[++pozicija] = '\0';              // zakljuèi niz znakov

         PostaviSeNaXY(0, 5); cout << "Ponovite celotno kombinacijo ... ";
         cin.getline(odgovor, MAX);
         
         if (pozicija > MAX - 2) break;
      } while ( stricmp(Polje, odgovor) == 0 ); // stricmp ==> 'a' == 'A'

      BrisiZaslon();
      if (pozicija > MAX - 2) 
         cout << "Èe ste si zapomnili toliko znakov, mislim da goljufate!";
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
      


