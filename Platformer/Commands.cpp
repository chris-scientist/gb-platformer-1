// author: chris-scientist
// created at: 29/01/2019
// updated at: 10/02/2019

#include "Commands.h"

/*const int manageCommandsForHome() {
  if(gb.buttons.pressed(BUTTON_A)) {
    return LAUNCH_PLAY_STATE;
  }
  return HOME_STATE;
}*/

const int manageCommandsForPause() {
  if(gb.buttons.pressed(BUTTON_A)) {
    return GO_BACK_GAME_STATE;
  } else if(gb.buttons.pressed(BUTTON_B)) {
    return HOME_STATE;
  }
  return PAUSE_STATE;
}

const int manageCommandsOutOfGame(const int aState) {
  if(gb.buttons.pressed(BUTTON_A)) {
    return LAUNCH_PLAY_STATE;
  } else if(gb.buttons.pressed(BUTTON_B)) {
    return HOME_STATE;
  }

  return aState;
}

const int manageCommands(Character &aCharacter) {
  bool isMove = false;
  aCharacter.vx = 0;
  if(gb.buttons.repeat(BUTTON_LEFT, 1)) {
    if(aCharacter.x > OVER_CENTER_X_HERO) {
      aCharacter.x--;
      aCharacter.toTheLeft = true;
      aCharacter.vx = -HORIZONTAL_VELOCITY;
      isMove = true;
    }
  } else if(gb.buttons.repeat(BUTTON_RIGHT, 1)) {
    if(aCharacter.x < (80 - UNDER_CENTER_X_HERO)) {
      aCharacter.x++;
      aCharacter.toTheLeft = false;
      aCharacter.vx = HORIZONTAL_VELOCITY;
      isMove = true;
    }
  }

  if(gb.buttons.pressed(BUTTON_A) && aCharacter.state != JUMP_STATE) {
    aCharacter.state = PUSH_FOR_JUMP_STATE;
  }

  if(gb.buttons.pressed(BUTTON_MENU)) {
    return PAUSE_STATE;
  }

  if(isMove) {
    if(aCharacter.animation >= MAX_INDEX_ANIMATION_HERO) {
      aCharacter.animation = MIN_INDEX_ANIMATION_HERO;
    } else {
      aCharacter.animation++;
    }
  }
  
  return PLAY_STATE;
}
