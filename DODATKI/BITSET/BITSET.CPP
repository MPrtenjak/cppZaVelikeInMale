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

#include "bitset.hpp"

// konstruktrji
BitSet::BitSet(unsigned long size)
{
   _length = size;
   unsigned long alloc = (size+CHAR_LEN-1)/CHAR_LEN;
   _data = new unsigned char[(unsigned int) alloc];
   memset(_data, '\x00', (unsigned int) alloc);
}

BitSet::BitSet(BitSet &bs)
{
   _length = bs._length;
   unsigned long alloc = (bs._length+CHAR_LEN-1)/CHAR_LEN;
   _data = new unsigned char[(unsigned int) alloc];
   memcpy(_data,bs._data,(unsigned int) alloc);
}

// destruktor
BitSet::~BitSet(void)
{
   if (_data != NULL)
      delete [] _data;
}

// operator prirejanja
void BitSet::operator= (BitSet &bs)
{
   if (_length != bs._length)
      {
      _length = bs._length;
      unsigned long alloc = (bs._length+CHAR_LEN-1)/CHAR_LEN;

      if (_data != NULL)
            delete _data;

      _data = new unsigned char[(unsigned int) alloc];
      memcpy(_data,bs._data,(unsigned int) alloc);
      }
   else
      memcpy(_data,bs._data,(unsigned int) ((_length+CHAR_LEN-1) / CHAR_LEN));
}

BitSet BitSet::operator& (BitSet &bs)
{
   BitSet result;
   unsigned long max;

   if (_length>bs._length)
      {
      result = BitSet(_length);
      max = bs._length;
      }
   else
      {
      result = BitSet(bs._length);
      max = _length;
      }

   for (unsigned long bit = 0;  bit < max; bit++)
      if ((*this)[bit] & bs[bit])
         result.Include(bit);

   return result;
}

BitSet BitSet::operator&=  (BitSet &bs)
{
   *this = *this & bs;
   return *this;
}

BitSet BitSet::operator| (BitSet &bs)
{
   BitSet result;
   unsigned long bit;

   if (_length<bs._length)
      {
      result = bs;

      for(bit = 0; bit<_length; bit++)
            if ((*this)[bit])
               result.Include(bit);
      }
   else
      {
      result = *this;

      for (bit = 0; bit<bs._length; bit++)
         if (bs[bit])
               result.Include(bit);
      }

   return result;
}

BitSet BitSet::operator|=  (BitSet &bs)
{
   *this = *this | bs;
   return *this;
}

BitSet BitSet::operator^ (BitSet &bs)
{
   BitSet result;
   unsigned long max;

   if (_length>bs._length)
      {
      result = BitSet(_length);
      max = bs._length;
      }
   else
      {
      result = BitSet(bs._length);
      max = _length;
      }

   for (unsigned long bit = 0;bit<max;bit++)
      if ((*this)[bit] ^ bs[bit])
         result.Include(bit);

   return result;
}

BitSet BitSet::operator^=  (BitSet &bs)
{
   *this = *this ^ bs;
   return *this;
}

// complement operator
BitSet BitSet::operator~ ()
{
   BitSet result(_length);

   for (unsigned long bit = 0;bit<_length;bit++)
      if ((*this)[bit])
         result.Exclude(bit);
      else
         result.Include(bit);

   return result;
}

// comparison operators
int BitSet::operator== (BitSet &bs)
{
   if (_length != bs._length) return 0;

   for (unsigned long bit = 0; bit<_length; bit++)
      if ((*this)[bit] !=  bs[bit])
         return 0;

   return 1;
}

int BitSet::operator!=  (BitSet &bs)
{
   if (_length != bs._length) return 1;

   unsigned long bit = 0;

   while (bit < 
   _length)
      if ((*this)[bit]  ==  bs[bit])
         ++bit;
      else
         return 1;

   return 0;
}
