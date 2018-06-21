#include <iostream.h>

int main() {
   int a, b, c;

   cout << "Podajte dolino prve stranice kvadra ..... ";
   cin >> a;
   cout << "Podajte dolino druge stranice kvadra .... ";
   cin >> b;
   cout << "Podajte dolino tretje stranice kvadra ... ";
   cin >> c;

   cout << endl;
   cout << "Površina kvadra znaša " << 2*(a*b + a*c + b*c) << "." << endl;
   cout << "Prostornina kvadra znaša " << a*b*c << "." << endl;

   return 1;
}


