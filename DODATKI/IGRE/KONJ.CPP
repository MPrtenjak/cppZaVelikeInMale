/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matja� Prtenjak

   NAMEN:
      Program, ki testira, zmo�nost abstraktnega mi�ljenja.
      Potrebno je premikati �ahovsko figuro (konja) po �ahovski plo��i!

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <string.h>  // deklaracije str...() funkcij
#include <stdlib.h>  // deklaracije funkcij za naklju�na �tevila
#include <ctype.h>   // deklaracije funkcije toupper()

#include "zaslon.hpp"   // za delo z zaslonom

// ********
// ********    KONSTANTE
// ********

#define TRUE   1
#define FALSE  0

const char MinStolpec = 'A';     // levi rob plo��e
const char MaxStolpec = 'H';     // desni rob plo��e

const char MinVrstica = '1';        // spodnji rob plo��e
const char MaxVrstica = '8';        // zgornji rob plo��e


// ********
// ********    RAZRED FIGURA
// ********

class Figura { // �ahovska figura
protected:
   char  stolpec,
         vrstica;

public:
   Figura()
      { stolpec = MinStolpec; vrstica = MinVrstica; }

   char  Stolpec()   { return stolpec; }
   char  Vrstica()   { return vrstica; }

      // postavi figuro na plo��o in vrne TRUE
      // �e je pozicija napa�na, vrne FALSE
   int Postavi(char stlp, char vrst);

      // nakljucno postavi figuro na plo��o
   void PostaviNakljucno() {
      stolpec = ( rand() % (MaxStolpec - MinStolpec) ) + 'A';
      vrstica = ( rand() % (MaxVrstica - MinVrstica) ) + '1';
   }

      // ali sta dve figuri na istem mestu
   friend int operator==(Figura&, Figura&);
};

int Figura::Postavi(char stlp, char vrst)
{
   stlp = toupper(stlp);
   vrst = toupper(vrst);                 

   if (  (stlp > MaxStolpec) || (stlp < MinStolpec) || 
         (vrst > MaxVrstica) || (vrst < MinVrstica) )
      return FALSE;
   else {
      stolpec = stlp;
      vrstica = vrst;
   }

   return TRUE;
}

int operator==(Figura &f1, Figura &f2)
{
   return ( (f1.stolpec == f2.stolpec) && (f1.vrstica == f2.vrstica) );
}


// ********
// ********    RAZRED KONJ
// ********

class Konj: public Figura {   // konj je �ahovska figura
public:
   Konj() : Figura() {}

      // Vrne TRUE, �e je poteza legalna, sicer vrne FALSE
   int AliLahko(char stlp, char vrst);
};

int Konj::AliLahko(char stlp, char vrst)
{
   stlp = toupper(stlp);
   vrst = toupper(vrst);                 

   if (  (stlp > MaxStolpec) || (stlp < MinStolpec) || 
         (vrst > MaxVrstica) || (vrst < MinVrstica) )
      return FALSE;  // sploh ni na plo��i
   else {
      int dx = abs(stlp - stolpec);    // absolutna razdalja po osi X
      int dy = abs(vrst - vrstica);    // absolutna razdalja po osi Y

      if  ( ((dx == 1) && (dy == 2)) ||
            ((dx == 2) && (dy == 1)) )
         return TRUE;
   }

   return FALSE;
}

int main()
{
   Konj     knj;              // konj     == startna pozicija
   Figura   fgr;              // figura   == kon�na pozicija
   int      stevecPotez;      // �tevec potez
   char     vnos[5];          // uporabnikov vnos
   
   randomize();   // inicializira generator naklju�nih �tevil

   for(;;) {   // naskon�na zanka
      BrisiZaslon();
      stevecPotez = 0;

      knj.PostaviNakljucno();    // izmisli si prvo pozicijo
      do {
         fgr.PostaviNakljucno(); // izmisli si drugo pozicijo
      } while ( knj == fgr );    // ponavljaj dokler sta enaki

      cout << "Prestavite konja iz pozicije " << knj.Stolpec() << knj.Vrstica();
      cout << " na pozicijo " << fgr.Stolpec() << fgr.Vrstica() << endl << endl;

      do {
         do {
            cout << "[BYE = konec]  #" << ++stevecPotez << ":  ";
            cout << knj.Stolpec() << knj.Vrstica() << " ---> ";
            cin.getline(vnos, 5);
            if ( stricmp(vnos, "BYE") == 0 ) 
               break;
            if ( !knj.AliLahko(vnos[0], vnos[1]))
               cout << "Napa�na poteza. Poskusite znova ..." << endl << endl;
         } while ( !knj.AliLahko(vnos[0], vnos[1]));

         if ( stricmp(vnos, "BYE") == 0 ) 
               break;

         knj.Postavi(vnos[0], vnos[1]);
      } while( !(knj == fgr) );

      if ( stricmp(vnos, "BYE") == 0 ) 
         break;

      cout << "Uspelo vam je v " << stevecPotez << " potezah." << endl;

      cout << endl << endl << "\tPritisnite <ENTER> za nadaljevanje";
      cin.getline(vnos, 5);
   }  // konec for

   return 1;
}                 
      


