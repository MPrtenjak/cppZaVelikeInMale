#include <iostream.h>

struct obcan {
   char ime[15];
   char priimek[15];
};

int main()
{
   obcan o[2]; // Dva ob�ana
   obcan *ko;  // Kazalec na strukturo obcan

   // podatki o prvem ob�anu
   cout << "Prvi ob�an : " << endl;
   cout << "Vpi�ite ime ....... ";
   cin >> o[0].ime;  
   cout << "Vpi�ite priimek ... ";
   cin >> o[0].priimek;

   ko = &o[1];    // kazalec ka�e na drugega ob�ana

   // Podatke o drugem ob�anu bomo vpisovali s pomo�jo kazalca.
   // Bodite pozorni na nov operator '->'
   cout << "Drugi ob�an : " << endl;
   cout << "Vpi�ite ime ....... ";
   cin >> ko->ime;   
   cout << "Vpi�ite priimek ... ";
   cin >> ko->priimek;

   int i = 0;
   while (i < 2) {
      cout << endl << endl << "Podatki o ob�anu #" << i << " : " << endl;
      cout << "          IME     : " << o[i].ime << endl;
      cout << "          PRIIMEK : " << o[i].priimek << endl;
      i = i + 1;
      }

   cout << endl << "Struktura obcan zaseda ";
   cout << sizeof(obcan) << " byte-ov." << endl;

   return 1;
}
