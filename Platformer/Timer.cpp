// author: chris-scientist
// created at: 31/01/2019
// updated at: 09/02/2019

#include "Timer.h"

// Gestion du chronomètre
void runTimer(Timer &aTimer) {
  if(aTimer.activateTimer) {
    incrementTime(aTimer);
    computeTime(aTimer);
  } else {
    pauseForTimer(aTimer);
  }
}

// Création du timer
void createTimer(Timer &aTimer) {
  aTimer.activateTimer = false;
}

// Réinitialisation du timer
void resetTimer(Timer &aTimer) {
  aTimer.timeInSeconds = 0;
  aTimer.tempTime = 0;
}

// Mettre en pause le timer
void pauseForTimer(Timer &aTimer) {
  if(aTimer.tempTime != 0) {
    aTimer.timeInSeconds += aTimer.tempTime;
    aTimer.tempTime = 0;
  }
}

// Décomposé le temps écoulé en jours, heures, minutes et secondes
void computeTime(Timer &aTimer) {
  int32_t rest = aTimer.timeInSeconds + aTimer.tempTime;

  const uint16_t DAYS_IN_FRAMES    = 24*60*60*1000;
  const uint16_t HOURS_IN_FRAMES   = 60*60*1000;
  const uint16_t MINUTES_IN_FRAMES = 60*1000;
  const uint16_t SECONDS_IN_FRAMES = 1000;

  uint16_t nbDays = 0;
  uint16_t nbHours = 0;
  uint16_t nbMinutes = 0;
  uint16_t nbSeconds = 0;

  // Calculer les jours
  if(rest >= DAYS_IN_FRAMES) {
    nbDays = (uint16_t)(rest / DAYS_IN_FRAMES);
    rest = (rest - (nbDays * DAYS_IN_FRAMES));
  }
  // Calculer les heures
  if(rest >= HOURS_IN_FRAMES) {
    nbHours = (uint16_t)(rest / HOURS_IN_FRAMES);
    rest = (rest - (nbHours * HOURS_IN_FRAMES));
  }
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

  aTimer.valueOfTime[DAYS_NUMBER] = nbDays;
  aTimer.valueOfTime[HOURS_NUMBER] = nbHours;
  aTimer.valueOfTime[MINUTES_NUMBER] = nbMinutes;
  aTimer.valueOfTime[SECONDS_NUMBER] = nbSeconds;
  aTimer.valueOfTime[MILLISECONDS_NUMBER] = rest;
}

void incrementTime(Timer &aTimer) {
  aTimer.tempTime += gb.getTimePerFrame();
}
