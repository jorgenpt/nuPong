//
//  CollisionHandler.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "CollisionHandler.h"


void CollisionHandler::handleCollision(b2Contact* contact, b2Body* first, b2Body* second)
{
    auto it = handlers.find(first);
    if (it != handlers.end())
    {
        it->second((Entity*)second->GetUserData(), contact);
    }
}


/// Called when two fixtures begin to touch.
void CollisionHandler::BeginContact(b2Contact* contact)
{
    b2Body *bodyA = contact->GetFixtureA()->GetBody();
    b2Body *bodyB = contact->GetFixtureB()->GetBody();
    if (bodyA == NULL || bodyB == NULL)
        return;

    handleCollision(contact, bodyA, bodyB);
    handleCollision(contact, bodyB, bodyA);
}
