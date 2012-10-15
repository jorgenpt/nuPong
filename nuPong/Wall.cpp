//
//  Wall.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Wall.h"

#include <GL/glfw.h>

Wall::Wall(b2World& world, b2Vec2 topLeft, b2Vec2 bottomRight)
{
    b2Vec3 vertices[8];
    vertices[0] = b2Vec3(topLeft.x, topLeft.y, 0.);
    vertices[1] = b2Vec3(topLeft.x, topLeft.y, 1.);
    vertices[2] = b2Vec3(bottomRight.x, topLeft.y, 0.);
    vertices[3] = b2Vec3(bottomRight.x, topLeft.y, 1.);
    vertices[4] = b2Vec3(bottomRight.x, bottomRight.y, 0.);
    vertices[5] = b2Vec3(bottomRight.x, bottomRight.y, 1.);
    vertices[6] = b2Vec3(topLeft.x, bottomRight.y, 0.);
    vertices[7] = b2Vec3(topLeft.x, bottomRight.y, 1.);

    // Three vertices per triangle, two triangles per side, six sides.
    unsigned short indices[] = {
        0, 4, 2, 0, 6, 4, // Top face
        1, 3, 5, 1, 5, 7, // Bottom face
    };
    
    glGenBuffers(1, &vertexVboId);
    glBindBuffer(GL_ARRAY_BUFFER,vertexVboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(b2Vec3) * 8, &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &indexVboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);

    body = createBoxBody (world, topLeft, bottomRight);
}

b2Body* Wall::createBoxBody(b2World& world, b2Vec2 topLeft, b2Vec2 bottomRight)
{
    b2Vec2 origin = 1./2. * (topLeft + bottomRight);
    b2BodyDef groundBodyDef;
    groundBodyDef.position = origin;
    b2Body* body = world.CreateBody(&groundBodyDef);
    
    b2Vec2 extent = topLeft - bottomRight;
    b2PolygonShape groundBox;
    groundBox.SetAsBox(fabs(extent.x), fabs(extent.y));
    
    body->CreateFixture(&groundBox, 0.0f);
    return body;
}

void Wall::render()
{
    glBindBuffer(GL_ARRAY_BUFFER, vertexVboId);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(b2Vec3), 0);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVboId);
//    glDrawRangeElements(GL_TRIANGLES, 6, 11, 6, GL_UNSIGNED_SHORT, 0);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_SHORT, 0);
}