#include <iostream.h>   // deklaracija za tok

class Nekaj {
protected:
   static int stevilo;

public:
   Nekaj()  // Konstruktor
      { stevilo++; }

   ~Nekaj() // Destruktor
      { stevilo--; }

   void Hello(int line);
};

int Nekaj::stevilo = 0; // inicializacija

void Nekaj::Hello(int line)
{
   if (stevilo > 3) {
      cout << "Ven, ne morem ve�! V vrstici " << line;
      cout << " nas je prevec, " << stevilo << "." << endl;
      return;
      }

   switch (stevilo) {
      case 1 :
         cout << "�mrk, �mrk ... V vrstici " << line << " sem sam!!" << endl;
         break;
      case 2 :
         cout << "Aha, �e nekdo je tukaj, v vrstici " << line << "!!" << endl;
         break;
      case 3 :
         cout << "Uf, v vrstici " << line << " smo �e trije." << endl;
         break;
      }
}

int main()
{
   Nekaj a; // konstruktor za a

   // __LINE__ zamenja preprocesor s teko�o vrstico
   a.Hello(__LINE__);
   {
   Nekaj b; // konstruktor za b
   b.Hello(__LINE__);
      {
      Nekaj c; // konstruktor za c
      c.Hello(__LINE__);
         {
         Nekaj d; // konstruktor za d
         d.Hello(__LINE__);
         }        // destruktor za d
      c.Hello(__LINE__);
      }        // destruktor za c
   b.Hello(__LINE__);
   }        // destruktor za b
   a.Hello(__LINE__);

   return 1;
}     // destruktor za a



