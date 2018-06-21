#include <iostream.h>

int main()
{
   char string[21];

   cout << "Vpišite niz znakov (najveè 20) ... ";
   cin >> string;

   int i = 0;
   while (string[i] != '\0') {
      cout << i << " : " << string[i] << " ima kodo " << int(string[i]) << endl;
      i = i + 1;
      }
   cout << i << " : " << string[i] << " ima kodo " << int(string[i]) << endl;

   cout << "Za niz " << string << " sem porabil " <<  i + 1 << " naslovov.";

   return 1;
}
