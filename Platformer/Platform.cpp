// author: chris-scientist
// created at: 30/01/2019
// updated at: 10/02/2019

#include "Platform.h"

void initPlatforms(Platform * aSet) {
  #if ! DEBUG_PLATFORMER // Mode debug inactif ===========================================
  
  aSet[0] = createPlatform(4, 59, 10, GROUND_TYPE, ID_GROUND, false);
  aSet[1] = createPlatform(4, 46, 3, HILL_TYPE, ID_HILL_1, true);
  aSet[2] = createPlatform(60, 46, 3, HILL_TYPE, ID_HILL_2, true);
  aSet[3] = createPlatform(24, 20, 5, PLATFORM_TYPE, ID_PLATFORM_1, false);

  #else // Mode debug actif ==============================================================

  aSet[0] = createPlatform(4, 62, 10, GROUND_TYPE, ID_GROUND, false);
  aSet[1] = createPlatform(4, 50, 2, PLATFORM_TYPE, ID_PLATFORM_1, true);
  aSet[2] = createPlatform(35, 40, 2, PLATFORM_TYPE, ID_PLATFORM_2, false);
  aSet[3] = createPlatform(68, 30, 2, PLATFORM_TYPE, ID_PLATFORM_3, false);

  #endif
}

Platform createPlatform(int aX, int aY, int aLength, int aType, int aId, bool goThrough) {
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
  aPlatform.id = aId;
  aPlatform.isGoThrough = goThrough;
  
  return aPlatform;
}

Platform getPlatformFromId(const int aId, Platform * aSet) {

  for(int i = 0 ; i < NB_OF_PLATFORMS ; i++) {
    if(aSet[i].id == aId) {
      return aSet[i];
    }
  }

  Platform nullPlatform;
  nullPlatform.id = NO_ID;
  return nullPlatform;
}
