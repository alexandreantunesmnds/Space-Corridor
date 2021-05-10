/**
 * \file graphic.h
 * \brief Gestion des textures et affichage graphique
 * \author Alexandre Antunes && Corentin DROMER
 * \date 14 Avril 2021
 */
 #ifndef GRAPHIC_H
 #define GRAPHIC_H


#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "world.h"
/**
 * \brief Structure des textures du monde
*/
struct textures_s{
    SDL_Texture* background; /*!< Texture liée à l'image du fond de l'écran. */
    SDL_Texture* spaceship; /*!< Texture liée au vaisseau*/
	SDL_Texture* finish_line;/*!< Texture liée à la ligne d'arrivée*/
    SDL_Texture* meteorite; /*!< Texture liée au météorites */
    TTF_Font* font;
};
/**
 * \brief Type qui correspond aux textures du jeu
*/
typedef struct textures_s textures_t;

/**
 * \brief La fonction permet d'appliquer le sprite sur le renderer à une position donnée. La hauteur et la largeur est la même que celle de la texture.
 * \param texture  la texture que l'on va appliquer
 * \param renderer le renderer qui va recevoir la texture
 * \param sprite va appliquer la texture associée au sprite sur le renderer à la position indiquée dans le sprite
*/
void apply_sprite(SDL_Texture *texture,SDL_Renderer *renderer,sprite_t *sprite);

/**
 * \brief La fonction nettoie les textures
 * \param textures les textures
*/

void clean_textures(textures_t *textures);

/**
 * \brief La fonction les textures des météorites
 * \param renderer le renderer
 * \param world les données du monde
 * \param textures les textures du jeu
 */

void build_wall(SDL_Renderer *renderer, world_t *world,textures_t *textures);

/**
 * \brief La fonction initialise les texures
 * \param screen la surface correspondant à l'écran de jeu
 * \param textures les textures du jeu
*/

void init_textures(SDL_Renderer *renderer, textures_t *textures);


/**
 * \brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu
 * \param renderer le renderer
 * \param textures les textures du jeu
*/

void apply_background(SDL_Renderer *renderer, textures_t *textures);

/**
 * \brief La fonction rafraichit l'écran en fonction de l'état des données du monde
 * \param renderer le renderer
 * \param world les données du monde
 * \param textures les textures du jeu
 */

void refresh_graphics(SDL_Renderer *renderer, world_t *world,textures_t *textures);

/**
* \brief fonction qui nettoie le jeu: nettoyage de la partie graphique (SDL), nettoyage des textures, nettoyage des données
* \param window la fenêtre du jeu
* \param renderer le renderer
* \param textures les textures
* \param world le monde
*/

void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world);

/**
 * \brief fonction qui initialise le jeu: initialisation de la partie graphique (SDL), chargement des textures, initialisation des données
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param textures les textures
 * \param wordl le monde
 */

void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world);

void message(SDL_Renderer *renderer, world_t *world,textures_t *textures);
#endif