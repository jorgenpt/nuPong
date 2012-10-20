//
//  Wall.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Wall__
#define __nuPong__Wall__

#include "Game.h"

#include <OpenGL/OpenGL.h>

class Wall : public IStaticEntity {
    GLuint vertexVboId, indexVboId;
    b2Body* body;
    b2Body* createBoxBody(b2World& world, b2Vec2 topLeft, b2Vec2 bottomRight);

public:
    Wall(b2World& world, b2Vec2 topLeft, b2Vec2 bottomRight);
    void render();
    virtual void update(float) {};
};

#endif /* defined(__nuPong__Wall__) */
