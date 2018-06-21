#include <iostream.h>

void fun(int l, int x = 5, int y = 10)
{
   cout << "Vrstica " << l << ": X = " << x << ", Y = " << y << endl;
}

int main()
{
   fun(__LINE__,1,2);
   fun(__LINE__,1);
   fun(__LINE__);
   
   return 1;
}

