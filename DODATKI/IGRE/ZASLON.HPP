/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matja� Prtenjak

   NAMEN:
      Definira ANSI sekvence, za delo z zaslonom.

   OPERACIJSKI SISTEM:
      MS-DOS   (mogo�e tudi nekateri drugi)
*/

#include <iostream.h>   // Za delo z nizi

const char ESC = 27;

// ********
// ******** BRI�E EKRAN
// ********
// sekvenca : ESC [ 2 J 
inline void BrisiZaslon()
{
   cout << ESC << "[2J";
}

// ********
// ******** BRI�E VRSTICO, OD KURZRJA DALJE
// ********
// sekvenca : ESC [ K
inline void BrisiVrstico()
{
   cout << ESC << "[K";
}

// ********
// ******** POSTAVI SE NA �ELJENO VRSTICO OZ. STOLPEC
// ********
// sekvenca : ESC [ <vrstica> ; <stolpec> H  
inline void PostaviSeNaXY(int Stolpec, int Vrstica)
{
   // POZOR: najprej VRSTICA in nato STOLPEC
   cout << ESC << "[" << Vrstica << ";" << Stolpec << "H";
}

