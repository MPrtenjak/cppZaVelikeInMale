/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Zaglavje sortirnih algoritmov

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#ifndef __SORT_HPP
#define __SORT_HPP

#define TRUE   1
#define FALSE  0

/*
   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   !!!                                                             !!!
   !!!   Èe želite drugi tip podatkov, spremenite to definicijo.   !!!
   !!!                                                             !!!
   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
typedef  int   TIP_PODATKA;



// v MAIN.cpp
extern TIP_PODATKA      *Podatek;   // kazalec na podatke, ki bodo prebrani iz datoteke
extern int              Kolicina;   // število podatkov

// kaj naj javimo operacijskemu sistemu
enum SISTEM {
   VSE_OK               = 0,
   VHODNA_DATOTEKA      = 1,
   IZHODNA_DATOTEKA     = 2,
   PREMALO_SPOMINA      = 3
};

inline int manjsi(TIP_PODATKA &p1, TIP_PODATKA &p2)
{
   return (p1 < p2) ? TRUE : FALSE;
}

inline void zamenjaj(TIP_PODATKA &p1, TIP_PODATKA &p2)
{
   TIP_PODATKA tmp = p1;
   p1 = p2;
   p2 = tmp;
}

// V_I.cpp
void preberi(char *datoteka); // REZERVIRA PROSTOR za podatke in jih prebere
void zapisi(char *datoteka);  // zapiše podatke in PROSTOR VRNE operac. sist.

#endif
