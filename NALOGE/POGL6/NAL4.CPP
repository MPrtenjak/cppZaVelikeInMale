#include <iostream.h>

#ifdef PREDPROCES

// MAKRO DEFINICIJA
#define min(a, b) ( (a < b) ? (a) : (b) )

#else

// VRINJENE FUNKCIJE
inline char min(char a, char b) { return ((a < b) ? a : b); }
inline int min(int a, int b) { return ((a < b) ? a : b); }
inline long min(long a, long b) { return ((a < b) ? a : b); }
inline float min(float a, float b) { return ((a < b) ? a : b); }
inline double min(double a, double b) { return ((a < b) ? a : b); }

// ZA NIZE ZNAKOV
inline char* min(char *str1, char *str2)
{
   char  *kc1 = str1,
         *kc2 = str2;

   while ( *kc1 && *kc2 ) {
      if ( *kc1 < *kc2)    // èe je prvi manjši
         return str1;
      if ( *kc1 > *kc2 )   // èe je drugi manjši
         return str2;
      kc1++; kc2++;        // sicer samo oba poveèaj
   }
   // na tem mestu je enega (ali obeh nizov) konec

   if ( *kc1 )    // èe še ni konec prvega niza
      return str2;

   if ( *kc2 )    // èe še ni konec drugega niza
      return str1;

   return str1;      // niza sta enaka
}

#endif
