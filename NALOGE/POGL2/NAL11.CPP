#include <iostream.h>

int main()
{
   double sit, dem, ats;

   cout << "Vpi�ite, koliko SIT je vredna nem�ka marka ........ ";
   cin >> dem;

   cout << "Vpi�ite, koliko SIT je vreden avstrijski �iling ... ";
   cin >> ats;

   cout << endl << endl;
   
   cout << "Vpi�ite koliko denarja imaste (v SIT) ... ";
   cin >> sit;

   cout << endl;
   cout << "V nem�kih markah to znese ......... " << sit/dem
       << "DEM." << endl;
   cout << "V avstrijskih �ilingih to znese ... " << sit/ats
       << "ATS." << endl;

   return 1;
}
