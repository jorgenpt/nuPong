//
//  Game.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef nuPong_game_state_h
#define nuPong_game_state_h

#include <Box2D.h>
#include "Wall.h"
#include "Paddle.h"

class Game {
    class Ball {
    public:
        Ball (b2World& world);
        void ApplyRandomForce (float scale);
        b2Body *body;
        GLUquadric *quadric;
    };

    b2World world;
    Paddle paddle;
    Ball ball;
    Wall walls[3];

public:
    Game();
    void update(float delta);
    void render();
};

#endif
