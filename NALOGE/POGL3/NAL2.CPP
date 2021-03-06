/* POZOR:

      V naboru znakov ra�unalnika, v splo�nem �rke ne sledijo �tevilkam.
      Zato je potrebno pri �tevilskih sistemih, ki uporabljajo �rke namesto
      cifer, posebej paziti na primer ko cifer zmanjka.

      �e je potrebno v nekem sistemu zapisati 'cifro' 10 se uporabi �rka a.
      Zato je potrebna �e dodatna kontrola, ki v primeru ve�je cifre da
      �rko!
*/

#include <iostream.h>

void bin(unsigned int i, char *s)
{
   int j = 0;

   while (i != 0) { // to je enakovredno z while (i) !!!
      s[j++] = i % 2 + '0'; // ostanek pri deljenju z 2, hkrati pove�amo j
      i /= 2;  // i delimo z 2
      }
   s[j] = '\0'; // Niz znakov moramo vedno kon�ati z '\0' !!!!

   // tu imamo bitno predstavitev, ki pa je obrnjena narobe
   // njena dol�ina je j - 1 (ker se je j pove�al pred iztopom iz zanke)

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

void oct(unsigned int i, char *s)
{
   int j = 0;

   while (i != 0) {
      s[j++] = i % 8 + '0';
      i /= 8;
      }
   s[j] = '\0';

   char temp;
   int k = 0;
   j--;
   while (j > k) {
      temp = s[k];
      s[k++] = s[j];
      s[j--] = temp;
      }
}
void hex(unsigned int i, char *s)
{
   int j = 0;

   while (i != 0) {
      if ( i % 16 > 9 )
         s[j++] = i % 16 - 10 + 'a';
      else
         s[j++] = i % 16 + '0';
      i /= 16;
      }
   s[j] = '\0';

   char temp;
   int k = 0;
   j--;
   while (j > k) {
      temp = s[k];
      s[k++] = s[j];
      s[j--] = temp;
      }
}

int main()
{
   unsigned int   stevilo;
   char  transform[sizeof(int) * 8 + 1];  // da bo sigurno dovolj prostora

   cout << "Vpi�ite pozitivno �tevilo ... ";
   cin >> stevilo;

   cout << endl << endl;

   bin(stevilo, transform);
   cout << "V dvoji�kem sistemu je to ... " << transform << endl;

   oct(stevilo, transform);
   cout << "V osmi�kem sistemu je to ... " << transform << endl;

   hex(stevilo, transform);
   cout << "V �estnajsti�kem sistemu je to ... " << transform << endl;

   return 1;
}
