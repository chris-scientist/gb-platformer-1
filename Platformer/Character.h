// author: chris-scientist
// created at: 29/01/2019
// updated at: 07/02/2019

#ifndef PLATFORMER_CHARACTER
#define PLATFORMER_CHARACTER

#include "Constantes.h"
#include "Platform.h"

struct Character {
  int x; // ........................... position x
  int y; // ........................... position y
  int oldY; // ........................ position y au dernier rafraîchissement
  int vx; // .......................... accélération horizontale
  int vy; // .......................... accélération verticale
  bool toTheLeft; // .................. true si le personnage va vers la gauche, false sinon
  bool haveKey; // .................... true si le personnage à la clé, false sinon
  int animation; // ................... pour animer le personnage
  int state; // ....................... état du personnage : 0 = normal, 1 = chute libre, 2 = impulsion pour saut, 3 = saut
};

void initCharacter(Character &aCharacter);
bool isFall(Character aCharacter);
void rectifyPositionY(Character &aCharacter, Platform &aPlatform);

#endif
