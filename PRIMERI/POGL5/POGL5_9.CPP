#include <iostream.h>
#include <stdarg.h>

int sestej(int dolzina, ...)  // vsaj eden mora biti podan
{
   int sest = 0;
   va_list  parametri;

   va_start(parametri, dolzina); // inicializacija
   for(int i = 0;i < dolzina; i++)
      sest += va_arg(parametri, int);  // naslednji parameter

   va_end(parametri);   // pocistimo za sabo

   return sest;
}

int main()
{
   cout << "seštej 1: " << sestej(1,2) << endl;
   cout << "seštej 2: " << sestej(3,2,2,4) << endl;
   cout << "seštej 3: " << sestej(7,2,2,4,3,6,4,8) << endl;
                                                                   
   return 1;
}
