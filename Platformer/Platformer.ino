// author: chris-scientist
// created at: 29/01/2019
// updated at: 02/01/2019

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Commands.h"
#include "Display.h"
#include "PhysicsEngine.h"
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
  
  // à effacer - forcer les coordonnées du personnage
  hero.x = 40;
  hero.y = 5;
  hero.state = FREE_FALL_STATE;

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

  if(hero.state != JUMP_STATE && hero.state != PUSH_FOR_JUMP_STATE) {
    gravity(hero, setOfPlatforms);
  } else if(hero.state == JUMP_STATE || hero.state == PUSH_FOR_JUMP_STATE) {
    jump(hero, setOfPlatforms);
  }
  
  if(hero.state == ON_THE_PLATFORM_STATE) {
    manageCommands(hero);
  }

  paint(hero, setOfPlatforms);
  /*gb.display.setColor(BLACK);
  gb.display.printf("(%d, %d)",hero.x, hero.y); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  delay(500);*/
}
