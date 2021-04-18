/**
 * \file world.h
 * \brief Signature des fonctions de définition et gestion des données du monde
 * \author Alexandre ANTUNES && Corentin DROMER
 * \date 14 Avril 2021
 */
#ifndef WORLD_H
#define WORLD_H
#include "constantes.h"
#include "sdl2-light.h"
/**
 * \brief Représentation des sprite
*/
 struct sprite_s{
	 int x; /*!< Coordonnées x du sprite */
	 int y; /*!< Coordonnées y du sprite */
	 int h; /*!< Hauteur h du sprite */
	 int w; /*!< Largeur w du sprite */
	 int visible; /*! Champ indiquant la visibilité du sprite */
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
	sprite_t table_murs[N]; /*!< Champ correspondant au tableau de météorites*/
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
void init_sprite(sprite_t *sprite, int x, int y, int w, int h);

/**
 * \brief La fonction affiche les coordonnées du sprite
 * \param sprite les données du sprite
 */
void print_sprite (sprite_t* sprite);

/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */


void init_data(world_t * world);

/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */


void clean_data(world_t *world);

/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world);

/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param world les données du monde
 */

void update_data(world_t *world);

/**
<<<<<<< HEAD
 * \brief La fonction donne la position des murs pour former un couloir
 * \param world les données du monde
 */
void init_walls (world_t *world);
=======
 * \brief La fonction met à jour les données en tenant compte de la position du vaisseau dans le monde pour pas qu'il dépasse la droite du monde
 * \param les données du monde
 */
 
void left_limit_screen(world_t *world);

/**
 * \brief La fonction met à jour les données en tenant compte de la position du vaisseau dans le monde pour pas qu'il dépasse la droite du monde
 * \param les données du monde
 */

void right_limit_screen(world_t *world);

>>>>>>> cc4eb4e05f2fa5b0806e71495e3bd036bf7eb8f2

#endif