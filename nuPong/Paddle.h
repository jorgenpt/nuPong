//
//  Paddle.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Paddle__
#define __nuPong__Paddle__

#include "Wall.h"

class Paddle : public Wall {
protected:
    virtual b2Body* createBoxBody(b2World& world, b2Vec2 origin, b2Vec2 extents);
    b2AABB getAABB () const;
    
public:
    virtual void update(float delta);
};

#endif /* defined(__nuPong__Paddle__) */
