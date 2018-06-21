#include <iostream.h>                                      l

inline double *mesto(double *polje, int x, int y)
{
   return (polje + 50*y + x);
}

int main()
{
   double *kd;

   kd = new double[1000];

   *mesto(kd, 0, 0) = 1;
   *mesto(kd, 0, 1) = 2;
   *mesto(kd, 1, 0) = 3;
   *mesto(kd, 1, 1) = 4;
   *mesto(kd, 2, 0) = 5;
   *mesto(kd, 2, 1) = 5;
   *mesto(kd, 3, 0) = 6;
   *mesto(kd, 3, 1) = 7;
   *mesto(kd, 4, 0) = 8;
   *mesto(kd, 4, 1) = 9;

    // ....

   return 1;
}


