#include <iostream.h>

int fun(int i1, int i2)
{
   return (3*i1 + 5*i2);
}

int main()
{
   int r1, r2;

   r1 = fun(13, 4);
   r2 = fun(5, 7);

   cout << r1 << " " << r2 << endl;

   return 1;
}

