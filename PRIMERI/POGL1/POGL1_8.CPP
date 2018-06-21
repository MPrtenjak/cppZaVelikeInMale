#include <iostream.h>

int vpisi()
{
   int st;

   cout << "Vpišite število /0 - konec/ ... ";
   cin >> st;

   return st;  // funkcija vrne tisto, kar je uporabnik vpisal
}

int main()
{
   int st, sestevek;

   st = vpisi();
   sestevek = st;

   while (st != 0) {
      st = vpisi();
      sestevek = sestevek + st;
      } 

   cout << "Seštevek števil je " << sestevek << "." << endl;

   return 1;
}
