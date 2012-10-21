//
//  SphereRenderer.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "SphereRenderer.h"

#include <GL/glfw.h>


SphereRenderer::SphereRenderer (Entity& owner, float radius) : Component(owner)
{
    mRadius = radius;
    mQuadric = gluNewQuadric();
}

void SphereRenderer::render()
{
    b2Body* body = getBody();
    if (body == NULL) {
        // TODO: Log error.
        return;
    }

    glLoadIdentity();
    b2Vec2 ballPosition = body->GetPosition();
    glTranslatef (ballPosition.x, ballPosition.y, 0.0);
    glColor3f(0., 1., 0.);
    gluSphere(mQuadric, mRadius, 24, 24);
}