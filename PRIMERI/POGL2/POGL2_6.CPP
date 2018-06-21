#include <iostream.h>

void zamenjaj(int *i1, int *i2) // tu sprejmemo naslove
{
   // izpisati moramo vrednosti na teh naslovih, zato *i1 in ne i1!
   cout << "   V FUNKCIJI PRED ZAMENJAVO i1 == " << *i1 << ", i2 == " << *i2 << endl;
   
   int temp = *i1;
   *i1 = *i2;  // zamenjujemo vrednosti, zato *i1 in ne i1!
   *i2 = temp;
   
   cout << "   V FUNKCIJI PO   ZAMENJAVI i1 == " << *i1 << ", i2 == " << *i2 << endl;
}

int main()
{
   int i1 = 11, i2 = 22;

   cout << "PRED ZAMENJAVO i1 == " << i1 << ", i2 == " << i2 << endl;
   
   zamenjaj(&i1, &i2);  // sedaj moramo posredovati naslove
   
   cout << "PO   ZAMENJAVI i1 == " << i1 << ", i2 == " << i2 << endl;

   return 1;
}                                                  
