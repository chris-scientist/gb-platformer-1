// author: chris-scientist
// created at: 02/02/2019
// updated at: 10/02/2019

#include "Object.h"

void initObjects(Object * aSet) {
  #if ! DEBUG_PLATFORMER // Mode debug inactif ===========================================
  
  aSet[KEY_OBJECT_ID] = createObject(40, 13, KEY_OBJECT, KEY_ON_THE_PLATFORM);
  aSet[DOOR_OBJECT_ID] = createObject(72, 48, DOOR_OBJECT, DOOR_CLOSED);

  #else // Mode debug actif ==============================================================

  aSet[KEY_OBJECT_ID] = createObject(75, 26, KEY_OBJECT, KEY_ON_THE_PLATFORM);
  aSet[DOOR_OBJECT_ID] = createObject(72, 54, DOOR_OBJECT, DOOR_CLOSED);

  #endif
}

Object createObject(int aX, int aY, int aType, int aState) {
  Object anObject;

  anObject.x = aX;
  anObject.y = aY;
  anObject.type = aType;
  anObject.state = aState;
  
  return anObject;
}
