#include <iostream.h>

void dec_to_bin(unsigned int i, char *s)
{
   int j = 0;

   while (i != 0) { // to je enakovredno z while (i) !!!
      s[j++] = i % 2 + '0'; // ostanek pri deljenju z 2, hkrati pove�amo j
      i /= 2;  // i delimo z 2
      }
   s[j] = '\0'; // Niz znakov moramo vedno kon�ati z '\0' !!!!
   
   // tu imamo bitno predstavitev, ki pa je obrnjena narobe
   // njena dol�ina je j - 1 (ker se je j pove�al pred izstopom iz zanke)

   char temp;  // zamenjevali bomo 1 in zadnji element, 2 in predzadnji ..
   int k = 0;  // za�etek niza je indeks 0
   j--;     // j sedaj ka�e na zadnji element
   while (j > k) {   // dokler je zgorni indeks ve�ji od spodnjega
      temp = s[k];   
      s[k++] = s[j]; // ob koncu k pove�amo
      s[j--] = temp; // ob koncu j zmanj�amo
      } 
   // niz je sestavljen
}

int main()
{
   int  stevilo;
   char biti[sizeof(int)*8 + 1]; // 16 ali 32 bit-ov + '\0'!!

   cout << "Vpi�ite �tevilo ... ";
   cin >> stevilo;

   dec_to_bin(stevilo, biti);
   cout << "Binarna predstavitev �tevila " << stevilo << " je " << biti << endl;

   return 1;
}
