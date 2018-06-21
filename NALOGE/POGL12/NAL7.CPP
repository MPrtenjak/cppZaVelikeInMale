#include <iostream.h>
#include <fstream.h>

class Tocka {
protected:
   int x, y;      // koordinati

public:

   friend istream& operator>>(istream&, Tocka&);      
   friend ostream& operator<<(ostream&, Tocka&);      

   // ostale metode
};

istream& operator>>(istream& in, Tocka &T)
{  
   // zapis na datoteki mora biti takšenle (X,Y)
   int x, y;   // koordinati
   char c;     // prebrani znaki

   in >> c;
   if (c == '(') {      // ali smo prebrali oklepaj
      in >> x >> c;     // preberemo koordinato X in znak, ki ji sledi
      if (c == ',') {
         in >> y >> c;  
         if (c != ')')  // ni zaklepaja - NAPAKA
            in.clear(ios::badbit);     // v datoteki je napaka
      }
      else  // koordinati X ne sledi vejica
         in.clear(ios::badbit);
   }
   else  // prvi znak ni oklepaj
      in.putback(c);    // vrnemo prebrani znak

   if (in)  {     // èe ni prišlo do napake
      T.x = x;
      T.y = y;
   }

   return in;
}
   
ostream& operator<<(ostream& out, Tocka &T)
{
   out << "(" << T.x << "," << T.y << ")";

   return out;
}

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

   Tocka T;

   cout << "V datoteki so naslednje toèke ... " << endl;
   Vhod >> T;
   while (Vhod) {
      cout << "\t" << T << endl;
      Vhod >> T;
      }

   return 1;
}
