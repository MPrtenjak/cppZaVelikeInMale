#include <iostream.h>

// tu so preimenovani nekateri stavki, ki jih že poznamo
#define CE           if
#define SICER        else
#define PONAVLJAJ    do
#define DOKLER       while
#define ZA           for
#define IZBERI       switch
#define V_PRIMERU    case
#define GLAVNA       main
#define VRNI         return
#define VELIKOST     sizeof

#define nic          void
#define cel          int
#define znak         char
#define dolg         long
#define realni       float
#define dvojni       double

#define nepredznacen unsigned

/*


    POSLOVENIL BOM PRIMER IZ POGLAVJA 3

            POGL3_4.cpp


*/

nic dec_to_bin(nepredznacen cel i, znak *s, cel konec)
{
   cel j = 0;

   DOKLER (i) {
      s[j++] = i % 2 + '0';
      i /= 2;
      }
   DOKLER (j < konec)
      s[j++] = '0';  // dodamo nièle
   s[j--] = '\0';

   znak temp;
   cel  k = 0;
   DOKLER (j > k) {
      temp = s[k]; s[k++] = s[j]; s[j--] = temp;
      }
}

cel GLAVNA()
{
   cel  st1, st2, st3, resitev;
   znak cST1[VELIKOST(cel)*8 + 1], cST2[VELIKOST(cel)*8 + 1],
       cST3[VELIKOST(cel)*8 + 1], cRESITEV[VELIKOST(cel)*8 + 1];

   cout << "Vpišite prvo število ..... ";
   cin >> st1;
   cout << "Vpišite drugo število .... ";
   cin >> st2;
   cout << "Vpišite tretje število ... ";
   cin >> st3;

   resitev = st1 & st2 & st3;

   dec_to_bin(st1, cST1, VELIKOST(cel)*8);
   dec_to_bin(st2, cST2, VELIKOST(cel)*8);
   dec_to_bin(st3, cST3, VELIKOST(cel)*8);
   dec_to_bin(resitev, cRESITEV, VELIKOST(cel)*8);

   cout << endl;
   cout << cST1 << " &      " << st1 << " & " << endl;
   cout << cST2 << " &      " << st2 << " & " << endl;
   cout << cST3 << " =      " << st3 << " = " << endl;
   cout << "-----------------------------" << endl;
   cout << cRESITEV << "        " << resitev << "   " << endl;

   VRNI 1;
}



