#include <iostream.h>

int main()
{
   float op1, op2,   // obe števili (operanda)
         rezultat;   // rezultat izraèuna
   char  oper,       // operand
         odg;        // odgovor uporabnika

   do
   {
      cout << "Vpišite število, operand, število : ";
      cin >> op1 >> oper >> op2;

      while ( oper != '+' && oper != '-' &&
               oper != '*' && oper != '/') {
         cout << oper << " ni operator. Prosim vpišite operator : ";
         cin >> oper;
      }

      switch (oper) {
         case '+' :
            rezultat = op1 + op2;
            break;
         case '-' :
            rezultat = op1 - op2;
            break;
         case '/' :
            rezultat = op1 / op2;
            break;

         default:       // èe ni niè od zgornega, je monženje!
            rezultat = op1 * op2;
      }

      cout << "Rezultat = " << rezultat << endl;

      do {
         cout << "Želite še nadaljevati (d/n) : ";
         cin >> odg;
      } while ( odg != 'd' && odg != 'D' && odg != 'n' && odg != 'N' );
   }
   while ( odg != 'n' && odg != 'N' );

   return 1;
}
