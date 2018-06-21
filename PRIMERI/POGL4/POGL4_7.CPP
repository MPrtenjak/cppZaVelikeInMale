#include <iostream.h>

int main()
{
   int konec;

   cout << "Podajte mejo ... ";
   cin >> konec;

   for (int gor = 1, dol = konec; (gor <= konec) && (dol >= 1); gor++, dol--)
      cout << gor << "    " << dol << endl;

   return 1;
}
