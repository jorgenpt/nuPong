//
//  WallCollision.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "WallCollision.h"

#include <GL/glfw.h>

#include "Game.h"

void WallCollision::initialize()
{
    renderer = getComponent<BoxRenderer>();

    Physics& physics = Game::getInstance().getPhysics();
    physics.collisionHandler(this, [this](Entity *collidedWith, b2Contact *contact)
                             {
                                 printf("ZOMG COLLISION %s!\n", collidedWith->getName().c_str());
                                 b2WorldManifold worldManifold;
                                 contact->GetWorldManifold(&worldManifold);
                                 renderer->startBlinkAt(worldManifold.points[0]);
                             });
}
