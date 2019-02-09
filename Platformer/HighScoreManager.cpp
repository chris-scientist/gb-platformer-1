// author: chris-scientist
// created at: 08/02/2019

#include "HighScoreManager.h"

void initHighScoreManager(HighScoreManager &aManager) {
  initHighScore(aManager.highScore1, "    ", 0);
  initHighScore(aManager.highScore2, "    ", 0);
  initHighScore(aManager.highScore3, "    ", 0);
  aManager.nbHighScore = 0;
  aManager.indexNewHighScore = 0;
}

void paintHighScoreWindow(const HighScoreManager& aScoreManager) {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  gb.display.println("High score");
  gb.display.println("");
  const uint8_t listHighScore[3] = { HIGH_SCORE_1, HIGH_SCORE_2, HIGH_SCORE_3 };
  for(int i=0 ; i<aScoreManager.nbHighScore ; i++) {
    uint8_t index = listHighScore[i];
    const HighScore& highScore = getHighScore(aScoreManager, index);
    if(index == aScoreManager.indexNewHighScore) {
      gb.display.setColor(BROWN);
    } else {
      gb.display.setColor(WHITE);
    }
    gb.display.printf("%s ", highScore.nameOfScore);

    int32_t rest = highScore.score;

    const uint16_t MINUTES_IN_FRAMES = 60*1000;
    const uint16_t SECONDS_IN_FRAMES = 1000;
  
    uint16_t nbMinutes = 0;
    uint16_t nbSeconds = 0;
  
    // Calculer les minutes
    if(rest >= MINUTES_IN_FRAMES) {
      nbMinutes = (uint16_t)(rest / MINUTES_IN_FRAMES);
      rest = (rest - (nbMinutes * MINUTES_IN_FRAMES));
    }
    // Calculer les secondes
    if(rest >= SECONDS_IN_FRAMES) {
      nbSeconds = (uint16_t)(rest / SECONDS_IN_FRAMES);
      rest = (rest - (nbSeconds * SECONDS_IN_FRAMES));
    }

    gb.display.cursorX = 25;
    if(nbMinutes < 10) {
      gb.display.print("0");
    }
    gb.display.printf("%d m ", nbMinutes);
    if(nbSeconds < 10) {
      gb.display.print("0");
    }
    gb.display.printf("%d s ", nbSeconds);
    gb.display.printf("%d", rest);
    gb.display.println("");
  }

  // Afficher en bas de l'écran "retourner au menu"
  int l = aScoreManager.nbHighScore;
  while(l<3) {
    gb.display.println();
    l++;
  }
  gb.display.println();
  gb.display.println();
  gb.display.println();
  gb.display.setColor(WHITE);
  gb.display.println("(A) Try again");
  gb.display.println("(B) Menu");
}

const HighScore& getHighScore(const HighScoreManager &aManager, uint8_t anIndex) {
  switch(anIndex) {
    case HIGH_SCORE_2:
      return aManager.highScore2;
      break;
    case HIGH_SCORE_3:
      return aManager.highScore3;
      break;
  }
  return aManager.highScore1;
}

bool saveScoreIfNewHighScore(HighScoreManager &aManager, const int32_t aTimeOfPart) {
  // Compaer le score actuel aux scores en mémoire
  const uint8_t highScoreIndex = setHighScore4Time(aManager, aTimeOfPart);

  // S'il y a un nouveau meilleur score alors on le sauvegarde
  bool haveNewHighScore = (highScoreIndex != NO_HIGH_SCORE);
  if(haveNewHighScore) {
    saveAllHighScore(aManager);
  }
  aManager.indexNewHighScore = highScoreIndex;

  return haveNewHighScore;
}

