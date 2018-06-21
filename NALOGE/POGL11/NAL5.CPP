#include <iostream.h>
#include <values.h>     // definirane MAX... konstante

class Int {
protected:
   long stevilo;

   void postavi(long l) {
      if (l < (-MAXINT - 1) || l > MAXINT )
         { cout << "\tPreveliko število !!"  << endl; l = 0; }
      stevilo = l;
   }

public:
   Int(int l = 0) {              // iz int --> Int
      postavi(l); }

   operator int() {              // iz Int --> int
      return (int) stevilo;
   }

   friend Int operator+(Int i1, Int i2) {
      Int Temp( i1.stevilo + i2.stevilo );
      return Temp;
      }

   friend Int operator-(Int i1, Int i2) {
      Int Temp( i1.stevilo - i2.stevilo );
      return Temp;
      }

   friend Int operator*(Int i1, Int i2) {
      Int Temp( i1.stevilo * i2.stevilo );
      return Temp;
      }

   Int& operator++() {
      postavi( stevilo + 1 );
      return *this;
      }

   Int& operator++(int) {
      postavi( stevilo + 1 );
      return *this;
      }

   Int& operator--() {
      postavi( stevilo - 1 );
      return *this;
      }

   Int& operator--(int) {
      postavi( stevilo - 1 );
      return *this;
      }
};

int main()
{
   Int   I2(-MAXINT - 1),
         I3(MAXINT);
   int   i2 = -MAXINT - 1, 
         i3 = MAXINT;

   cout << endl << "Poskusimo I2-- ... ";
   I2--;
   cout << endl << "Kaj pa i2-- ... ";
   i2--;

   cout << endl << "Poskusimo I3++ ... ";
   I3++;
   cout << endl << "Kaj pa i3++ ... ";
   i3++;

   return 1;
}

