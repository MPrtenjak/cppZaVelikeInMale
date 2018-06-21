long sekunde(int ure, int minute, int sekunde)
{
   long SkupajSekunde = sekunde;

   SkupajSekunde += ( 60 * (long)minute);
   SkupajSekunde += ( 60 * 60 * (long)ure);  // da ne pride do prekoraèitve
         // sicer e pri 10 urah preide do prekoraèitve:
         // 60*60*10 = 36000, kar je veè kot 32767, kot lahko vsebuje int

   return SkupajSekunde;
}

