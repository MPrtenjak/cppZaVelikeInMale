#include <fstream.h>
#include <stdlib.h>

void Napaka(char *s1, char *s2 = "")
{
   cerr << s1 << ' ' << s2 << '\n';
   exit(2);
}

int main(int ArgC, char *ArgV[])
{
   if (ArgC != 3)
      Napaka("Napaèno število argumentov");

   ifstream Vhod(ArgV[1]); // prva datoteka je vhodna
   if (!Vhod)
      Napaka("Ne morem odpreti vhodne datoteke", ArgV[1]);

   ofstream Izhod(ArgV[2]);   // druga datoteka je izhodna
   if (!Izhod)
      Napaka("Ne morem odpreti izhodne datoteke", ArgV[2]);

   char ch;
   while ( Vhod.get(ch) )
      Izhod.put(ch);

   if (!Vhod.eof() || Izhod.bad())  // èe ni konec vhodne ali je izhodna pokvarjena
      Napaka("Nekaj je šlo narobe");

   cout << "Datoteki sta prepisani " << '\n';

   return 1;
}
