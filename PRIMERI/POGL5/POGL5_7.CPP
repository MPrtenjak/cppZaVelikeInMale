#include <iostream.h>

void A(int a)
{
   cout << "Funkciji A je podano celo število " << a << "\n";
}

void A(char a)
{
   cout << "Funkciji A je podan znak " << a << "\n";
}

void main()
{
   A(240);
   A('b');
   A((char) 240);
   A((int) 'b');
}
