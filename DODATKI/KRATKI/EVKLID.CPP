/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Evklidov algoritem, za iskanje najveèjega skupnega deljitelja

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>

int main()
{
   unsigned int   stevilo1, stevilo2;  // dve naravni števili

   cout << "Program išèe najveèje skupne deljitelje." << endl;

   for(;;) {   // neskonèna zanka
      cout << "Podajte prvo  NARAVNO ŠTEVILO [0 = konec] ... ";
      cin >> stevilo1;
      if (stevilo1 == 0) break;

      cout << "Podajte drugo NARAVNO ŠTEVILO [0 = konec] ... ";
      cin >> stevilo2;
      if (stevilo2 == 0) break;

      // algoritem zahteva, da je prvo število veèje
      if (stevilo1 < stevilo2)  {
         unsigned int temp = stevilo1;    // zamenjaj števili
         stevilo1 = stevilo2;
         stevilo2 = temp;
      }

      unsigned int ostanek = stevilo1 % stevilo2;  // to evklidov algoritem
      while (ostanek != 0) {
         stevilo1 = stevilo2;
         stevilo2 = ostanek;
         ostanek = stevilo1 % stevilo2;
      }  

      cout << "\tNajveèji skupni deljitelj je " << stevilo2 << endl;
      }  // konec for

   return 0;
}
