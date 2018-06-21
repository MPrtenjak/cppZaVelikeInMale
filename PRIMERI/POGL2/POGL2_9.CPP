#include <iostream.h>

void IzpisiPolje(int *p)
{
   int i = 0;
   
   cout << "Polje vsebuje ... ";
   while (i < 3) {
      cout << p[i] << " ";
      i = i + 1;
      }

   cout << endl;
}

int main()
{
   int pl[3];
   int *kp = &pl[0]; // lahko tudi int *kp = pl;

   cout << "Vpišite polje ... " << endl;
   int i = 0;
   while (i < 3) {
      cout << "Vpišite pl[" << i << "] ... ";
      cin >> pl[i];
      i = i + 1;
      }
   IzpisiPolje(pl);

   pl[1] = 4;
   IzpisiPolje(pl);
   
   *(pl + 1) = 5;
   IzpisiPolje(pl);

   *(kp + 1) = 6;
   IzpisiPolje(pl);

   kp[1] = 7;
   IzpisiPolje(pl);

   return 1;
}
