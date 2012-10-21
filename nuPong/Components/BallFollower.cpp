//
//  BallFollower.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "BallFollower.h"

#include "Game.h"

BallFollower::BallFollower(Entity& owner, float speed) : Component(owner), ballBody(NULL)
{
    mSpeed = speed;
}

void BallFollower::update(float delta)
{
    b2Body *body = getBody();
    if (body == NULL)
        return;

    if (ballBody == NULL)
    {
        Entity* ball = Game::getInstance().getEntityWithName("ball");
        if (ball != NULL)
            ballBody = ball->body;
        if (ballBody == NULL)
            return;
    }

    float xDelta = ballBody->GetPosition().x - body->GetPosition().x;
    if (b2Abs(xDelta) < 0.1 || ballBody->GetPosition().y < Game::getSize().y / 2.)
    {
        body->SetLinearVelocity(b2Vec2_zero);
        return;
    }

    float direction = -mSpeed;
    if (xDelta > 0.)
        direction = mSpeed;

    body->SetLinearVelocity(direction * b2Vec2(1., 0.));
}
