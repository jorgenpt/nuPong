//
//  GameState.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef nuPong_game_state_h
#define nuPong_game_state_h

#include "vector2.h"

class GameState {
    class Paddle {
    public:
        Paddle ();
        float location;
        float speed;
        float width;
    };
    class Ball {
    public:
        Ball ();
        vector2_t position;
        vector2_t velocity;
    };
    
    Paddle paddle;
    Ball ball;

public:
    void update(float delta);
    void render();
};

#endif
