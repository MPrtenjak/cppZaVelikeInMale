#include <iostream.h>

void IzpisZnaka(char ch)
{
   cout << "Znak " << ch << " je predstavljen s kodo " << (int) ch << endl;
   // z (int) ch spremenimo char v int, zato se izpiše število
}
int main()
{
   char znaki;

   znaki = 'a';
   while (znaki != 'z') {
      IzpisZnaka(znaki);
      znaki = znaki + 1;
      }
   IzpisZnaka('z');  // izpisati moramo še  'z'

   cout << endl << endl;   // izpustimo dve vrstici

   znaki = 'A';
   while (znaki != 'Z') {
      IzpisZnaka(znaki);
      znaki = znaki + 1;
      }
   IzpisZnaka('Z');  // izpisati moramo se 'Z'

   cout << endl << endl;   // izpustimo dve vrstici

   znaki = '0';
   while (znaki != '9') {
      IzpisZnaka(znaki);
      znaki = znaki + 1;
      }
   IzpisZnaka('9');  // izpisati moramo se mali '9'

   return 1;
}
