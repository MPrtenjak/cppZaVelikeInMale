/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

      ALGORITMA za funkciji
         ZapolniPolje in Poisci
            sta povzeta po knjigi Algorithms, Robert-a Sedgewick-a

   NAMEN:
      Poišèe niz v datoteki.

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <fstream.h>
#include <string.h>

void help(char *ProgName)
{
   cout << "Program preveri ali se doloèen niz pojavi v datoteki." << endl;
   cout << "V primeru pojavitve vrne vrednost 0, sicer pa vrednost 1." << endl;
   cout << "Èe pride do kakšne druge napake vrne vrednost 2." << endl << endl;
   cout << "UPORABA: " << ProgName << " <datoteka> \"niz\"" << endl;
   cout << "PRIMER : " << ProgName << " imena.dat \"Matjaž Prtenjk\"" << endl;
}

void ZapolniPolje(int *polje, char *niz)
{
   int i, j;   // pomožni spr.

   i = 0;
   j = -1;
   polje[i] = -1;

   do {
      if ( (j == -1) || (niz[i] == niz[j]) )
         {  i++; j++; polje[i] = j; }
      else
         j = polje[j];
   } while (i != strlen(niz));
}

int Poisci(ifstream &Datoteka, int *Nazaj, char *niz)
{
   int ch,                    // znak v datoteki
       j,                     // pomožna spr.
       dolzina = strlen(niz); //dolzina niza

   j = -1; ch = Datoteka.get();
   do {
      if ( (j == -1) || (ch == niz[j]) )
         { j++; ch = Datoteka.get(); }
      else
         j = Nazaj[j];
   } while ( (j != dolzina) && (Datoteka) );

   if (j == dolzina) return 1;
   else              return 0;
}

int main(int ArgC, char *ArgV[])
{
   if (ArgC != 3) {  // napaèno število argumentov
      cout << "NAPAKA: Napaèno število argumentov!" << endl << endl;
      help(ArgV[0]);
      return(2);
   }

   ifstream StrIn(ArgV[1]);   // odpri datoteko
   if (!StrIn) {  // napaka pri odpiranju datoteke
      cout << "NAPAKA: Ne morem odpreti datoteke " << ArgV[1] << "!";
      cout << endl << endl;
      help(ArgV[0]);
      return(2);
   }

// povzeto po Robertu Sedgewicku
   int   *Nazaj;  // polje s podatki o vraèanju
   Nazaj = new int[ strlen(ArgV[2]) + 1 ];
   if (Nazaj == NULL) {
      cout << "NAPAKA: Premalo spomina! " << endl << endl;
      help(ArgV[0]);
      return(2);
   }

   ZapolniPolje(Nazaj, ArgV[2]); // na tem mestu je polje Nazaj zapolnjeno!
   if (Poisci(StrIn, Nazaj, ArgV[2])) { // èe vrne TRUE (!=0)
      cout << "Nasel sem niz!" << endl;

      cout << ArgV[2];                 // izpiše šesam niz
      for (int i = 0; i < 30; i++)     // in nadalnjih 30 znakov
         cout << (char)(StrIn.get());  // èe je datoteke prej konec, niè hudega

      return(0);                       // obvesti OS, da je niz našel
   }

   StrIn.close();
   delete [] Nazaj;  // poèistimo za sabo
   return(1);        // obvesti OS, da niza ni našel
}