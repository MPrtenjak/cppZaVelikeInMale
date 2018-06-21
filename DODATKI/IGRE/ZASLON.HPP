/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Definira ANSI sekvence, za delo z zaslonom.

   OPERACIJSKI SISTEM:
      MS-DOS   (mogoèe tudi nekateri drugi)
*/

#include <iostream.h>   // Za delo z nizi

const char ESC = 27;

// ********
// ******** BRIŠE EKRAN
// ********
// sekvenca : ESC [ 2 J 
inline void BrisiZaslon()
{
   cout << ESC << "[2J";
}

// ********
// ******** BRIŠE VRSTICO, OD KURZRJA DALJE
// ********
// sekvenca : ESC [ K
inline void BrisiVrstico()
{
   cout << ESC << "[K";
}

// ********
// ******** POSTAVI SE NA ŽELJENO VRSTICO OZ. STOLPEC
// ********
// sekvenca : ESC [ <vrstica> ; <stolpec> H  
inline void PostaviSeNaXY(int Stolpec, int Vrstica)
{
   // POZOR: najprej VRSTICA in nato STOLPEC
   cout << ESC << "[" << Vrstica << ";" << Stolpec << "H";
}

