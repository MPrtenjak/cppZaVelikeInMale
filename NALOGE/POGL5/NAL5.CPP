#include <iostream.h>

char potenca(char x, int y = 2)
{
   char pot = 1;     // nekaj na 0 je 1

   for (int i = 0; i < y; i++)
      pot *= x;         // pomnoži y-krat

   return pot;
}

int potenca(int x, int y = 2)
{
   int pot = 1;      // nekaj na 0 je 1

   for (int i = 0; i < y; i++)
      pot *= x;         // pomnoži y-krat

   return pot;
}

long potenca(long x, int y = 2)
{
   long pot = 1;     // nekaj na 0 je 1

   for (int i = 0; i < y; i++)
      pot *= x;         // pomnoži y-krat

   return pot;
}

double potenca(double x, int y = 2)
{
   double pot = 1;      // nekaj na 0 je 1

   for (int i = 0; i < y; i++)
      pot *= x;         // pomnoži y-krat

   return pot;
}

int main()
{
   char   c = 5;
   int    i = 5;
   long   l = 5;
   double d = 5;

   cout << "Že pri malih potencah bo prišlo do prekoraèitev ..." << endl;
   cout << "Potenciramo število 5, kot: " << endl;
   cout << "pot\tchar\t(int) char\tint\tlong\tdouble" << endl;
   for(int j = 0; j < 20; j++)
      cout << i << "\t"
            << potenca(c, j) << "\t"
            << (int) potenca(c, j) << "\t\t"
            << potenca(i, j) << "\t"
            << potenca(l, j) << "\t"
            << potenca(d, j) << endl;

   return 1;
}



