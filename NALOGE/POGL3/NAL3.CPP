/* POZOR:

      V naboru znakov raèunalnika, v splošnem èrke ne sledijo številkam.
      Zato je potrebno pri številskih sistemih, ki uporabljajo èrke namesto
      cifer, posebej paziti na primer ko cifer zmanjka.

      Èe je potrebno v nekem sistemu zapisati 'cifro' 10 se uporabi èrka a.
      Zato je potrebna še dodatna kontrola, ki v primeru veèje cifre da
      èrko!
*/

/*
      Èe pogledamo rešitev druge naloge, vidimo, da so funkcije med sabo
      skoraj enake. Spreminja se samo številski sistem.

      Potrebno je torej takšno funkcijo še samo dopolniti s parametrom,
      ki pove številski sistem. Za osnovo pa lahko vzamemo funkcijo hex
      (iz naloge 2), ki je najsplošnejša.
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

   cout << "Vpišite pozitivno število .................................. ";
   cin >> stevilo;
   cout << "Vpišite številski sistem v katerega ga želite spremeniti ... ";
   cin >> sistem;

   sistem = (sistem > 35) ? 35 : sistem;  // èe je sistem veèji od 35 ga postavimo
                                       // na 35
   cout << endl << endl;

   pretvori(stevilo, transform, sistem);
   cout << "V " << sistem << ". sistemu je to ... " << transform << endl;

   return 1;
}
