#include <iostream.h>

class complex {
   double re, im;
public:
   complex() { re = im = 0.0; }
   complex(double r, double i)
      { re = r; im =i; }

   friend complex operator+(complex, complex);

   void Izpisi()
      { cout << "(" << re << "," << im << ")" << endl; }
};

complex operator+(complex c1, complex c2)
{
   return ( complex(c1.re + c2.re, c1.im + c2.im) );
}

int main()
{
   complex A(10, 4), B(3, 5);
   complex C;

   C = A + B;
   C.Izpisi();

   C = complex(1,1) + A + B + complex(10, 5);
   C.Izpisi();

   return(1);
}



