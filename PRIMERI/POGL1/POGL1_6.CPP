#include <iostream.h>

int main()
{
   int st1, st2;

   cout << "Podajte prvo število .... ";
   cin >> st1;
   cout << "Podajte drugo število ... ";
   cin >> st2;

   if (st1 > st2)
      cout << "Prvo število je veèje.";
   else
      cout << "Drugo število je veèje ali enako prvemu.";

   return 0;
}
