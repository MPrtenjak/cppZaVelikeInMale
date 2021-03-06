#include <iostream.h>

enum  Kje { zacetek, konec };    // kje se za�ne operacija, na za�etku ali koncu

int strlen(const char *niz)
{
   const char *n = niz;

   while( *n ) n++;

   return n - niz;
}

class Niz {
protected:
   char  *polje;        // polje znakov
   int   dolzina;    // dol�ina niza

   void Dodaj(char *n, Kje tip);

public:
   Niz() { polje = NULL; dolzina = 0; }
   Niz(char *n) { polje = NULL; prepisi(n); }
   Niz(char ch, int dol)         // napolni polje z znakom ch
      { polje = NULL; postavi(ch, dol); }
   Niz(const Niz &n) { polje = NULL; prepisi(n.polje); }

   ~Niz() { delete polje; }

   Niz& operator=(const Niz &n);
   operator char*() { return polje; }
   operator int() { return dolzina; }

   void postavi(char ch, int dol);  // napolni polje z znakom ch

   int primerjaj(const char *n);    // -1 �e je polje manj�i

   void prepisi(const char *n);     // prepi�e polje

   void dodaj_niz(char *n, Kje k = konec) // doda polje
      { Dodaj(n, k); }

   const char *Isci(char ch, Kje k = zacetek);  // i��e prvo pojavitev �rke

   void velike_crke();  // spremeni vse �rke v velike
   void male_crke();    // spremeni vse �rke v male
};

void Niz::Dodaj(char *n, Kje tip)
{
   int dolzina_n = strlen(n);
   char *tmp = new char[ dolzina + dolzina_n + 1];

   char  *kc1, *kc2, *ktmp = tmp;      // kazalec na temp

   if (tip == zacetek)  // doda na za�etek
   {
      kc1 = polje;      // najprej polje
      kc2 = n;       // nato n
   }
   else
   {
      kc1 = n;       // najprej n
      kc2 = polje;      // nato polje
   }

   while ( *kc1 ) {  // dokler ni konec prvega
      *ktmp = *kc1;  // prepi�i prvega v tmp
      kc1++; ktmp++; // oba pove�aj
   }

   while ( *kc2 ) {  // dokler ni konec drugega
      *ktmp = *kc2;  // prepi�i drugega v tmp
      kc2++; ktmp++; // oba pove�aj
   }

   *(ktmp) = '\0';     // na konec '\0' !!!!!

   delete polje;                       // starega zbri�emo
   polje = tmp;                        // ka�e na novega
   dolzina = dolzina + dolzina_n;      // nova dol�ina
}

Niz& Niz::operator=(const Niz &n)
{
   if (this != &n)
      prepisi(n.polje);
   return *this;
}

void Niz::postavi(char ch, int dol)
{
   delete polje;

   dolzina = dol;
   polje = new char[ dolzina + 1 ];

   for (int i = 0; i < dolzina; i++)
      polje[i] = ch;
   polje[dolzina] = '\0';
}

int Niz::primerjaj(const char *n)
{
   char        *kc1 = polje;
   const char  *kc2 = n;

   while ( *kc1 && *kc2 ) {
      if ( *kc1 > *kc2)    // �e je polje ve�ji vrni 1
         return 1;
      if ( *kc1 < *kc2 )   // �e je n ve�ji vrni -1
         return -1;
      kc1++; kc2++;        // sicer samo oba pove�aj
   }
   // na tem mestu je enega (ali obeh nizov) konec

   if ( *kc1 )    // �e �e ni konec prvega niza
      return 1;

   if ( *kc2 )    // �e �e ni konec drugega niza
      return -1;

   return 0;      // niza sta enaka
}

void Niz::prepisi(const char *n)
{
   delete polje;

   polje = new char[ strlen(n) + 1 ];

   char  *kc1 = polje;        // kazalec na polje
   const char  *kc2 = n;   // kazalec na n

   while ( *kc2 ) {  // dokler ni konec n
      *kc1 = *kc2;   // prepi�i iz n v polje
      kc1++; kc2++;  // oba pove�aj
   }

   *(kc1) = '\0';   // na konec '\0' !!!!!

   dolzina = kc2 - n;
}

const char *Niz::Isci(char ch, Kje k)
{
   const char *kz;      // kazalec
   int  i = 0;

   if (k == zacetek) // i��i na za�etku
   {
      kz = polje;
      while ( *kz != ch && i < dolzina )
         { kz++; i++; }

      if ( *kz == ch )
         return kz;
      else
         return NULL;
   }
   else
   {
      kz = polje + dolzina - 1;
      while ( *kz != ch && i < dolzina )
         { kz--; i++; }

      if ( *kz == ch )
         return kz;
      else
         return NULL;
   }
}

