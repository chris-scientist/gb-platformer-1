// author: chris-scientist
// created at: 29/01/2019
// updated at: 31/01/2019

#ifndef PLATFORMER_DISPLAY
#define PLATFORMER_DISPLAY

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Character.h"
#include "Platform.h"

void paint(Character &aCharacter, Platform * aSet);
void paintBackground();
void paintHero(Character &aCharacter);
void paintPlatforms(Platform * aSet);
void paintPlatform(Platform aPlatform);
void paintPlatform(const int anIndex, const int aNbBlocks, const int aX, const int aY);
void paintHill(const int anIndex, const int aNbBlocks, const int aX, const int aY);
void paintGround(const int aX, const int aY);

#endif
