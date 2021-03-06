#include <iostream.h>

struct Oseba {
   char *ime;
   char *priimek;
};

// zanima nas tudi dol�ina vnesenega teksta
char *Vnos(const char *tekst, int &dol)
{
   char tmp[200];    // za�asno polje

// vnos
   cout << tekst;    // izpi�emo tekst
   cin >> tmp;       // uporabnik vpi�e niz znakov

// �tetje znakov (dol�ina)
   char *kTmp = tmp;          // kazalec na tmp - da pre�tejemo znake
   while ( *kTmp ) kTmp++;    // pre�tej znake
   dol = kTmp - tmp;          // dol�ina je razlika kazalcev

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

   cout << "�tevilo oseb ... ";
   cin >> stevilo;

   kOsebe = new Oseba[ stevilo ];
   for(int i = 0; i < stevilo; i++) {
      kOsebe[i].ime = Vnos("Vpi�ite ime ....... ", dol); zasedeno += dol;
      kOsebe[i].priimek = Vnos("Vpi�ite priimek ... ", dol); zasedeno += dol;
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



