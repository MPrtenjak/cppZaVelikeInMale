#include <iostream.h>
#include <math.h>       // definiran M_PI

int main()
{
   int num;

   do {
      cout << "Število [0 - konec] ... ";
      cin >> num;

      cout << "   osmiško       == " << oct << num << endl;
      cout << "   desetiško     == " << dec << num << endl;
      cout << "   šestnajstiško == " << hex << num << endl;
   } while(num);

   return 1;
}
