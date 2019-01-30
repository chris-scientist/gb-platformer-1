// author: chris-scientist
// created at: 30/01/2019

#include "Platform.h"

void initPlatforms(Platform * aSet) {
  aSet[0] = buildPlatform(33, 21, 10);
  aSet[1] = buildPlatform(3, 31, 3);
  aSet[2] = buildPlatform(25, 45, 4);
}

Platform buildPlatform(int aX, int aY, int aLength) {
  // on force la taille de la plateforme à 2 bloc
  if(aLength < 2) {
    aLength = 2;
  }

  // création de la plateforme
  Platform aPlatform;
  aPlatform.x = aX;
  aPlatform.y = aY;
  aPlatform.lengthPlatform = aLength;
  
  return aPlatform;
}
