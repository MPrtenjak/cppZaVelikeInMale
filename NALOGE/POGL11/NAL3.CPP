#include <iostream.h>

class Cas {
protected:
   int ure,
       minute,
       sekunde;

public:
   Cas() { ure = minute = sekunde = 0; }
   Cas(int u, int m, int s) {
      ure = (u > 23) ? 23 : u;   // ura ne more biti veè kot 23
      minute = (m > 59) ? 59 : m;   // ura ne more biti veè kot 59
      sekunde = (s > 59) ? 59 : s;  // ura ne more biti veè kot 59
   }
   Cas(long sec);

   int Ure() { return ure; }
   int Minute() { return ure; }
   int Sekunde() { return ure; }

   friend Cas operator+(Cas&, Cas&);   // sekunde se avtomatsko pretvorijo v Cas
   friend Cas operator-(Cas&, Cas&);   // sekunde se avtomatsko pretvorijo v Cas

   friend ostream& operator<<(ostream &out, Cas &c);
   friend istream& operator>>(istream &in, Cas &c);

   // ostale metode
};


Cas::Cas(long sec)
{
   ure = sec / 3600;    // celoštevilèno deljenje !!!
   if (ure > 23) ure = 23;

   minute = (sec % 3600) / 60;
   sekunde = (sec % 3600) % 60;
}

Cas operator+(Cas &c1, Cas &c2)
{
   Cas temp;
   int sum;

// sekunde
   sum = c1.sekunde + c2.sekunde;   // seštejemo sekunde
   temp.sekunde = sum % 60;            // rezultat je ostanek, pri deljenju s 60

// minute
// minutam moramo dodati mono prekoraèitev
   sum = c1.minute + c2.minute + sum/60;
   temp.minute = sum % 60;

// ure
   sum = c1.ure + c2.ure + sum/60;
   temp.ure = sum % 24;

   return temp;
}

Cas operator-(Cas &c1, Cas &c2)
{
   Cas temp;
   int sub;

// sekunde
   sub = c1.sekunde - c2.sekunde;

   if (sub < 0) {
      temp.sekunde = 60 + sub;
      sub = c1.minute - c2.minute - 1;
   }
   else {
      temp.sekunde = sub;
      sub = c1.minute - c2.minute;
   }

// minute
   if (sub < 0) {
      temp.minute = 60 + sub;
      sub = c1.ure - c2.ure - 1;
   }
   else {
      temp.minute = sub;
      sub = c1.ure - c2.ure;
   }

// ure
   if (sub < 0)
      temp.ure = 24 + sub;
   else
      temp.ure = sub;

   return temp;
}


ostream& operator<<(ostream &out, Cas &c)
{
   return out << c.ure << ":" << c.minute << ":" << c.sekunde;
}

istream& operator>>(istream &in, Cas &c)
{
   char dvopicje;

   in >> c.ure;
   in >> dvopicje;   // prebere ":"
   in >> c.minute;
   in >> dvopicje;   // prebere ":"
   in >> c.sekunde;

   return in;
}

int main()
{
   Cas  c1, c2;
   char konec;

   do {
      cout << "Vpišite prvi  èas [uu:mm:ss] ... ";
      cin >> c1;
      cout << "Vpišite drugi èas [uu:mm:ss] ... ";
      cin >> c2;

      cout << endl;
      cout << c1 << " + " << c2 << " = " << (c1 + c2) << endl;
      cout << c2 << " + " << c1 << " = " << (c2 + c1) << endl;
      cout << c1 << " - " << c2 << " = " << (c1 - c2) << endl;
      cout << c2 << " - " << c1 << " = " << (c2 - c1) << endl;

      cout << "Konec [D/N]? ";
      cin >> konec;
      if ( konec == 'd' || konec == 'D' )
         break;
   } while (1);

   return 1;
}


