#include <iostream.h>

int vpisi()
{
   int st;

   cout << "Vpi�ite �tevilo /0 - konec/ ... ";
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

   cout << "Se�tevek �tevil je " << sestevek << "." << endl;

   return 1;
}
