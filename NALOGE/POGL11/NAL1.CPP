#include <iostream.h>

class MalaSt {
protected:
   int stevilo;
   int interval;

   void postavi(int i) {
      if (i < 0 || i > interval )   // samo števila od 0 .. interval
         { cout << "\tPreveliko število !!"  << endl; i = 0; }
      stevilo = i;
   }

public:
   MalaSt(int i = 0, int interv = 31)  {
      interval = ( interv > 0 ) ? interv : -interv;   // samo pozitiven interval
      // cout << "\tPretvarjam int => MalaSt! " << endl;
      postavi(i);
   }

   operator int() {
      // cout << "\tPretvarjam MalaSt => int! " << endl;
      return stevilo;
   }
};

int main()
{
   MalaSt   a(5), b(10), c(40),
            d(5, 5), e(10 , 5), f(40, 5),
            g(5, 40), h(10 , 40), i(40, 40),
            j;

   cout << "a " << a << endl;
   cout << "b " << b << endl;
   cout << "c " << c << endl;
   cout << "d " << d << endl;
   cout << "e " << e << endl;
   cout << "f " << f << endl;
   cout << "g " << g << endl;
   cout << "h " << h << endl;
   cout << "i " << i << endl;
   cout << "j " << j << endl;

   return 1;
}

