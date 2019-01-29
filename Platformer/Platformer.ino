// author: chris-scientist
// created at: 29/01/2019

#include <Gamebuino-Meta.h>

#include "Display.h"
#include "Character.h"
#include "Commands.h"

// Création du personnage
Character hero;

void setup() {
  // initialiser la gamebuino
  gb.begin();

  initCharacter(hero);
}

void loop() {
  // boucle d'attente
  while(!gb.update());

  gb.display.clear();

  manageCommands(hero);
  paint(hero);
}
