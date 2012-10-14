//
//  game.c
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include <GL/glfw.h>

#include <stdlib.h>

typedef struct game_data {
    int a;
} game_data;

game_data* game_init()
{
    game_data* game = (game_data*)calloc(1, sizeof(game_data));
    
    return game;
}

void game_update(game_data* game, float delta)
{
    
}

void game_render(game_data* game)
{
    
}
