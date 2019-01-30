// author: chris-scientist
// created at: 29/01/2019
// updated at: 30/01/2019

#include "Character.h"

void initCharacter(Character &aCharacter) {
  // On force la position initiale du héro  au milieu de l'écran et plaqué au sol
  aCharacter.x = 40;
  aCharacter.y = 64 - UNDER_CENTER_Y_HERO;
  
  // On lui d'y d'aller vers la droite par défaut
  aCharacter.toTheLeft = false;
  
  // On initialise l'animation
  aCharacter.animation = 1;
}
