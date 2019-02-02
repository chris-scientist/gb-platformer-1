// author: chris-scientist
// created at: 30/01/2019
// updated at: 02/02/2019

#include "PhysicsEngine.h"

// Implémentation du saut du personnage
void jump(Character &aCharacter, Platform * aSet) {
  if(aCharacter.state == PUSH_FOR_JUMP_STATE) {
    // le joueur donne une impulsion pour le saut
    // on initialise alors les données pour le saut
    aCharacter.vy = -INIT_VERTICAL_VELOCITY;
    aCharacter.state = JUMP_STATE;

    // le personnage saute
    aCharacter.vy += ACCELERATION_FOR_JUMP;
    aCharacter.x += (aCharacter.toTheLeft ? -HORIZONTAL_VELOCITY : HORIZONTAL_VELOCITY);
    aCharacter.y += aCharacter.vy;
  } else if( isOnOnePlatform(aCharacter, aSet) ) {
    // Si on n'est en contact avec une plateforme
    // alors on a atteint une plateforme
    aCharacter.state = ON_THE_PLATFORM_STATE;
  } else if( isOutOfWorld(aCharacter) ) {
    // Si le saut nous conduit en dehors du monde
    // alors on applique la gravité
    aCharacter.state = FREE_FALL_STATE;
  } else {
    // le personnage saute
    aCharacter.vy += ACCELERATION_FOR_JUMP;
    aCharacter.x += (aCharacter.toTheLeft ? -HORIZONTAL_VELOCITY : HORIZONTAL_VELOCITY);
    aCharacter.y += aCharacter.vy;
  }
}

// Si le personnage chute alors on renvoie true, false sinon
bool gravity(Character &aCharacter, Platform * aSet) {
  bool isFall = false;
  
  if(! isOnOnePlatform(aCharacter, aSet) ) {
    // Chute libre
    aCharacter.state = FREE_FALL_STATE;
    aCharacter.y += GRAVITY;
    isFall = true;
  } else {
    // En conctat avec une structure (plateforme, sol, etc)
    aCharacter.state = ON_THE_PLATFORM_STATE;
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

  // Selon que l'on saute ou non, le premier test de collision n'est pas le même
  if( (aCharacter.state != JUMP_STATE) ? ( (aCharacter.y + UNDER_CENTER_Y_HERO) == yPlatform ) : ( (aCharacter.y + UNDER_CENTER_Y_HERO) >= yPlatform ) ) {
    return gb.collideRectRect(xCharacter, yCharacter, WIDTH_HERO, HEIGHT_HERO, xPlatform, yPlatform - 1, widthPlatform * aPlatform.lengthPlatform, heightPlatform);
  }
  
  return false;
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
