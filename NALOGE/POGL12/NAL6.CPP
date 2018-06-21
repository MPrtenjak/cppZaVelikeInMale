/*
   Klasièni UNIX program WC - word count
*/

#include <iostream.h>
#include <fstream.h>


main(int ArgC, char *ArgV[])
{
   ofstream Izhod( ArgV[ArgC - 1] );   // zadnja je izhodna
   if (!Izhod) {
      cerr << "Ne morem odpreti datoteke " << ArgV[ArgC-1] << "!\n";
      return 2;
   }

   for(int i = 1; i < ArgC - 1; i++) { // vsi vmesni parametri
      ifstream Vhod( ArgV[i] );
      if ( !Vhod ) {
         cerr << "Ne morem odpreti datoteke " << ArgV[i] << "!\n";
         continue;   // poskusi z naslednjo
      }

      char ch;

      Vhod.get(ch);     // ZELO ZELO slaba rešitev. Za resno uporabo
      while( Vhod ) {   // se v pomnilnik prebere in nato zapiše
         Izhod.put(ch); // celoten sektor diska ali kaj podobnega...
         Vhod.get(ch);  // Zatorej spet povdarjam, da so tu podane 
      }                 // najtrivialnejše rešitve

      Vhod.close();
   }

   return 1;
}
