//
//  PlayerInputHandler.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "PlayerInputHandler.h"

#include <GL/glfw.h>
#include "Game.h"

PlayerInputHandler::PlayerInputHandler(Entity& owner, float speed) : Component(owner)
{
    mSpeed = speed;
}

void PlayerInputHandler::update(float delta)
{
    b2Body* body = getBody();
    if (body == NULL) {
        // TODO: Log error.
        return;
    }

    b2Vec2 desiredVelocity = b2Vec2_zero;
    if (glfwGetKey(GLFW_KEY_LEFT)) {
        desiredVelocity = b2Vec2(-mSpeed, 0.);
    } else if (glfwGetKey(GLFW_KEY_RIGHT)) {
        desiredVelocity = b2Vec2( mSpeed, 0.0);
    }
    body->SetLinearVelocity(desiredVelocity);

    b2Vec2 gameSize = Game::getSize();

    b2AABB aabb = getEntity().getAABB();
    b2Vec2 position = body->GetPosition();
    if (aabb.lowerBound.x <= 0.) {
        position.x -= aabb.lowerBound.x;
        body->SetTransform(position, body->GetAngle());
    } else if (aabb.upperBound.x >= gameSize.x) {
        position.x -= (aabb.upperBound.x - gameSize.x);
        body->SetTransform(position, body->GetAngle());
    }
}