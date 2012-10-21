//
//  Physics.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Physics.h"

Physics::Physics() :world(b2Vec2_zero), accumulator(0.)
{
    world.SetContactListener(&handler);
}

void Physics::update(float delta)
{
    // TODO: Interpolation
    // Reference: http://www.unagames.com/blog/daniele/2010/06/fixed-time-step-implementation-box2d
    accumulator += delta;
    while (accumulator >= getStepSize())
    {
        accumulator -= getStepSize();
        world.Step(getStepSize(), getVelocitySolverIterations(), getPositionSolverIterations());
    }
}

void Physics::collisionHandler(Component *component, CollisionHandler::Handler function)
{
    handler.handlers[component->getBody()] = function;
}