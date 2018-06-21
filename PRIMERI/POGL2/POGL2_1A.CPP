#include <iostream.h>

int main()
{
   int      i1 = -12, i2 = 3  , i3 = 4;
   unsigned    u1 = 10 , u2;
   float       f1      , f2 = 3.0;

/* A */ 
   u2 = u1 + i1;  // unsigned + int
   cout << "A: <unsigned> + <int> = <unsigned>             = " << u2 << endl;

/* B */ 
   f1 = i2/i3;
   cout << "B: <int> / <int>      = <int> -> <float> (3/4) = " << f1 << endl;

/* C */ 
   f1 = i2/f2;
   cout << "C: <int> / <float>    = <float> (3/4.0)        = " << f1 << endl;

/* D */ 
   f1 = i3/i2;
   cout << "D: <int> / <int>      = <int> -> <float> (4/3) = " << f1 << endl;

/* E */ 
   f1 = i3/f2;
   cout << "E: <int> / <float>    = <float> (4/3.0)        = " << f1 << endl;

   return 0;
}
