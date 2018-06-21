#include <iostream.h>

int main() {
   cout << "Potrebno število byte-ov za posamezne tipe:" << endl;
   cout <<  "     char        : " << sizeof(char) << endl << endl;

   cout <<  "     short int   : " << sizeof(short int) << endl;
   cout <<  "     int         : " << sizeof(int) << endl;
   cout <<  "     long int    : " << sizeof(long int) << endl << endl;

   cout <<  "     float       : " << sizeof(float) << endl;
   cout <<  "     double      : " << sizeof(double) << endl;
   cout <<  "     long double : " << sizeof(long double) << endl;

   return 1;
}
