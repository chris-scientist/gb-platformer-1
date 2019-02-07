// author: chris-scientist
// created at: 30/01/2019
// updated at: 07/02/2019

#ifndef PLATFORMER_CONSTANTES
#define PLATFORMER_CONSTANTES

#include <Gamebuino-Meta.h>

#define DEBUG_PLATFORMER true

// Etat du jeu
const int HOME_STATE = 0;
const int LAUNCH_PLAY_STATE = 1;
const int PLAY_STATE = 2;
const int GAME_IS_FINISH = 3;
const int GAME_OVER_STATE = 4;

// Type de plateforme
const int NO_PLATFORM_TYPE = 0;
const int GROUND_TYPE = 1;
const int PLATFORM_TYPE = 2;
const int HILL_TYPE = 3;

// Temps maximum d'une partie (en secondes)
const int MAX_TIME_OF_GAME = 20;

// Identifiant objet
const int KEY_OBJECT_ID = 0;
const int DOOR_OBJECT_ID = 1;

#if ! DEBUG_PLATFORMER // Mode debug inactif ===========================================

// Largeur de l'écran
const int WIDTH_SCREEN = 80;

// Nombre de plateformes
const int NB_OF_PLATFORMS = 4;

// Nombre d'objets
const int NB_OF_OBJECTS = 2;

// Identifiants des plateformes
const int NO_ID = 0;
const int ID_GROUND = 1;
const int ID_HILL_1 = 2;
const int ID_HILL_2 = 3;
const int ID_PLATFORM_1 = 4;

// Pour paramétrer l'animation du personnage
const int MIN_INDEX_ANIMATION_HERO = 0;
const int MAX_INDEX_ANIMATION_HERO = 4;
const int INDEX_FOR_CHANGE_ANIMATION_HERO = 2;

// Etat du personnage
const int ON_THE_PLATFORM_STATE = 0;
const int FREE_FALL_STATE = 1;
const int PUSH_FOR_JUMP_STATE = 2;
const int JUMP_STATE = 3;
const int CONTACT_WITH_PLATFORM_STATE = 4;

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

// Pour une clé de 7 pixels de haut sur 10 pixels de large
const int HEIGHT_KEY = 7;
const int WIDTH_KEY = 10;
const int OVER_CENTER_X_KEY = 5;
const int OVER_CENTER_Y_KEY = 4;

// Pour une porte de 12 pixels de haut sur 10 pxels de large
const int HEIGHT_DOOR = 12;
const int WIDTH_DOOR = 10;
const int OVER_CENTER_X_DOOR = 5;
const int OVER_CENTER_Y_DOOR = 6;

// Type d'objet
const int NO_OBJECT = 0;
const int KEY_OBJECT = 1;
const int DOOR_OBJECT = 2;

// Etat clé
const int KEY_ON_THE_PLATFORM = 0;
const int KEY_COLLECTED = 1;

// Etat porte
const int DOOR_CLOSED = 0;
const int DOOR_BTW_OPEN = 1;
const int DOOR_OPEN = 2;

// Gravité
const int GRAVITY = 1;

// Paramétrage du saut
const int HORIZONTAL_VELOCITY = 2; // ...... Vitesse horizontale
const int INIT_VERTICAL_VELOCITY = 8; // ... Vitesse verticale initiale

#else // Mode debug actif ==============================================================

// Couleur des box
const Color color4HeroR = BLUE;
const Color color4HeroL = LIGHTBLUE;
const Color color4HeroWithKey = DARKBLUE;
const Color color4Ground = BROWN;
const Color color4PlatformT = LIGHTGREEN;
const Color color4PlatformNotT = GREEN;
const Color color4Key = YELLOW;
const Color color4DoorClosed = GRAY;
const Color color4DoorOpen = DARKGRAY;

// Largeur de l'écran
const int WIDTH_SCREEN = 80;

// Nombre de plateformes
const int NB_OF_PLATFORMS = 4;

// Nombre d'objets
const int NB_OF_OBJECTS = 2;

// Identifiants des plateformes
const int NO_ID = 0;
const int ID_GROUND = 1;
const int ID_PLATFORM_1 = 2;
const int ID_PLATFORM_2 = 3;
const int ID_PLATFORM_3 = 4;

// Pour paramétrer l'animation du personnage
const int MIN_INDEX_ANIMATION_HERO = 0;
const int MAX_INDEX_ANIMATION_HERO = 4;
const int INDEX_FOR_CHANGE_ANIMATION_HERO = 2;

// Etat du personnage
const int ON_THE_PLATFORM_STATE = 0;
const int FREE_FALL_STATE = 1;
const int PUSH_FOR_JUMP_STATE = 2;
const int JUMP_STATE = 3;
const int CONTACT_WITH_PLATFORM_STATE = 4;

// Pour un personnage de 13 pixels de haut sur 8 pixels de large
const int WIDTH_HERO = 6;
const int HEIGHT_HERO = 8;
const int UNDER_CENTER_X_HERO = 3; // à droite du héro
const int UNDER_CENTER_Y_HERO = 4;
const int OVER_CENTER_X_HERO = 3; // à gauche du héro
const int OVER_CENTER_Y_HERO = 4;

// Pour une plateforme de 8 pixels de haut sur 8 pixels de large
const int HEIGHT_PLATFORM = 4;
const int WIDTH_PLATFORM = 8;
const int OVER_CENTER_X_PLATFORM = 4;
const int OVER_CENTER_Y_PLATFORM = 2;

// Pour le sol de 10 pixels de haut sur 8 pixels de large
const int HEIGHT_GROUND = 4;
const int WIDTH_GROUND = 8;
const int OVER_CENTER_X_GROUND = 4;
const int OVER_CENTER_Y_GROUND = 2;

// Pour une colline de 16 pixels de haut sur 8 pixels de large
const int HEIGHT_HILL = 16;
const int WIDTH_HILL = 8;
const int OVER_CENTER_X_HILL = 4;
const int OVER_CENTER_Y_HILL = 8;

// Pour une clé de 7 pixels de haut sur 10 pixels de large
const int HEIGHT_KEY = 4;
const int WIDTH_KEY = 8;
const int OVER_CENTER_X_KEY = 4;
const int OVER_CENTER_Y_KEY = 2;

// Pour une porte de 12 pixels de haut sur 10 pxels de large
const int HEIGHT_DOOR = 12;
const int WIDTH_DOOR = 10;
const int OVER_CENTER_X_DOOR = 5;
const int OVER_CENTER_Y_DOOR = 6;

// Type d'objet
const int NO_OBJECT = 0;
const int KEY_OBJECT = 1;
const int DOOR_OBJECT = 2;

// Etat clé
const int KEY_ON_THE_PLATFORM = 0;
const int KEY_COLLECTED = 1;

// Etat porte
const int DOOR_CLOSED = 0;
const int DOOR_BTW_OPEN = 1;
const int DOOR_OPEN = 2;

// Gravité
const int GRAVITY = 1;

// Paramétrage du saut
const int HORIZONTAL_VELOCITY = 2; // ...... Vitesse horizontale
const int INIT_VERTICAL_VELOCITY = 6; // ... Vitesse verticale initiale

#endif // Fin mode debug actif =========================================================

#endif
