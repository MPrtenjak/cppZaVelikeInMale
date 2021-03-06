/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matja� Prtenjak

      ALGORITMA za funkciji
         ZapolniPolje in Poisci
            sta povzeta po knjigi Algorithms, Robert-a Sedgewick-a

   NAMEN:
      Poi��e niz v datoteki.

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <fstream.h>
#include <string.h>

void help(char *ProgName)
{
   cout << "Program preveri ali se dolo�en niz pojavi v datoteki." << endl;
   cout << "V primeru pojavitve vrne vrednost 0, sicer pa vrednost 1." << endl;
   cout << "�e pride do kak�ne druge napake vrne vrednost 2." << endl << endl;
   cout << "UPORABA: " << ProgName << " <datoteka> \"niz\"" << endl;
   cout << "PRIMER : " << ProgName << " imena.dat \"Matja� Prtenjk\"" << endl;
}

void ZapolniPolje(int *polje, char *niz)
{
   int i, j;   // pomo�ni spr.

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
       j,                     // pomo�na spr.
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
   if (ArgC != 3) {  // napa�no �tevilo argumentov
      cout << "NAPAKA: Napa�no �tevilo argumentov!" << endl << endl;
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
   int   *Nazaj;  // polje s podatki o vra�anju
   Nazaj = new int[ strlen(ArgV[2]) + 1 ];
   if (Nazaj == NULL) {
      cout << "NAPAKA: Premalo spomina! " << endl << endl;
      help(ArgV[0]);
      return(2);
   }

   ZapolniPolje(Nazaj, ArgV[2]); // na tem mestu je polje Nazaj zapolnjeno!
   if (Poisci(StrIn, Nazaj, ArgV[2])) { // �e vrne TRUE (!=0)
      cout << "Nasel sem niz!" << endl;

      cout << ArgV[2];                 // izpi�e �esam niz
      for (int i = 0; i < 30; i++)     // in nadalnjih 30 znakov
         cout << (char)(StrIn.get());  // �e je datoteke prej konec, ni� hudega

      return(0);                       // obvesti OS, da je niz na�el
   }

   StrIn.close();
   delete [] Nazaj;  // po�istimo za sabo
   return(1);        // obvesti OS, da niza ni na�el
}