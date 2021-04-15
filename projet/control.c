/**
 * \file control.c
 * \brief Gestion des constantes
 * \author Alexandre Antunes && Corentin DROMER
 * \date 14 Avril 2021
 */
#include "sdl2-light.h"
#include "world.h"
#include "constantes.h"
#include "control.h"

void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) {

        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if (event->type == SDL_QUIT) {
            //On indique la fin du jeu
            world->gameover = 1;
        }

         //si une touche est appuyée
         if(event->type == SDL_KEYDOWN){
            //si la touche appuyée est 'Echap'
             if(event->key.keysym.sym == SDLK_ESCAPE){
                 printf("La touche Echap est appuyée\n");
                 exit(0);
              }
            //si la touche appuyée est 'flèche haut'
             if(event->key.keysym.sym == SDLK_UP){
                 world->spaceship.y -= MOVING_STEP;
                 world->vy += 1;
              }
              //si la touche appuyée est 'flèche gauche'
             if(event->key.keysym.sym == SDLK_LEFT){
                 world->spaceship.x -= MOVING_STEP;
              }
              //si la touche appuyée est 'flèche bas'
             if(event->key.keysym.sym == SDLK_DOWN){
                 world->spaceship.y += MOVING_STEP;
                 world->vy -= 1;
              }
             //si la touche appuyée est 'flèche droite'
             if(event->key.keysym.sym == SDLK_RIGHT){
                 world->spaceship.x += MOVING_STEP;
             }
         }
    }
    }