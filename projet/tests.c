/**
 * \file tests.c
 * \brief Tests des fonctions liées aux données du monde
 * \author Alexandre ANTUNES && Corentin DROMER
 * \date 14 Avril 2021
 */

#include "world.h"
#include "events.h"
#include "constantes.h"

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

void test_sprites_collide_param(sprite_t *sp1, sprite_t *sp2){
    if(sprites_collide(sp1, sp2)){
        printf("Il y'a collision");
    }
    else {
        printf("Il n'y a pas collision");
    }
}

void test_sprites_collide(){
    sprite_t cobaye;
    sprite_t crashtest;
    test_init_sprite_param(&cobaye,10,12,45,45);
    test_init_sprite_param(&crashtest,10,12,21,21);
    test_sprites_collide_param(&cobaye,&crashtest);
}

void test_left_limit_screen_param(world_t *world){
    print_sprite(world->spaceship);
    left_limit_screen(&world);
    print_sprite(world->spaceship);
}

void test_left_limit_screen(){
    world_t world;
    test_left_limit_screen_param(&world);
    test_left_limit_screen_param(&world);
}
void test_right_limit_screen_param(){

}
void test_right_limit_screen_param(world_t *world){

}
*/
void handle_sprites_collision_param(sprite_t *sp1, sprite_t *sp2, world_t *world, int make_disappear){ //revoir les paramètres (avec make_disappear)
    handle_sprites_collision(sp1,sp2,world,make_disappear);
    printf("La vitesse du monde vaut après collision : %d",world->vy);
    if (sp1->visible==1){
        printf("Le sprite a disparu suite a la collision avec l'autre");
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


int main(int argc, char * argv[]){
    test_init_sprite();
    //test_left_limit_screen();
    //test_right_limit_screen();
    test_sprites_collide();
    test_handle_sprites_collision();
	test_left_limit_screen(world_t *world);
    return 0;
}