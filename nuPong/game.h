//
//  game.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef nuPong_game_h
#define nuPong_game_h

typedef struct game_t game_t;

game_t* game_init();
void game_update(game_t*, float delta);
void game_render(game_t*);

#endif
