/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matja� Prtenjak

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

int   pokvarjen;     // zaporedna �tevilka pokvarjenega hlebca
int   teza;          // te�a pokvarjenega hlebca

// 
// izmisli si zaporedno �tevilko in te�o pokvarjenega hlebca
//
void inicializiraj()
{
   // naklju�no izbere, ali naj bo pokvarjeni hlebec la�ji ali te�ji od ostalih
   if ((rand() % 50) > 50) // �e je �tevilo ve�je od 50, bo hlebec te�ji
      teza = 1100;
   else
      teza = 900;

   pokvarjen = rand() % 10;
}

//
// najprej preveri ali so v vseh poljih cifre, nato preveri, da v nizu hlebcev 
//    ni kateri hlebec zapisan dvakrat
//
// �e je kaj narobe vrne FALSE, sicer TRUE
//
int preveri(char *hlebci)  
{
   int kolicina = strlen(hlebci);

   for(int i = 0; i < kolicina; i++)
      if ( !isdigit(hlebci[i]) )
         return FALSE;  // v nizu je nekaj, kar ni cifra

   // ALI SO VSI RAZLI�NI?
   // najpreprostej�i algoritem: 
   //    za vsak element preverimo, ali se razlikuje od drugih
   for(i = 0; i < kolicina - 1; i++)
      for(int j = i + 1; j < kolicina; j++)
         if (hlebci[i] == hlebci[j])
            return FALSE;

   return TRUE;
}

//
// vrne te�o hlebcev
//
int tezaHlebcev(char *hlebci)
{
   // strchr vrne NULL, �e iskanega znaka ni v nizu
   // ker i��emo znak, moramo napisati pokvarjen + '0'!!!
   if (strchr(hlebci, (pokvarjen + '0')) != NULL)
      return ((strlen(hlebci) - 1)*1000 + teza);   // med hlebci je pokvarjen
   else
      return (strlen(hlebci) * 1000);        // sami dobri (vsi po 1000g)
}

int main()
{
   char  leva[10],   // leva stran tehtnice
         desna[10];  // desna stran tehnice
   int   tezaL,      // te�a leve strani
         tezaD;      // te�a desne strani

   randomize();   // inicializacija generatorja naklju�nih �tevil
   
   for(;;) {      // neskon�na zanka
      BrisiZaslon(); 
      inicializiraj();  // izmisli si pokvarjen hlebec
      cout << "S tehtanjem ugotovite, kateri izmed 10 [0..9] hlebcev je";
      cout << " pokvarjen!" << endl << endl;

      for(;;)  {  // dokler ne najde pokvarjenega
         cout << "\tLeva stran tehnice .... ";
         cin.getline(leva, 10);
         while ( !preveri(leva) ) {
            cout << "\t\t NAPA�EN NIZ !!!" << endl;
            cout << "\tLeva stran tehnice .... ";
            cin.getline(leva, 10);
         }

         cout << "\tDesna stran tehnice ... ";
         cin.getline(desna, 10);
         while ( !preveri(desna) ) {
            cout << "\t\t NAPA�EN NIZ !!!" << endl;
            cout << "\tDesna stran tehnice ... ";
            cin.getline(desna, 10);
         }

         tezaL = tezaHlebcev(leva);
         tezaD = tezaHlebcev(desna);

         if (tezaL < tezaD) cout << "\t\tLeva stran je la�ja!" << endl;
         if (tezaL > tezaD) cout << "\t\tDesna stran je la�ja!" << endl;
         if (tezaL == tezaD) cout << "\t\tTe�a je enaka!" << endl;

         cout << endl << "Ali ste �e na�li pokvarjnega [D/N]? ";
         cin.getline(leva, 10);
         if (leva[0] == 'd' || leva[0] == 'D') {   // na�el je defektnega
            cout << "\tPokvarjen hlebec nosi zaporedno �tevilko ... ";
            cin.getline(leva, 10);
            int poskus = atoi(leva);   // pretvorimo niz v celo �tevilo
            if (poskus == pokvarjen) 
               cout << endl << endl << "BRAVO, ugotovili ste pravilno!";
            else  {
               cout << endl << endl << "Na �alost nepravilno!";
               cout << "\tPokvarjen je " << pokvarjen << ". hlebec, ki tehta ";
               cout << teza << "g.";
            }
            break;   // konec ugotavljanja
         }  // konec stavka if
      }  // konec notranje for(;;) zanke

      cout << endl << "Ali �elite �e [D/N]? ";
      cin.getline(leva, 10);
      if (leva[0] == 'n' || leva[0] == 'N')
         break;
   }  // konec zunanje for(;;) zanke

   return 1;
}
            
            


         
   
      
   


