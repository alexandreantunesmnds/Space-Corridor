/**
 * \file control.h
 * \brief Gestion des textures et affichage graphique
 * \author Alexandre Antunes && Corentin DROMER
 * \date 14 Avril 2021
 */
 #include "sdl2-light.h"
 #include "world.h"
 #ifndef CONTROL_H
 #define CONTROL_H
 
 void handle_events(SDL_Event *event,world_t *world);
 #endif