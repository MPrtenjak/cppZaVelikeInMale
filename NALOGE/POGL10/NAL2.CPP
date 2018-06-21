#include <iostream.h>
#include <string.h>     // za delo z nizi

/*  **************************************************

    **********     BAZNI RAZRED Izdelek     **********

    **************************************************  */
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

/*  ***********************************************

    **********     BAZNI RAZRED Cene     **********

    ***********************************************  */
class Cene {
protected:
   double   cena[3];

   void Set(double c1, double c2, double c3) {
      cena[0] = c1;     // pred tremi meseci
      cena[1] = c2;     // pred dvema mesecima
      cena[2] = c3;     // pred enim mesecem
   }

public:
   Cene(double c1, double c2, double c3) 
      { Set(c1, c2, c3); }

   void Vnos(double c1, double c2, double c3)
      { Set(c1, c2, c3); }
   virtual void Izpis()
      {
      cout << "\t Prejšnje cene : " <<
         cena[0] << "/" << cena[1] << "/" << cena[2] << endl;
      }
};

/*  *******************************************

    **********     RAZRED Knjiga     **********

    *******************************************  */
class Knjiga : public Izdelek, public Cene {
protected:
   unsigned int st_strani;    // število strani

public:
   Knjiga() : Izdelek(), Cene(0.0, 0.0, 0.0)
       { st_strani = 0; }
   Knjiga(char *nasl, double cn, unsigned int strani,
         double c1, double c2, double c3) :
      Izdelek(nasl, cn), Cene(c1, c2, c3)
      { st_strani = strani; }

   void Vnos(char *nasl, double cn, unsigned int strani,
         double c1, double c2, double c3)
      {
      Izdelek::Set(nasl, cn);
      Cene::Set(c1, c2, c3);
      st_strani = strani;
      }
   virtual void Izpis()
      {
      Izdelek::Izpis();
      cout << ", št. strani: " << st_strani << endl;
      Cene::Izpis();
      }
};

/*  ********************************************

    **********     RAZRED AvKaseta    **********

    ********************************************  */
class AvKaseta : public Izdelek, public Cene {
protected:
   unsigned int cas;    // èas v sekundah

public:
   AvKaseta() : Izdelek(), Cene(0.0, 0.0, 0.0)
       { cas = 0; }
   AvKaseta(char *nasl, double cn, unsigned int cs,
      double c1, double c2, double c3) :
      Izdelek(nasl, cn), Cene(c1, c2, c3)
         { cas = cs; }

   void Vnos(char *nasl, double cn, unsigned int cs,
      double c1, double c2, double c3)
      {
      Izdelek::Set(nasl, cn);
      Cene::Set(c1, c2, c3);
      cas = cs;
      }
   virtual void Izpis()
      {
      Izdelek::Izpis();
      cout << ", èas v sec.: " << cas << endl;
      Cene::Izpis();
      }
};

int main()
{
   Izdelek *izd[8];

   izd[0] = new Knjiga("V 80 dneh okrog sveta", 3503.50, 400,
      3603.20, 3603.20, 3800.00);
   izd[1] = new Knjiga("Pod svobodnim soncem", 4312.30, 500,
      4312.30, 0 ,0);
   izd[2] = new Knjiga("Destei brat", 2250.20, 250,
      2250.20, 2250.20, 2250.20);
   izd[3] = new Knjiga("Mi otroci s postaje ZOO", 5413.20, 350,
      5413.20, 5500.50, 5500.50);

   izd[4] = new AvKaseta("Pekarna MišMaš", 2503.50, 4513,
      2503.50, 2503.50, 2600.00);
   izd[5] = new AvKaseta("Metalica", 4250.30, 4245,
      4250.30, 4312.20, 4312.20);
   izd[6] = new AvKaseta("Ansambel Slak", 1240.20, 3850,
      1240.20, 1300.30, 1300.30);
   izd[7] = new AvKaseta("Zvezdica Zaspanka", 800.00, 3150,
      800.00, 800.00, 1000.00);

   for (int i = 0; i < 8; i++)
   {
      cout << (i + 1) << ": ";
      izd[i]->Izpis();  // pa še vse izpišemo
      delete izd[i];    // in pobrišemo
      cout << endl;
   }

   return 1;
}