//
//  ProgrammaticGeometry.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "ProgrammaticGeometry.h"

#include <GL/glfw.h>

void ProgrammaticGeometry::uploadBox (GLuint& vboId, GLuint& indexId, b2Vec3 extents)
{
    b2Vec3 vertices[8];
    vertices[0] = b2Vec3(-extents.x,  extents.y, -extents.z);
    vertices[1] = b2Vec3(-extents.x,  extents.y,  extents.z);
    vertices[2] = b2Vec3( extents.x,  extents.y, -extents.z);
    vertices[3] = b2Vec3( extents.x,  extents.y,  extents.z);
    vertices[4] = b2Vec3( extents.x, -extents.y, -extents.z);
    vertices[5] = b2Vec3( extents.x, -extents.y,  extents.z);
    vertices[6] = b2Vec3(-extents.x, -extents.y, -extents.z);
    vertices[7] = b2Vec3(-extents.x, -extents.y,  extents.z);

    // Three vertices per triangle, two triangles per side, six sides.
    unsigned short indices[] = {
        0, 4, 2, 0, 6, 4, // Top face
        1, 3, 5, 1, 5, 7, // Bottom face
        // TODO: The other faces.
    };

    glGenBuffers(1, &vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &indexId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);
}