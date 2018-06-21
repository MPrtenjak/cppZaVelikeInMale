/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Delo z nizi znakov

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#ifndef __STRING_HPP
#define __STRING_HPP 1

#include <iostream.h>

enum StrCompVal   { SC_LESS, SC_EQUAL, SC_GREATER, SC_ERROR };
enum StrCompMode  { SM_SENSITIVE, SM_IGNORE };
enum StrError     { SE_ALLOC, SE_TOO_LONG };

class String {
protected :
   unsigned int _size;  // allocated size
   unsigned int _len;   // current lenght
   
   char  *_text;     // pointer to text

   static unsigned int AllocIncr;

   // pointer to exception handler
   static void (*ErrorHandler)(StrError err);

   void Shrink();

public :
   String();
   String(const String &str);
   String(const char   *cstr);
   String(char fillCh,unsigned int count);

   ~String()
      { delete [] _text; }

   unsigned int Length() const
      { return _len; }
   unsigned int Size() const
      { return _size; }

   operator char * ()
      { return _text;   }

   static void SetErrorHandler(void (* userHandler)(StrError))
      { ErrorHandler=userHandler; }

   void operator = (const String &str);

   friend String operator + (const String &str1, const String &str2);
   void operator += (const String &str);

   int operator < (const String &str) const    
      { return (Compare(str) == SC_LESS); }
   int operator > (const String &str) const
      { return (Compare(str) == SC_GREATER); }
   int operator <= (const String &str) const
      { return (Compare(str) != SC_GREATER); }
   int operator >= (const String &str) const
      { return (Compare(str) != SC_LESS); }
   int operator == (const String &str) const
      { return (Compare(str) == SC_EQUAL); }
   int operator != (const String &str) const
      { return (Compare(str) != SC_EQUAL); }

   StrCompVal Compare(const String &str,StrCompMode caseChk=SM_IGNORE) const;

   int Find(const String &str, unsigned int &pos,
      StrCompMode caseChk=SM_IGNORE) const;

   int Find_Repl(const String &find_str, const String &repl_str,
         unsigned int &pos, StrCompMode caseChk=SM_IGNORE);

   void Delete(unsigned int pos, unsigned int count);

   void Insert(unsigned int pos, char ch);
   void Insert(unsigned int pos, const String &str);

   String SubStr(unsigned int start, unsigned int count);

   // pos == first (NON BLANK) character in SECOND word
   int FindFirst(unsigned int &pos) const;

   // pos == last (NON BLANK) character in pre-last word
   int FindLast(unsigned int &pos) const;

   // word -deliting methods
   String DelFirst(void);
   String DelLast(void);

   char operator [] (unsigned int pos)
      { return (pos >=_len) ? '\x00' : _text[pos]; }

   String ToUpper();
   String ToLower();
};

#endif
