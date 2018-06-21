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

   char* Naslov()
      { return naslov; }
   double Cena()
      { return cena; } 
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

   double Cena(int i)
      { return cena[i]; }
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

   unsigned int Strani()
      { return st_strani; }
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

   unsigned int Cas()
      { return cas; }
};

/*  ********************************************

    **********     RAZRED AvKaseta    **********

    ********************************************  */
class VideoKaseta : public Izdelek, public Cene {
protected:
   unsigned int cas;    // èas v sekundah

public:
   VideoKaseta() : Izdelek(), Cene(0.0, 0.0, 0.0)
       { cas = 0; }
   VideoKaseta(char *nasl, double cn, unsigned int cs,
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

   unsigned int Cas()
      { return cas; }
};

/*  *******************************************

    **********     RAZRED Komplet    **********

    *******************************************  */
class Komplet : public Izdelek {
protected:
   Knjiga      knj;
   VideoKaseta video;

public:
   //
   // TO NI POPOLNOMA PRAVILNO, SAJ MANJKA PREOBLOŽITEV OPERATORJA =,
   // KAR PA BOMO SPOZNALI V NASLEDNJEM POGLAVJU
   //
   Komplet(Knjiga &k, VideoKaseta &v)
      { knj = k; video = v; }

   //
   // TO NI POPOLNOMA PRAVILNO, SAJ MANJKA PREOBLOŽITEV OPERATORJA =,
   // KAR PA BOMO SPOZNALI V NASLEDNJEM POGLAVJU
   //
   void Vnos(Knjiga &k, VideoKaseta &v)
      { knj = k; video = v; }

   virtual void Izpis();
};

void Komplet::Izpis()
{
   double cena = knj.Izdelek::Cena() + video.Izdelek::Cena(),
            cena0 = (knj.Cene::Cena(0) + video.Cene::Cena(0)) * 0.9,
            cena1 = (knj.Cene::Cena(1) + video.Cene::Cena(1)) * 0.9,
            cena2 = (knj.Cene::Cena(2) + video.Cene::Cena(2)) * 0.9;

   cout << "Komplet (10% popust !!) : " << endl <<
      "\t" << knj.Naslov() << " in " << video.Naslov() <<
      " skupaj samo: " << cena*0.9 <<
      "SIT. (sicer " << cena << "SIT." << endl <<
      "\t" << cena0 << "/" << cena1 << "/" << cena2 << endl;
}

int main()
{
   Izdelek *izd[12];

   izd[0] = new Knjiga("V 80 dneh okrog sveta", 3503.50, 400,
      3603.20, 3603.20, 3800.00);
   izd[1] = new Knjiga("Pod svobodnim soncem", 4312.30, 500,
      4312.30, 0 ,0);
   izd[2] = new Knjiga("Destei brat", 2250.20, 250,
      2250.20, 2250.20, 2250.20);
   izd[3] = new Knjiga("Mi otroci s postaje ZOO", 5413.20, 350,
      5413.20, 5500.50, 5500.50);

   izd[4] = new VideoKaseta("Top secret", 2503.50, 4513,
      2503.50, 2503.50, 2600.00);
   izd[5] = new VideoKaseta("Doktor Živago", 4250.30, 4245,
      4250.30, 4312.20, 4312.20);
   izd[6] = new VideoKaseta("Samorastniki", 1240.20, 3850,
      1240.20, 1300.30, 1300.30);
   izd[7] = new VideoKaseta("Ko to tamo pjeva", 800.00, 3150,
      800.00, 800.00, 1000.00);

   for (int i = 0; i < 4; i++)
      izd[8 + i] = new Komplet( *((Knjiga *)izd[i]),
               *((VideoKaseta*)izd[4+i]) );

   for (i = 0; i < 12; i++)
   {
      cout << (i + 1) << ": ";
      izd[i]->Izpis();  // pa še vse izpišemo
      // delete izd[i];
      //
      // ZATO, KER RAZRED Komplet NI POPOLNOMA PRAVILNO NAPISAN,
      // S TEM KO ZBRIŠEMO KNJIGO, ŠKODUJEMO TUDI OBJEKTU Komplet,
      // KI TO KNJIGO VSEBUJE
      //
   }

   return 1;
}