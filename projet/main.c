/**
 * \file main.c
 * \brief Programme principal initial du niveau 1
 * \author Mathieu Constant
 * \version 1.0
 * \date 18 mars 2021
 */
#include "sdl2-light.h"
#include "graphic.h"
#include "world.h"
#include "constantes.h"
#include "events.h"


/**
 *  \brief programme principal qui implémente la boucle du jeu
 */


int main( int argc, char* args[] )
{
    SDL_Event event;
    world_t world;
    resources_t resources;
    SDL_Renderer *renderer;
    SDL_Window *window;

    //initialisation du jeu
    init(&window,&renderer,&resources,&world);
	
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return -1;
    
    while(!is_game_over(&world)){ //tant que le jeu n'est pas fini
        
        //gestion des évènements
        handle_events(&event,&world);
        
        //mise à jour des données liée à la physique du monde
        update_data(&world);
        
        //rafraichissement de l'écran
        refresh_graphics(renderer,&world,&resources);
        
        // pause de 10 ms pour controler la vitesse de rafraichissement
        pause(10);
		
		
    }
    
    //nettoyage final
    clean(window,renderer,&resources,&world);
    
    /*on retourne 0 pour annoncer que le programme n'a pas d'erreurs*/
	return 0;

}
