//
//  Ball.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Ball__
#define __nuPong__Ball__

#include "Game.h"

#include <OpenGL/glu.h>

class Ball : public IDynamicEntity {
    b2Body *body;
    GLUquadric *quadric;

    void applyRandomForce (float scale);
    b2Vec2 getStartingPosition() const;
public:
    Ball (b2World& world);

    virtual void render();
    virtual void update(float delta);
};


#endif /* defined(__nuPong__Ball__) */
