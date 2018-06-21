#include <iostream.h>

enum  Kje { zacetek, konec };    // kje se zaène operacija, na zaèetku ali koncu

int strlen(const char *niz)
{
   const char *n = niz;

   while( *n ) n++;

   return n - niz;
}

class Niz {
protected:
   char  *polje;        // polje znakov
   int   dolzina;    // dolžina niza

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

   int primerjaj(const char *n);    // -1 èe je polje manjši

   void prepisi(const char *n);     // prepiše polje

   void dodaj_niz(char *n, Kje k = konec) // doda polje
      { Dodaj(n, k); }

   const char *Isci(char ch, Kje k = zacetek);  // išèe prvo pojavitev èrke

   void velike_crke();  // spremeni vse èrke v velike
   void male_crke();    // spremeni vse èrke v male
};

void Niz::Dodaj(char *n, Kje tip)
{
   int dolzina_n = strlen(n);
   char *tmp = new char[ dolzina + dolzina_n + 1];

   char  *kc1, *kc2, *ktmp = tmp;      // kazalec na temp

   if (tip == zacetek)  // doda na zaèetek
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
      *ktmp = *kc1;  // prepiši prvega v tmp
      kc1++; ktmp++; // oba poveèaj
   }

   while ( *kc2 ) {  // dokler ni konec drugega
      *ktmp = *kc2;  // prepiši drugega v tmp
      kc2++; ktmp++; // oba poveèaj
   }

   *(ktmp) = '\0';     // na konec '\0' !!!!!

   delete polje;                       // starega zbrišemo
   polje = tmp;                        // kaže na novega
   dolzina = dolzina + dolzina_n;      // nova dolžina
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
      if ( *kc1 > *kc2)    // èe je polje veèji vrni 1
         return 1;
      if ( *kc1 < *kc2 )   // èe je n veèji vrni -1
         return -1;
      kc1++; kc2++;        // sicer samo oba poveèaj
   }
   // na tem mestu je enega (ali obeh nizov) konec

   if ( *kc1 )    // èe še ni konec prvega niza
      return 1;

   if ( *kc2 )    // èe še ni konec drugega niza
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
      *kc1 = *kc2;   // prepiši iz n v polje
      kc1++; kc2++;  // oba poveèaj
   }

   *(kc1) = '\0';   // na konec '\0' !!!!!

   dolzina = kc2 - n;
}

const char *Niz::Isci(char ch, Kje k)
{
   const char *kz;      // kazalec
   int  i = 0;

   if (k == zacetek) // išèi na zaèetku
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
      if ( *k >= 'a' && *k <= 'z' ) // mala èrka
         *k += 'A' - 'a';
      k++;
   }
}

void Niz::male_crke()
{
   char *k = polje;

   while ( *k ) {
      if ( *k >= 'A' && *k <= 'Z' ) // mala èrka
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

   if (dol > b.dolzina) // èe bi želeli veè znakov, kot jih imamo na voljo
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

   if (dol > b.dolzina) // èe bi želeli veè znakov, kot jih imamo na voljo
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

   if (start + dol > b.dolzina)  // èe bi želeli veè znakov, kot jih imamo na voljo
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









