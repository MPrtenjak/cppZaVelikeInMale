#include <iostream.h>

int main()
{
   int st;

   cout << "Vpi�ite �tevilo ... ";
   cin >> st;

   if (st % 2 == 0)
      if (st % 4 == 0)
         if (st % 6 == 0)
            cout << "�tevilo je deljivo z 2,4 in 6.";
         else
            cout << "�tevilo je deljivo z 2 in 4.";
      else
         cout << "�tevilo je sodo.";
   else
      if (st % 3 == 0)
         if (st % 5 == 0)
            cout << "�tevilo je deljivo s 3 in 5.";
         else
            cout << "�tevilo je deljivo s 3.";
      else
         cout << "�tevilo je liho.";

   return 1;
}
