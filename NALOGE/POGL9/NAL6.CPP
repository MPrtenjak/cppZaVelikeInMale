#include <iostream.h>

class Stevilka {
protected:
   static int stObjektov;     // koliko objektov �e obstoja

   int MojaStevilka;          // �tevilka konkretnega objekta
public:
   Stevilka() { MojaStevilka = ++stObjektov; }

   void Izpisi() {
      cout << "Pozdravljeni, jaz sem objekt #" << MojaStevilka << "." << endl;
   }
};

int Stevilka::stObjektov = 0;    // na za�etku ni �e nobenega objekta

int main()
{
   Stevilka a,b,c,d,e,f,g,h,i,j,k,l,m,n;

   a.Izpisi();
   h.Izpisi();
   d.Izpisi();
   i.Izpisi();
   k.Izpisi();
   c.Izpisi();
   j.Izpisi();
   m.Izpisi();
   b.Izpisi();
   f.Izpisi();
   l.Izpisi();
   n.Izpisi();
   e.Izpisi();
   g.Izpisi();

   return 1;
}


