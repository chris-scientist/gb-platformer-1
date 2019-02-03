// author: chris-scientist
// created at: 30/01/2019
// updated at: 03/02/2019

#include "Platform.h"

void initPlatforms(Platform * aSet) {
  #if ! DEBUG_PLATFORMER // Mode debug inactif ===========================================
  
  aSet[0] = createPlatform(4, 59, 10, GROUND_TYPE, false);
  aSet[1] = createPlatform(4, 46, 3, HILL_TYPE, true);
  aSet[2] = createPlatform(60, 46, 3, HILL_TYPE, true);
  aSet[3] = createPlatform(24, 20, 5, PLATFORM_TYPE, false);

  #else // Mode debug actif ==============================================================

  aSet[0] = createPlatform(4, 59, 10, GROUND_TYPE, false);
  aSet[1] = createPlatform(4, 47, 2, PLATFORM_TYPE, true);
  aSet[2] = createPlatform(35, 37, 2, PLATFORM_TYPE, false);
  aSet[3] = createPlatform(68, 27, 2, PLATFORM_TYPE, false);

  #endif
}

Platform createPlatform(int aX, int aY, int aLength, int aType, bool goThrough) {
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
  aPlatform.isGoThrough = goThrough;
  
  return aPlatform;
}
