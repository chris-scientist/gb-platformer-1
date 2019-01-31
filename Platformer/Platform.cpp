// author: chris-scientist
// created at: 30/01/2019
// updated at: 31/01/2019

#include "Platform.h"

void initPlatforms(Platform * aSet) {
  aSet[0] = createPlatform(4, 59, 10, 1);
  aSet[1] = createPlatform(4, 46, 3, 2);
  aSet[2] = createPlatform(60, 46, 3, 2);
  aSet[3] = createPlatform(24, 20, 5, 3);
}

Platform createPlatform(int aX, int aY, int aLength, int aType) {
  // on force la taille de la plateforme à 2 bloc
  if(aLength < 2) {
    aLength = 2;
  }

  // on force le type de plateforme à 3 (plateforme flottante)
  if(aType < 1 || aType > 3) {
    aType = 3;
  }

  // création de la plateforme
  Platform aPlatform;
  aPlatform.x = aX;
  aPlatform.y = aY;
  aPlatform.lengthPlatform = aLength;
  aPlatform.type = aType;
  
  return aPlatform;
}
