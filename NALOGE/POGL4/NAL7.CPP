#include <iostream.h>

int main()
{
   int otroci,    // �tevilo otrok
       stoli;     // �tevilo stolov

   cout << "Podajte �tevilo otrok ... ";
   cin >> otroci;
   cout << "Podajte �tevilo stolov ... ";
   cin >> stoli;

   if (stoli >= otroci) {
      cout << " Stolov je preve�! " << endl;
      return 2;
   }

   long nacini = 1;     // �tevilo na�inov
   for(int i = 0; i < stoli; i++)
      nacini *= otroci--;

   cout << "Otroci se na stole lahko posedejo na " << nacini << " na�inov.";
   cout << endl;

   return 1;
}

