#include <iostream.h>

void dec_to_bin(unsigned int i, char *s, int konec)
{
   int j = 0;

   while (i) {
      s[j++] = i % 2 + '0'; 
      i /= 2;
      }
   while (j < konec)
      s[j++] = '0';  // dodamo ni�le
   s[j--] = '\0';
   
   char temp;  
   int k = 0;  
   while (j > k) {
      temp = s[k]; s[k++] = s[j]; s[j--] = temp; 
      } 
}

int main()
{
   int   stevilo[10],      // polje �tevil
         resitev,          // re�itev
         i = 0;            // �tevec
   char  operat;           // operator
   char  transform[sizeof(int) * 8 + 1];

   cout << "Vpi�ite �tevilo [" << (i+1) << "] ..... ";
   cin >> stevilo[i];
   while( stevilo[i] != 0 && i < 9) { // vpisuje �tevila, dokler ne vpi�e 0
      i++;                           // ali pa je vpisal 10 �tevil
      cout << "Vpi�ite �tevilo [" << (i+1) << "] ..... ";
      cin >> stevilo[i];
   }

   if (stevilo[i] == 0)
      i--;     // zadnnje �tevilo je bilo 0, kar pomeni konec, zato ga izvr�emo

   cout << " OPERATOR ... ";
   cin >> operat;

   cout << endl << endl;

   for (int j = 0; j <= i; j++)
      {
      dec_to_bin(stevilo[j], transform, sizeof(int)*8);
      switch (operat) {
         case '&':   // ali je to operacije IN
            cout << transform << " &      " << stevilo[j] << " & " << endl;
            if ( j == 0 )
               resitev = stevilo[0];   // prvo [tevilo samo priredimo !!!
            else
               resitev &= stevilo[j];
            break;
         case '|':   // ali je to operacija ALI
            cout << transform << " |      " << stevilo[j] << " | " << endl;
            if ( j == 0 )
               resitev = stevilo[0];   // prvo [tevilo samo priredimo !!!
            else
               resitev |= stevilo[j];
            break;
         default:    // karkoli je, re�emo da je to EKSKLUZIVNI ALI
            cout << transform << " ^      " << stevilo[j] << " ^ " << endl;
            if ( j == 0 )
               resitev = stevilo[0];   // prvo [tevilo samo priredimo !!!
            else
               resitev ^= stevilo[j];
      }
   }

   dec_to_bin(resitev, transform, sizeof(int)*8);
   cout << "-----------------------------" << endl;
   cout << transform << "        " << resitev << "   " << endl;

   return 1;
}
