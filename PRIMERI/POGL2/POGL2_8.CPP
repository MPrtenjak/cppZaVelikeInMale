#include <iostream.h>

int main()
{
   char ime[15];

   cout << "Vpišite svoje ime ... ";
   cin >> ime;
   cout << "Pozdravljeni gospod (gospa) " << ime << "." << endl << endl;

   int   i = 0;
   double   meseci[12], LetnoPovprecje = 0;
   while (i < 12) {
      cout << "Vpišite povp. meseèno temp. za mesec " << (i + 1) << " ...";
      // izpišemo (i+1), da se meseci zaènejo izpisovati z 1 in ne z 0
      cin >> meseci[i];
      LetnoPovprecje = LetnoPovprecje + meseci[i];
      i = i + 1;
      }

   cout << endl << "Povpreène temperature : " << endl;
   i = 0;
   while (i < 12) {
      cout << (i + 1) << " : " << meseci[i] << endl;
      i = i + 1;
      }

   cout << endl << "Povpreèna letna temperature je bila : ";
   cout << LetnoPovprecje / 12 << endl;

   return 1;
}
