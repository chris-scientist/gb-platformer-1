// author: chris-scientist
// created at: 31/01/2019

#include "Timer.h"

// Gestion du chronomètre
void runTimer(Timer &aTimer) {
  if(aTimer.activateTimer) {
    if(aTimer.tempTime == 0) {
      initTimer(aTimer);
    }
    incrementTime(aTimer);
    computeTime(aTimer);
  } else {
    pauseForTimer(aTimer);
  }
}

// Création du timer
void createTimer(Timer &aTimer) {
  aTimer.rtc.begin();
  aTimer.rtc.setY2kEpoch(0);
  aTimer.activateTimer = false;
}

// Réinitialisation du timer
void resetTimer(Timer &aTimer) {
  aTimer.timeInSeconds = 0;
  aTimer.tempTime = 0;
  aTimer.initialized = false;
}

// Initialiser le timer
void initTimer(Timer &aTimer) {
  if(! aTimer.initialized) {
    aTimer.rtc.setY2kEpoch(0);
    aTimer.initialized = true;
  }
}

// Mettre en pause le timer
void pauseForTimer(Timer &aTimer) {
  if(aTimer.tempTime != 0) {
    aTimer.timeInSeconds += aTimer.tempTime;
    aTimer.tempTime = 0;
    aTimer.initialized = false;
  }
}

// Décomposé le temps écoulé en jours, heures, minutes et secondes
void computeTime(Timer &aTimer) {
  unsigned long rest = aTimer.timeInSeconds + aTimer.tempTime;

  const unsigned long DAYS_IN_FRAMES    = 24*60*60*1;
  const unsigned long HOURS_IN_FRAMES   = 60*60*1;
  const unsigned long MINUTES_IN_FRAMES = 60*1;
  const unsigned long SECONDS_IN_FRAMES = 1;

  int nbDays = 0;
  int nbHours = 0;
  int nbMinutes = 0;
  int nbSeconds = 0;

  // Calculer les jours
  if(rest >= DAYS_IN_FRAMES) {
    nbDays = (int)(rest / DAYS_IN_FRAMES);
    rest = (rest - (nbDays * DAYS_IN_FRAMES));
  }
  // Calculer les heures
  if(rest >= HOURS_IN_FRAMES) {
    nbHours = (int)(rest / HOURS_IN_FRAMES);
    rest = (rest - (nbHours * HOURS_IN_FRAMES));
  }
  // Calculer les minutes
  if(rest >= MINUTES_IN_FRAMES) {
    nbMinutes = (int)(rest / MINUTES_IN_FRAMES);
    rest = (rest - (nbMinutes * MINUTES_IN_FRAMES));
  }
  // Calculer les secondes
  if(rest >= SECONDS_IN_FRAMES) {
    nbSeconds = (int)(rest / SECONDS_IN_FRAMES);
    rest = (rest - (nbSeconds * SECONDS_IN_FRAMES));
  }

  aTimer.valueOfTime[DAYS_NUMBER] = nbDays;
  aTimer.valueOfTime[HOURS_NUMBER] = nbHours;
  aTimer.valueOfTime[MINUTES_NUMBER] = nbMinutes;
  aTimer.valueOfTime[SECONDS_NUMBER] = nbSeconds;
}

void incrementTime(Timer &aTimer) {
  aTimer.tempTime = aTimer.rtc.getY2kEpoch();
}
