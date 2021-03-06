#include <iostream.h>

// MAKRO DEFINICIJA
#define MIN(a, b) ( (a < b) ? (a) : (b) )

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
      if ( *kc1 < *kc2)    // �e je prvi manj�i
         return str1;
      if ( *kc1 > *kc2 )   // �e je drugi manj�i
         return str2;
      kc1++; kc2++;        // sicer samo oba pove�aj
   }
   // na tem mestu je enega (ali obeh nizov) konec

   if ( *kc1 )    // �e �e ni konec prvega niza
      return str2;

   if ( *kc2 )    // �e �e ni konec drugega niza
      return str1;

   return str1;      // niza sta enaka
}

int main()
{
   cout << MIN(3,4) << endl;
   cout << MIN(4,3) << endl;
   cout << MIN(3.99999,4) << endl;
   cout << MIN(3.9999,4.01) << endl;
   cout << MIN(3,'a') << endl;
   cout << MIN('a','b') << endl;
   cout << MIN("Niz1","Niz2") << endl;
   cout << MIN("Niz2","Niz1") << endl;

   return 1;
}

