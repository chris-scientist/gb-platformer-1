// author: chris-scientist
// created at: 29/01/2019
// updated at: 30/01/2019

#ifndef PLATFORMER_CHARACTER
#define PLATFORMER_CHARACTER

#include "Constantes.h"

struct Character {
  int x; // ........................... position x
  int y; // ........................... position y
  bool toTheLeft; // .................. true si le personnage va vers la gauche, false sinon
  int animation; // ................... pour animer le personnage
};

void initCharacter(Character &aCharacter);

#endif
