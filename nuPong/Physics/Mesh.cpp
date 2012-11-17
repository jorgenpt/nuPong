//
//  Mesh.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 11/16/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Mesh.h"

#include <Box2D.h>

#include <stdio.h>

void Mesh::render() const
{
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(b2Vec3), 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
    glDrawElements(GL_TRIANGLES, numVertices, GL_UNSIGNED_SHORT, 0);
}