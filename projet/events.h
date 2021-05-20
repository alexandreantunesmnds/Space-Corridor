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

 /**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */
 void handle_events(SDL_Event *event,world_t *world);

/**
 * \brief La fonction met à jour les données en tenant compte de la position du vaisseau dans le monde pour pas qu'il dépasse la gauche du monde
 * \param world données du monde
 */
 
void left_limit_screen(world_t *world);

/**
 * \brief La fonction met à jour les données en tenant compte de la position du vaisseau dans le monde pour pas qu'il dépasse la droite du monde
 * \param world données du monde
 */

void right_limit_screen(world_t *world);

/**
 * \brief La fonction renvoie 1 si il y a collision 0 sinon
 * \param sp1 sprite 1
 * \param sp2 sprite 2 
 */
 int sprites_collide(sprite_t *sp1, sprite_t *sp2);

/**
 * \brief La fonction renvoie 1 si il y a collision 0 sinon
 * \param sp1 sprite 1
 * \param sp2 sprite 2 
 * \param world les données du monde
 * \param make_disappear paramètre à 1 fait dispara$itre le sprite
 */
 void handle_sprites_collision(sprite_t *sp1, sprite_t *sp2, world_t *world, int make_disappear);

 void lost_life(world_t* world);

 void too_late(world_t* world);
 #endif