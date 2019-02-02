// author: chris-scientist
// created at: 02/02/2019

#ifndef PLATFORMER_INTERACTIONS
#define PLATFORMER_INTERACTIONS

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Character.h"
#include "Object.h"

void interactionsWithWorld(Character &aCharacter, Object * aSetOfObjects);
const int isContactWithObject(Character aCharacter, Object * aSetOfObjects);
const int isContactWithObject(Character aCharacter, Object anObject);

#endif
