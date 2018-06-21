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

void izpisi(int j, int st1, int st2, char *predpis)
{
   char cST1[sizeof(int)*8 + 1], cST2[sizeof(int)*8 + 1];

   dec_to_bin(st1, cST1, sizeof(int)*8);
   dec_to_bin(st2, cST2, sizeof(int)*8);

   cout << predpis << j << ":  " << cST1 << "(" << st1 << ")";
   cout << "  " << cST2 << "(" << st2 << ")" << endl;
}

int main()
{
   int  st1, st2;

   st1 = -1;   // to število je predstavljeno s samimi enicami (vsi biti 1)
   st2 = 11; 

   izpisi(0, st1, st2, "PRED PREMIKOM : ");

   int j = 1;
   while (j <= sizeof(int) * 8) {
      st1 <<= 1;  // enako st1 = st1 << 1
      st2 <<= 1;

      izpisi(j++, st1, st2, "    premik za ");
      }

   return 1;
}
