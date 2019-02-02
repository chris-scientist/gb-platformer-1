// author: chris-scientist
// created at: 02/02/2019

#include "Object.h"

void initObjects(Object * aSet) {
  aSet[0] = createObject(40, 13, KEY_OBJECT, KEY_ON_THE_PLATFORM);
  aSet[1] = createObject(72, 48, DOOR_OBJECT, DOOR_CLOSED);
}

Object createObject(int aX, int aY, int aType, int aState) {
  Object anObject;

  anObject.x = aX;
  anObject.y = aY;
  anObject.type = aType;
  anObject.state = aState;
  
  return anObject;
}
