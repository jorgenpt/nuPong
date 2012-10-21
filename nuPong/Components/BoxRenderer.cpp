//
//  BoxRenderer.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "BoxRenderer.h"

#include <GL/glfw.h>
#include "ProgrammaticGeometry.h"


BoxRenderer::BoxRenderer (Entity& owner, const b2Vec3& extents) : Component(owner)
{
    ProgrammaticGeometry::uploadBox(vertexBufferId, indexBufferId, extents);
}

void BoxRenderer::render()
{
    b2Body* body = getBody();
    if (body == NULL) {
        // TODO: Log error.
        return;
    }

    const b2Vec2 position = body->GetPosition();
    glLoadIdentity();
    glTranslatef(position.x, position.y, 0.5);
    glColor3f(0.9, 0.9, 1.0);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(b2Vec3), 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_SHORT, 0);
}