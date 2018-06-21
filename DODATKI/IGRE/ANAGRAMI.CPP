/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Program podaja anagrame, ki jih morate razvozlati.
      Anagrami se tvorijo iz vhodne datoteke (tekstovne).

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>       
#include <string.h>
#include <ctype.h>      // za funkcije is...()

#include "zaslon.hpp"   // za delo z zaslonom

// ********
// ********    KONSTANTE
// ********

#define TRUE   1
#define FALSE  0

#define MAX_BUFF  100

const char *Indeks = "anagrami.inp";

//
// izpiše menu in vrne uporabnikovo izbiro
//
int menu()
{
   int izbira;

   do {
      BrisiZaslon(); 
      cout << endl << endl ;
      cout << "\tIzberite opcijo ...." << endl << endl;
      cout << "\t\t1. Nova datoteka" << endl;
      cout << "\t\t2. Nov anagram" << endl << endl;
      cout << "\t\t3. Konec" << endl;
      cout << "\t\t==================" << endl;
      cout << "\t\t>>>> ";

      cin >> izbira;       // v toku ostane še znak za novo vrstico
   } while (izbira < 1 || izbira > 3);

   char ch;
   cin.get(ch);      // sprazni tok

   BrisiZaslon(); 
   return izbira;
}
//
// preetvori tekstovno datoteko 'Besede' v datoteko Indeks
//
int pretvori(char *Besede)
{
   ifstream Vhod(Besede);     // vhodna datoteka
   if (!Vhod) return FALSE;

   ofstream Izhod(Indeks);    // izhodna datoteka
   if (!Izhod) return FALSE;

   char line[MAX_BUFF];
   int  i = 0;

   Vhod.get(line[i]);
   while (Vhod) {
      if (isalpha(line[i]))      // ali je prebrani znak èrka
         Vhod.get(line[++i]); // preberi naslednji znak
      else {
         if (i > 4 && i < 15) // anagrami naj bodo dolgi med 4 in 15 znaki
            for (int j = 0; j < 15; j++) 
               if (j < i) Izhod.put(line[j]);   // izpiši znak
               else       Izhod.put('\0');      // smo že na koncu besede
         i = 0;
         Vhod.get(line[i]);
      }  // konec else
   }  // konec while

   // še zadnja beseda
   if (i > 4 && i < 15) // anagrami naj bodo dolgi med 4 in 15 znaki
      for (int j = 0; j < 15; j++) 
         if (j < i) Izhod.put(line[j]);   // izpiši znak
         else       Izhod.put('\0');      // smo že na koncu besede

   Vhod.close();
   Izhod.close();

   return TRUE;
}

//
// prešteje anagrame v datoteki
//
int prestejAnagrame()
{
   ifstream    Vhod(Indeks);

   Vhod.seekg((streampos) 0, ios::end);   // postavimo se na konec datoteke
   int st = Vhod.tellg() / 15;         // anagram zasede 15 znakov v datoteki

   Vhod.close();

   return (st);            
}

// 
// izmisli si anagram
//
void Igraj(int pozicija)
{
   char  anagram[15],      // pomešana beseda
         original[15],     // originalna beseeda
         vnos[MAX_BUFF];         // uporabnikov vnos

   ifstream    Vhod(Indeks);

   Vhod.seekg((streampos) pozicija * 15, ios::beg);
   Vhod.getline(original, 15);

   int dol = strlen(original);   // dolzina anagrama
   strcpy(anagram, original);    // prepišemo

   for (int i = 0; i < 10; i++)  { // opravimo 10 zamenjav
      int k = rand() % dol;      // izmisli si dve poziciji
      int l = rand() % dol;

      int temp = anagram[k];     // zamenjaj èrke na teh pozicijah
      anagram[k] = anagram[l];
      anagram[l] = temp;
   }

   int p = 0;  // dolžina pomoèi
   do {
      cout << "Kaj pomeni '" << anagram << "'? [P == pomoè] ... ";
      cin.getline(vnos, MAX_BUFF);
      if ( stricmp(vnos, "p") == 0 ) {
         p++;                          // pomagaj eno èrko veè
         if (p > dol) p = dol;   // pomagaj do konca
         cout << "\t";
         for(int j = 0; j < p; j++) cout << original[j];
         for(; j < dol; j++) cout << "?";
         cout << endl;
      }
   } while ( stricmp(vnos, original) != 0 );

   cout << endl << endl << "\tPitisnite <ENTER> za nadaljevanje";
   cin.getline(vnos, MAX_BUFF);

   Vhod.close();
}

int main()
{
   char  datoteka[MAX_BUFF];     // vhodna datoteka
   int   st_anagramov;        // število anagramov

   randomize();   // inicializira generator nakljuènih števil
   st_anagramov = prestejAnagrame();

   for(;;) {   // neskonèna zanka
      int mnu = menu(); // izpiše menu

      if (mnu == 1) {
         do {
            cout << "Podajte vhodno datoteko ... ";
            cin.getline(datoteka, MAX_BUFF);
         } while( pretvori( datoteka) == FALSE );
         st_anagramov = prestejAnagrame();
      }

      if (mnu  == 2) {
         if (st_anagramov < 5) {
            cout << "Premalo anagramov. Podajte vhodno datoteko!" << endl;
            cout << endl << endl << "\tPitisnite <ENTER> za nadaljevanje";
            cin.getline(datoteka, MAX_BUFF);
         }
         else  {
            int pozicija = rand() % st_anagramov;  // kateri anagram
            Igraj(pozicija);
         }
      }
            
      if ( mnu == 3 )   // konec
         break;         // pobegne iz zanke
   }  // koneec for;

   return 1;
}                 
      


