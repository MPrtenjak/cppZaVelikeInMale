#include <iostream.h>

void funkcija(int i)
{
   cout << "Sem v funkciji s parametrom funkcija(" << i << ")\n";
   if (i--)
      funkcija(i);
}

int main()
{
   funkcija(2);

   return 1;
}
