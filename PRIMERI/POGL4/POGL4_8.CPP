#include <iostream.h>
#include <math.h>

int main()
{
   int konec;
   char c;

   for (float i = 0; i < 10.0; i += 0.1) {
      cout << "kvadratni koren " << i << " = " << sqrt(i) << endl;
      cin.get(c); // prebere naslednji znak iz vhoda
      if (c == 'q')
         break;
      }

   return 1;
}
