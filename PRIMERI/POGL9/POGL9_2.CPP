#include <iostream.h>

class Test {
public:
   void Izpisi()
      { cout << "kazalec this kaže na ... " << this << endl; }
};

int main()
{
   Test T;

   cout << "Objekt T se nahaja na ... " << &T << endl;
   T.Izpisi();

   return(1);
}  

