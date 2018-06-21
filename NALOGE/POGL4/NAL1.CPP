char *strcat(char *str1, const char *str2)
{
   char  *kc1 = str1;   // kazalec na prvi niz
   const char  *kc2 = str2;   // kazalec na drugi niz

   while( *kc1 ) kc1++; // najdi konec prvega niza

   while ( *kc2 ) {  // dokler ni konec drugega
      *kc1 = *kc2;   // prepiši iz drugega v prvega
      kc1++; kc2++;  // oba poveèaj
   }

   *(kc1) = '\0';   // na konec '\0' !!!!!

   return str1;
}

char *strchr(char *str, const char ch)
{
   char *kc = str;

   while ( *kc ) { // dokler ni konec
      if ( *kc == ch )  // našli smo ga
         return kc;
      kc++;             // sicer poveèaj kazalec
   }

   // èe smo prišli do sem, pomeni, da ga nismo našli
   return NULL;
}

char *strcpy(char *dest, const char *src)
{
   char  *kc1 = dest;   // kazalec na prvi niz
   const char  *kc2 = src; // kazalec na drugi niz

   while ( *kc2 ) {  // dokler ni konec drugega
      *kc1 = *kc2;   // prepiši iz drugega v prvega
      kc1++; kc2++;  // oba poveèaj
   }

   *(kc1) = '\0';   // na konec '\0' !!!!!

   return dest;
}

int strcmp(const char *s1, const char *s2)
{
   const char  *kc1 = s1,
               *kc2 = s2;

   while ( *kc1 && *kc2 ) {
      if ( *kc1 > *kc2)    // èe je prvi veèji vrni 1
         return 1;
      if ( *kc1 < *kc2 )   // èe je drugi veèji vrni -1
         return -1;
      kc1++; kc2++;        // sicer samo oba poveèaj
   }
   // na tem mestu je enega (ali obeh nizov) konec

   if ( *kc1 )    // èe še ni konec prvega niza
      return 1;

   if ( *kc2 )    // èe še ni konec drugega niza
      return -1;

   return 0;      // niza sta enaka
}

