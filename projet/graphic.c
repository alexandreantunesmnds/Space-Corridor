/**
 * \file graphic.c
 * \brief Gestion des constantes
 * \author Alexandre Antunes && Corentin DROMER
 * \date 14 Avril 2021
 */
#include "sdl2-light.h"
#include "constantes.h"
#include "world.h"
#include "graphic.h"

void apply_sprite(SDL_Texture *texture,SDL_Renderer *renderer,sprite_t *sprite){
      apply_texture(texture, renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2) ;
}

void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->spaceship);
	clean_texture(textures->finish_line);
    clean_texture(textures->meteorite);
}


void build_wall(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    int y = world->mur.y - world->mur.h/2 + METEORITE_SIZE/2;
    for(int j = 0 ; j < world->mur.h/METEORITE_SIZE ; j++){
        int x = world->mur.x - world->mur.w/2 + METEORITE_SIZE/2;
        for(int i = 0 ; i < world->mur.w/METEORITE_SIZE ; i++){
            apply_texture(textures->meteorite, renderer, x, y);
            x += METEORITE_SIZE;
        }
        y += METEORITE_SIZE;
    }
}


void init_textures(SDL_Renderer *renderer, textures_t *textures){
    textures->background = load_image( "ressources/space-background.bmp",renderer);
	textures->spaceship = load_image( "ressources/spaceship.bmp",renderer);
	textures->finish_line = load_image( "ressources/finish_line.bmp",renderer);
    textures->meteorite = load_image( "ressources/meteorite.bmp",renderer);

    
}


void apply_background(SDL_Renderer *renderer, textures_t *textures){
    if(textures->background != NULL){
      apply_texture(textures->background, renderer, 0, 0);
    }
}

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


void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}


void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
	init_data(world);
    init_textures(*renderer,textures);
}
