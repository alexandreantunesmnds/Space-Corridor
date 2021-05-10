/**
 * \file graphic.c
 * \brief Gestion des constantes
 * \author Alexandre Antunes && Corentin DROMER
 * \date 14 Avril 2021
 */
#include "sdl2-light.h"
#include"sdl2-ttf-light.h"
#include "constantes.h"
#include "world.h"
#include "graphic.h"

void apply_sprite(SDL_Texture *texture,SDL_Renderer *renderer,sprite_t *sprite){
    if (sprite->visible == 0){
      apply_texture(texture, renderer, sprite->x - sprite->w/2, sprite->y - sprite->h/2) ;
    }
}

void clean_textures(textures_t *textures){
    clean_texture(textures->background);
    clean_texture(textures->spaceship);
	clean_texture(textures->finish_line);
    clean_texture(textures->meteorite);
    clean_font(textures->font);
}

/*
void build_wall(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    for (int i = 0;i < N ;i++){
        int y = world->mur.y - world->mur.h/2 + METEORITE_SIZE/2; // on determine la place que vas occuper le mur en ordonnée
        for(int j = 0 ; j < world->mur.h/METEORITE_SIZE ; j++){
            int x = world->mur.x - world->mur.w/2 + METEORITE_SIZE/2;//puis en abscisses
            for(int i = 0 ; i < world->mur.w/METEORITE_SIZE ; i++){
                apply_texture(textures->meteorite, renderer, x, y);
                x += METEORITE_SIZE;
            }
            y += METEORITE_SIZE;
        }
    }
}*/

void apply_wall(SDL_Renderer *renderer, world_t *world,textures_t *textures, int k){
    int h = world->table_murs[k].h; //Nombre max de météores en hauteur
    int w = world->table_murs[k].w; //Nombre max de météores en largeur

    int x = world->table_murs[k].x - w/2;
    int y = world->table_murs[k].y - h/2;

    for (int i = 0 ; i < h/METEORITE_SIZE ; i ++){
        for (int j = 0 ; j < w/METEORITE_SIZE ; j++){
            apply_texture(textures->meteorite,renderer, x + j*METEORITE_SIZE, y + i*METEORITE_SIZE);
        }
    }
}

void apply_walls(SDL_Renderer *renderer, world_t *world,textures_t *textures){
    for (int k = 0 ; k < N ; k ++){
        apply_wall(renderer, world, textures, k);
    }
}

void message(SDL_Renderer *renderer, world_t *world,textures_t *textures){
      char text[20];
    if (world->gameover==1){
        sprintf(text,"You finished in %d s!",world->time);
        apply_text(renderer,SCREEN_WIDTH/2-110/2,SCREEN_HEIGHT/2-60/2,150,60,text,textures->font);
    }
    else if (world->gameover==2){
        sprintf(text,"You lose!");
        apply_text(renderer,SCREEN_WIDTH/2-110/2,SCREEN_HEIGHT/2-60/2,110,60,text,textures->font);
    }
}

void init_textures(SDL_Renderer *renderer, textures_t *textures){
    load_font("ressources/arial.ttf",14);
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
    //build_wall(renderer, world,textures);
    //application des textures du tableau de météorites selon la taille et la largeur du mur de météorites
    apply_walls(renderer,world,textures);
    //Affichage du chronomètre
    char text[20];
    sprintf(text,"Timer:%d",timer(world));
    apply_text(renderer,10,10,100,50,text,textures->font);
    //message de fin
    message(renderer,world,textures);
    // on met à jour l'écran
    update_screen(renderer);
}


void clean(SDL_Window *window, SDL_Renderer * renderer, textures_t *textures, world_t * world){
    clean_data(world);
    clean_textures(textures);
    clean_sdl(renderer,window);
}


void init(SDL_Window **window, SDL_Renderer ** renderer, textures_t *textures, world_t * world){
    init_ttf();
    init_sdl(window,renderer,SCREEN_WIDTH, SCREEN_HEIGHT);
	init_data(world);
    init_textures(*renderer,textures);
}
