#include <iostream.h>

struct obcan {
   char ime[15];
   char priimek[15];
   char EMSO[13];
};    // Na tem mestu smo samo deklarirali nov tip.
      // V spominu zanj �e ni rezerviranega prostora!

int main()
{
   obcan o; // Ker je obcan nov tip, ga kot tak�nega tudi obravnavamo.
            // Na tem mestu se je za spremenljivko o rezerviralo 43
            // mest (15 + 15 + 13 = 43).

   cout << "Vpi�ite ime ....... ";
   cin >> o.ime;  // do imena v strukturi obcan dostopamo z operatorjem '.'
   cout << "Vpi�ite priimek ... ";
   cin >> o.priimek;
   cout << "Vpi�ite EM�O ...... ";
   cin >> o.EMSO;

   cout << endl << endl << "Podatki o ob�anu : " << endl;
   cout << "          EM�O    : " << o.EMSO << endl;
   cout << "          IME     : " << o.ime << endl;
   cout << "          PRIIMEK : " << o.priimek << endl;

   return 1;
}
