#include <iostream.h>

const double dem = 81.3;
const double ats = 11.6;

int main()
{
   double sit;

   cout << "Vpi�ite koliko denarja imaste (v SIT) ... ";
   cin >> sit;

   cout << endl;
   cout << "V nem�kih markah to znese ......... " << sit/dem
       << "DEM." << endl;
   cout << "V avstrijskih �ilingih to znese ... " << sit/ats
       << "ATS." << endl;

   return 1;
}
