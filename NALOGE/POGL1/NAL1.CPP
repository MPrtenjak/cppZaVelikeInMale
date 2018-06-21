#include <iostream.h>

int main() {
   int r;

   cout << "Podajte polmer kroga ... ";
   cin >> r;

   cout << endl;
   cout << "Obseg kroga s polmerom " << r << " je " << 2*3.14*r << "." << endl;
   cout << "Površina kroga s polmerom " << r << " je " << 3.14*r*r << "." << endl;

   return 1;
}