void Niz::velike_crke()
{
   char *k = polje;

   while ( *k ) {
      if ( *k >= 'a' && *k <= 'z' ) // mala �rka
         *k += 'A' - 'a';
      k++;
   }
}

void Niz::male_crke()
{
   char *k = polje;

   while ( *k ) {
      if ( *k >= 'A' && *k <= 'Z' ) // mala �rka
         *k -= 'A' - 'a';
      k++;
   }
}

class BASIC : public Niz {
public:
   BASIC() : Niz() {}
   BASIC(char *n) : Niz(n) {}
   BASIC(char ch, int dol) : Niz(ch, dol) {}

   friend BASIC left(BASIC b, int dol);
   friend BASIC right(BASIC b, int dol);
   friend BASIC mid(BASIC b, int start, int dol);
};

BASIC left(BASIC b, int dol)
{
   BASIC tmp;

   if (dol > b.dolzina) // �e bi �eleli ve� znakov, kot jih imamo na voljo
      dol = b.dolzina;

   tmp.polje = new char[ dol + 1 ];

   char  *izvor = b.polje, // izvorni polje
         *ponor = tmp.polje;     // ponor
   int   i = 0;

   while ( i < dol ) {
      *ponor = *izvor;
      izvor++; ponor++; i++;
   }
   *ponor = '\0';

   tmp.dolzina = dol;

   return tmp;
}

BASIC right(BASIC b, int dol)
{
   BASIC tmp;

   if (dol > b.dolzina) // �e bi �eleli ve� znakov, kot jih imamo na voljo
      dol = b.dolzina;

   tmp.polje = new char[ dol + 1 ];

   char  *izvor = b.polje + b.dolzina - dol ,   // izvorni polje
         *ponor = tmp.polje;     // ponor

   while ( *izvor )  {
      *ponor = *izvor;
      izvor++; ponor++;
   }
   *ponor = '\0';

   tmp.dolzina = dol;

   return tmp;
}

BASIC mid(BASIC b, int start, int dol)
{
   BASIC tmp;

   if (start >= b.dolzina) // ali smo sploh v polju
      return tmp;

   if (start + dol > b.dolzina)  // �e bi �eleli ve� znakov, kot jih imamo na voljo
      dol = b.dolzina - start;

   tmp.polje = new char[ dol + 1 ];

   char  *izvor = b.polje + start,  // izvorni polje
         *ponor = tmp.polje;     // ponor
   int   i = 0;

   while ( i < dol ) {
      *ponor = *izvor;
      izvor++; ponor++; i++;
   }
   *ponor = '\0';

   tmp.dolzina = dol;

   return tmp;
}

int main()
{
   BASIC n1("Matjaz Prtenjak"), n2('V', 10), n3;

   cout << (char*) n1 << " " << (int) n1 << endl;
   cout << (char*) n2 << " " << (int) n2 << endl;
   cout << (char*) n3 << " " << (int) n3 << endl;

   n3.prepisi("Veronika Prtenjak");
   cout << (char*) n3 << " " << (int) n3 << endl;

   cout << n3.primerjaj("Veronika Prtenjak") << endl;
   cout << n3.primerjaj("Veronika Prtenjaj") << endl;
   cout << n3.primerjaj("Veronika Prtenjal") << endl;

   n1.dodaj_niz(" ");
   n1.dodaj_niz(n3);
   cout << (char*) n1 << " " << (int) n1 << endl;

   n1.dodaj_niz(" ", zacetek);
   n1.dodaj_niz(n3, zacetek);
   cout << (char*) n1 << " " << (int) n1 << endl;

   cout << n1.Isci('P') << endl;
   cout << n1.Isci('P', konec) << endl;

   n1.velike_crke();
   cout << (char*) n1 << " " << (int) n1 << endl;
   n2.male_crke();
   cout << (char*) n2 << " " << (int) n2 << endl;

   for (int i = 0; i < 51; i++) {
      n2 = right(n1, i);
      cout << (char*) n2 << " " << (int) n2 << endl;
   }

   cout << (char*) n1 << " " << (int) n1 << endl;
   cout << "LEFT" << endl;
   for (i = 0; i < 51; i++) {
      n2 = left(n1, i);
      cout << (char*) n2 << " " << (int) n2 << endl;
   }

   cout << (char*) n1 << " " << (int) n1 << endl;
   cout << "MID 5" << endl;
   for (i = 0; i < 51; i++) {
      n2 = mid(n1, i, 1);
      cout << (char*) n2 << " " << (int) n2 << endl;
   }

   return 1;
}









