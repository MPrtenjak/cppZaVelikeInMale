/*

   Funkcija spreminja vse niz, dokler ne naleti na znak, ki ni cifra.
   �e �e prvi znak ni �tevilo, pa� vrne 0!

   NE OPOZORI NA PREKORA�ITEV!
*/
long atol(const char *str)
{
   const char *s = str;
   long  stevilo = 0;

   // '\0' ni cifra, zato je tudi konec niza konec zanke!!
   while ( (*s) >= '0' && (*s) <= '9' ) {    // dokler je cifra
      stevilo *= 10;          // pomno�imo z deset
      stevilo += (*s) - '0';  // in pri�tejemo teko�o cifro
      s++;                    // premaknemo kazalec
   }

   return stevilo;
}


