//
//  game.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef nuPong_game_h
#define nuPong_game_h

typedef struct game_data game_data;

game_data* game_init();
void game_update(game_data*, float delta);
void game_render(game_data*);

#endif
