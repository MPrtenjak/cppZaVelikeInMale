/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Program podaja anagrame, ki jih morate razvozlati.
      Anagrami se tvorijo iz vhodne datoteke (tekstovne).

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <iostream.h>
#include <stdlib.h>       
#include <string.h>
#include <ctype.h>      // za funkcije is...()
          
#include "zaslon.hpp"   // za delo z zaslonom

// ********
// ********    KONSTANTE
// ********

#define TRUE   1
#define FALSE  0

int   pokvarjen;     // zaporedna številka pokvarjenega hlebca
int   teza;          // teža pokvarjenega hlebca

// 
// izmisli si zaporedno številko in težo pokvarjenega hlebca
//
void inicializiraj()
{
   // nakljuèno izbere, ali naj bo pokvarjeni hlebec lažji ali težji od ostalih
   if ((rand() % 50) > 50) // èe je število veèje od 50, bo hlebec težji
      teza = 1100;
   else
      teza = 900;

   pokvarjen = rand() % 10;
}

//
// najprej preveri ali so v vseh poljih cifre, nato preveri, da v nizu hlebcev 
//    ni kateri hlebec zapisan dvakrat
//
// èe je kaj narobe vrne FALSE, sicer TRUE
//
int preveri(char *hlebci)  
{
   int kolicina = strlen(hlebci);

   for(int i = 0; i < kolicina; i++)
      if ( !isdigit(hlebci[i]) )
         return FALSE;  // v nizu je nekaj, kar ni cifra

   // ALI SO VSI RAZLIÈNI?
   // najpreprostejši algoritem: 
   //    za vsak element preverimo, ali se razlikuje od drugih
   for(i = 0; i < kolicina - 1; i++)
      for(int j = i + 1; j < kolicina; j++)
         if (hlebci[i] == hlebci[j])
            return FALSE;

   return TRUE;
}

//
// vrne težo hlebcev
//
int tezaHlebcev(char *hlebci)
{
   // strchr vrne NULL, èe iskanega znaka ni v nizu
   // ker išèemo znak, moramo napisati pokvarjen + '0'!!!
   if (strchr(hlebci, (pokvarjen + '0')) != NULL)
      return ((strlen(hlebci) - 1)*1000 + teza);   // med hlebci je pokvarjen
   else
      return (strlen(hlebci) * 1000);        // sami dobri (vsi po 1000g)
}

int main()
{
   char  leva[10],   // leva stran tehtnice
         desna[10];  // desna stran tehnice
   int   tezaL,      // teža leve strani
         tezaD;      // teža desne strani

   randomize();   // inicializacija generatorja nakljuènih števil
   
   for(;;) {      // neskonèna zanka
      BrisiZaslon(); 
      inicializiraj();  // izmisli si pokvarjen hlebec
      cout << "S tehtanjem ugotovite, kateri izmed 10 [0..9] hlebcev je";
      cout << " pokvarjen!" << endl << endl;

      for(;;)  {  // dokler ne najde pokvarjenega
         cout << "\tLeva stran tehnice .... ";
         cin.getline(leva, 10);
         while ( !preveri(leva) ) {
            cout << "\t\t NAPAÈEN NIZ !!!" << endl;
            cout << "\tLeva stran tehnice .... ";
            cin.getline(leva, 10);
         }

         cout << "\tDesna stran tehnice ... ";
         cin.getline(desna, 10);
         while ( !preveri(desna) ) {
            cout << "\t\t NAPAÈEN NIZ !!!" << endl;
            cout << "\tDesna stran tehnice ... ";
            cin.getline(desna, 10);
         }

         tezaL = tezaHlebcev(leva);
         tezaD = tezaHlebcev(desna);

         if (tezaL < tezaD) cout << "\t\tLeva stran je lažja!" << endl;
         if (tezaL > tezaD) cout << "\t\tDesna stran je lažja!" << endl;
         if (tezaL == tezaD) cout << "\t\tTeža je enaka!" << endl;

         cout << endl << "Ali ste že našli pokvarjnega [D/N]? ";
         cin.getline(leva, 10);
         if (leva[0] == 'd' || leva[0] == 'D') {   // našel je defektnega
            cout << "\tPokvarjen hlebec nosi zaporedno številko ... ";
            cin.getline(leva, 10);
            int poskus = atoi(leva);   // pretvorimo niz v celo število
            if (poskus == pokvarjen) 
               cout << endl << endl << "BRAVO, ugotovili ste pravilno!";
            else  {
               cout << endl << endl << "Na žalost nepravilno!";
               cout << "\tPokvarjen je " << pokvarjen << ". hlebec, ki tehta ";
               cout << teza << "g.";
            }
            break;   // konec ugotavljanja
         }  // konec stavka if
      }  // konec notranje for(;;) zanke

      cout << endl << "Ali želite še [D/N]? ";
      cin.getline(leva, 10);
      if (leva[0] == 'n' || leva[0] == 'N')
         break;
   }  // konec zunanje for(;;) zanke

   return 1;
}
            
            


         
   
      
   


