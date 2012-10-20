//
//  Paddle.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Paddle.h"

#include <GL/glfw.h>

b2Body* Paddle::createBoxBody(b2World& world, b2Vec2 origin, b2Vec2 extents)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody;
    bodyDef.position = origin;

    b2PolygonShape box;
    box.SetAsBox(extents.x, extents.y);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.0f;

    b2Body* body = world.CreateBody(&bodyDef);
    body->CreateFixture(&fixtureDef);
    return body;
}

b2AABB Paddle::getAABB () const {
    b2AABB aabb;
    aabb.lowerBound = b2Vec2(FLT_MAX,FLT_MAX);
    aabb.upperBound = b2Vec2(-FLT_MAX,-FLT_MAX);
    
    for (b2Fixture* fixture = body->GetFixtureList(); fixture != NULL; fixture = fixture->GetNext ()) {
        aabb.Combine(aabb, fixture->GetAABB(0));
    }
    
    return aabb;
}

void Paddle::update(float delta)
{
    b2Vec2 desiredVelocity = b2Vec2_zero;
    if (glfwGetKey(GLFW_KEY_LEFT)) {
        desiredVelocity = b2Vec2(-8.0, 0.);
    } else if (glfwGetKey(GLFW_KEY_RIGHT)) {
        desiredVelocity = b2Vec2( 8.0, 0.0);
    }
    body->SetLinearVelocity(desiredVelocity);

    b2AABB aabb = getAABB();
    b2Vec2 position = body->GetPosition();
    if (aabb.lowerBound.x <= 0.) {
        position.x -= aabb.lowerBound.x;
        body->SetTransform(position, body->GetAngle());
    } else if (aabb.upperBound.x >= 10.) {
        position.x -= (aabb.upperBound.x - 10.);
        body->SetTransform(position, body->GetAngle());
    }
}
