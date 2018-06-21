#include <iostream.h>   // deklaracija za tok

class Nekaj {
protected:
   static int stevilo;

public:
   Nekaj()  // Konstruktor
      { stevilo++; }

   ~Nekaj() // Destruktor
      { stevilo--; }

   static void Koliko() {
     cout << "V programu je trenutno " << stevilo;
     cout << " objektov razreda Nekaj!" << endl;
     }
};

int Nekaj::stevilo = 0; // inicializacija

int main()
{
   // Nimamo še nobenega objekta razreda Nekaj
   Nekaj::Koliko();

   // Ustvarimo objekt
   Nekaj a; // konstruktor za a

   // Sedaj lahko statièno metodo klièem na dva naèina
   a.Koliko(); // iz tipa objekta a ugotovi katero metodo mora poklicati
   Nekaj::Koliko();

   // Ustvarimo še veè objektov
   Nekaj b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;
   Nekaj::Koliko();

   return 1;
}

