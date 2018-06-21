#include <iostream.h>

int main(int ArgC, char *ArgV[])
{
   for(int i = 0; i < ArgC; i++)
      cout << "ArgV[" << i << "] = " << ArgV[i] << endl;

   return 1;
}
