#include <iostream.h>

float Cel_to_Far(float CelTemp)  // GLAVA FUNKCIJE
{
   return (CelTemp * 9.0 / 5.0) + 32;  // TELO FUNKCIJE
}

float Far_to_Cel(float FarTemp)  // GLAVA FUNKCIJE
{
   return (FarTemp - 32) * 5.0 / 9.0;  // TELO FUNKCIJE
}

int main()  // GLAVA FUNKCIJE
{        // ZACETEK TELESA FUNKCIJE
   char  ch;
   int      Temp;

   do
      {
      cout << "\nPodajte merski sistem : 'F' - Fahrenheit, 'C' - Celsius ... ";
      cin.get(ch);
      }
   while (ch != 'f' && ch != 'F' && ch != 'c' && ch != 'C');

   cout << "Podajte temperaturo ... ";
   cin >> Temp;

   switch (ch) {
      case 'f' :
      case 'F' :
         cout << Temp << " stopinj Fahrenheit-a je " << Far_to_Cel(Temp);
         cout << " stopinj Celsius-a." << endl;
         break;
      case 'c' :
      case 'C' :
         cout << Temp << " stopinj Celsius-a je " << Cel_to_Far(Temp);
         cout << " stopinj Fahrenheit-a." << endl;
         break;
      }

   return 1;
}        // KONEC TELESA FUNKCIJE
