#include <iostream.h>

void main()
{
   int st;

   cout << "Vpi�ite �tevilo ... ";
   cin >> st;

   if (st % 2 == 0)
      if (st % 4 == 0)
         cout << "�tevilo je deljivo z 2,4.";
   else
      cout << "�tevilo ni deljivo z 2.";

   return 1;
}
