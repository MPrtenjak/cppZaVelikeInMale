#include <iostream.h>

int main()
{
   float op1, op2,   // obe �tevili (operanda)
         rezultat;   // rezultat izra�una
   char  oper,       // operand
         odg;        // odgovor uporabnika

   do
   {
      cout << "Vpi�ite �tevilo, operand, �tevilo : ";
      cin >> op1 >> oper >> op2;

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
         default:       // �e ni ni� od zgornega, je mon�enje!
            rezultat = op1 * op2;
      }

      cout << "Rezultat = " << rezultat << endl;

      cout << "�elite �e nadaljevati (d/n) : ";
      cin >> odg;
   }
   while ( odg != 'n' && odg != 'N' );

   return 1;
}
