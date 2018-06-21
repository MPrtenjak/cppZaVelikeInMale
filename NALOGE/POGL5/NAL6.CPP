#include <iostream.h>

struct Cas {
   int ure;
   int minute;
   int sekunde;
};

void swap(Cas &c1, Cas &c2)
{
   Cas temp = c1;
   c1 = c2;
   c2 = temp;
}

void Izpisi(char *str, const Cas &c)
{
   cout << str << c.ure << ":" << c.minute << ":" << c.sekunde << endl;
}

int main()
{
   Cas c1, c2, c3;

   c1.ure = 12; c1.minute = 30; c1.sekunde = 14;
   c2.ure = 6; c2.minute = 15; c2.sekunde = 7;
   c3.ure = 23; c3.minute = 14; c3.sekunde = 0;

   Izpisi("c1 = ", c1);
   Izpisi("c2 = ", c2);
   cout << "Zamenjam c1 in c2 .... " << endl;
   swap(c1, c2);
   Izpisi("c1 = ", c1);
   Izpisi("c2 = ", c2);

   cout << endl << endl;
   Izpisi("c1 = ", c1);
   Izpisi("c3 = ", c3);
   cout << "Zamenjam c1 in c3 .... " << endl;
   swap(c1, c3);
   Izpisi("c1 = ", c1);
   Izpisi("c3 = ", c3);

   return 1;
}
