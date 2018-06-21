#include <iostream.h>   

int min(int v1, int v2)
{  return (v1 < v2 ? v1 : v2);
}

void main()
{  int s1, s2;

   cout << "Vpišite dve naravni števili ... ";
   cin >> s1 >> s2;
   cout << "Manjše število je ... " << min(s1, s2) << "\n";
   cout << "Veèje  število je ... " << (s1 > s2 ? s1 : s2);
}  
