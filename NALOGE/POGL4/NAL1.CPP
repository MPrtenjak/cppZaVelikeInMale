char *strcat(char *str1, const char *str2)
{
   char  *kc1 = str1;   // kazalec na prvi niz
   const char  *kc2 = str2;   // kazalec na drugi niz

   while( *kc1 ) kc1++; // najdi konec prvega niza

   while ( *kc2 ) {  // dokler ni konec drugega
      *kc1 = *kc2;   // prepi�i iz drugega v prvega
      kc1++; kc2++;  // oba pove�aj
   }

   *(kc1) = '\0';   // na konec '\0' !!!!!

   return str1;
}

char *strchr(char *str, const char ch)
{
   char *kc = str;

   while ( *kc ) { // dokler ni konec
      if ( *kc == ch )  // na�li smo ga
         return kc;
      kc++;             // sicer pove�aj kazalec
   }

   // �e smo pri�li do sem, pomeni, da ga nismo na�li
   return NULL;
}

char *strcpy(char *dest, const char *src)
{
   char  *kc1 = dest;   // kazalec na prvi niz
   const char  *kc2 = src; // kazalec na drugi niz

   while ( *kc2 ) {  // dokler ni konec drugega
      *kc1 = *kc2;   // prepi�i iz drugega v prvega
      kc1++; kc2++;  // oba pove�aj
   }

   *(kc1) = '\0';   // na konec '\0' !!!!!

   return dest;
}

int strcmp(const char *s1, const char *s2)
{
   const char  *kc1 = s1,
               *kc2 = s2;

   while ( *kc1 && *kc2 ) {
      if ( *kc1 > *kc2)    // �e je prvi ve�ji vrni 1
         return 1;
      if ( *kc1 < *kc2 )   // �e je drugi ve�ji vrni -1
         return -1;
      kc1++; kc2++;        // sicer samo oba pove�aj
   }
   // na tem mestu je enega (ali obeh nizov) konec

   if ( *kc1 )    // �e �e ni konec prvega niza
      return 1;

   if ( *kc2 )    // �e �e ni konec drugega niza
      return -1;

   return 0;      // niza sta enaka
}

