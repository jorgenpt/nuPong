//
//  BoxRenderer.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__BoxRenderer__
#define __nuPong__BoxRenderer__

#include "Component.h"

#include <Box2D.h>
#include <OpenGL/OpenGL.h>

struct BoxRenderer : public Component
{
    GLuint vertexBufferId, indexBufferId;

    BoxRenderer (Entity& owner, const b2Vec3& extents);

    void update(float delta) {}
    void render() const;
};

#endif /* defined(__nuPong__BoxRenderer__) */
