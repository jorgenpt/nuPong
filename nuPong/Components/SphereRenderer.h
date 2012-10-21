//
//  SphereRenderer.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__SphereRenderer__
#define __nuPong__SphereRenderer__

#include "Component.h"

#include <Box2D.h>
#include <OpenGL/glu.h>

class SphereRenderer : public Component
{
    GLUquadric *mQuadric;

public:
    float mRadius;

    SphereRenderer (Entity& owner, float radius);

    void update(float delta) {}
    void render() const;
};

#endif /* defined(__nuPong__SphereRenderer__) */
