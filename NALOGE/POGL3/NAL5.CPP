#include <iostream.h>

int main()
{
   int   funti,
         silingi,
         peniji;
   double novSistem;

   cout << "�tevilo funtov   : ";
   cin >> funti;
   cout << "�tevilo �ilingov : ";
   cin >> silingi;
   cout << "�tevilo penijev  : ";
   cin >> peniji;

   novSistem = funti + double(silingi) / 20 + double(peniji) / (12*20);
   cout << "V novi obliki je to �" << novSistem;

   return 1;
}

