#include <iostream.h>

struct obcan {
   char ime[15];
   char priimek[15];
};

int main()
{
   obcan o[2]; // Dva obèana
   obcan *ko;  // Kazalec na strukturo obcan

   // podatki o prvem obèanu
   cout << "Prvi obèan : " << endl;
   cout << "Vpišite ime ....... ";
   cin >> o[0].ime;  
   cout << "Vpišite priimek ... ";
   cin >> o[0].priimek;

   ko = &o[1];    // kazalec kaže na drugega obèana

   // Podatke o drugem obèanu bomo vpisovali s pomoèjo kazalca.
   // Bodite pozorni na nov operator '->'
   cout << "Drugi obèan : " << endl;
   cout << "Vpišite ime ....... ";
   cin >> ko->ime;   
   cout << "Vpišite priimek ... ";
   cin >> ko->priimek;

   int i = 0;
   while (i < 2) {
      cout << endl << endl << "Podatki o obèanu #" << i << " : " << endl;
      cout << "          IME     : " << o[i].ime << endl;
      cout << "          PRIIMEK : " << o[i].priimek << endl;
      i = i + 1;
      }

   cout << endl << "Struktura obcan zaseda ";
   cout << sizeof(obcan) << " byte-ov." << endl;

   return 1;
}
