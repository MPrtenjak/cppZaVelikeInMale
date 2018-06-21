#include <iostream.h>

void main()
{
   int ctemp;

   cout << "Vpišite temperaturo v sistemu po Celsius-u: ";
   cin >> ctemp;

   cout << endl << endl;
   cout << "V Fahrnheitih to znaša : " << (ctemp*(9.0/5.0)+32) << '\n';
}