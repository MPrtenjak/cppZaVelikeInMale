#include <iostream.h>

struct complex {
   double re, im;
};

union vrednost {
      int         v_int;
      double      v_dbl;
      complex  v_cpx;
};

int main() {
   vrednost v;

   cout << "Velikost celotne unije ....... " << sizeof(vrednost) << endl;
   cout << "Velikost elementa int ........ " << sizeof(v.v_int) << endl;
   cout << "Velikost elementa double ..... " << sizeof(v.v_dbl) << endl;
   cout << "Velikost elementa complex  ... " << sizeof(v.v_cpx) << endl << endl;

   cout << "Naslovi spremenljivk so : " << endl;
   cout << "   naslov v ............ " << &v << endl;
   cout << "   naslov v.v_int ...... " << &v.v_int << endl;
   cout << "   naslov v.v_dbl ...... " << &v.v_dbl << endl;
   cout << "   naslov v.v_cpx ...... " << &v.v_cpx << endl;
   cout << "   naslov v.v_cpx.re ... " << &v.v_cpx.re << endl;
   cout << "   naslov v.v_cpx.im ... " << &v.v_cpx.im << endl << endl;

   cout << "Podajte realno število ...";
   cin >> v.v_dbl;

   cout << "V uniji so naslednje vrednosti : " << endl;
   cout << "   vrednost v.v_int ...... " << v.v_int << endl;
   cout << "   vrednost v.v_dbl ...... " << v.v_dbl << endl;
   cout << "   vrednost v.v_cpx.re ... " << v.v_cpx.re << endl;
   cout << "   vrednost v.v_cpx.im ... " << v.v_cpx.im << endl;

   return 1;
}
