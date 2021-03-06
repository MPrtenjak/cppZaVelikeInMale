/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matja� Prtenjak

   NAMEN:
      Preprost skladovni kalkulator

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <ctype.h>   // deklaracije is...() funkcij
#include <string.h>  // deklaracije str...() funkcij
#include <math.h>    // deklaracije matemati�nih funkcij

const int MaxElem=100;  // maksimalno �tevilo elementov
const int MaxLine=100;  // maksimalno �tevilo znakov pri vnosu

enum ErrorType { Unknown = 0, ParameterMissing = 1, DivByZerro = 2 };

class Error {
public:
   ErrorType type;   // tip napake

   Error(int typ)    // konstruktor postavi tip
      { type = (ErrorType) typ; }

   friend ostream& operator<<( ostream& OutStream, Error err);
};

ostream& operator<<( ostream& OutStream, Error err)
{
   switch (err.type) {
      case Unknown :
         OutStream << "NAPAKA: Ne poznam ukaza ! " << endl << endl;
         break;
      case ParameterMissing:
         OutStream << "NAPAKA: Premalo parametrov za ta ukaz ! " << endl << endl;
         break;
      case DivByZerro:
         OutStream << "NAPAKA: Deljenje z 0 ! " << endl << endl;
         break;
   }

   return OutStream;
}

class Calc {
protected:
   double element[ MaxElem ]; // tabela z elementi
   int used;   // koliko elementov je zapolnjenih

   void Init();
   void Add( float num )
      { element[used] = num; used++; }

public:
   Calc() { Init(); }

   int Input(char *Line);
   void help();

   friend ostream& operator<<( ostream& OutStream, Calc clc);
};

void Calc::Init() // za�etne vrednosti
{
   used = 0;
   for (int i = 0; i < MaxElem; i++)
      element[i] = 0.0;
}

int Calc::Input(char *Line)
{
   char tmpLine[ MaxLine ];

   for(char *l = Line; isspace(*l); l++); // presko�i vodilne presledke
   strcpy(tmpLine, l);

   // �e je prvi znak �tevilo ali decimalna pika, dodaj �tevilo
   if ( isdigit(tmpLine[0]) || tmpLine[0] == '.' ) {
      Add( atof(tmpLine) );
      return (0);
      }
   else {   // sicer je opereator
      if ( isalpha(tmpLine[0]) ) {  // ali je prvi znak �rka
         if (strcmpi(tmpLine, "exit") == 0) return(1);

         if (strcmpi(tmpLine, "sin") == 0) {
            if (used < 1) throw (Error(1));
            element[used-1] = sin (element[used-1]);
            return(0); }
         if (strcmpi(tmpLine, "cos") == 0) {
            if (used < 1) throw (Error(1));
            element[used-1] = cos (element[used-1]);
            return(0); }
         if (strcmpi(tmpLine, "PI") == 0) {
            Add(M_PI);  // doda [tevilo PI
            return(0); }


         throw (Error(0));
         }
      else {  // prvi znak ni �rka
         switch (tmpLine[0]) {
            case '+' :  if (used < 2) throw (Error(1));
                        element[used-2] += element[used-1];
                        used--; return(0);
            case '-' :  if (used < 2) throw (Error(1));
                        element[used-2] -= element[used-1];
                        used--; return(0);
            case '*' :  if (used < 2) throw (Error(1));
                        element[used-2] *= element[used-1];
                        used--; return(0);
            case '/' :  if (used < 2) throw (Error(1));
                        if (element[used-1] == 0.0) throw (Error(2));
                        element[used-2] /= element[used-1];
                        used--; return(0);
            case '?' :  help();
                        return(0);
            default:
               throw (Error(0));
            } // konc switch
         }  // konec else
   }  // konec else
}

void Calc::help()
{
   cout << "Za konec vpi�ite 'exit'" << endl << endl;
}
   
ostream& operator<<( ostream& OutStream, Calc clc)
{
   OutStream << endl;
   for (int i = 0; i < clc.used; i++)
      OutStream << (clc.used - i) << ": " << clc.element[i] << endl;
   OutStream << "--------------------" << endl;

   return OutStream;
}

int main()
{
   Calc clc;
   char Line[ MaxLine ];
   int  exit = 0;

   for(;!exit;) { // ponavljaj dokler je exit enak 0 (false)
      cout << clc;   // izpi�emo vrednosti v kalkulatorju
      cout << ">> ";
      cin >> Line;   // vpi�i niz
      try {
         exit = clc.Input( Line );  // izra�unaj
         }
      catch ( Error err ) {   // �e je pri�lo do napake
         cout << err;   // jo izpi�i
         }
      }

   return (1);
}








