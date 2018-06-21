#include <iostream.h>
#include <stdlib.h>  // deklarirana funkcija exit

extern void (*_new_handler) (void);

void napaka() {
   cout << "Premalo pomnilnika ... Konèujem!" << endl;
   exit (10);
}

int main()
{
   int *ki;

   _new_handler = napaka;

   for(;;)  { // neskoncna zanka
      ki = new int[1000];
      cout << "Zasegel sem novih 1000 celih stevil " << endl;
      } // ker pomnilnika ne sprošèamo, ga bo prej ali slej zmanjkalo

   return (1);
}