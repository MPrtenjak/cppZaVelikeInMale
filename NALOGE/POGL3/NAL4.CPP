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
   int   stevilo[10],      // polje števil
         resitev,          // rešitev
         i = 0;            // števec
   char  operat;           // operator
   char  transform[sizeof(int) * 8 + 1];

   cout << "Vpišite število [" << (i+1) << "] ..... ";
   cin >> stevilo[i];
   while( stevilo[i] != 0 && i < 9) { // vpisuje števila, dokler ne vpiše 0
      i++;                           // ali pa je vpisal 10 števil
      cout << "Vpišite število [" << (i+1) << "] ..... ";
      cin >> stevilo[i];
   }

   if (stevilo[i] == 0)
      i--;     // zadnnje število je bilo 0, kar pomeni konec, zato ga izvržemo

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
         default:    // karkoli je, reèemo da je to EKSKLUZIVNI ALI
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
