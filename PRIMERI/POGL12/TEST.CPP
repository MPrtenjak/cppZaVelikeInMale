#include <iostream.h>
#include <typeinfo.h>

class Delavec {
   // ...
public:
   virtual double placa() { return 1; }
   virtual double bonus() { return 2; }
   // ...
};

class Direktor : public Delavec {
   // ...
public:
   double placa() { return 100000.00; }
   double bonus() { return 100000.00; }
   // ...
};

class Snazilka : public Delavec {
   // ...
public:
   double placa() { return 0.0; }
   double bonus() { return 0.0; }
   // ...
};

int main()
{

   Delavec *kd = new Direktor;

   if (  typeid(kd)  == typeid(Delavec*)   )
      cout << " 1 TRUE " << cout;

   if (  typeid(kd)  == typeid(Direktor*)  )    // NERESNICA
      cout << " 2 TRUE " << cout;

   if (  typeid(kd)  == typeid(Delavec)    )    // NERESNICA
      cout << " 3 TRUE " << cout;

   if (  typeid(kd)  == typeid(Direktor)   )    // NERESNICA
      cout << " 4 TRUE " << cout;

   if (  typeid(*kd) == typeid(Delavec)    )    // NERESNICA
      cout << " 5 TRUE " << cout;

   if (  typeid(*kd) == typeid(Direktor)   )    // RESNICA
      cout << " 6 TRUE " << cout;

   
   Delavec &rd = *kd;

   if (  typeid(rd)  == typeid(Delavec)    )    // NERESNICA
      cout << " 7 TRUE " << cout;

   if (  typeid(rd)  == typeid(Direktor)   )    // RESNICA
      cout << " 8 TRUE " << cout;

   if (  typeid(&rd) == typeid(Delavec*)   )    // RESNICA
      cout << " 9 TRUE " << cout;
   
   if (  typeid(&rd) == typeid(Direktor*)  )    // NERESNICA.
      cout << " 10 TRUE " << cout;

   return 1;

}
