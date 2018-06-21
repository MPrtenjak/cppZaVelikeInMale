#include <iostream.h>

void M_izpis(char *ime)
{
   cout << "Pozdravljeni gospod " << ime << " ." << endl;
}

void Z_izpis(char *ime)
{
   cout << "Pozdravljena gospa " << ime << " ."  << endl;
}

int main()
{
   void (*kFun)(char *);   // kFun je kazalec na funkcijo, ki sprejme
               // parameter tipa char* in vraca tip void.

   kFun = &M_izpis;  // kazalec moramo inicializirati!!
   M_izpis("Kranjski Janez");
   (*kFun)("Kranjski Janez mlajši");

   kFun = &Z_izpis; 
   Z_izpis("Kranjska Micka");
   (*kFun)("Kranjska Micka mlajša");

   return 1;
}
