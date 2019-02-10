// author: chris-scientist
// created at: 29/01/2019
// updated at: 08/02/2019

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Game.h"
#include "Commands.h"
#include "Display.h"
#include "Timer.h"
#include "HighScoreManager.h"
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
HighScoreManager highScoreManager;
int stateOfGame = HOME_STATE;

void setup() {
  // initialiser la gamebuino
  gb.begin();

  createTimer(myTimer);
  initHighScoreManager(highScoreManager);
  loadAllHighScore(highScoreManager);

  /*
  // debug
  gb.display.clear();
  for(int i=0 ; i < NB_OF_PLATFORMS ; i++) {
    Platform zPlatform = setOfPlatforms[i];
    gb.display.printf("%d, %d : %d", zPlatform.x, zPlatform.y, zPlatform.lengthPlatform);
    gb.display.println("");
  }
  delay(10000);*/
  gb.display.setColor(WHITE);
  gb.display.println("  Work in progress");
  delay(1000);
}

void loop() {
  // boucle d'attente
  while(!gb.update());

  gb.display.clear();

  switch(stateOfGame) {
    case HOME_STATE:
      // Ecran d'accueil
      
      stateOfGame = paintHomeScreen();
      //stateOfGame = manageCommandsForHome();
      break;
    case LAUNCH_PLAY_STATE:
      // initialisé la partie
      
      initCharacter(hero); // ......... on réinitialise la position du personnage
      initPlatforms(setOfPlatforms);
      initObjects(setOfObjects); // ... on réinitialise les objets
      resetIndexNewHighScore(highScoreManager);
      resetTimer(myTimer);
      myTimer.activateTimer = true;

      stateOfGame = PLAY_STATE;
      break;
    case PLAY_STATE:
      // Partie en cours...

      if(hero.state == ON_THE_PLATFORM_STATE && (stateOfGame != GAME_OVER_STATE && stateOfGame != GAME_IS_FINISH)) {
        stateOfGame = manageCommands(hero);
        switch(stateOfGame) {
          case PAUSE_STATE:
            myTimer.activateTimer = false;
            pauseForTimer(myTimer);
            break;
        }
      }

      runTimer(myTimer);
      
      if(hero.state != JUMP_STATE && hero.state != PUSH_FOR_JUMP_STATE) {
        gravity(hero, setOfPlatforms);
      } else if(hero.state == JUMP_STATE || hero.state == PUSH_FOR_JUMP_STATE) {
        jump(hero, setOfPlatforms);
      }
      
      interactionsWithWorld(hero, setOfObjects);
  
      paint(hero, setOfPlatforms, setOfObjects, myTimer);

      if( stateOfGame != PAUSE_STATE ) {
        if( isEndOfGame(setOfObjects[DOOR_OBJECT_ID]) ) {
          //stateOfGame = GAME_IS_FINISH;
          stateOfGame = SAVE_HIGH_SCORE_STATE;
        } else {
          stateOfGame = ( isGameOver(myTimer) ? GAME_OVER_STATE : PLAY_STATE );
        }
      }
      //delay(1000); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      /*gb.display.setColor(BLACK);
      gb.display.printf("(%d, %d)",hero.x, hero.y); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      delay(500);*/
      break;
    case PAUSE_STATE:
      stateOfGame = manageCommandsForPause();
      paintPause();
      break;
    case GO_BACK_GAME_STATE:
      myTimer.activateTimer = true;
      stateOfGame = PLAY_STATE;
      break;
    case GAME_IS_FINISH:
      stateOfGame = manageCommandsOutOfGame(stateOfGame);
      paintEndOfGame(myTimer.valueOfTime);
      break;
    case SAVE_HIGH_SCORE_STATE:
      // on arrête le chronomètre
      pauseForTimer(myTimer);
      myTimer.activateTimer = false;
      
      stateOfGame = (saveScoreIfNewHighScore(highScoreManager, myTimer.timeInSeconds) ? HIGH_SCORE_STATE : GAME_IS_FINISH);
      break;
    case HIGH_SCORE_STATE:
      stateOfGame = manageCommandsOutOfGame(stateOfGame);
      
      paintHighScoreWindow(highScoreManager);
      break;
    case GAME_OVER_STATE:
      stateOfGame = manageCommandsOutOfGame(stateOfGame);
      paintGameOverScreen();
      break;
    default:
      gb.display.println("Etat non gere");
      delay(1000);
      stateOfGame = HOME_STATE;
  }
}
