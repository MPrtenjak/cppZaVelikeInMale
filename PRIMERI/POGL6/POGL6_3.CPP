#include <iostream.h>

#define KVADRAT(X)   (X)*(X)

int main()
{
   for (int j = 0; j < 5; j++) {
      int i;
      cout << "Vpišite število ...";  cin >> i;
      cout << "Kvadrat števila " << i << " je " << KVADRAT(i) << ".";
      cout << endl << endl;
      }

   return 1;
}
