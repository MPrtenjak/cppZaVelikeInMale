#include <iostream.h>

int main()
{
   char polje[10];

   cin.get(polje, 10, 'a');
   cout << polje << '\n';

   cin.get(polje, 10, '\t');
   cout << polje << '\n';

   return 1;
}