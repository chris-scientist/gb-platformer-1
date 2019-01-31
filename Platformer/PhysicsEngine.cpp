// author: chris-scientist
// created at: 30/01/2019
// updated at: 31/01/2019

#include "PhysicsEngine.h"

// Si le personnage chute alors on renvoie true, false sinon
bool gravity(Character &aCharacter, Platform * aSet) {
  bool isFall = false;
  
  if(! isOnOnePlatform(aCharacter, aSet) ) {
    aCharacter.y += GRAVITY;
    isFall = true;
  }

  return isFall;
}

bool isOnOnePlatform(Character aCharacter, Platform * aSet) {
  for(int i = 0 ; i < NB_OF_PLATFORMS ; i++) {
    if(isOnThePlatform(aCharacter, aSet[i])) {
      return true;
    }
  }
  return false;
}

bool isOnThePlatform(Character aCharacter, Platform aPlatform) {
  int xCharacter = aCharacter.x - OVER_CENTER_X_HERO;
  int yCharacter = aCharacter.y - OVER_CENTER_Y_HERO;
  
  // calcul selon le type de plateforme
  int xPlatform = aPlatform.x - OVER_CENTER_X_PLATFORM;
  int yPlatform = aPlatform.y - OVER_CENTER_Y_PLATFORM;
  int widthPlatform = WIDTH_PLATFORM;
  int heightPlatform = HEIGHT_PLATFORM;
  if(aPlatform.type == 1) {
    xPlatform = aPlatform.x - OVER_CENTER_X_GROUND;
    yPlatform = aPlatform.y - OVER_CENTER_Y_GROUND;
    widthPlatform = WIDTH_GROUND;
    heightPlatform = HEIGHT_PLATFORM;
  } else if(aPlatform.type == 2) {
    xPlatform = aPlatform.x - OVER_CENTER_X_HILL;
    yPlatform = aPlatform.y - OVER_CENTER_Y_HILL;
    widthPlatform = WIDTH_HILL;
    heightPlatform = HEIGHT_HILL;
  }

  if( gb.collideRectRect(xCharacter, yCharacter, WIDTH_HERO, HEIGHT_HERO, xPlatform, yPlatform - 1, widthPlatform * aPlatform.lengthPlatform, heightPlatform) ) {
    return (aCharacter.y + UNDER_CENTER_Y_HERO) == yPlatform;
  }
  
  return false;
}
