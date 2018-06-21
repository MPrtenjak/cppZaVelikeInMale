#include <iostream.h>

int main()
{
   izpisi1(0);
   return 1;
}

void izpisi1(int i)
{
   if (i == 0)
      izpisi2(0);

   cout << "Izpis prve funkcije " << endl;
}

void izpisi2(int i)
{
   if (i == 0)
      izpisi1(1);

   cout << "Izpis druge funkcije " << endl;
}
