#include <iostream.h>

int main()
{
   char ime[15];

   cout << "Vpi�ite svoje ime ... ";
   cin >> ime;
   cout << "Pozdravljeni gospod (gospa) " << ime << "." << endl << endl;

   int   i = 0;
   double   meseci[12], LetnoPovprecje = 0;
   while (i < 12) {
      cout << "Vpi�ite povp. mese�no temp. za mesec " << (i + 1) << " ...";
      // izpi�emo (i+1), da se meseci za�nejo izpisovati z 1 in ne z 0
      cin >> meseci[i];
      LetnoPovprecje = LetnoPovprecje + meseci[i];
      i = i + 1;
      }

   cout << endl << "Povpre�ne temperature : " << endl;
   i = 0;
   while (i < 12) {
      cout << (i + 1) << " : " << meseci[i] << endl;
      i = i + 1;
      }

   cout << endl << "Povpre�na letna temperature je bila : ";
   cout << LetnoPovprecje / 12 << endl;

   return 1;
}
