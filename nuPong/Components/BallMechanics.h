//
//  BallMechanics.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__BallMechanics__
#define __nuPong__BallMechanics__

#include "Component.h"

struct BallMechanics : public Component
{
    BallMechanics(Entity& owner, float speed);

    float mSpeed;

    void update(float delta);
    void render() const {}

    void resetPosition();
    void applyRandomForce(float scale);
};


#endif /* defined(__nuPong__BallMechanics__) */
