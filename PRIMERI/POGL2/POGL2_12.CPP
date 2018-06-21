#include <iostream.h>

struct obcan {
   char ime[15];
   char priimek[15];
   char EMSO[13];
};    // Na tem mestu smo samo deklarirali nov tip.
      // V spominu zanj še ni rezerviranega prostora!

int main()
{
   obcan o; // Ker je obcan nov tip, ga kot takšnega tudi obravnavamo.
            // Na tem mestu se je za spremenljivko o rezerviralo 43
            // mest (15 + 15 + 13 = 43).

   cout << "Vpišite ime ....... ";
   cin >> o.ime;  // do imena v strukturi obcan dostopamo z operatorjem '.'
   cout << "Vpišite priimek ... ";
   cin >> o.priimek;
   cout << "Vpišite EMŠO ...... ";
   cin >> o.EMSO;

   cout << endl << endl << "Podatki o obèanu : " << endl;
   cout << "          EMŠO    : " << o.EMSO << endl;
   cout << "          IME     : " << o.ime << endl;
   cout << "          PRIIMEK : " << o.priimek << endl;

   return 1;
}
