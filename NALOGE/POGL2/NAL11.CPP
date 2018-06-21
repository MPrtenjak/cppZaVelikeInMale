#include <iostream.h>

int main()
{
   double sit, dem, ats;

   cout << "Vpišite, koliko SIT je vredna nemška marka ........ ";
   cin >> dem;

   cout << "Vpišite, koliko SIT je vreden avstrijski šiling ... ";
   cin >> ats;

   cout << endl << endl;
   
   cout << "Vpišite koliko denarja imaste (v SIT) ... ";
   cin >> sit;

   cout << endl;
   cout << "V nemških markah to znese ......... " << sit/dem
       << "DEM." << endl;
   cout << "V avstrijskih šilingih to znese ... " << sit/ats
       << "ATS." << endl;

   return 1;
}
