/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Delo z bitnimi polji

   OPERACIJSKI SISTEM:
      Na nekaterih boste morali popraviti vrstice z operatorjem
         <<, ki ni popolnoma prenosljiv!
      Èe char zaseda 16 (ali veè) bitov, popraviti tudi vrednost konstante 
         CHAR_LEN.
*/

#ifndef __BITSET_HPP
#define __BITSET_HPP 1

#include <stddef.h>
#include <string.h>

#define CHAR_LEN  8     // število bitov, ki jo zaseda char

class BitSet {
protected :
   unsigned long  _length;
   unsigned char  *_data;

   // Prazen konstruktor
   BitSet()
      {
      _length=0L;
      _data  =NULL;
      }

public:
   // konstruktor, ki doloèi dolžino polja
   BitSet(unsigned long size);
   // prireditveni konstruktor
   BitSet(BitSet &bs);

   // destruktor
   ~BitSet();

   // prireditveni operator
   void operator = (BitSet & bs);

   // velikost polja
   inline unsigned long Size() const
      { return _length; }

   // vkljuèi bit na izbrani poziciji
   inline void Include(unsigned long bit) {
      if (bit<_length)
         _data[bit/CHAR_LEN] |= (unsigned char) (1 << (bit & (CHAR_LEN - 1)));
      }
   // izkljuèi bit na izbrani poziciji
   inline void Exclude(unsigned long bit) {
      if (bit<_length)
         _data[bit/CHAR_LEN] &=~ (unsigned char) (1 << (bit & (CHAR_LEN - 1)));
         }

   // vkljuèi oz. izkljuèi VSE bite
   inline void AllOn()
      { memset(_data,'\xff',(_length+CHAR_LEN-1)/CHAR_LEN); }
   inline void AllOff()
      { memset(_data,'\x00',(_length+CHAR_LEN-1)/CHAR_LEN); }

   // logièni operatorji
   BitSet operator& (BitSet & bs);
   BitSet operator&= (BitSet & bs);

   BitSet operator| (BitSet & bs);
   BitSet operator|= (BitSet & bs);

   BitSet operator^ (BitSet & bs);
   BitSet operator^= (BitSet & bs);

   // kompleementarni operator
   BitSet operator~ ();

   // operator prirejaja
   int operator== (BitSet & bs);
   int operator!= (BitSet & bs);

   // vrne vrednost izbranega bita
   inline int operator[] (unsigned long bit) {
      if (bit<_length)
         return (_data[bit/CHAR_LEN] & (1 << (bit & (CHAR_LEN - 1))));
       else
         return 0;
      }
};

#endif


