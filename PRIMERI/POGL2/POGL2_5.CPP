#include <iostream.h>

void zamenjaj(int i1, int i2)
{
   cout << "   V FUNKCIJI : &i1 == " << &i1 << ", &i2 == " << &i2 << endl;
}

int main()
{
   int i1 = 11, i2 = 22;

   cout << "V GLAVNEM PROGRAMU : &i1 == " << &i1 << ", &i2 == " << &i2 << endl;
   zamenjaj(i1, i2);

   return 1;
}
