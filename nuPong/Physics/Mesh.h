//
//  Mesh.h
//  nuPong
//
//  Created by Jørgen Tjernø on 11/16/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Mesh__
#define __nuPong__Mesh__

#include <GL/glfw.h>

class ProgrammaticGeometry;

class Mesh {
protected:
    int numVertices;
    GLuint indexBufferId, vertexBufferId;
    friend class ProgrammaticGeometry;

public:
    void render() const;
};

#endif /* defined(__nuPong__Mesh__) */
