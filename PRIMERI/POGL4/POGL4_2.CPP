#include <iostream.h>

int main()
{
   int st;

   cout << "Vpišite število ... ";
   cin >> st;

   if (st % 2 == 0)
      if (st % 4 == 0)
         if (st % 6 == 0)
            cout << "Število je deljivo z 2,4 in 6.";
         else
            cout << "Število je deljivo z 2 in 4.";
      else
         cout << "Število je sodo.";
   else
      if (st % 3 == 0)
         if (st % 5 == 0)
            cout << "Število je deljivo s 3 in 5.";
         else
            cout << "Število je deljivo s 3.";
      else
         cout << "Število je liho.";

   return 1;
}
