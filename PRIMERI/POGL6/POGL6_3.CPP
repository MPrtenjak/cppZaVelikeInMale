#include <iostream.h>

#define KVADRAT(X)   (X)*(X)

int main()
{
   for (int j = 0; j < 5; j++) {
      int i;
      cout << "Vpi�ite �tevilo ...";  cin >> i;
      cout << "Kvadrat �tevila " << i << " je " << KVADRAT(i) << ".";
      cout << endl << endl;
      }

   return 1;
}
