#include <iostream.h>

int main()
{
   int st, sestevek;

   cout << "Vpi�ite �tevilo /0 - konec/ ... ";
   cin >> st;
   sestevek = st; // se�tevek je enak prvemu �tevilu, �e je to �tevilo 0, 
        // kar pomeni konec, ni� hudega, saj je zato tudi se�tevek enak 0

   while (st != 0) { // ponavljaj, dokler je vpisano �tevilo razli�no od 0
      cout << "Vpi�ite �tevilo /0 - konec/ ... ";
      cin >> st;        // vpi�ite novo �tevilo
      sestevek = sestevek + st;  // se�tevku pri�tejemo to novo �tevilo
      }

   cout << "Se�tevek �tevil je " << sestevek << "." << endl;

   return 1;
}
