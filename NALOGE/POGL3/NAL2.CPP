/* POZOR:

      V naboru znakov raèunalnika, v splošnem èrke ne sledijo številkam.
      Zato je potrebno pri številskih sistemih, ki uporabljajo èrke namesto
      cifer, posebej paziti na primer ko cifer zmanjka.

      Èe je potrebno v nekem sistemu zapisati 'cifro' 10 se uporabi èrka a.
      Zato je potrebna še dodatna kontrola, ki v primeru veèje cifre da
      èrko!
*/

#include <iostream.h>

void bin(unsigned int i, char *s)
{
   int j = 0;

   while (i != 0) { // to je enakovredno z while (i) !!!
      s[j++] = i % 2 + '0'; // ostanek pri deljenju z 2, hkrati poveèamo j
      i /= 2;  // i delimo z 2
      }
   s[j] = '\0'; // Niz znakov moramo vedno konèati z '\0' !!!!

   // tu imamo bitno predstavitev, ki pa je obrnjena narobe
   // njena dolžina je j - 1 (ker se je j poveèal pred iztopom iz zanke)

   char temp;  // zamenjevali bomo 1 in zadnji element, 2 in predzadnji ..
   int k = 0;  // zaèetek niza je indeks 0
   j--;     // j sedaj kaže na zadnji element
   while (j > k) {   // dokler je zgorni indeks veèji od spodnjega
      temp = s[k];
      s[k++] = s[j]; // ob koncu k poveèamo
      s[j--] = temp; // ob koncu j zmanjšamo
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

   cout << "Vpišite pozitivno število ... ";
   cin >> stevilo;

   cout << endl << endl;

   bin(stevilo, transform);
   cout << "V dvojiškem sistemu je to ... " << transform << endl;

   oct(stevilo, transform);
   cout << "V osmiškem sistemu je to ... " << transform << endl;

   hex(stevilo, transform);
   cout << "V šestnajstiškem sistemu je to ... " << transform << endl;

   return 1;
}
