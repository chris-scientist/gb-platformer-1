// author: chris-scientist
// created at: 31/01/2019
// updated at: 09/02/2019

#ifndef MY_TIMER
#define MY_TIMER

#include <Gamebuino-Meta.h>

#include "ConstantesTimer.h"

struct Timer {
  int32_t timeInSeconds; // ...................... temps total écoulé
  int32_t tempTime; // ........................... temps écoulé depuis la dernière pause
  uint16_t valueOfTime[5] = {0, 0, 0, 0, 0}; // ... temps découpé en jours, heures, minutes, secondes et millisecondes
  bool activateTimer; // .......................... indique si le timer est actif
};

void runTimer(Timer &aTimer);
void createTimer(Timer &aTimer);
void resetTimer(Timer &aTimer);
void pauseForTimer(Timer &aTimer);
void computeTime(Timer &aTimer);
void incrementTime(Timer &aTimer);

#endif
