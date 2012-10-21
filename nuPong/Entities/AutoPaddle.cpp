//
//  AutoPaddle.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "AutoPaddle.h"

#include "Game.h"
#include "BoxRenderer.h"
#include "BallFollower.h"

AutoPaddle::AutoPaddle(b2World& world, float width)
{
    b2Vec2 extents = 1./2. * b2Vec2(width, getHeight());
    b2Vec2 origin(Game::getSize().x / 2., Game::getSize().y - (getHeight() + 0.25));

    // TODO: Move the creation of the b2Body into a component.
    body = createBoxBody (world, origin, extents);

    addComponent(new BoxRenderer(*this, b2Vec3(extents.x, extents.y, 0.5)));
    addComponent(new BallFollower(*this, 3.));
}
