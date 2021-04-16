/**
 * \file tests.c
 * \brief Tests des fonctions liées aux données du monde
 * \author Alexandre ANTUNES && Corentin DROMER
 * \date 14 Avril 2021
 */

#include "world.h"
#include "events.h"

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

void handle_sprites_collision_param(sprite_t *sp1, sprite_t *sp2, world_t *world){
    handle_sprites_collision(sp1,sp2,world);
    printf("La vitesse du monde vaut après collision : %d",world->vy);
    
}

void test_handle_sprites_collision(){
    sprite_t cobaye;
    sprite_t crashtest;
    world_t world;
    test_init_sprite_param(&cobaye,10,12,45,45);
    test_init_sprite_param(&crashtest,10,12,21,21);

    handle_sprites_collision_param(&cobaye,&crashtest,&world);
}


int main(int argc, char * argv[]){
    test_init_sprite();
    test_sprites_collide();
    test_handle_sprites_collision();
    return 0;
}