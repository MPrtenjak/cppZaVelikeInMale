#include <iostream.h>

#define NA3(x) ( (x) * (x) * (x) )

int na3(int x)
{
   return x*x*x;
}

int main()
{
   int i, j;

   i = 2; j = NA3(i++); // Koliko je i, koliko je j
   i = 2; j = na3(i++); // Koliko je i, koliko je j
   i = 2; j = NA3(++i); // Koliko je i, koliko je j
   i = 2; j = na3(i++); // Koliko je i, koliko je j

   return 1;
}
