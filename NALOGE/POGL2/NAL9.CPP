#include <iostream.h>

int strlen(char *string)
{
   char *ch = string;   // kazalec postavimo na za�etek niza

   while(*ch != '\0')   // dokler ni konec niza
      ch = ch + 1;   // pove�uj kazalec

   return (ch - string);
}

int main()
{
   char str[100];

   cout << "Vpi�ite niz znakov ... ";
   cin >> str;

   cout << "Ta niz vsebuje " << strlen(str) << " znakov.";

   return 1;
}
