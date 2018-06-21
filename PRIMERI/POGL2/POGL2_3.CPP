#include <iostream.h>

int main()
{
   int i1 = 11, i2 = 22, temp;

   cout << "PRED ZAMENJAVO i1 == " << i1 << ", i2 == " << i2 << endl;
   
   temp = i1;
   i1 = i2;
   i2 = temp;
   
   cout << "PO   ZAMENJAVI i1 == " << i1 << ", i2 == " << i2 << endl;

   return 1;
}
