/**
 * \file tests.c
 * \brief Tests des fonctions liées aux données du monde
 * \author Alexandre ANTUNES && Corentin DROMER
 * \date 14 Avril 2021
 */

#include "world.h"

 void test_init_sprite_param(sprite_t *sprite, int x, int y, int w, int h){
     init_sprite(sprite,x,y,w,h);
     print_sprite(sprite);
 }

 void test_init_sprite(){
     sprite_t cobaye;
     test_init_sprite_param(&cobaye,10,12,7,7);
 }



int main(int argc, char * argv[]){
    test_init_sprite();

    return 0;
}