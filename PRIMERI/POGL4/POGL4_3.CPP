#include <iostream.h>

void main()
{
   int st;

   cout << "Vpišite število ... ";
   cin >> st;

   if (st % 2 == 0)
      if (st % 4 == 0)
         cout << "Število je deljivo z 2,4.";
   else
      cout << "Število ni deljivo z 2.";

   return 1;
}
