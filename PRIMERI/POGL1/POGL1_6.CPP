#include <iostream.h>

int main()
{
   int st1, st2;

   cout << "Podajte prvo �tevilo .... ";
   cin >> st1;
   cout << "Podajte drugo �tevilo ... ";
   cin >> st2;

   if (st1 > st2)
      cout << "Prvo �tevilo je ve�je.";
   else
      cout << "Drugo �tevilo je ve�je ali enako prvemu.";

   return 0;
}
