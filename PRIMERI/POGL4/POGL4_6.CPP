#include <iostream.h>

int main()
{
   cout << endl << " PRVA VERZIJA ... " << endl;
   int i = 10; 
   while (i--) 
      cout << i << " * " << i << " = " << i * i << endl;

   cout << endl << " DRUGA VERZIJA ... " << endl;
   i = 10;
   while (--i) 
      cout << i << " * " << i << " = " << i * i << endl;

   return 1;
}
