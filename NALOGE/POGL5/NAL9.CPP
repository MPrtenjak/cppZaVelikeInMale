#include <iostream.h>

long Fib_rekurziven(int n)
{
   if (n < 2) return 1;

   return (Fib_rekurziven(n - 1) + Fib_rekurziven(n - 2));
}

// izmenjujemo dve �tevili, od katerih vedno eno predstavlja
// re�itev, drugo pa predhodno generacijo
long Fib_iterativen(int n)
{
   if (n < 2) return 1;

   long a = 1, b = 1;
   int drugi = 1; // drugo �tevilo je re�itev

   for (int j = 0; j < n - 1;j++)
      if (drugi) {
         a += b;
         drugi = 0;  // re�itev je v prvem
      }
      else {
         b += a;
         drugi = 1;  // re�itev je v drugem
      }

   return (drugi) ? b : a;
}

int main()
{
   for (int i = 0; i < 20; i++)
      cout << "Fibbonacijevo �tevilo reda " << i << " je "
         << Fib_rekurziven(i) << "  " << Fib_iterativen(i) << endl;

   return 1;
}
