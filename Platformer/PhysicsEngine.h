// author: chris-scientist
// created at: 30/01/2019
// updated at: 03/02/2019

#ifndef PLATFORMER_PHYSICS_ENGINE
#define PLATFORMER_PHYSICS_ENGINE

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Character.h"
#include "Platform.h"

void jump(Character &aCharacter, Platform * aSet);
bool gravity(Character &aCharacter, Platform * aSet);
const int isOnOnePlatform(Character aCharacter, Platform * aSet);
const int isOnThePlatform(Character aCharacter, Platform aPlatform);
bool isOutOfWorld(Character &aCharacter);

#endif
