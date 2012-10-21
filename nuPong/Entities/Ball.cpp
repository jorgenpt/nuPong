//
//  Ball.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Ball.h"

#include "SphereRenderer.h"
#include "BallMechanics.h"

#define BALL_RADIUS 0.1
#define BALL_SPEED  5.0

Ball::Ball(b2World& world) {
    // TODO: Move the creation of the b2Body into a component.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.bullet = true;

    body = world.CreateBody(&bodyDef);

    b2CircleShape dynamicCircle;
    dynamicCircle.m_radius = BALL_RADIUS;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicCircle;
    fixtureDef.friction = 0.;
    fixtureDef.restitution = 1;

    body->CreateFixture(&fixtureDef);
    body->ResetMassData();

    addComponent(new SphereRenderer(*this, BALL_RADIUS));
    addComponent(new BallMechanics(*this, BALL_SPEED));
}