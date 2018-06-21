#include <iostream.h>

const int Cena = 50;

class Cestnina {
protected:
   unsigned int   vsi,        // vsi avtomobili
                  neplacniki; // neplaèniki
public:
   Cestnina() { vsi = neplacniki = 0; }
   void Placal() { vsi++; }
   void NiPlacal() { vsi++; neplacniki++; }

   unsigned int Vsi() { return vsi; }
   unsigned int Neplacniki() { return neplacniki; }
};

int main()
{
   Cestnina most;
   char odg;

   do
   {
      cout << "> ";
      cin >> odg;

      switch (odg) {
         case 'n' :
         case 'N' :
            most.NiPlacal();
            break;
         case 'p' :
         case 'P' :
            most.Placal();
            break;
      }
   }
   while ( odg != 'k' && odg != 'K' );

   cout << "Zaslužili ste " << ( most.Vsi() - most.Neplacniki() ) * Cena <<
      "SIT." << endl;
   cout << "Ob tem pa ste zaradi neplaènikov izgubili " <<
      most.Neplacniki() * Cena << "SIT." << endl;

   return 1;
}

