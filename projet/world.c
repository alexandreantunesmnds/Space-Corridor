/**
 * \file world.c
 * \brief Définition et gestion des données du monde
 * \author Alexandre ANTUNES && Corentin DROMER
 * \date 14 Avril 2021
 */
#include "sdl2-light.h"
#include "constantes.h"


/**
 * \brief La fonction initialise les sprites
 * \param sprite les données du sprite
 * \param x coordonnées en abscisse
 * \param y coordonnées en ordonnée
 * \param w taille du sprite en largeur
 * \param h taille du sprite en hauteur
 */
void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
    sprite->w = w;
    sprite->h = h;
    sprite->x = x;
    sprite->y = y;
}

/**
 * \brief La fonction affiche les coordonnées du sprite
 * \param sprite les données du sprite
 */
void print_sprite (sprite_t* sprite){
    printf("Coordonnées : \n");
    printf("x : %d\n",sprite->x);
    printf("y : %d\n", sprite->y);
    printf("Hauteur : %d\n",sprite->h);
    printf("Largeur : %d\n",sprite->w);
}

/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */


void init_data(world_t * world){
    
    //on n'est pas à la fin du jeu
    world->gameover = 0;
    //on place le vaisseau
    init_sprite(&(world->spaceship),SCREEN_WIDTH/2,SCREEN_HEIGHT-SHIP_SIZE,SHIP_SIZE,SHIP_SIZE);
    //Test de la position du vaisseau
    print_sprite(&(world->spaceship));
    //On place la ligne d'arrivée 
    init_sprite(&(world->finish_line),SCREEN_WIDTH/2,FINISH_LINE_HEIGHT,SCREEN_WIDTH,FINISH_LINE_HEIGHT);
    //Test de la position de la ligne d'arrivée
    print_sprite(&(world->finish_line));
    //on initialise la vitesse de déplacement
    world->vy = INITIAL_SPEED;
    //on place le mur de météorites
    init_sprite(&world->mur, SCREEN_WIDTH/2-METEORITE_SIZE/2, SCREEN_HEIGHT/2, 3*METEORITE_SIZE, 7*METEORITE_SIZE);
}

/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */


void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    
}

/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world){
    return world->gameover;
}

/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param les données du monde
 */

void update_data(world_t *world){
    world->finish_line.y += world->vy;
    world->mur.y += world->vy;
}

/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */

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