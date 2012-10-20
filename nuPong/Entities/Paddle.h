//
//  Paddle.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Paddle__
#define __nuPong__Paddle__

#include "Game.h"

#include <OpenGL/OpenGL.h>

class Paddle : public Entity {
    GLuint vertexVboId, indexVboId;
    b2Body* body;
    b2Body* createBoxBody(b2World& world, b2Vec2 topLeft, b2Vec2 bottomRight);

    b2AABB getAABB () const;

public:
    Paddle(b2World& world, float width);

    virtual void render();
    virtual void update(float delta);

    float getHeight() const { return 0.25; }
};

#endif /* defined(__nuPong__Paddle__) */
