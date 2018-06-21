#include <iostream.h>
#include <string.h>     // za delo z nizi

/*  ********************************************

    **********     RAZRED Izdelek     **********

    ********************************************  */
class Izdelek {
protected:
   char     *naslov;
   double   cena;

   void Set(char *n, float c);

public:
   Izdelek()
      { naslov = NULL; cena = 0.0; }
   Izdelek(char *nasl, float cn)
      {
      naslov = NULL;       // da ga lahko funkcija Set pobriše !!!
      Set(nasl, cn);
      }
   ~Izdelek()
      { delete naslov; }

   void Vnos(char *nasl, float cn);
   virtual void Izpis()
      { cout << naslov << " : " << cena << "SIT"; }
};

void Izdelek::Set(char *n, float c)
{
   delete naslov;    // pobrišemo prejšnji naslov

   naslov = new char[ strlen(n) + 1 ];
   strcpy(naslov, n);

   cena = c;
}

/*  *******************************************

    **********     RAZRED Knjiga     **********

    *******************************************  */
class Knjiga : public Izdelek {
protected:
   unsigned int st_strani;    // število strani

public:
   Knjiga() : Izdelek() { st_strani = 0; }
   Knjiga(char *nasl, double cn, unsigned int strani) :
      Izdelek(nasl, cn)
      { st_strani = strani; }

   void Vnos(char *nasl, double cn, unsigned int strani)
      { Set(nasl, cn); st_strani = strani; }
   virtual void Izpis()
      {
      Izdelek::Izpis();
      cout << ", št. strani: " << st_strani << endl;
      }
};

/*  ********************************************

    **********     RAZRED AvKaseta    **********

    ********************************************  */
class AvKaseta : public Izdelek {
protected:
   unsigned int cas;    // èas v sekundah

public:
   AvKaseta() : Izdelek() { cas = 0; }
   AvKaseta(char *nasl, double cn, unsigned int cs) :
      Izdelek(nasl, cn)
      { cas = cs; }

   void Vnos(char *nasl, double cn, unsigned int cs)
      { Set(nasl, cn); cas = cs; }
   virtual void Izpis()
      {
      Izdelek::Izpis();
      cout << ", èas v sec.: " << cas << endl;
      }
};

int main()
{
   Izdelek *izd[8];

   izd[0] = new Knjiga("V 80 dneh okrog sveta", 3503.50, 400);
   izd[1] = new Knjiga("Pod svobodnim soncem", 4312.30, 500);
   izd[2] = new Knjiga("Destei brat", 2250.20, 250);
   izd[3] = new Knjiga("Mi otroci s postaje ZOO", 5413.20, 350);

   izd[4] = new AvKaseta("Pekarna MišMaš", 2503.50, 4513);
   izd[5] = new AvKaseta("Metalica", 4250.30, 4245);
   izd[6] = new AvKaseta("Ansambel Slak", 1240.20, 3850);
   izd[7] = new AvKaseta("Zvezdica Zaspanka", 800.00, 3150);

   for (int i = 0; i < 8; i++)
   {
      cout << (i + 1) << ": ";
      izd[i]->Izpis();  // pa še vse izpišemo
      delete izd[i];    // in pobrišemo
      cout << endl;
   }

   return 1;
}