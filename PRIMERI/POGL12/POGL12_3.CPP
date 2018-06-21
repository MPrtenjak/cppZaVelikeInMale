#include <iostream.h>
#include <math.h>       // definiran M_PI

int main()
{
   int num = 12;
   double pi100 = M_PI * 100;    // število pi * 100

   for (int i = 0; i < 10; i++) {
      cout << "(";
      cout.width(i);
      cout << num << ")" << endl;
      }

   for (i = 0; i < 10; i++) {
      cout << "(";
      cout.width(i);
      cout.fill('#');
      cout <<  num << ")" << endl;
      }

   for (i = 0; i < 10; i++) {
      cout.precision(i);
      cout << pi100 << endl;
      }

   return 1;
}