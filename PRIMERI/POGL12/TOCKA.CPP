#include <iostream.h>

class Tocka {
   float x, y;

public:
   Tocka(float xx = 0, float yy = 0) { x = xx; y = yy; }

   void SetX(float xx) { x = xx; }
   void SetY(float yy) { y = yy; }

   float GetX() const
      { return x; }
   float GetY() const
      { return y; }

   friend ostream& operator<<(ostream& out, Tocka T);
};

ostream& operator<<(ostream& out, Tocka T)
{
   return out << "(" << T.x << "," << T.y << ")";
}

int main()
{
   Tocka a, b(10, 10);

   a.SetX(12.3);

   cout << "Toèka a se nahaja na " << a << '\n';
   cout << "Toèka b se nahaja na " << b << '\n';

   return 1;
}


