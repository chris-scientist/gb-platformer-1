// author: chris-scientist
// created at: 31/01/2019

// ***********************************************************************
// ** La durée maximum qui peut être calculé avec ce programme est de : **
// ** 49710 jours, 6 heures, 28 minutes et 15 secondes !                **
// **                                                                   **
// ** Autrement dit : 136 années (de 365 jours), 70 jours, 6 heures,    **
// ** 28 minutes et 15 secondes !                                       **
// ***********************************************************************

#ifndef MY_TIMER
#define MY_TIMER

#include <RTCZero.h>

#include "ConstantesTimer.h"

struct Timer {
  unsigned int timeInSeconds; // .......... temps total écoulé
  unsigned int tempTime; // ............... temps écoulé depuis la dernière pause
  bool initialized; // .................... drapeau true si le timer est initialisé, false sinon
  RTCZero rtc; // ......................... le coeur du chronomètre
  int valueOfTime[4] = {0, 0, 0, 0}; // ... temps découpé en jours, heures, minutes et secondes
  bool activateTimer; // ................... indique si le timer est actif
};

void runTimer(Timer &aTimer);
void createTimer(Timer &aTimer);
void resetTimer(Timer &aTimer);
void initTimer(Timer &aTimer);
void pauseForTimer(Timer &aTimer);
void computeTime(Timer &aTimer);
void incrementTime(Timer &aTimer);

#endif
