#include <iostream.h>

int main()
{
   int    i, j;

   i = 32763;  // �e na va�em ra�. int zasede 32 bitov, potem napi�ite 2147483643
   j = 0;
   while (j++ < 10) 
      cout << i++ << endl;

   return 0;
}
