#include <iostream.h>

struct Cas {
   int ure;
   int minute;
   int sekunde;
};

long sekunde(const Cas *p)
{
   long SkupajSekunde = p->sekunde;

   SkupajSekunde += (60 * (long) p->minute);
   SkupajSekunde += (60 * 60 * (long) p->ure); // da ne pride do prekoraèitve
         // sicer e pri 10 urah preide do prekoraèitve:
         // 60*60*10 = 36000, kar je veè kot 32767, kot lahko vsebuje int

   return SkupajSekunde;
}

int main()
{
   Cas c;

   c.ure = 12; c.minute = 30; c.sekunde = 14;
   cout << "12:30:14 = " << sekunde(&c) << endl;

   c.ure = 6; c.minute = 15; c.sekunde = 7;
   cout << "06:15:7 = " << sekunde(&c) << endl;

   c.ure = 23; c.minute = 14; c.sekunde = 0;
   cout << "23:14:00 = " << sekunde(&c) << endl;

   return 1;
}
