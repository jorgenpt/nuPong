//
//  Wall.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Wall.h"

#include "ProgrammaticGeometry.h"
#include <GL/glfw.h>

Wall::Wall(b2World& world, b2Vec2 topLeft, b2Vec2 bottomRight)
{
    b2Vec2 extents = 1./2. * b2Abs(topLeft - bottomRight);
    ProgrammaticGeometry::uploadBox(vertexVboId, indexVboId, b2Vec3(extents.x, extents.y, 0.5));

    b2Vec2 origin = 1./2. * (topLeft + bottomRight);
    body = createBoxBody (world, origin, extents);
}

b2Body* Wall::createBoxBody(b2World& world, b2Vec2 origin, b2Vec2 extents)
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position = origin;

    b2PolygonShape groundBox;
    groundBox.SetAsBox(extents.x, extents.y);

    b2Body* body = world.CreateBody(&groundBodyDef);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &groundBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.;
    fixtureDef.restitution = 1;

    body->CreateFixture(&fixtureDef);
    return body;
}

void Wall::render()
{
    const b2Vec2 position = body->GetPosition();
    glLoadIdentity();
    glTranslatef(position.x, position.y, 0.5);
    glColor3f(0.8, 0.8, 0.9);

    glBindBuffer(GL_ARRAY_BUFFER, vertexVboId);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(b2Vec3), 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVboId);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_SHORT, 0);
}
