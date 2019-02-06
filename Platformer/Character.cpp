// author: chris-scientist
// created at: 29/01/2019
// updated at: 05/02/2019

#include "Character.h"

void initCharacter(Character &aCharacter) {
  // On force la position initiale du héro  au milieu de l'écran et plaqué au sol
  aCharacter.x = 40;
  aCharacter.y = 64 - (UNDER_CENTER_Y_HERO + HEIGHT_GROUND);
  aCharacter.oldY = aCharacter.y;

  // On lui d'y d'aller vers la droite par défaut
  aCharacter.toTheLeft = false;

  // Le personnage n'a pas la clé au départ
  aCharacter.haveKey = false;
  
  // On initialise l'animation
  aCharacter.animation = MIN_INDEX_ANIMATION_HERO;

  // On initialise la vitesse verticale
  aCharacter.vy = 0;

  // par défaut, le joueur est dans un état "normal" c'est-à-dire sur le sol
  aCharacter.state = ON_THE_PLATFORM_STATE;
  
  #if DEBUG_PLATFORMER // Mode debug actif ===============================================
  aCharacter.x = 40;
  aCharacter.y = 53;
  
  /*aCharacter.x = 29;
  aCharacter.y = 31;
  aCharacter.vx = HORIZONTAL_VELOCITY;
  aCharacter.state = PUSH_FOR_JUMP_STATE;*/
  
  aCharacter.oldY = aCharacter.y;
  #endif
}

bool isFall(Character aCharacter) {
  return (aCharacter.oldY - aCharacter.y) < 0;
}
