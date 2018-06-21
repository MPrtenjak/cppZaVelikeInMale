#include <iostream.h>

long Fib(int n, int a, int b)
{
   if (n < 1) return a;
   if (n < 2) return b;

   return (Fib(n - 1, a, b) + Fib(n - 2, a, b));
}

int main()
{
   for (int i = 0; i < 10; i++)
      cout << "Fibbonacijevo število (1,1) reda " << i << " je "
         << Fib(i, 1, 1) << endl;

   for (i = 0; i < 10; i++)
      cout << "Fibbonacijevo število (4,6) reda " << i << " je "
         << Fib(i, 4, 6) << endl;

   for (i = 0; i < 10; i++)
      cout << "Fibbonacijevo število (1,1) reda " << i << " je "
         << Fib(i, 12, 15) << endl;

   return 1;
}
