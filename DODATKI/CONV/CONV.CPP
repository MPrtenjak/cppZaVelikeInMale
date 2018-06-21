/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Zamenja znake v datoteki

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <fstream.h>

class Pretvorba {
protected:
   unsigned char tabela[256];

public:
   Pretvorba() {
      for (int i = 0; i < 256; i++)
         tabela[i] = i;
   }

   unsigned char& operator[](unsigned char index) {
      return tabela[index];
   }
};

void help(char *ProgName)
{
   cout << "Program zamenja znake v datoteki." << endl;
   cout << "V primeru napake vrne vrednost veèjo od 0, sicer pa 0.";
   cout << endl << endl;
   cout << "UPORABA: " << ProgName << " <datoteka s podatki> <vhodna datoteka>";
   cout << " <izhodna datoteka>" << endl;
}


int main(int ArgC, char *ArgV[])
{
   if (ArgC != 4) {  // napaèno število argumentov
      cout << "NAPAKA: Napaèno število argumentov!" << endl << endl;
      help(ArgV[0]);
      return(1);
   }

   ifstream Podatki(ArgV[1]); // odpri datoteko
   if (!Podatki)  {  // napaka pri odpiranju datoteke
      cout << "NAPAKA: Ne morem odpreti datoteke " << ArgV[1] << "!";
      cout << endl << endl;
      help(ArgV[0]);
      return(1);
   }

   Pretvorba pret;
   int num1, num2;

   Podatki >> num1 >> num2;         // preberi prvi par
   if (Podatki)
      pret[num1] = num2;            // èe par obstaja ju zamenjaj

   while (Podatki) {                // dokler so podatki
      Podatki >> num1 >> num2;      // preberi naslednji par
      if (Podatki)
         pret[num1] = num2;         // èe par obstaja ju zamenjaj
   }
   Podatki.close();

   ifstream StrIn(ArgV[2]);   // odpri vhodno datoteko
   if (!StrIn) {  // napaka pri odpiranju datoteke
      cout << "NAPAKA: Ne morem odpreti datoteke " << ArgV[2] << "!";
      cout << endl << endl;
      help(ArgV[0]);
      return(1);
   }

   ofstream StrOut(ArgV[3]);  // odpri izhodno datoteko
   if (!StrOut)   {  // napaka pri odpiranju datoteke
      cout << "NAPAKA: Ne morem odpreti datoteke " << ArgV[3] << "!";
      cout << endl << endl;
      help(ArgV[0]);
      return(1);
   }

   unsigned char ch;
   StrIn.get(ch);             // preberi znak iz datoteke
   while (StrIn) {            // dokler datoteke ni konec
      StrOut.put(pret[ch]);     // pretvori znak in ga zapisi
      StrIn.get(ch);            // preberi naslednjega
   }

   StrIn.close();
   StrOut.close();

   return(0);        // obvesti OS, da niza ni našel
}