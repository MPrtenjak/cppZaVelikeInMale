#include <iostream.h>

class Int {
public:
   int vrednost;

   Int() { vrednost = 0; }
};

Int sestej(Int a, Int b)
{
   Int c;

   c.vrednost = a.vrednost + b.vrednost;

   return c;
}

int sestej(int a, Int b)
{
   return a + b.vrednost;
}

