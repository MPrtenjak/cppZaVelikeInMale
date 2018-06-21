#ifndef __TOCKA_H
#define __TOCKA_H

class Tocka {
public:
   float x, y;

   void SetX(float xx)
   { x = xx; }
   void SetY(float);

   void Izpisi();
};

inline void Tocka::SetY(float yy)   // ta funkcija je vrinjena
{ y = yy; }          // zato mora biti zapisana v zaglavju

#endif



