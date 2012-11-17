//
//  BallFollower.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__BallFollower__
#define __nuPong__BallFollower__

#include "Component.h"

#include <Box2D.h>

struct BallFollower : public Component
{
    b2Body *ballBody;
    float mSpeed;

    BallFollower(Entity& owner, float speed);

    void initialize() override;
    void update(float delta) override;
};

#endif /* defined(__nuPong__BallFollower__) */
