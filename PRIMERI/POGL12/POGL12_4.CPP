#include <iostream.h>
#include <math.h>       // definiran M_PI

int main()
{
   int num;

   do {
      cout << "�tevilo [0 - konec] ... ";
      cin >> num;

      cout << "   osmi�ko       == " << oct << num << endl;
      cout << "   deseti�ko     == " << dec << num << endl;
      cout << "   �estnajsti�ko == " << hex << num << endl;
   } while(num);

   return 1;
}