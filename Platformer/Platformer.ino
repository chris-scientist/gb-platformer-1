// author: chris-scientist
// created at: 29/01/2019
// updated at: 07/02/2019

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Game.h"
#include "Commands.h"
#include "Display.h"
#include "Timer.h"
#include "PhysicsEngine.h"
#include "Interactions.h"
#include "Character.h"
#include "Platform.h"
#include "Object.h"

// Création du personnage
Character hero;
Platform setOfPlatforms[NB_OF_PLATFORMS];
Object setOfObjects[NB_OF_OBJECTS];
Timer myTimer;
int stateOfGame = HOME_STATE;

void setup() {
  // initialiser la gamebuino
  gb.begin();

  initPlatforms(setOfPlatforms);
  createTimer(myTimer);

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

  switch(stateOfGame) {
    case HOME_STATE:
      // Ecran d'accueil
      
      paintHomeScreen();
      stateOfGame = manageCommandsForHome();
      break;
    case LAUNCH_PLAY_STATE:
      // initialisé la partie
      
      initCharacter(hero); // ......... on réinitialise la position du personnage
      initObjects(setOfObjects); // ... on réinitialise les objets
      resetTimer(myTimer);
      myTimer.activateTimer = true;

      stateOfGame = PLAY_STATE;
      break;
    case PLAY_STATE:
      // Partie en cours...

      runTimer(myTimer);
  
      if(hero.state == ON_THE_PLATFORM_STATE) {
        stateOfGame = manageCommands(hero);
        switch(stateOfGame) {
          case HOME_STATE:
            myTimer.activateTimer = false;
            pauseForTimer(myTimer);
            break;
        }
      }
      
      if(hero.state != JUMP_STATE && hero.state != PUSH_FOR_JUMP_STATE) {
        gravity(hero, setOfPlatforms);
      } else if(hero.state == JUMP_STATE || hero.state == PUSH_FOR_JUMP_STATE) {
        jump(hero, setOfPlatforms);
      }
      
      interactionsWithWorld(hero, setOfObjects);

      stateOfGame = ( isGameOver(myTimer) ? GAME_OVER_STATE : PLAY_STATE );
  
      paint(hero, setOfPlatforms, setOfObjects, myTimer);
      //delay(1000); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      /*gb.display.setColor(BLACK);
      gb.display.printf("(%d, %d)",hero.x, hero.y); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      delay(500);*/
      break;
    case GAME_OVER_STATE:
      stateOfGame = manageCommandsForGameOver();
      paintGameOverScreen();
      break;
    default:
      gb.display.println("Etat non gere");
      delay(1000);
      stateOfGame = HOME_STATE;
  }
}
