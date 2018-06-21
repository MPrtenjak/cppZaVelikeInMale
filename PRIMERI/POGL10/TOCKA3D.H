#ifndef __TOCKA3D_H
#define __TOCKA3D_H

#include "tocka.h"

class Tocka3D : public Tocka {
protected:
   float z;

public:
   void SetZ(float zz) { z = zz; }

   void Izpisi();
};

#endif


