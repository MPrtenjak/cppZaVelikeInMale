#include <iostream.h>
#include <stdlib.h>  // za funkcijo exit()

class Ulomek {
protected:
   int   im,      // imenovalec
         st;      // števec

   void okrajsaj();              // okrajša ulomek
   void Init(int s, int i);      // inicializira ulomek

public:
   Ulomek(int s = 0, int i = 1)
      { Init(s, i); }

   int St() { return st; }
   int Im() { return im; }
   void Set(int s = 0, int i = 1)
      { Init(s, i); }

   void Izpisi()
      { cout << st << "/" << im << endl; }


   friend Ulomek sestej(Ulomek u1, Ulomek u2);
   friend Ulomek odstej(Ulomek u1, Ulomek u2);
   friend Ulomek deli(Ulomek u1, Ulomek u2);
   friend Ulomek mnozi(Ulomek u1, Ulomek u2);
};

// NAJPREPROSTEJŠI ALGORITEM
//
// V zanki se 'sprehodimo' do minimuma med imenovalcem in števcem,
// ter za vsako število poskusimo, ali sta oba deljiva...
void Ulomek::okrajsaj()
{
   int   abs_im = (im < 0) ? -im : im, // absolutna vrednost imenovalca
         abs_st = (st < 0) ? -st : st; // absolutna vrednost števca

   int min = (abs_im < abs_st) ? abs_im : abs_st;  // minimum

   for (int i = 2; i <= min; i++) {
      if ( st % i == 0 && im % i == 0 ) { // oba sta deljiva s tem številom
         st /= i; im /= i; min /= i;   // vse delimo
         i = 2;                        // spet na zaèetek!
      }
   }
}

void Ulomek::Init(int s, int i)
{
   if (i == 0) {
      cerr << "Deljenje z niè !!" << endl;
      exit(2);
   }

   st = s;
   im = i;

   okrajsaj();
}

Ulomek sestej(Ulomek u1, Ulomek u2)
{
   Ulomek rez;

   if ( u1.st == 0 ) // prvi ulomek je niè
      { rez = u2; rez.okrajsaj(); return rez; }

   if ( u2.st == 0 ) // drugi ulomek je niè
      { rez = u1; rez.okrajsaj(); return rez; }

   rez.st = u1.st*u2.im + u1.im*u2.st;
   rez.im = u1.im * u2.im;
   rez.okrajsaj();

   return rez;
}

Ulomek odstej(Ulomek u1, Ulomek u2)
{
   Ulomek rez;

   if ( u1.st == 0 ) // prvi ulomek je niè
      { rez.st = -u2.st;
        rez.im = u2.im;
        rez.okrajsaj();
        return rez; }

   if ( u2.st == 0 ) // drugi ulomek je niè
      { rez = u1; rez.okrajsaj(); return rez; }

   rez.st = u1.st*u2.im - u1.im*u2.st;
   rez.im = u1.im * u2.im;
   rez.okrajsaj();

   return rez;
}

Ulomek mnozi(Ulomek u1, Ulomek u2)
{
   Ulomek rez;

   if ( u1.st == 0  || u2.st == 0 ) // èe je kateri 0
        { rez.okrajsaj(); return rez; }

   rez.st = u1.st * u2.st;
   rez.im = u1.im * u2.im;
   rez.okrajsaj();

   return rez;
}

Ulomek deli(Ulomek u1, Ulomek u2)
{
   Ulomek rez;

   if ( u2.st == 0 ) { // drugi ulomek je niè
      cerr << "Deljenje z niè !!" << endl;
      exit(2);
   }

   if ( u1.st == 0 ) // prvi ulomek je niè
      { rez.okrajsaj(); return rez; }

   rez.st = u1.st * u2.im;
   rez.im = u1.im * u2.st;
   rez.okrajsaj();

   return rez;
}

int main()
{
   Ulomek a(65,76), b(3,4), c;

   c = sestej(a,b);  c.Izpisi();
   c = sestej(b,a);  c.Izpisi();
   c = odstej(a,b);  c.Izpisi();
   c = odstej(b,a);  c.Izpisi();
   c = mnozi(a,b);  c.Izpisi();
   c = mnozi(b,a);  c.Izpisi();
   c = deli(a,b);  c.Izpisi();
   c = deli(b,a);  c.Izpisi();

   return 1;
}

