// author: chris-scientist
// created at: 30/01/2019
// updated at: 02/02/2019

#ifndef PLATFORMER_CONSTANTES
#define PLATFORMER_CONSTANTES

// Largeur de l'écran
const int WIDTH_SCREEN = 80;

// Nombre de plateformes
const int NB_OF_PLATFORMS = 4;

// Pour paramétrer l'animation du personnage
const int MIN_INDEX_ANIMATION_HERO = 0;
const int MAX_INDEX_ANIMATION_HERO = 4;
const int INDEX_FOR_CHANGE_ANIMATION_HERO = 2;

// Etat du personnage
const int ON_THE_PLATFORM_STATE = 0;
const int FREE_FALL_STATE = 1;
const int PUSH_FOR_JUMP_STATE = 2;
const int JUMP_STATE = 3;

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

// Paramétrage du saut
const int ACCELERATION_FOR_JUMP = 1; // ... Hauteur maximum
const int HORIZONTAL_VELOCITY = 2; // ...... Vitesse horizontale
const int INIT_VERTICAL_VELOCITY = 8; // ... Vitesse verticale initiale

#endif
