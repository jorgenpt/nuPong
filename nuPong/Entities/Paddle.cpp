//
//  Paddle.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Paddle.h"

#include "Game.h"

#include "BoxRenderer.h"
#include "PlayerInputHandler.h"

#include <GL/glfw.h>

#define PADDLE_INITIAL_SPEED 8.0

Paddle::Paddle(b2World& world, float width)
{
    b2Vec2 extents = 1./2. * b2Vec2(width, getHeight());
    b2Vec2 origin(Game::getSize().x / 2., getHeight() + 0.25);

    // TODO: Move the creation of the b2Body into a component.
    body = createBoxBody (world, origin, extents);

    addComponent(new BoxRenderer(*this, b2Vec3(extents.x, extents.y, 0.5)));
    addComponent(new PlayerInputHandler(*this, PADDLE_INITIAL_SPEED));
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