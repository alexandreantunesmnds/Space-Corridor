/**
 * \file tests.c
 * \brief Tests des fonctions liées aux données du monde
 * \author Alexandre ANTUNES && Corentin DROMER
 * \date 14 Avril 2021
 */

#include "world.h"
#include "events.h"
#include "constantes.h"
// Architecture de tests
 void test_init_sprite_param(sprite_t *sprite, int x, int y, int w, int h){
     init_sprite(sprite,x,y,w,h);
     print_sprite(sprite);
 }

 void test_init_sprite(){
     sprite_t cobaye;
     sprite_t crashtest;
     test_init_sprite_param(&cobaye,10,12,7,7);
     test_init_sprite_param(&crashtest,10,12,21,21);
 }
 //Test de la fonction limite gauche de l'écran
void test_left_limit_screen_param(world_t *world){
    sprite_t spaceship;
    init_sprite(&(world->spaceship),-405,10,SHIP_SIZE,SHIP_SIZE);
	if (world->spaceship.x-world->spaceship.w/2 < 0){
        print_sprite(&world->spaceship);
		printf("Le sprite touche la bordure gauche\n");
        printf("Le sprite est remis en place :\n");
        world->spaceship.x = world->spaceship.x + SHIP_SIZE;
        print_sprite(&world->spaceship);
	}
	else {
		printf("Le sprite ne touche pas la bordure gauche\n");
	}
}

void test_left_limit_screen(){
    world_t world;
    test_left_limit_screen_param(&world);
}

//Test de la fonction limite droite de l'écran
void test_right_limit_screen_param(world_t *world){
    sprite_t spaceship;
    init_sprite(&(world->spaceship),405,10,SHIP_SIZE,SHIP_SIZE);
    if (world->spaceship.x+world->spaceship.w/2 > SCREEN_WIDTH){
        print_sprite(&world->spaceship);
		printf("Le sprite touche la bordure droite\n");
        world->spaceship.x = world->spaceship.x - SHIP_SIZE;
        printf("Le sprite est remis en place :\n");
        print_sprite(&world->spaceship);
	}
	else {
		printf("Le sprite ne touche pas la bordure droite\n");
	}
}

void test_right_limit_screen(){
    world_t world;
    test_right_limit_screen_param(&world);
}

 //Test de la collision de sprites
void test_sprites_collide_param(sprite_t *sp1, sprite_t *sp2){
    if(sprites_collide(sp1, sp2)){
        printf("Il y'a collision\n");
    }
    else {
        printf("Il n'y a pas collision\n");
    }
}

void test_sprites_collide(){
    sprite_t cobaye;
    sprite_t crashtest;
    test_init_sprite_param(&cobaye,10,12,45,45);
    test_init_sprite_param(&crashtest,10,12,21,21);
    test_sprites_collide_param(&cobaye,&crashtest);
}

 //Test de la gestion de collision de sprites
void handle_sprites_collision_param(sprite_t *sp1, sprite_t *sp2, world_t *world, int make_disappear){
    handle_sprites_collision(sp1,sp2,world,make_disappear);
    printf("La vitesse du monde vaut après collision : %d\n",world->vy);
    if (sp1->visible==1){
        printf("Le sprite a disparu suite a la collision avec l'autre\n");
    }
    else{
        printf("Le sprite n'a pas disparu");
    }
    
}

void test_handle_sprites_collision(){
    sprite_t cobaye;
    sprite_t crashtest;
    world_t world;
    test_init_sprite_param(&cobaye,10,12,45,45);
    test_init_sprite_param(&crashtest,10,12,21,21);
    handle_sprites_collision_param(&cobaye,&crashtest,&world, 1);
}

 //Test de la fonction initialisation du tableau de murs
void test_init_walls_params(world_t *world){
    init_walls(world);
    for (int i = 0; i< N ;i++){
        print_sprite(&world->table_murs[i]);
    }
}

void test_init_walls(){
    world_t world;
    test_init_walls_params(&world);
}

int main(int argc, char * argv[]){
    test_init_sprite();
    test_left_limit_screen();
    test_right_limit_screen();
    test_sprites_collide();
    test_handle_sprites_collision();
    test_init_walls();
    return 0;
}