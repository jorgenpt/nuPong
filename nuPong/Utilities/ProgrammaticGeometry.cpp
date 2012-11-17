//
//  ProgrammaticGeometry.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "ProgrammaticGeometry.h"

#include <GL/glfw.h>

Mesh *ProgrammaticGeometry::uploadBox (b2Vec3 extents)
{
    b2Vec3 vertices[8];
    vertices[0] = b2Vec3(-extents.x,  extents.y,  extents.z);
    vertices[2] = b2Vec3( extents.x,  extents.y,  extents.z);
    vertices[4] = b2Vec3( extents.x, -extents.y,  extents.z);
    vertices[6] = b2Vec3(-extents.x, -extents.y,  extents.z);

    vertices[1] = b2Vec3(-extents.x,  extents.y, -extents.z);
    vertices[3] = b2Vec3( extents.x,  extents.y, -extents.z);
    vertices[5] = b2Vec3( extents.x, -extents.y, -extents.z);
    vertices[7] = b2Vec3(-extents.x, -extents.y, -extents.z);

    // Three vertices per triangle, two triangles per side, six sides.
    unsigned short indices[3*2*6];
    unsigned short* indicesWalker = &indices[0];

    // Top face
    indicesWalker = createTrianglesForQuad(1, 0, 2, 3, indicesWalker);
    // Bottom face
    indicesWalker = createTrianglesForQuad(5, 4, 6, 7, indicesWalker);

    // Left face
    indicesWalker = createTrianglesForQuad(1, 7, 6, 0, indicesWalker);
    // Right face
    indicesWalker = createTrianglesForQuad(2, 4, 5, 3, indicesWalker);

    // Near face
    indicesWalker = createTrianglesForQuad(0, 6, 4, 2, indicesWalker);
    // Far face
    indicesWalker = createTrianglesForQuad(3, 5, 7, 1, indicesWalker);

    GLuint vertexBufferId;
    glGenBuffers(1, &vertexBufferId);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

    GLuint indexBufferId;
    glGenBuffers(1, &indexBufferId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);

    Mesh *mesh = new Mesh();
    mesh->numVertices = sizeof(vertices);
    mesh->vertexBufferId = vertexBufferId;
    mesh->indexBufferId = indexBufferId;
    return mesh;
}

unsigned short* ProgrammaticGeometry::createTrianglesForQuad (unsigned short topLeft, unsigned short bottomLeft,
                                                              unsigned short bottomRight, unsigned short topRight,
                                                              unsigned short* indices)
{
    indices[0] = topLeft;
    indices[1] = bottomLeft;
    indices[2] = topRight;

    indices[3] = bottomLeft;
    indices[4] = bottomRight;
    indices[5] = topRight;

    return &indices[6];
}
