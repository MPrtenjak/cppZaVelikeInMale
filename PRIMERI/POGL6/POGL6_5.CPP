#include <iostream.h>

#define S1(x,y)   x+y
#define S2(x,y)   (x+y)

#define M2(x,y)   (x*y)
#define M3(x,y)   ((x)*(y))

int main()
{
   cout << S1(1,2) * S1(3,4) << " " << S1(1*2, 3*4) << endl;
   cout << S2(1,2) * S2(3,4) << " " << S2(1*2, 3*4) << endl << endl;

   cout << M2(1,2) + M2(3,4) << " " << M2(1+2, 3+4) << endl;
   cout << M3(1,2) + M3(3,4) << " " << M3(1+2, 3+4) << endl << endl;
   
   return 1;
}
