#include <iostream.h>

class MalaSt {
protected:
   int stevilo;

   void postavi(int i) {
      if (i & ~31)   // samo števila od 0 .. 31
         { cout << "\tPreveliko število !!"  << endl; i = 0; }
      stevilo = i;
   }

public:
   MalaSt(int i = 0) {
      cout << "\tPretvarjam int => MalaSt! " << endl;
      postavi(i);
   }

   operator int() {
      cout << "\tPretvarjam MalaSt => int! " << endl;
      return stevilo;
   }
};

int main()
{
   MalaSt a(5), b(10), c;
   int    i, j;

   cout << "i = 5*a+b;" << endl;
   i = 5*a+b;
   cout << "j = 200/a*b-10+5;" << endl;
   j = 200/a*b-10+5;
   cout << "c = 5*a+b;" << endl;
   c = 5*a+b;
   cout << "c = 200/a*b-10+5;" << endl;
   c = 200/a*b-10+5;

   return 1;
}

