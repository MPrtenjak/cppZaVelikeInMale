#include <iostream.h>

struct Oseba {
   char *ime;
   char *priimek;
};

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
   Oseba *kOsebe;
   int   stevilo;

   cout << "Število oseb ... ";
   cin >> stevilo;

   kOsebe = new Oseba[ stevilo ];
   for(int i = 0; i < stevilo; i++) {
      kOsebe[i].ime = Vnos("Vpišite ime ....... ");
      kOsebe[i].priimek = Vnos("Vpišite priimek ... ");
   }

   cout << endl << endl << endl;
   for(i = 0; i < stevilo; i++) {
      cout << "Oseba #" << (i+1) << endl;
      cout << "\t" << kOsebe[i].ime << " " << kOsebe[i].priimek << endl;
   }

   for(i = 0; i < stevilo; i++) {
      delete kOsebe[i].ime;
      delete kOsebe[i].priimek;
   }
   delete kOsebe;

   return 1;
}



