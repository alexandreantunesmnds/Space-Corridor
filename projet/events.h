/**
 * \file control.h
 * \brief Gestion des textures et affichage graphique
 * \author Alexandre Antunes && Corentin DROMER
 * \date 14 Avril 2021
 */
 #include "sdl2-light.h"
 #include "world.h"
 #ifndef EVENTS_H
 #define EVENTS_H
 
 void handle_events(SDL_Event *event,world_t *world);
 #endif