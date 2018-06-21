/*
   Eden izmed dodanih primerov h knjigi "C++ za velike in male"

   AVTOR:
      Matjaž Prtenjak

   NAMEN:
      Delo z nizi znakov

   OPERACIJSKI SISTEM:
      Vsi operacijski sistemi
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#include "Str.hpp"

// prototype for default error handler
static void DefaultHandler(StrError err);

// class-global constant initialization
unsigned int String::AllocIncr=8;
void (*(String::ErrorHandler))(StrError) = DefaultHandler;

// default error handler
static void DefaultHandler(StrError err)
{   printf("\a ERROR in String object : ");

    switch(err) {
       case SE_ALLOC :
       printf("memory allocation faliure\n");
       break;
       case SE_TOO_LONG :
       printf("exceeded %d character limit\n",UINT_MAX);
       break;
    }

    exit(1);
}

// private function to shrink the size of an allocated string
void String::Shrink()
{    char *temp;

     if ((_size-_len) > AllocIncr) {
   _size=((_len+AllocIncr) / AllocIncr) * AllocIncr;

   temp=new char[_size];
   if (temp!=NULL) {
      strcpy(temp,_text);
      delete [] _text;
      _text=temp; }
       else
      ErrorHandler(SE_ALLOC);
     }
}

// constructors
String::String()
{   _len=0;
    _size=AllocIncr;

    _text=new char[_size];

    if (_text==NULL)
       ErrorHandler(SE_ALLOC);

    _text[0]='\x00';
}

String::String(const String &str)
{   _len=str._len;
    _size=str._size;

    _text=new char[_size];

    if (_text==NULL)
       ErrorHandler(SE_ALLOC);

    strcpy(_text,str._text);
}

String::String(const char *cstr)
{   if ((cstr==NULL) || (cstr[0]=='\x00')) {
       _len=0;
       _size=AllocIncr; }
    else {
       _len=strlen(cstr);
       _size=((_len+AllocIncr) / AllocIncr) * AllocIncr; }

    _text=new char[_size];

    if (_text==NULL)
       ErrorHandler(SE_ALLOC);

       if (_len>0)
     strcpy(_text,cstr);
       else
     _text[0]='\x00';
}

String::String(char fillCh, unsigned int count)
{   _size=((count + AllocIncr) / AllocIncr) * AllocIncr;
    _len=count;

    _text=new char[_size];

    if (_text==NULL)
       ErrorHandler(SE_ALLOC);

    memset(_text,fillCh,count);

    _text[count]='\x00';
}

// assigment method
void String::operator = (const String &str)
{   _len=str._len;
    _size=str._size;

    delete []  _text;

    _text=new char[_size];

    if (_text==NULL)
       ErrorHandler(SE_ALLOC);

    strcpy(_text,str._text);
}

String operator + (const String &str1, const String &str2)
{   unsigned int  newSize;
    String    tempStr;
    char      *temp;

    if ((long)(str1._len+str2._len) > UINT_MAX)
       String::ErrorHandler(SE_TOO_LONG); // it is friend !!!!

    newSize=str1._size+str2._size;

    if ((temp=new char[newSize]) == NULL)
       String::ErrorHandler(SE_ALLOC);    // it is friend !!!!

    strcpy(temp,str1._text);
    strcpy(&temp[str1._len],str2._text);

    tempStr = temp;

    return tempStr;
}

void String::operator += (const String &str)
{   unsigned long totallen;
    unsigned int  newLen,
        newSize;
    char      *temp;

    if ((totallen=str._len+_len) > UINT_MAX)
       String::ErrorHandler(SE_TOO_LONG); // it is friend !!!!

    newLen = (unsigned int) totallen;
    newSize=str._size+_size;

    if ((temp=new char[newSize]) == NULL)
       String::ErrorHandler(SE_ALLOC);    // it is friend !!!!

    strcpy(temp,_text);

    delete []  _text;

    _text=temp;

    strcpy(&_text[_len],str._text);
    _len=newLen;
    _size=newSize;

    Shrink();
}

StrCompVal String::Compare(const String &str, StrCompMode caseChk) const
{   char *tempStr1,
         *tempStr2;
    int  len1, len2;
    StrCompVal compVal;

    len1 = strlen(_text);
    len2 = strlen(str._text);
    if ((tempStr1 = new char[len1 + 1]) == NULL )
       ErrorHandler(SE_ALLOC);
    if ((tempStr2 = new char[len2 + 1]) == NULL )
       ErrorHandler(SE_ALLOC);
    strcpy(tempStr1, _text);
    strcpy(tempStr2, str._text);

    if (caseChk == SM_IGNORE) {
       strupr(tempStr1);
       strupr(tempStr2); }

    int err=strcmp(tempStr1,tempStr2);
    if (err<0) compVal = SC_LESS;
    else if (err>0) compVal = SC_GREATER;
    else compVal = SC_EQUAL;

    delete []  tempStr1;
    delete []  tempStr2;

    return compVal;
}

// substring search methods
int String::Find(const String &str,unsigned int &pos, StrCompMode caseChk) const 
{   char *tempStr1,
    *tempStr2;
    unsigned int lastPos,
       searchLen,
       tempPos;
    int found;

    if ((tempStr1=strdup(_text)) == NULL )
       ErrorHandler(SE_ALLOC);
    if ((tempStr2=strdup(str._text)) == NULL)
       ErrorHandler(SE_ALLOC);
    if (caseChk == SM_IGNORE) {
       strupr(tempStr1);
       strupr(tempStr2); }

    tempPos    = pos;
    found   = 0;
    searchLen  = str._len;

    if (searchLen > _len) {
       delete []  tempStr1;
       delete []  tempStr2;
       return found;      }
    else
       lastPos    = _len - searchLen;

    while ((tempPos <= lastPos) && !found) {
     if (strncmp(&tempStr1[tempPos],tempStr2,searchLen) == 0 ) {
        pos = tempPos;
        found = 1; }
     else
        ++tempPos;
    }

    delete []  tempStr1;
    delete []  tempStr2;

    return found;
}

// substring search and replace methods
int String::Find_Repl(const String &find_str, const String &repl_str,
            unsigned int &pos, StrCompMode caseChk)
{   if (Find(find_str,pos,caseChk))
       { Delete(pos,find_str._len);
    Insert(pos,repl_str);
    return 1; }
    else
       return 0;
}

// substring deletion method
void String::Delete(unsigned int pos, unsigned int count)
{    unsigned int copyPos;

     if (pos>_len)
   return;
     copyPos = pos + count;

     if (copyPos >= _len)
   _text[pos]=0;
     else
   while (copyPos <= _len +1) {
         _text[pos]=_text[copyPos];
         ++pos;
         ++copyPos; }

     _len -= count;

     Shrink();
}

// substring insertion method
void String::Insert(unsigned int pos, char ch)
{    char *temp;

     if (pos>_len)
   return;

     if (_len +1 == _size) {
   _size+=AllocIncr;
   if ((temp = new char[_size]) == NULL)
      ErrorHandler(SE_ALLOC);

   strcpy(temp,_text);
   _text = temp; }

     for(unsigned int col = _len +1; col > pos; --col)
   _text[col] = _text[col-1];

     _text[pos] = ch;
     ++_len;
     _text[_len+1]='\x00';
}

void String::Insert(unsigned int pos, const String &str)
{    unsigned long totallen = str._len + _len;

     if (totallen>UINT_MAX)
   ErrorHandler(SE_TOO_LONG);

     unsigned int Slen = str._len;
     if (Slen > 0)
   for(unsigned int i = 0; i < Slen; ++i) {
      Insert(pos,str._text[i]);
      ++pos; }
}

// substring retrival method
String String::SubStr(unsigned int start, unsigned int count)
{   String tempStr;
    char   *temp;

    if ((start < _len) && (count > 0)) {
       temp = new char[count+1];
       memcpy(temp,&_text[start],count);
       temp[count] = '\x00'; }
    else
       temp="";

    tempStr=temp;

    return tempStr;
}

// word -searching methods
// pos == first (NON BLANK) character in SECOND word
int String::FindFirst(unsigned int &pos) const
{   pos=0;

    while ((_text[pos]==' ') && (pos<_len)) pos++;
    if (pos==_len) return 0;
    while ((_text[pos]!=' ') && (pos<_len)) pos++;
    while ((_text[pos]==' ') && (pos<_len)) pos++;
    return 1;
}

// pos == last (NON BLANK) character in pre-last word
int String::FindLast(unsigned int &pos) const
{   pos = _len-1;

    if (pos<1) return 0;
    while ((_text[pos]==' ') && (pos>0)) pos--;
    if (pos==0) return 0;
    while ((_text[pos]!=' ') && (pos>0)) pos--;
    return 1;
}

// word -deliting methods
String String::DelFirst(void)
{   String tempStr;
    unsigned int pos;

    if (FindFirst(pos) != 0 ) {
       tempStr=SubStr(0,pos);
       Delete(0,pos); }
    else
       tempStr="";

    return tempStr;
}

String String::DelLast(void)
{   String tempStr;
    unsigned int pos;

    if (FindLast(pos) != 0 ) {
       tempStr=SubStr(pos,_len);
       Delete(pos,_len-pos); }
    else
       tempStr="";

    return tempStr;
}

// case modification method
String String::ToUpper()
{   String tempStr=*this;

    strupr(tempStr._text);

    return tempStr;
}

String String::ToLower()
{   String tempStr=*this;

    strlwr(tempStr._text);

    return tempStr;
}