const uint8_t setHighScore4Time(HighScoreManager &aManager, const int32_t aTimeOfPart) {
  uint8_t highScoreIndex = NO_HIGH_SCORE;

  if(aManager.nbHighScore == 0) {
    // S'il n'y a pas de meilleur score

    char * pseudo = paintInputPseudoWindow();

    strncpy(aManager.highScore1.nameOfScore, pseudo, 5);
    aManager.highScore1.nameOfScore[4] = '\0';
    aManager.highScore1.score = aTimeOfPart;

    aManager.nbHighScore = 1;
    highScoreIndex = HIGH_SCORE_1;
    
  } else {
    const int cmpTime1 = compareTime(aManager.highScore1, aTimeOfPart);
    if(cmpTime1 == 0 || cmpTime1 == 1) {
      // Si le score est égale ou meilleur que le score 1

      if(aManager.nbHighScore == 3) {
        // High score 3 = High score 2
        strncpy(aManager.highScore3.nameOfScore, aManager.highScore2.nameOfScore, 5);
        aManager.highScore3.nameOfScore[4] = '\0';
        aManager.highScore3.score = aManager.highScore2.score;
      } else if(aManager.nbHighScore == 2) {
        // High score 3 = High score 2
        strncpy(aManager.highScore3.nameOfScore, aManager.highScore2.nameOfScore, 5);
        aManager.highScore3.nameOfScore[4] = '\0';
        aManager.highScore3.score = aManager.highScore2.score;

        aManager.nbHighScore = 3;
      } else {
        aManager.nbHighScore = 2;
      }

      // High score 2 = High score 1
      strncpy(aManager.highScore2.nameOfScore, aManager.highScore1.nameOfScore, 5);
      aManager.highScore2.nameOfScore[4] = '\0';
      aManager.highScore2.score = aManager.highScore1.score;

      char * pseudo = paintInputPseudoWindow();

      strncpy(aManager.highScore1.nameOfScore, pseudo, 5);
      aManager.highScore1.nameOfScore[4] = '\0';
      aManager.highScore1.score = aTimeOfPart;

      highScoreIndex = HIGH_SCORE_1;
      
    } else if(aManager.nbHighScore == 1) {
      // S'il n'y a pas de meilleur score 2

      char * pseudo = paintInputPseudoWindow();

      strncpy(aManager.highScore2.nameOfScore, pseudo, 5);
      aManager.highScore2.nameOfScore[4] = '\0';
      aManager.highScore2.score = aTimeOfPart;

      aManager.nbHighScore = 2;
      highScoreIndex = HIGH_SCORE_2;
      
    } else {
      const int cmpTime2 = compareTime(aManager.highScore2, aTimeOfPart);
      if(cmpTime2 == 0 || cmpTime2 == 1) {
        // Si le score est égale ou meilleur que le score 2

        if(aManager.nbHighScore == 2) {
          aManager.nbHighScore = 3;
        }

        // High score 3 = High score 2
        strncpy(aManager.highScore3.nameOfScore, aManager.highScore2.nameOfScore, 5);
        aManager.highScore3.nameOfScore[4] = '\0';
        aManager.highScore3.score = aManager.highScore2.score;

        char * pseudo = paintInputPseudoWindow();

        strncpy(aManager.highScore2.nameOfScore, pseudo, 5);
        aManager.highScore2.nameOfScore[4] = '\0';
        aManager.highScore2.score = aTimeOfPart;

        highScoreIndex = HIGH_SCORE_2;
      } else if(aManager.nbHighScore == 2) {
        // S'il n'y a pas de meilleur score 3

        char * pseudo = paintInputPseudoWindow();

        strncpy(aManager.highScore3.nameOfScore, pseudo, 5);
        aManager.highScore3.nameOfScore[4] = '\0';
        aManager.highScore3.score = aTimeOfPart;

        aManager.nbHighScore = 3;
        highScoreIndex = HIGH_SCORE_3;
      } else {
        const int cmpTime3 = compareTime(aManager.highScore3, aTimeOfPart);
        if(cmpTime3 == 0 || cmpTime3 == 1) {
          // Si le score est égale ou meilleur que le score 3

          char * pseudo = paintInputPseudoWindow();

          strncpy(aManager.highScore3.nameOfScore, pseudo, 5);
          aManager.highScore3.nameOfScore[4] = '\0';
          aManager.highScore3.score = aTimeOfPart;

          highScoreIndex = HIGH_SCORE_3;
        }
      }
    }
    
  }
  
  return highScoreIndex;
}

void resetIndexNewHighScore(HighScoreManager &aManager) {
  aManager.indexNewHighScore = NO_HIGH_SCORE;
}

void loadAllHighScore(HighScoreManager &aManager) {
  int32_t nbHighScoreSaved = gb.save.get(NB_HIGH_SCORE_BLOCK);
  if(nbHighScoreSaved > 0) {

    uint8_t nbScore = 0;

    // Charger le meilleur score 1
    loadHighScore(aManager.highScore1, NAME_HIGH_SCORE_1_BLOCK, SCORE_HIGH_SCORE_1_BLOCK);
    nbScore++;

    // Charger le meilleur score 2
    if(nbHighScoreSaved >= 2) {
      loadHighScore(aManager.highScore2, NAME_HIGH_SCORE_2_BLOCK, SCORE_HIGH_SCORE_2_BLOCK);
      nbScore++;
    }

    // Charger le meilleur score 3
    if(nbHighScoreSaved >= 3) {
      loadHighScore(aManager.highScore3, NAME_HIGH_SCORE_3_BLOCK, SCORE_HIGH_SCORE_3_BLOCK);
      nbScore++;
    }

    aManager.nbHighScore = nbScore;
    
  }
}

void loadHighScore(HighScore &aScore, uint16_t aBlockName, uint16_t aBlockScore) {
  char temp[5];
  gb.save.get(aBlockName, temp, 5);
  strncpy(aScore.nameOfScore, temp, 5);
  aScore.nameOfScore[4] = '\0';
  aScore.score = gb.save.get(aBlockScore);
}

void saveAllHighScore(HighScoreManager &aManager) {
  switch(aManager.nbHighScore) {
    case 1:
      saveHighScore((char*)aManager.highScore1.nameOfScore, aManager.highScore1.score, NAME_HIGH_SCORE_1_BLOCK, SCORE_HIGH_SCORE_1_BLOCK);
      break;
    case 2:
      saveHighScore((char*)aManager.highScore1.nameOfScore, aManager.highScore1.score, NAME_HIGH_SCORE_1_BLOCK, SCORE_HIGH_SCORE_1_BLOCK);
      saveHighScore((char*)aManager.highScore2.nameOfScore, aManager.highScore2.score, NAME_HIGH_SCORE_2_BLOCK, SCORE_HIGH_SCORE_2_BLOCK);
      break;
    case 3:
      saveHighScore((char*)aManager.highScore1.nameOfScore, aManager.highScore1.score, NAME_HIGH_SCORE_1_BLOCK, SCORE_HIGH_SCORE_1_BLOCK);
      saveHighScore((char*)aManager.highScore2.nameOfScore, aManager.highScore2.score, NAME_HIGH_SCORE_2_BLOCK, SCORE_HIGH_SCORE_2_BLOCK);
      saveHighScore((char*)aManager.highScore3.nameOfScore, aManager.highScore3.score, NAME_HIGH_SCORE_3_BLOCK, SCORE_HIGH_SCORE_3_BLOCK);
      break;
  }
  gb.save.set(NB_HIGH_SCORE_BLOCK, aManager.nbHighScore);
}

void saveHighScore(char * aName, int32_t aScore, uint16_t aBlockName, uint16_t aBlockScore) {
  gb.save.set(aBlockName, aName);
  gb.save.set(aBlockScore, aScore);
}
