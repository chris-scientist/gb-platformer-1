// author: chris-scientist
// created at: 02/02/2019

#include "Interactions.h"

void interactionsWithWorld(Character &aCharacter, Object * aSetOfObjects) {
  switch(isContactWithObject(aCharacter, aSetOfObjects)) {
    case KEY_OBJECT:
      aCharacter.haveKey = true;
    break;
  }
}

const int isContactWithObject(Character &aCharacter, Object * aSetOfObjects) {
  for(int i = 0 ; i < NB_OF_OBJECTS ; i++) {
    const int anObject = isContactWithObject(aCharacter, aSetOfObjects[i]);
    switch(anObject) {
      case KEY_OBJECT:
        aSetOfObjects[i].state = KEY_COLLECTED;
        return anObject;
      break;
      case DOOR_OBJECT:
        if(aCharacter.haveKey) {
          aSetOfObjects[i].state = DOOR_BTW_OPEN;
          aCharacter.haveKey = false;
        }
        return anObject;
      break;
    }
  }
  return NO_OBJECT;
}

const int isContactWithObject(Character aCharacter, Object anObject) {
  int xObject = anObject.x;
  int yObject = anObject.y;
  int widthObj = WIDTH_KEY;
  int heightObj = HEIGHT_KEY;
  switch(anObject.type) {
    case KEY_OBJECT:
      xObject -= OVER_CENTER_X_KEY;
      yObject -= OVER_CENTER_Y_KEY;
    break;
    case DOOR_OBJECT:
      xObject -= OVER_CENTER_X_DOOR;
      yObject -= OVER_CENTER_Y_DOOR;
      widthObj = WIDTH_DOOR;
      heightObj = HEIGHT_DOOR;
    break;
  }
  if(gb.collideRectRect(aCharacter.x - OVER_CENTER_X_HERO, aCharacter.y - OVER_CENTER_Y_HERO, WIDTH_HERO, HEIGHT_HERO, xObject, yObject, widthObj, heightObj)) {
    switch(anObject.type) {
      case KEY_OBJECT:
        return (anObject.state == KEY_ON_THE_PLATFORM) ? KEY_OBJECT : NO_OBJECT;
      break;
      case DOOR_OBJECT:
        return DOOR_OBJECT;
      break;
    }
  }
  return NO_OBJECT;
}
