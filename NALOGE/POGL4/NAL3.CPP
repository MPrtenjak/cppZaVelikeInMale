/*

   Funkcija spreminja vse niz, dokler ne naleti na znak, ki ni cifra.
   Èe že prvi znak ni število, paè vrne 0!

   NE OPOZORI NA PREKORAÈITEV!
*/
long atol(const char *str)
{
   const char *s = str;
   long  stevilo = 0;

   // '\0' ni cifra, zato je tudi konec niza konec zanke!!
   while ( (*s) >= '0' && (*s) <= '9' ) {    // dokler je cifra
      stevilo *= 10;          // pomnožimo z deset
      stevilo += (*s) - '0';  // in prištejemo tekoèo cifro
      s++;                    // premaknemo kazalec
   }

   return stevilo;
}


