#include <iostream.h>

class sklad {
   int* vrh;   // kazalec na vrh sklada
   int* dno;   // kazalec na dno sklada

public:
   sklad(int v)
      { vrh = dno = new int[v];  }
   ~sklad()
      { delete [] vrh; }

   void push(int a)
      { *dno++ = a; }
   int pop()
      { return *--dno; }
};

int main()
{
   sklad s(5); // sklad velikosti 5 števil

   cout << "VNOS ... " << endl;
   for(int i = 0; i < 5; i++) {
      cout << "\tNa sklad zapisujem število "  << i << endl;
      s.push(i);
      }

   cout << endl << "IZPIS ..." << endl;
   for(i = 0; i < 5; i++)
      cout << "\tS sklada sem pobral število"  << s.pop() << endl;

   return(1);
}

