#include <iostream.h>
#include <typeinfo.h>

class Baza1
{
   virtual void f(void) { }
};

class Baza2
{
};

class Izpeljani : public Baza1, public Baza2
{
};

int main(void) {
   try {
      Izpeljani d, *pd;
      Baza1 *b1 = &d;

      // izvaja spremembo tipa iz Baza1 v Izpeljani
      if ((pd = dynamic_cast<Izpeljani *>(b1)) != 0) {
           cout << "Kazalec je tipa " << typeid(pd).name() << endl;
         }
      else 
   throw Bad_cast(); // izvrži izjemo o nezmožnosti pretvorbe

      // Poskus pretvorbe okoli hiararhije. To pomeni, pretvorbo iz
      // prve baze v izpelljani razred in nato pretvorbo nazaj v
      // drugo bazo!
      Baza2 *b2;
      if ((b2 = dynamic_cast<Baza2 *>(b1)) != 0) {
          cout << "Kazalec je tipa " << typeid(b2).name() << endl;
         }
      else throw Bad_cast();
      }
   catch (Bad_cast) {
      cout << "Pretvorba ni uspela!" << endl;
      return 2;
      }

   return 1;
}

