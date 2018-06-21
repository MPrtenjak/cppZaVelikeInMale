#include <iostream.h>

struct biti {
   unsigned b0 : 1;
   unsigned b1 : 1;
   unsigned b2 : 1;
   unsigned b3 : 1;
   unsigned b4 : 1;
   unsigned b5 : 1;
   unsigned b6 : 1;
   unsigned b7 : 1;
};

union znak {
   char z_char;
   biti z_biti;
};

int main()
{
   znak z;
   unsigned int i;

   z.z_char = 'A';
   i = z.z_char;

   cout << "Predstavitev znaka " << z.z_char << " je ";
   cout << z.z_biti.b0 << z.z_biti.b1 << z.z_biti.b2 << z.z_biti.b3;
   cout << z.z_biti.b4 << z.z_biti.b5 << z.z_biti.b6 << z.z_biti.b7;
   cout << " kar predstavlja koda " <<  i << endl;

   return 1;
}
