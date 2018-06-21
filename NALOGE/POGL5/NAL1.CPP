double potenca(double x, int y = 2)
{
   double pot = 1;      // nekaj na 0 je 1

   for (int i = 0; i < y; i++)
      pot *= x;         // pomnoži y-krat

   return pot;
}

