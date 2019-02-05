// author: chris-scientist
// created at: 30/01/2019
// updated at: 05/02/2019

#include "PhysicsEngine.h"

// Implémentation du saut du personnage
void jump(Character &aCharacter, Platform * aSet) {
  const int platformId = isOnOnePlatform(aCharacter, aSet);
  Platform aPlatform = getPlatformFromId(platformId, aSet);
  if(aCharacter.state == PUSH_FOR_JUMP_STATE) {
    // le joueur donne une impulsion pour le saut
    // on initialise alors les données pour le saut
    aCharacter.vy = -INIT_VERTICAL_VELOCITY;
    aCharacter.state = JUMP_STATE;

    // le personnage saute
    aCharacter.oldY = aCharacter.y;
    aCharacter.vy += GRAVITY;
    aCharacter.x += aCharacter.vx;
    aCharacter.y += aCharacter.vy;
  } else if( platformId != NO_ID ) {
    // Si on n'est en contact avec une plateforme

    if(aPlatform.isGoThrough || (isFall(aCharacter) && aCharacter.y <= aPlatform.y)) {
      int overCenterY = OVER_CENTER_Y_PLATFORM;
      switch(aPlatform.type) {
        case GROUND_TYPE:
          overCenterY = OVER_CENTER_Y_GROUND;
        break;
        case HILL_TYPE:
          overCenterY = OVER_CENTER_Y_HILL;
        break;
      }
      aCharacter.y = (aPlatform.y - (overCenterY + UNDER_CENTER_Y_HERO));
      aCharacter.state = ON_THE_PLATFORM_STATE;
    } else {
      // le personnage saute
      aCharacter.oldY = aCharacter.y;
      aCharacter.vy += GRAVITY;
      aCharacter.x += aCharacter.vx;
      aCharacter.y += aCharacter.vy;
    }
    
    //aCharacter.state = ON_THE_PLATFORM_STATE;
    
  } else if( isOutOfWorld(aCharacter) ) {
    // Si le saut nous conduit en dehors du monde
    // alors on applique la gravité
    aCharacter.state = FREE_FALL_STATE;
  } else {
    // le personnage saute
    aCharacter.oldY = aCharacter.y;
    aCharacter.vy += GRAVITY;
    aCharacter.x += aCharacter.vx;
    aCharacter.y += aCharacter.vy;
  }
}

// Si le personnage chute alors on renvoie true, false sinon
bool gravity(Character &aCharacter, Platform * aSet) {
  bool isFall = false;

  const int platformId = isOnOnePlatform(aCharacter, aSet);
  Platform aPlatform = getPlatformFromId(platformId, aSet);
  if( platformId == NO_ID ) {
    // Chute libre
    aCharacter.oldY = aCharacter.y;
    aCharacter.state = FREE_FALL_STATE;
    aCharacter.y += GRAVITY;
    isFall = true;
  } else {
    // En conctat avec une structure (plateforme, sol, etc)
    int overCenterY = OVER_CENTER_Y_PLATFORM;
    switch(aPlatform.type) {
      case GROUND_TYPE:
        overCenterY = OVER_CENTER_Y_GROUND;
      break;
      case HILL_TYPE:
        overCenterY = OVER_CENTER_Y_HILL;
      break;
    }
    aCharacter.y = (aPlatform.y - (overCenterY + UNDER_CENTER_Y_HERO));
    aCharacter.state = ON_THE_PLATFORM_STATE;
  }

  return isFall;
}

const int isOnOnePlatform(Character aCharacter, Platform * aSet) {
  for(int i = 0 ; i < NB_OF_PLATFORMS ; i++) {
    const int platformId = isOnThePlatform(aCharacter, aSet[i]);
    if(platformId != NO_ID) {
      return platformId;
    }
  }
  return NO_ID;
}

const int isOnThePlatform(Character aCharacter, Platform aPlatform) {
  int xCharacter = aCharacter.x - OVER_CENTER_X_HERO;
  int yCharacter = aCharacter.y - OVER_CENTER_Y_HERO;
  
  // calcul selon le type de plateforme
  int xPlatform = aPlatform.x - OVER_CENTER_X_PLATFORM;
  int yPlatform = aPlatform.y - OVER_CENTER_Y_PLATFORM;
  int widthPlatform = WIDTH_PLATFORM;
  int heightPlatform = HEIGHT_PLATFORM;
  if(aPlatform.type == GROUND_TYPE) {
    xPlatform = aPlatform.x - OVER_CENTER_X_GROUND;
    yPlatform = aPlatform.y - OVER_CENTER_Y_GROUND;
    widthPlatform = WIDTH_GROUND;
    heightPlatform = HEIGHT_PLATFORM;
  } else if(aPlatform.type == HILL_TYPE) {
    xPlatform = aPlatform.x - OVER_CENTER_X_HILL;
    yPlatform = aPlatform.y - OVER_CENTER_Y_HILL;
    widthPlatform = WIDTH_HILL;
    heightPlatform = HEIGHT_HILL;
  }

  if(aCharacter.state == JUMP_STATE && !isFall(aCharacter) && aPlatform.isGoThrough) {
    return NO_ID;
  } else if(
      aCharacter.state == JUMP_STATE &&
      gb.collideRectRect(xCharacter, yCharacter, WIDTH_HERO, HEIGHT_HERO, xPlatform, yPlatform, widthPlatform * aPlatform.lengthPlatform, heightPlatform)
    )
  {
    return aPlatform.id;
  } else {
    // Selon que l'on saute ou non, le premier test de collision n'est pas le même
    if( (aCharacter.y + UNDER_CENTER_Y_HERO) == yPlatform ) {
      return gb.collideRectRect(xCharacter, yCharacter, WIDTH_HERO, HEIGHT_HERO, xPlatform, yPlatform - 1, widthPlatform * aPlatform.lengthPlatform, heightPlatform) ? aPlatform.id : NO_ID;
    }
  }
  
  return NO_ID;
}

bool isOutOfWorld(Character &aCharacter) {
  if( aCharacter.x <= OVER_CENTER_X_HERO ) {
    // Si le personnage sort à gauche de l'écran
    // alors on force ses coordonnées pour qu'il soit toujours sur l'écran
    aCharacter.x = OVER_CENTER_X_HERO;
    return true;
  } else if( aCharacter.x >= (WIDTH_SCREEN - UNDER_CENTER_X_HERO) ) {
    // Si le personnage sort à droite de l'écran
    // alors on force ses coordonnées pour qu'il soit toujours sur l'écran
    aCharacter.x = WIDTH_SCREEN - UNDER_CENTER_X_HERO;
    return true;
  }
  return false;
}
