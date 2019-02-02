// author: chris-scientist
// created at: 02/02/2019

#ifndef PLATFORMER_OBJECT
#define PLATFORMER_OBJECT

#include "Constantes.h"

struct Object {
  int x;
  int y;
  int type; // .... type d'objet : voir constantes
  int state; // ... état de l'objet voir constantes
};

void initObjects(Object * aSet);
Object createObject(int aX, int aY, int aType, int aState);

#endif
