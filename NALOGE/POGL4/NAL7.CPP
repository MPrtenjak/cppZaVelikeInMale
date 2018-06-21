#include <iostream.h>

int main()
{
   int otroci,    // število otrok
       stoli;     // število stolov

   cout << "Podajte število otrok ... ";
   cin >> otroci;
   cout << "Podajte število stolov ... ";
   cin >> stoli;

   if (stoli >= otroci) {
      cout << " Stolov je preveè! " << endl;
      return 2;
   }

   long nacini = 1;     // število naèinov
   for(int i = 0; i < stoli; i++)
      nacini *= otroci--;

   cout << "Otroci se na stole lahko posedejo na " << nacini << " naèinov.";
   cout << endl;

   return 1;
}

