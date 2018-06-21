#include <iostream.h>

long Fib(int n)
{
   if (n < 2) return 1;

   return (Fib(n - 1) + Fib(n - 2));
}

int main()
{
   for (int i = 0; i < 20; i++)
      cout << "Fibbonacijevo število reda " << i << " je " << Fib(i) << endl;

   return 1;
}
