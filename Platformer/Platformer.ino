// author: chris-scientist
// created at: 29/01/2019
// updated at: 30/01/2019

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Commands.h"
#include "Display.h"
#include "Character.h"
#include "Platform.h"

// Création du personnage
Character hero;
Platform setOfPlatforms[NB_OF_PLATFORMS];

void setup() {
  // initialiser la gamebuino
  gb.begin();

  initCharacter(hero);
  initPlatforms(setOfPlatforms);

  // à effacer
  gb.display.print("  Work in progress");
  delay(5000);
  
  /*
  // debug
  gb.display.clear();
  for(int i=0 ; i < NB_OF_PLATFORMS ; i++) {
    Platform zPlatform = setOfPlatforms[i];
    gb.display.printf("%d, %d : %d", zPlatform.x, zPlatform.y, zPlatform.lengthPlatform);
    gb.display.println("");
  }
  delay(10000);*/
}

void loop() {
  // boucle d'attente
  while(!gb.update());

  gb.display.clear();

  manageCommands(hero);
  paint(hero, setOfPlatforms);
}
