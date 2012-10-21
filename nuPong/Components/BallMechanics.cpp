//
//  BallMechanics.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "BallMechanics.h"

#include "Game.h"

BallMechanics::BallMechanics(Entity& owner, float speed) : Component(owner)
{
    mSpeed = speed;

    resetPosition();
    applyRandomForce(mSpeed);
}


void BallMechanics::resetPosition()
{
    b2Body *body = getBody();
    if (body == NULL) {
        // TODO: Log error!
        return;
    }
    body->SetTransform(1./2. * Game::getSize(), body->GetAngle());
}

void BallMechanics::applyRandomForce (float scale)
{
    b2Body *body = getBody();
    if (body == NULL) {
        // TODO: Log error!
        return;
    }

    float angle = rand()/(float)RAND_MAX * 2. * M_PI;
    b2Vec2 vec = b2Rot(angle).GetXAxis();
    body->ApplyLinearImpulse(scale * vec, body->GetPosition());
}


void BallMechanics::update(float delta) {
    b2Body *body = getBody();
    if (body == NULL) {
        // TODO: Log error!
        return;
    }

    b2Vec2 pos = body->GetPosition();
    if (pos.y < 0. || pos.y > Game::getInstance().getSize().y)
    {
        resetPosition();
        body->SetLinearVelocity(b2Vec2_zero);
        applyRandomForce(mSpeed);
    }
}
