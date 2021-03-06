/* POZOR:

      V naboru znakov ra�unalnika, v splo�nem �rke ne sledijo �tevilkam.
      Zato je potrebno pri �tevilskih sistemih, ki uporabljajo �rke namesto
      cifer, posebej paziti na primer ko cifer zmanjka.

      �e je potrebno v nekem sistemu zapisati 'cifro' 10 se uporabi �rka a.
      Zato je potrebna �e dodatna kontrola, ki v primeru ve�je cifre da
      �rko!
*/

/*
      �e pogledamo re�itev druge naloge, vidimo, da so funkcije med sabo
      skoraj enake. Spreminja se samo �tevilski sistem.

      Potrebno je torej tak�no funkcijo �e samo dopolniti s parametrom,
      ki pove �tevilski sistem. Za osnovo pa lahko vzamemo funkcijo hex
      (iz naloge 2), ki je najsplo�nej�a.
*/

#include <iostream.h>

void pretvori(unsigned int stevilo, char *s, int sistem)
{
   int j = 0;

   while (stevilo != 0) {
      if ( stevilo % sistem > 9 )
         s[j++] = stevilo % sistem - 10 + 'a';
      else
         s[j++] = stevilo % sistem + '0';
      stevilo /= sistem;
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
   unsigned int   stevilo,
                  sistem;
   char  transform[sizeof(int) * 8 + 1];  // da bo sigurno dovolj prostora

   cout << "Vpi�ite pozitivno �tevilo .................................. ";
   cin >> stevilo;
   cout << "Vpi�ite �tevilski sistem v katerega ga �elite spremeniti ... ";
   cin >> sistem;

   sistem = (sistem > 35) ? 35 : sistem;  // �e je sistem ve�ji od 35 ga postavimo
                                       // na 35
   cout << endl << endl;

   pretvori(stevilo, transform, sistem);
   cout << "V " << sistem << ". sistemu je to ... " << transform << endl;

   return 1;
}
