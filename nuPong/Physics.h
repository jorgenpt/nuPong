//
//  Physics.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Physics__
#define __nuPong__Physics__

#include <Box2D.h>

class Physics {
    b2World world;
    double accumulator;

public:
    Physics();
    void update(float delta);
    b2World& getWorld() { return world; }

    float getStepSize() const { return 1./60.; }
    int getVelocitySolverIterations() const { return 8; }
    int getPositionSolverIterations() const { return 3; }
};

#endif /* defined(__nuPong__Physics__) */
