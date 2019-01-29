// author: chris-scientist
// created at: 29/01/2019

#include "Commands.h"

void manageCommands(Character &aCharacter) {
  bool isMove = false;
  if(gb.buttons.pressed(BUTTON_LEFT)) {
    if(aCharacter.x > 8) {
      aCharacter.x--;
      aCharacter.toTheLeft = true;
      isMove = true;
    }
  } else if(gb.buttons.pressed(BUTTON_RIGHT)) {
    if(aCharacter.x < 73) {
      aCharacter.x++;
      aCharacter.toTheLeft = false;
      isMove = true;
    }
  }

  if(isMove) {
    if(aCharacter.animation == 2) {
      aCharacter.animation = 1;
    } else {
      aCharacter.animation = 2;
    }
  }
}
