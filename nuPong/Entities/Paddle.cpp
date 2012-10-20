//
//  Paddle.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Paddle.h"

#include "ProgrammaticGeometry.h"

#include <GL/glfw.h>

#define PADDLE_INITIAL_SPEED 8.0

Paddle::Paddle(b2World& world, float width)
{
    b2Vec2 extents = 1./2. * b2Vec2(width, getHeight());
    ProgrammaticGeometry::uploadBox(vertexVboId, indexVboId, b2Vec3(extents.x, extents.y, 0.5));

    b2Vec2 origin(Game::getSize().x / 2., getHeight() + 0.25);
    body = createBoxBody (world, origin, extents);
}

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

void Paddle::render()
{
    const b2Vec2 position = body->GetPosition();
    glLoadIdentity();
    glTranslatef(position.x, position.y, 0.5);
    glColor3f(0.9, 0.9, 1.0);

    glBindBuffer(GL_ARRAY_BUFFER, vertexVboId);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(b2Vec3), 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVboId);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_SHORT, 0);
}

void Paddle::update(float delta)
{
    b2Vec2 desiredVelocity = b2Vec2_zero;
    if (glfwGetKey(GLFW_KEY_LEFT)) {
        desiredVelocity = b2Vec2(-PADDLE_INITIAL_SPEED, 0.);
    } else if (glfwGetKey(GLFW_KEY_RIGHT)) {
        desiredVelocity = b2Vec2( PADDLE_INITIAL_SPEED, 0.0);
    }
    body->SetLinearVelocity(desiredVelocity);

    b2Vec2 gameSize = Game::getSize();

    b2AABB aabb = getAABB();
    b2Vec2 position = body->GetPosition();
    if (aabb.lowerBound.x <= 0.) {
        position.x -= aabb.lowerBound.x;
        body->SetTransform(position, body->GetAngle());
    } else if (aabb.upperBound.x >= gameSize.x) {
        position.x -= (aabb.upperBound.x - gameSize.x);
        body->SetTransform(position, body->GetAngle());
    }
}
