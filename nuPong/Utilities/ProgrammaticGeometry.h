//
//  ProgrammaticGeometry.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__ProgrammaticGeometry__
#define __nuPong__ProgrammaticGeometry__

#include <OpenGL/OpenGL.h>
#include <Box2D.h>

struct ProgrammaticGeometry {
    static int uploadBox (GLuint& vboId, GLuint& indexId, b2Vec3 extents);

private:
    static unsigned short* createTrianglesForQuad (unsigned short topLeft, unsigned short bottomLeft,
                                                   unsigned short bottomRight, unsigned short topRight,
                                                   unsigned short* indices);
};

#endif /* defined(__nuPong__ProgrammaticGeometry__) */
