#include <iostream.h>
#include <iomanip.h>
#include <string.h>

#define DOL_IME      10
#define DOL_PRIIMEK  10
#define DOL_NASLOV   20
#define DOL_MESTO    10

class Clovek {
protected:
   char     ime[DOL_IME],
            priimek[DOL_PRIIMEK],
            naslov[DOL_NASLOV],
            mesto[DOL_MESTO];

public:

   friend istream& operator>>(istream&, Clovek&);     
   friend ostream& operator<<(ostream&, Clovek&);     

   // ostale metode
};

istream& operator>>(istream& in, Clovek &cl)
{  
   in.getline(cl.ime, DOL_IME);
   in.getline(cl.priimek, DOL_PRIIMEK);
   in.getline(cl.naslov, DOL_NASLOV);
   in.getline(cl.mesto, DOL_MESTO);

   return in;
}
   
ostream& operator<<(ostream& out, Clovek &cl)
{
   out << setw(DOL_IME + 2) << cl.ime;
   out << setw(DOL_PRIIMEK + 2) << cl.priimek;
   out << setw(DOL_NASLOV + 2) << cl.naslov;
   out << setw(DOL_MESTO + 2) << cl.mesto << endl;

   return out;
}

int main()
{
   Clovek cl[3];

   for(int i = 0; i < 3; i++) {
      cout << "Vpisite podatke o osebi ... ";
      cin >> cl[i];
   }

   cout.setf(ios::left,ios::adjustfield);    // s tem dosežemo levo poravnavo
   cout << setw(DOL_IME + 2) << "IME";
   cout << setw(DOL_PRIIMEK + 2) << "PRIIMEK";
   cout << setw(DOL_NASLOV + 2) << "NASLOV";
   cout << setw(DOL_MESTO + 2) << "MESTO" << endl;
   
   cout << "----------------------------------------";
   cout << "----------------------------------------" << endl;
      
   for(i = 0; i < 3l; i++)
      cout << cl[i];

   return 1;
}