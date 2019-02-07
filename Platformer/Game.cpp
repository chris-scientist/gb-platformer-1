// author: chris-scientist
// created at: 07/02/2019

#include "Game.h"

bool isGameOver(Timer &aTimer) {
  return ( (aTimer.timeInSeconds + aTimer.tempTime) >= MAX_TIME_OF_GAME );
}

bool isEndOfGame(Object &aDoor) {
  return (aDoor.state == DOOR_BTW_OPEN);
}
