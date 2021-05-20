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
//on initialise les coordonnées de chaques murs
void init_walls (world_t *world){
    init_sprite(&world->table_murs[0],48,0,96,192);
    init_sprite(&world->table_murs[1],252,0,96,192);
    init_sprite(&world->table_murs[2],16,-352,32,160);
    init_sprite(&world->table_murs[3],188,-352,224,160);
    init_sprite(&world->table_murs[4],48,-672,96,192);
    init_sprite(&world->table_murs[5],252,-672,96,192);
}
void update_walls (world_t *world){
    for (int i = 0;i < N;i++){
        world->table_murs[i].y += world->vy;
        handle_sprites_collision(&world->spaceship, &world->table_murs[i],world,1); //gestion de la collision pour tous les murs et on passe le paramètre disappear à 1 pour demander à faire disparaître le vaisseau
    }
}

void init_data(world_t * world){
        if (world->NB_LIVES > 0){
            //on n'est pas à la fin du jeu
            world->gameover = 0;
        }
        //on place le vaisseau
        init_sprite(&(world->spaceship),SCREEN_WIDTH/2,SCREEN_HEIGHT-SHIP_SIZE,SHIP_SIZE,SHIP_SIZE);
        world->spaceship.visible = 0;
        //Test de la position du vaisseau
        //print_sprite(&(world->spaceship));
        //On place la ligne d'arrivée 
        init_sprite(&(world->finish_line),SCREEN_WIDTH/2,-960,SCREEN_WIDTH,FINISH_LINE_HEIGHT);
        world->finish_line.visible = 0;
        //Test de la position de la ligne d'arrivée
        //print_sprite(&(world->finish_line));
        //on initialise la vitesse de déplacement
        world->vy = INITIAL_SPEED;
        //on place le mur de météorites
        /*init_sprite(&world->mur, SCREEN_WIDTH/2-METEORITE_SIZE/2, SCREEN_HEIGHT/2, 3*METEORITE_SIZE, 7*METEORITE_SIZE);
        world->mur.visible = 0;*/
        //on place le tableau de murs
        init_walls(world);
        init_sprite(&world->lives, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, LIVES_SIZE*3, 1*LIVES_SIZE);

}

void init_lives(world_t * world){
    world->NB_LIVES=3;
}


int timer(world_t *world){
  if (world->vy!=0){
      world->time=SDL_GetTicks()/1000;
  }
  //printf("\n timer: %d \n",world->time);
  return world->time;
}

void clean_data(world_t *world){
    /* utile uniquement si vous avez fait de l'allocation dynamique (malloc); la fonction ici doit permettre de libérer la mémoire (free) */
    
}

int is_game_over(world_t *world){
    return world->gameover;
}

void update_data(world_t *world){
    world->finish_line.y += world->vy;
    update_walls(world);
    //gestion de la collision
    handle_sprites_collision(&world->spaceship, &world->finish_line,world,0);
    //gestion du temps
    too_late(world);
	left_limit_screen(world);
	right_limit_screen(world);
}
