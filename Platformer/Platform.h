// author: chris-scientist
// created at: 30/01/2019
// updated at: 04/02/2019

#ifndef PLATFORMER_PLATFORM
#define PLATFORMER_PLATFORM

#include "Constantes.h"

struct Platform {
  int x; // ........................... position x du début de la plateforme (centre de la première plateforme)
  int y; // ........................... position y de la plateforme (centre de la plateforme)
  int lengthPlatform; // .............. longueur de la plateforme en bloc (doit être au minimum égale à 2), un bloc fait 5 pixels sur 5
  int type; // ........................ type de plateforme : voir constantes
  int id; // .......................... identifiant (unique) de la plateforme
  bool isGoThrough; // ................ true pour indiquer que le joueur peu passer à travers la plateforme, sinon false
};

void initPlatforms(Platform * aSet);
Platform createPlatform(int aX, int aY, int aLength, int aType, int aId, bool goThrough);
Platform getPlatformFromId(const int aId, Platform * aSet);

#endif
