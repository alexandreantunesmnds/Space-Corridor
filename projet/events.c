/**
 * \file events.c
 * \brief Gestion des évênements
 * \author Alexandre Antunes && Corentin DROMER
 * \date 14 Avril 2021
 */
#include "sdl2-light.h"
#include "events.h"
#include "world.h"
#include "constantes.h"

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
                 world->gameover = 1;
              }
            //si la touche appuyée est 'flèche haut'
             if(event->key.keysym.sym == SDLK_UP){
                 world->vy += 1;
              }
              //si la touche appuyée est 'flèche gauche'
             if(event->key.keysym.sym == SDLK_LEFT){
                 world->spaceship.x -= MOVING_STEP;
              }
              //si la touche appuyée est 'flèche bas'
             if(event->key.keysym.sym == SDLK_DOWN){
                 world->vy -= 1;
              }
             //si la touche appuyée est 'flèche droite'
             if(event->key.keysym.sym == SDLK_RIGHT){
                 world->spaceship.x += MOVING_STEP;
             }
         }
    }
    }


    int sprites_collide(sprite_t *sp1, sprite_t *sp2){
        if (((abs(sp1->x - sp2->x)) <= (sp1->w + sp2->w)/2) && ((abs(sp1->y - sp2->y)) <= (sp1->h + sp2->h)/2)){
            return 1;
        }
        else{
            return 0;
        }
    }

    void handle_sprites_collision(sprite_t *sp1, sprite_t *sp2, world_t *world){
        if (sprites_collide(sp1,sp2)){
            world->vy = 0;
            world->make_dissapear = 1;
        }
    }