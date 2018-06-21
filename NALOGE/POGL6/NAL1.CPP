#include <iostream.h>

// Pri nizih vrne tistega, ki je v pomnilniku zapisan prej!
//
// Zato, ker primerja kazalca na niza in ne nizov!
#define MIN(a, b) ( (a < b) ? (a) : (b) )

int main()
{
   cout << MIN(3,4) << endl;
   cout << MIN(4,3) << endl;
   cout << MIN(3.99999,4) << endl;
   cout << MIN(3.9999,4.01) << endl;
   cout << MIN(3,'a') << endl;
   cout << MIN('a','b') << endl;
   cout << MIN("Niz1","Niz2") << endl;
   cout << MIN("Niz2","Niz1") << endl;

   return 1;
}

