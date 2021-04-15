/**
 * \file main.c
 * \brief Programme principal initial du niveau 1
 * \author Mathieu Constant
 * \version 1.0
 * \date 18 mars 2021
 */
#include "sdl2-light.h"
<<<<<<< HEAD
#include "constante.h" //Inclus le fichier d'en tête constante qui gère les constantes
#include "graphique.h" //Inclus le fichier d'en tête graphique qui gère l'affichage graphique et la gestion des textures
#include "monde.h"  //Inclus le fichier d'en tête monde qui gère les définitions et données du monde



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

=======
#include "graphic.h"
#include "world.h"
#include "constantes.h"


>>>>>>> e1ce42115a0ab2b2593ae3469e50844a6134c929
/**
 *  \brief programme principal qui implémente la boucle du jeu
 */


int main( int argc, char* args[] )
{
    SDL_Event event;
    world_t world;
    textures_t textures;
    SDL_Renderer *renderer;
    SDL_Window *window;

    //initialisation du jeu
    init(&window,&renderer,&textures,&world);
    
    while(!is_game_over(&world)){ //tant que le jeu n'est pas fini
        
        //gestion des évènements
        handle_events(&event,&world);
        
        //mise à jour des données liée à la physique du monde
        update_data(&world);
        
        //rafraichissement de l'écran
        refresh_graphics(renderer,&world,&textures);
        
        // pause de 10 ms pour controler la vitesse de rafraichissement
        pause(10);
    }
    
    //nettoyage final
    clean(window,renderer,&textures,&world);
    
    /*on retourne 0 pour annoncer que le programme n'a pas d'erreurs*/
    return 0;
}
