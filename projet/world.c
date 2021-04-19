/**
 * \file world.c
 * \brief Définition et gestion des données du monde
 * \author Alexandre ANTUNES && Corentin DROMER
 * \date 14 Avril 2021
 */
#include "sdl2-light.h"
#include "constantes.h"
#include "world.h"
#include "events.h"

void init_sprite(sprite_t *sprite, int x, int y, int w, int h){
    sprite->w = w;
    sprite->h = h;
    sprite->x = x;
    sprite->y = y;
}


void print_sprite (sprite_t* sprite){
    printf("Coordonnées : \n");
    printf("x : %d\n",sprite->x);
    printf("y : %d\n", sprite->y);
    printf("Hauteur : %d\n",sprite->h);
    printf("Largeur : %d\n",sprite->w);
}

void init_walls (world_t *world){
    

}

void init_data(world_t * world){
    
    //on n'est pas à la fin du jeu
    world->gameover = 0;
    //on place le vaisseau
    init_sprite(&(world->spaceship),SCREEN_WIDTH/2,SCREEN_HEIGHT-SHIP_SIZE,SHIP_SIZE,SHIP_SIZE);
    world->spaceship.visible = 0;
    //Test de la position du vaisseau
    //print_sprite(&(world->spaceship));
    //On place la ligne d'arrivée 
    init_sprite(&(world->finish_line),SCREEN_WIDTH/2,FINISH_LINE_HEIGHT,SCREEN_WIDTH,FINISH_LINE_HEIGHT);
    world->finish_line.visible = 0;
    //Test de la position de la ligne d'arrivée
    //print_sprite(&(world->finish_line));
    //on initialise la vitesse de déplacement
    world->vy = INITIAL_SPEED;
    //on place le mur de météorites
    init_sprite(&world->mur, SCREEN_WIDTH/2-METEORITE_SIZE/2, SCREEN_HEIGHT/2, 3*METEORITE_SIZE, 7*METEORITE_SIZE);
    world->mur.visible = 0;
}


void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    
}

int is_game_over(world_t *world){
    return world->gameover;
}


void update_data(world_t *world){
    world->finish_line.y += world->vy;
    world->mur.y += world->vy;
    //gestion de la collision
    handle_sprites_collision(&world->spaceship, &world->mur,world,1);
    handle_sprites_collision(&world->spaceship, &world->finish_line,world,0);
	left_limit_screen(world);
	right_limit_screen(world);
}
