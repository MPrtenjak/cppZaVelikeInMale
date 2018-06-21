#include <iostream.h>

int main()
{
   int    i, *ki = &i;
   float  f, *kf = &f;
   double d, *kd = &d;

   cout << "Kam kažejo kazalci ..." << endl;
   cout << "  ki == " << ki << "  kf == " << kf << "   kd == " << kd <<endl;

   cout << endl << "Prištejmo vsem kazalcem + 1 ... " << endl;
   ki = ki + 1;
   kf = kf + 1;
   kd = kd + 1;

   cout << "Kam kažejo kazalci ..." << endl;
   cout << "  ki == " << ki << "  kf == " << kf << "   kd == " << kd <<endl;

   cout << endl << "Velikosti tipov so ..." << endl;
   cout << "  int == " << sizeof(int) << "  float == " << sizeof(float);
   cout << "  double == " << sizeof(double) << endl;

   return 1;
}
