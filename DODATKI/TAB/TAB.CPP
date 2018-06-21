/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      V vhodni datoteki zamenja vse tabulatorje s presledki

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>

enum ErrorType { 
   OK = 0,        // vse OK
   ArgMissing,    // premalo argumentov 
   FileError,     // napaka z datotekami
   SpaceError     // število presledkov je negativno
};

const char  NewLine = 10;  // nova vrstica, ŠTEVILKA JE ODVISNA OD Oper. sist.
const char  Tab = 9;       // tabulator
const char  Space = 32;    // presledek

void help(char *prgName)
{
   cerr << "Program zamenja vse tabulatorje s presledki." << endl;
   cerr << "Uporaba programa je preprosta..." << endl;
   cerr << "\t" << prgName << " <vhodna dat.> <izhodna dat.> <št. presledkov>";
   cerr << endl << endl;
}

int main(int ArgC, char *ArgV[])
{
   if ( ArgC != 4 ) { 
      help(ArgV[0]); 
      return ArgMissing; 
      }

   ifstream DataIn(ArgV[1]); 
   if ( !DataIn ) {
      cerr << "Ne morem odpreti vhodne datoteke " << ArgV[1] << "." << endl;
      return FileError;
      }

   ofstream DataOut(ArgV[2]); 
   if ( !DataOut ) {
      cerr << "Ne morem odpreti izhodne datoteke " << ArgV[2] << "." << endl;
      return FileError;
      }

   int spaces = atoi(ArgV[3]);
   if (spaces < 0) {
      cerr << "Število presledkov je negativno." << endl;
      return SpaceError;
      }

   int   pos = 0,    // trenutna kolona      
         len = 0,    // potrebna kolièina presledkov
         i;          // pomožna spremenljivka
   char  ch;         // trenuten znak

   DataIn.get(ch); pos = 1;            // preberi prvi znak, kolona = 0
   while ( DataIn ) {
      switch (ch) {
         case NewLine :
            pos = 0;                            // nova vrstica
            DataOut.put(ch);
            break;
         case Tab:
            pos--;                           // tabulator je potrebno ignorirati
            len = spaces - (pos % spaces);   // potrebno število presledkov
            for (i = 0; i < len; i++)        // dodajamo presledke
               DataOut.put(Space);
            pos += len;                      // ustrezno popravimo pozicijo
            break;
         default:
            DataOut.put(ch);
            break;   
      }

      DataIn.get(ch); pos++;        // preberi naslednji znak, poveèaj kolono
   }        

   DataIn.close();
   DataOut.close();

   return OK;
}
   
