// author: chris-scientist
// created at: 30/01/2019
// updated at: 31/01/2019

#ifndef PLATFORMER_CONSTANTES
#define PLATFORMER_CONSTANTES

// Nombre de plateformes
const int NB_OF_PLATFORMS = 4;

// Pour un personnage de 13 pixels de haut sur 8 pixels de large
const int WIDTH_HERO = 8;
const int HEIGHT_HERO = 13;
const int UNDER_CENTER_X_HERO = 4; // à droite du héro
const int UNDER_CENTER_Y_HERO = 6;
const int OVER_CENTER_X_HERO = 4; // à gauche du héro
const int OVER_CENTER_Y_HERO = 7;

// Pour une plateforme de 8 pixels de haut sur 8 pixels de large
const int HEIGHT_PLATFORM = 8;
const int WIDTH_PLATFORM = 8;
const int OVER_CENTER_X_PLATFORM = 4;
const int OVER_CENTER_Y_PLATFORM = 4;

// Pour le sol de 10 pixels de haut sur 8 pixels de large
const int HEIGHT_GROUND = 10;
const int WIDTH_GROUND = 8;
const int OVER_CENTER_X_GROUND = 4;
const int OVER_CENTER_Y_GROUND = 5;

// Pour une colline de 16 pixels de haut sur 8 pixels de large
const int HEIGHT_HILL = 16;
const int WIDTH_HILL = 8;
const int OVER_CENTER_X_HILL = 4;
const int OVER_CENTER_Y_HILL = 8;

// Gravité
const int GRAVITY = 1;

#endif
