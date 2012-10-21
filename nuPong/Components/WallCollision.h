//
//  WallCollision.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__WallCollision__
#define __nuPong__WallCollision__

#include "Component.h"

struct WallCollision : Component
{
    WallCollision(Entity& owner) : Component(owner) {}
    void initialize();
};

#endif /* defined(__nuPong__WallCollision__) */
