// author: chris-scientist
// created at: 30/01/2019

#include "PhysicsEngine.h"

// Si le personnage chute alors on renvoie true, false sinon
bool gravity(Character &aCharacter, Platform * aSet) {
  bool isFall = false;
  
  if( ! isOnTheGround(aCharacter) && ! isOnOnePlatform(aCharacter, aSet) ) {
    //gb.display.println("CHUTE !"); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    aCharacter.y += GRAVITY;
    //gb.display.printf("G.y %d ", aCharacter.y); // <<<<<<<<<<<<<<<<<<<<<<<<<<<
    isFall = true;
  }

  return isFall;
}

bool isOnTheGround(Character aCharacter) {
  /*gb.display.printf("%d", aCharacter.y); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  gb.display.println("");*/
  return ( (aCharacter.y + UNDER_CENTER_Y_HERO) >= 64 );
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
  int xPlatform = aPlatform.x - OVER_CENTER_X_PLATFORM;
  int yPlatform = aPlatform.y - OVER_CENTER_Y_PLATFORM;
  
  return gb.collideRectRect(xCharacter, yCharacter, WIDTH_HERO, HEIGHT_HERO, xPlatform, yPlatform, WIDTH_PLATFORM * aPlatform.lengthPlatform, HEIGHT_PLATFORM);
}
