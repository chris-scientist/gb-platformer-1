// author: chris-scientist
// created at: 30/01/2019

#ifndef PLATFORMER_PHYSICS_ENGINE
#define PLATFORMER_PHYSICS_ENGINE

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Character.h"
#include "Platform.h"

bool gravity(Character &aCharacter, Platform * aSet);
bool isOnTheGround(Character aCharacter);
bool isOnOnePlatform(Character aCharacter, Platform * aSet);
bool isOnThePlatform(Character aCharacter, Platform aPlatform);

#endif
