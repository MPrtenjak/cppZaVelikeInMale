#include <iostream.h>

void dec_to_bin(unsigned int i, char *s, int konec)
{
   int j = 0;

   while (i) {
      s[j++] = i % 2 + '0'; 
      i /= 2;
      }
   while (j < konec)
      s[j++] = '0';  // dodamo nièle
   s[j--] = '\0';
   
   char temp;  
   int k = 0;  
   while (j > k) {
      temp = s[k]; s[k++] = s[j]; s[j--] = temp; 
      } 
}

int main()
{
   int  st1, st2, st3, resitev;
   char cST1[sizeof(int)*8 + 1], cST2[sizeof(int)*8 + 1],
       cST3[sizeof(int)*8 + 1], cRESITEV[sizeof(int)*8 + 1];

   cout << "Vpišite prvo število ..... ";
   cin >> st1;
   cout << "Vpišite drugo število .... ";
   cin >> st2;
   cout << "Vpišite tretje število ... ";
   cin >> st3;

   resitev = st1 & st2 & st3;

   dec_to_bin(st1, cST1, sizeof(int)*8);
   dec_to_bin(st2, cST2, sizeof(int)*8);
   dec_to_bin(st3, cST3, sizeof(int)*8);
   dec_to_bin(resitev, cRESITEV, sizeof(int)*8);

   cout << endl;
   cout << cST1 << " &      " << st1 << " & " << endl;
   cout << cST2 << " &      " << st2 << " & " << endl;
   cout << cST3 << " =      " << st3 << " = " << endl;
   cout << "-----------------------------" << endl;
   cout << cRESITEV << "        " << resitev << "   " << endl;

   return 1;
}
