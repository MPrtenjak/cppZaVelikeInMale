#include <iostream.h>   

int min(int v1, int v2)
{  return (v1 < v2 ? v1 : v2);
}

void main()
{  int s1, s2;

   cout << "Vpi�ite dve naravni �tevili ... ";
   cin >> s1 >> s2;
   cout << "Manj�e �tevilo je ... " << min(s1, s2) << "\n";
   cout << "Ve�je  �tevilo je ... " << (s1 > s2 ? s1 : s2);
}  
