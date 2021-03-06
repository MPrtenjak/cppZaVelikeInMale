/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matja� Prtenjak

   NAMEN:
      Evklidov algoritem, za iskanje najve�jega skupnega deljitelja

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>

int main()
{
   unsigned int   stevilo1, stevilo2;  // dve naravni �tevili

   cout << "Program i��e najve�je skupne deljitelje." << endl;

   for(;;) {   // neskon�na zanka
      cout << "Podajte prvo  NARAVNO �TEVILO [0 = konec] ... ";
      cin >> stevilo1;
      if (stevilo1 == 0) break;

      cout << "Podajte drugo NARAVNO �TEVILO [0 = konec] ... ";
      cin >> stevilo2;
      if (stevilo2 == 0) break;

      // algoritem zahteva, da je prvo �tevilo ve�je
      if (stevilo1 < stevilo2)  {
         unsigned int temp = stevilo1;    // zamenjaj �tevili
         stevilo1 = stevilo2;
         stevilo2 = temp;
      }

      unsigned int ostanek = stevilo1 % stevilo2;  // to evklidov algoritem
      while (ostanek != 0) {
         stevilo1 = stevilo2;
         stevilo2 = ostanek;
         ostanek = stevilo1 % stevilo2;
      }  

      cout << "\tNajve�ji skupni deljitelj je " << stevilo2 << endl;
      }  // konec for

   return 0;
}
