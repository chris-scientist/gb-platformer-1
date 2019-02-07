// author: chris-scientist
// created at: 29/01/2019
// updated at: 30/01/2019

#ifndef PLATFORMER_COMMANDS
#define PLATFORMER_COMMANDS

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Character.h"
#include "PhysicsEngine.h"

const int manageCommandsForHome();
const int manageCommandsOutOfGame(bool isGameOver);
const int manageCommands(Character &aCharacter);

#endif
