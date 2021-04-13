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

/**
  * \brief Vitesse initiale de déplacement vertical des éléments du jeu 
*/

#define INITIAL_SPEED 2

struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* spaceship; /*!< Texture liée au vaisseau*/
	SDL_Texture* finish_line;/*!< Texture liée à la ligne d'arrivée*/
    SDL_Texture* meteorite; /*!< Texture liée au météorites */
};


/**
 * \brief Type qui correspond aux textures du jeu
*/

typedef struct textures_s textures_t;

/**
 * \brief Représentation des sprite
*/
 struct sprite_s{
	 int x; /*!< Coordonnées x du vaisseau */
	 int y; /*!< Coordonnées y du vaisseau */
	 int h; /*!< Hauteur h du vaisseau */
	 int w; /*!< Largeur w du vaisseau */
};
/**
 * \brief Type qui correspond aux sprites
 */
typedef struct sprite_s sprite_t;


/**
 * \brief Représentation du monde du jeu
*/

struct world_s{
    int gameover; /*!< Champ indiquant si l'on est à la fin du jeu */
	sprite_t spaceship;  /*!< Champ indiquant le vaisseau */
	sprite_t finish_line;  /*!< Champ indiquant la ligne d'arrivée */
    sprite_t mur; /*!< Champ indiquant le mur de météorites */
    int vy; /*!< Champ indiquant le déplacement des objets du monde*/
};

/**
 * \brief Type qui correspond aux données du monde
 */

typedef struct world_s world_t;

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
     init_sprite(&world->mur, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 3, 7);
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

/**
 * \brief La fonction permet d'appliquer le sprite sur le renderer à une position donnée. La hauteur et la largeur est la même que celle de la texture.
 * \param texture  la texture que l'on va appliquer
 * \param renderer le renderer qui va recevoir la texture
 * \param sprite va appliquer la texture associée au sprite sur le renderer à la position indiquée dans le sprite
*/
void apply_sprite(SDL_Texture *texture,SDL_Renderer *renderer,sprite_t *sprite){
      apply_texture(texture, renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2) ;
}


/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/

void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->spaceship);
	clean_texture(textures->finish_line);
    clean_texture(textures->meteorite);
}

/**
 * \brief La fonction les textures des météorites
 * \param renderer le renderer
 * \param world les données du monde
 * \param textures les textures du jeu
 */
void build_wall(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    int y = world->mur.y - world->mur.h*METEORITE_SIZE/2;
    for(int j = 0 ; j < world->mur.h ; j++){
        int x = world->mur.x - world->mur.w*METEORITE_SIZE/2;
        for(int i = 0 ; i < world->mur.w ; i++){
            apply_texture(textures->meteorite, renderer, x, y);
            x += METEORITE_SIZE;
        }
        y += METEORITE_SIZE;
    }
}

/**
 * \brief La fonction initialise les texures
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/space-background.bmp",renderer);
	textures->spaceship = load_image( "ressources/spaceship.bmp",renderer);
	textures->finish_line = load_image( "ressources/finish_line.bmp",renderer);
    textures->meteorite = load_image( "ressources/meteorite.bmp",renderer);

    
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
    apply_sprite(textures->spaceship, renderer, &(world->spaceship));
    apply_sprite(textures->finish_line, renderer,&(world->finish_line));
    //application des textures des météorites selon la taille et la largeur du mur de météorites
    build_wall(renderer, world,textures);
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
