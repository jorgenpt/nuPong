//
//  Paddle.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Paddle__
#define __nuPong__Paddle__

#include "Entity.h"

class Paddle : public Entity {
protected:
    b2Body* createBoxBody(b2World& world, b2Vec2 topLeft, b2Vec2 bottomRight);
public:
    Paddle() {}
    Paddle(b2World& world, float width);
    float getHeight() const { return 0.25; }
};

#endif /* defined(__nuPong__Paddle__) */
