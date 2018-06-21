#include <iostream.h>
#include <fstream.h>

int main()
{
   char datoteka[100];

   cout << "Podajte ime vhodne datoteke ... ";
   cin.getline(datoteka, 100);

   ifstream Vhod(datoteka);
   if (!Vhod) {
      cerr << "Ne morem odpreti datoteke!";
      return 2;
   }

   int   i;
   long  sestevek = 0;

   Vhod >> i;
   while (Vhod) {
      sestevek += i;
      Vhod >> i;
      }

   cout << "Seštevek števil v datoteko znaša " << sestevek << ".\n";

   return 1;
}     
