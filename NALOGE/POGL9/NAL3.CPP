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

   // ostale metode
};

Cas::Cas(long sec)
{
   ure = sec / 3600;    // celoštevilèno deljenje !!!
   if (ure > 23) ure = 23;

   minute = (sec % 3600) / 60;
   sekunde = (sec % 3600) % 60;
}


