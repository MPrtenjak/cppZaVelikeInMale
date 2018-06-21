#include <iostream.h>

struct Oseba {
   char *ime;
   char *priimek;
};

// zanima nas tudi dolžina vnesenega teksta
char *Vnos(const char *tekst, int &dol)
{
   char tmp[200];    // zaèasno polje

// vnos
   cout << tekst;    // izpišemo tekst
   cin >> tmp;       // uporabnik vpiše niz znakov

// štetje znakov (dolžina)
   char *kTmp = tmp;          // kazalec na tmp - da preštejemo znake
   while ( *kTmp ) kTmp++;    // preštej znake
   dol = kTmp - tmp;          // dolžina je razlika kazalcev

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
   int   zasedeno = 0;
   int   dol;

   cout << "Število oseb ... ";
   cin >> stevilo;

   kOsebe = new Oseba[ stevilo ];
   for(int i = 0; i < stevilo; i++) {
      kOsebe[i].ime = Vnos("Vpišite ime ....... ", dol); zasedeno += dol;
      kOsebe[i].priimek = Vnos("Vpišite priimek ... ", dol); zasedeno += dol;
   }

   cout << endl << endl << endl;
   for(i = 0; i < stevilo; i++) {
      cout << "Oseba #" << (i+1) << endl;
      cout << "\t" << kOsebe[i].ime << " " << kOsebe[i].priimek << endl;
   }

   // vasaka oseba bi zasedla 20 mest (10 za ime in 10 za priimek)
   float procent = ((float) zasedeno) / ((float) stevilo * 20) * 100;
   cout << "Zasedenost je " << procent << "%" << endl;

   for(i = 0; i < stevilo; i++) {
      delete kOsebe[i].ime;
      delete kOsebe[i].priimek;
   }
   delete kOsebe;

   return 1;
}



