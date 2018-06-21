#include <iostream.h>

int main()
{
   int polje[10];

   int i = 0;
   while (cin >> polje[i] && ++i < 10);

   for (int j = 0; j < i; j++)
      cout << "polje[" << j << "] = " << polje[j] << '\n';

   return 1;
}