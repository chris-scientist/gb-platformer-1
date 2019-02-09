// author: chris-scientist
// created at: 08/02/2019
// updated at: 09/02/2019

#include "HighScore.h"

void initHighScore(HighScore &aHighScore, char * aName, int32_t aScore) {
  strncpy(aHighScore.nameOfScore, aName, 5);
  aHighScore.score = aScore;
}

// a = aScore et b = aTimeInSeconds
// Si a == b alors retourner 0
// Si a > b alors retourner 1
// Si a < b alors retourner -1
int8_t compareTime(const HighScore &aScore, const int32_t aTimeInSeconds) {
  if(aScore.score == aTimeInSeconds) {
    return 0;
  } else if(aScore.score > aTimeInSeconds) {
    return 1;
  }
  return -1;
}
