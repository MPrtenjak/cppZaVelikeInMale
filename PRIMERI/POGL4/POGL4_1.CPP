#include <iostream.h>

int main()
{
   int st;

   cout << "Vpišite število ... ";
   cin >> st;

   if (st % 2 == 0)
      cout << "Število je sodo.";
   else
      cout << "Število je liho.";

   return 1;
}
