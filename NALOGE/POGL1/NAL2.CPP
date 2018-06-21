#include <iostream.h>

void krog(int r)
{
   cout << "Obseg kroga s polmerom " << r << " je " << 2*3.14*r << "." << endl;
   cout << "Površina kroga s polmerom " << r << " je " << 3.14*r*r << "." << endl;
   cout << endl;
}

int main() {
   int r;

   r = 10;
   while (r < 50) {
      krog(r);
      r = r + 2;
      }

   return 1;
}

