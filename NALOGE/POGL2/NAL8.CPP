#include <iostream.h>

void IzpisZnaka(char ch)
{
   cout << "Znak " << ch << " je predstavljen s kodo " << (int) ch << endl;
}

void IzpisiZnake(char spMeja, char zgMeja)
{
   char znaki;

   znaki = spMeja;      // zaènemo pri spodnji meji
   while (znaki != zgMeja) {
      IzpisZnaka(znaki);
      znaki = znaki + 1;
      }
   IzpisZnaka(zgMeja);  // izpisati moramo èe zgornjo mejo

   cout << endl << endl;   // izpustimo dve vrstici
}

int main()
{
   IzpisiZnake('a', 'z');
   IzpisiZnake('A', 'Z');
   IzpisiZnake('1', '9');

   return 1;
}
