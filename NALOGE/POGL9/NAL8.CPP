#include <iostream.h>
#include <stdlib.h>  // za funkcijo exit()

class Ulomek {
protected:
   int   im,      // imenovalec
         st;      // �tevec

   void okrajsaj();              // okraj�a ulomek
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

// NAJPREPROSTEJ�I ALGORITEM
//
// V zanki se 'sprehodimo' do minimuma med imenovalcem in �tevcem,
// ter za vsako �tevilo poskusimo, ali sta oba deljiva...
void Ulomek::okrajsaj()
{
   int   abs_im = (im < 0) ? -im : im, // absolutna vrednost imenovalca
         abs_st = (st < 0) ? -st : st; // absolutna vrednost �tevca

   int min = (abs_im < abs_st) ? abs_im : abs_st;  // minimum

   for (int i = 2; i <= min; i++) {
      if ( st % i == 0 && im % i == 0 ) { // oba sta deljiva s tem �tevilom
         st /= i; im /= i; min /= i;   // vse delimo
         i = 2;                        // spet na za�etek!
      }
   }
}

void Ulomek::Init(int s, int i)
{
   if (i == 0) {
      cerr << "Deljenje z ni� !!" << endl;
      exit(2);
   }

   st = s;
   im = i;

   okrajsaj();
}

Ulomek sestej(Ulomek u1, Ulomek u2)
{
   Ulomek rez;

   if ( u1.st == 0 ) // prvi ulomek je ni�
      { rez = u2; rez.okrajsaj(); return rez; }

   if ( u2.st == 0 ) // drugi ulomek je ni�
      { rez = u1; rez.okrajsaj(); return rez; }

   rez.st = u1.st*u2.im + u1.im*u2.st;
   rez.im = u1.im * u2.im;
   rez.okrajsaj();

   return rez;
}

Ulomek odstej(Ulomek u1, Ulomek u2)
{
   Ulomek rez;

   if ( u1.st == 0 ) // prvi ulomek je ni�
      { rez.st = -u2.st;
        rez.im = u2.im;
        rez.okrajsaj();
        return rez; }

   if ( u2.st == 0 ) // drugi ulomek je ni�
      { rez = u1; rez.okrajsaj(); return rez; }

   rez.st = u1.st*u2.im - u1.im*u2.st;
   rez.im = u1.im * u2.im;
   rez.okrajsaj();

   return rez;
}

Ulomek mnozi(Ulomek u1, Ulomek u2)
{
   Ulomek rez;

   if ( u1.st == 0  || u2.st == 0 ) // �e je kateri 0
        { rez.okrajsaj(); return rez; }

   rez.st = u1.st * u2.st;
   rez.im = u1.im * u2.im;
   rez.okrajsaj();

   return rez;
}

Ulomek deli(Ulomek u1, Ulomek u2)
{
   Ulomek rez;

   if ( u2.st == 0 ) { // drugi ulomek je ni�
      cerr << "Deljenje z ni� !!" << endl;
      exit(2);
   }

   if ( u1.st == 0 ) // prvi ulomek je ni�
      { rez.okrajsaj(); return rez; }

   rez.st = u1.st * u2.im;
   rez.im = u1.im * u2.st;
   rez.okrajsaj();

   return rez;
}

int main()
{
   Ulomek ul[5];
   int    st, im;
   char   del;       // ulomkova �rta

   for (int i = 0; i < 5; i++) {
      cout << "Podajte ulomek #" << i << " (�tevec / imenovalec) ... ";
      cin >> st >> del >> im;
      ul[i].Set(st, im);
   }

   cout << '\t';
   for (i = 0; i < 5; i++) // izpi�e glavo
      cout << ul[i].St() << "/" << ul[i].Im() << "\t";

   cout << endl;
   for (i = 0; i < 5; i++) { // vrstice
      cout << ul[i].St() << "/" << ul[i].Im() << "\t";
      for (int j = 0; j < 5; j++) { // stolpci
         Ulomek temp;
         temp = mnozi(ul[i], ul[j]);
         cout << temp.St() << "/" << temp.Im() << "\t";
      }
      cout << endl;
   }

   return 1;
}

