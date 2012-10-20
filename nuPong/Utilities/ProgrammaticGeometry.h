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
    static void uploadBox (GLuint& vboId, GLuint& indexId, b2Vec3 extents);
};

#endif /* defined(__nuPong__ProgrammaticGeometry__) */
