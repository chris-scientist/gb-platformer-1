// author: chris-scientist
// created at: 08/02/2019

#ifndef PLATFORMER_HIGH_SCORE
#define PLATFORMER_HIGH_SCORE

#include <Gamebuino-Meta.h>
#include <cstring>

struct HighScore {
  char nameOfScore[5];
  uint8_t score;
};

void initHighScore(HighScore &aHighScore, char * aName, uint8_t aScore);
int8_t compareTime(const HighScore &aScore, const uint8_t aTimeInSeconds);

#endif
