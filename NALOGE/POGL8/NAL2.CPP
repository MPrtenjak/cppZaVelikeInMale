#include <iostream.h>

char *Vnos(const char *tekst)
{
   char tmp[200];    // zaèasno polje

// vnos
   cout << tekst;    // izpišemo tekst
   cin >> tmp;       // uporabnik vpiše niz znakov

// štetje znakov (dolžina)
   char *kTmp = tmp;          // kazalec na tmp - da preštejemo znake
   while ( *kTmp ) kTmp++;    // preštej znake
   int dol = kTmp - tmp;      // dolžina je razlika kazalcev

   if ( dol == 0 )
      return NULL;

// prepis niza
   char *spr = new char[ dol + 1 ]; // rezerviramo prostor
   char *kSpr = spr;                // kazalec na spremenljivko
   kTmp = tmp;                      // kazalec na tmp

   while ( *kTmp ) {
      *kSpr = *kTmp;
      kSpr++; kTmp++;
   }
   *kSpr = '\0';

   return spr;
}

int main()
{
   char *ime, *priimek;

   ime = Vnos("Vpišite ime ....... ");
   priimek = Vnos("Vpišite priimek ... ");

   cout << ime << priimek << endl;

   delete ime;
   delete priimek;

   return 1;
}



