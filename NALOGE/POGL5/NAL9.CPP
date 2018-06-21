#include <iostream.h>

long Fib_rekurziven(int n)
{
   if (n < 2) return 1;

   return (Fib_rekurziven(n - 1) + Fib_rekurziven(n - 2));
}

// izmenjujemo dve števili, od katerih vedno eno predstavlja
// rešitev, drugo pa predhodno generacijo
long Fib_iterativen(int n)
{
   if (n < 2) return 1;

   long a = 1, b = 1;
   int drugi = 1; // drugo število je rešitev

   for (int j = 0; j < n - 1;j++)
      if (drugi) {
         a += b;
         drugi = 0;  // rešitev je v prvem
      }
      else {
         b += a;
         drugi = 1;  // rešitev je v drugem
      }

   return (drugi) ? b : a;
}

int main()
{
   for (int i = 0; i < 20; i++)
      cout << "Fibbonacijevo število reda " << i << " je "
         << Fib_rekurziven(i) << "  " << Fib_iterativen(i) << endl;

   return 1;
}
