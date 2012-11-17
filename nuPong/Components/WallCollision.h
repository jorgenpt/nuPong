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

#include "BoxRenderer.h"

struct WallCollision : Component
{
    BoxRenderer *renderer;

    WallCollision(Entity& owner) : Component(owner) {}
    void initialize() override;
};

#endif /* defined(__nuPong__WallCollision__) */
