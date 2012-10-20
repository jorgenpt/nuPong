//
//  Ball.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Ball.h"

#define BALL_RADIUS 0.1

Ball::Ball(b2World& world) {
    quadric = gluNewQuadric();

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = getStartingPosition();
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

    applyRandomForce (5.);
}

b2Vec2 Ball::getStartingPosition() const {
    return 1./2. * Game::getSize();
}

void Ball::applyRandomForce (float scale) {
    float angle = rand()/(float)RAND_MAX * 2. * M_PI;
    b2Vec2 vec = b2Rot(angle).GetXAxis();
    body->ApplyLinearImpulse(scale * vec, body->GetPosition());
}

void Ball::render() {
    glLoadIdentity();
    b2Vec2 ballPosition = body->GetPosition();
    glTranslatef (ballPosition.x, ballPosition.y, 0.0);
    glColor3f(0., 1., 0.);
    gluSphere(quadric, BALL_RADIUS, 24, 24);
}

void Ball::update(float delta) {
    b2Vec2 pos = body->GetPosition();
    if (pos.y < 0.)
    {
        body->SetTransform(getStartingPosition (), body->GetAngle());
        body->SetLinearVelocity(b2Vec2_zero);
        applyRandomForce(5.);
    }
}
