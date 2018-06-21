#include <iostream.h>

class Tocka {
public:
   float x, y;
};

int main()
{
   Tocka T;

   T.x = 10.5; T.y = 3.14;
   cout << "Objekt T vsebuje: " << endl;
   cout << "\t x, ki ima vrednost " << T.x << endl;
   cout << "\t y, ki ima vrednost " << T.y << endl;

   return 0;
}
