#include <iostream.h>

char *Vnos(const char *tekst)
{
   char tmp[200];    // za�asno polje

// vnos
   cout << tekst;    // izpi�emo tekst
   cin >> tmp;       // uporabnik vpi�e niz znakov

// �tetje znakov (dol�ina)
   char *kTmp = tmp;          // kazalec na tmp - da pre�tejemo znake
   while ( *kTmp ) kTmp++;    // pre�tej znake
   int dol = kTmp - tmp;      // dol�ina je razlika kazalcev

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

   ime = Vnos("Vpi�ite ime ....... ");
   priimek = Vnos("Vpi�ite priimek ... ");

   cout << ime << priimek << endl;

   delete ime;
   delete priimek;

   return 1;
}



