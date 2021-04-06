/**
 * \file main.c
 * \brief Programme principal initial du niveau 1
 * \author Mathieu Constant
 * \version 1.0
 * \date 18 mars 2021
 */
#include "sdl2-light.h"

/**
 * \brief Largeur de l'écran
*/


#define SCREEN_WIDTH 300

/**
 * \brief Hauteur de l'écran
*/

#define SCREEN_HEIGHT 480

/**
 * \brief Taille du vaisseau
*/

#define SHIP_SIZE 32

/**
 * \brief Taille d'une météorite
*/

#define METEORITE_SIZE 32

/**
 * \brief Hauteur de la ligne d'arrivée
*/

#define FINISH_LINE_HEIGHT 10

/**
 * \brief Pas de déplacement horizontalement du vaisseau
*/

#define MOVING_STEP 10

/**
 * \brief Représentation pour stocker les textures nécessaires à l'affichage graphique
*/

struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* sprite; /*!< Texture liée au sprite joueur */
	SDL_Texture* finish_line;
};


/**
 * \brief Type qui correspond aux textures du jeu
*/

typedef struct textures_s textures_t;


/**
 * \brief Représentation du monde du jeu
*/

struct world_s{
    int x; /*!< Coordonnées x du joueur */
    int y; /*!< Coordonnées y du joueur */
	int h; /*!< Hauteur du joueur */
	int w; /*!< Largeur du joueur */
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */
	int spaceship;  /*!< Champ indiquant le vaisseau */
	int finish_line;  /*!< Champ indiquant la ligne d'arrivée */
	int finish_line_x;
	int finish_line_y;
};

/**
 * \brief Type qui correspond aux données du monde
 */

typedef struct world_s world_t;

 struct sprite_s{
	 int x; /*!< Coordonnées x du vaisseau */
	 int y; /*!< Coordonnées y du vaisseau */
	 int h; /*!< Hauteur h du vaisseau */
	 int w; /*!< Largeur w du vaisseau */
	 int finish_line_x;
	 int finish_line_y;
	 int finish_line;
};



typedef struct sprite_s sprite_t;

void init_sprite(sprite_t *sprite, int x, int y, int w, int h,int finish_line_x,int finish_line_y){
	w = 32;
	h = 32;
	x = SCREEN_WIDTH/2-SHIP_SIZE/2;
    y = SHIP_SIZE*13.5;
}



/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */


void init_data(world_t * world){
    
    //on n'est pas à la fin du jeu
    world->gameover = 0;
	world->w = 32;
	world->h = 32;
	world->x = SCREEN_WIDTH/2-SHIP_SIZE/2;
    world->y = SHIP_SIZE*13.5;
	world->finish_line_y = FINISH_LINE_HEIGHT /9;

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
/* A COMPLETER */
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
            //si la touche appuyée est 'Z'
             if(event->key.keysym.sym == SDLK_z){
                 world->y -= MOVING_STEP;
              }
              //si la touche appuyée est 'Q'
             if(event->key.keysym.sym == SDLK_q){
                 world->x -= MOVING_STEP;
              }
              //si la touche appuyée est 'S'
             if(event->key.keysym.sym == SDLK_s){
                 world->y += MOVING_STEP;
              }
             //si la touche appuyée est 'D'
             if(event->key.keysym.sym == SDLK_d){
                 world->x += MOVING_STEP;
              }
         }
    }
}

/**
 * \brief La fonction permet d'appliquer le sprite sur le renderer à une position donnée. La hauteur et la largeur est la même que celle de la texture.
 * \param texture  la texture que l'on va appliquer
 * \param renderer le renderer qui va recevoir la texture
 * \param sprite va appliquer la texture associée au sprite sur le renderer à la position indiquée dans le sprite
*/
void apply_sprite(SDL_Texture *texture,SDL_Renderer *renderer,sprite_t *sprite){
      apply_texture(texture, renderer, sprite->x, sprite->y);
	  apply_texture(texture, renderer, sprite->finish_line_x, sprite->finish_line_y);
}


/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/

void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->sprite);
	clean_texture(textures->finish_line);
}



/**
 * \brief La fonction initialise les texures
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void  init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/space-background.bmp",renderer);
	textures->sprite = load_image( "ressources/spaceship.bmp",renderer);
	textures->finish_line = load_image( "ressources/finish_line.bmp",renderer);

    
}


/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param textures les textures du jeu
*/

void apply_background(SDL_Renderer *renderer, textures_t *textures){
    if(textures->background != NULL){
      apply_texture(textures->background, renderer, 0, 0);
    }
}




/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer le renderer
 * \param world les données du monde
 * \param textures les textures du jeu
 */

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    
    //on vide le renderer
    clear_renderer(renderer);
    
    //application des textures dans le renderer
    apply_background(renderer, textures);
    apply_texture(textures->sprite, renderer, world->x, world->y);
	apply_texture(textures->finish_line, renderer, world->finish_line_x, world->finish_line_y);
    
    // on met à jour l'écran
    update_screen(renderer);
}



/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}



/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param wordl le monde
 */

void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
	 init_data(world);
    init_textures(*renderer,textures);
}


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
