// author: chris-scientist
// created at: 29/01/2019
// updated at: 01/02/2019

#include "Commands.h"

void manageCommands(Character &aCharacter) {
  bool isMove = false;
  if(gb.buttons.repeat(BUTTON_LEFT, 1)) {
    if(aCharacter.x > OVER_CENTER_X_HERO) {
      aCharacter.x--;
      aCharacter.toTheLeft = true;
      isMove = true;
    }
  } else if(gb.buttons.repeat(BUTTON_RIGHT, 1)) {
    if(aCharacter.x < (80 - UNDER_CENTER_X_HERO)) {
      aCharacter.x++;
      aCharacter.toTheLeft = false;
      isMove = true;
    }
  }

  if(isMove) {
    if(aCharacter.animation >= MAX_INDEX_ANIMATION_HERO) {
      aCharacter.animation = MIN_INDEX_ANIMATION_HERO;
    } else {
      aCharacter.animation++;
    }
  }
}
