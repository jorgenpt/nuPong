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

#include "Material.h"
#include "Mesh.h"

struct BoxRenderer : public Component
{
    Material *material;
    Mesh *mesh;
    bool blink;
    double blinkStart;

    BoxRenderer (Entity& owner, const b2Vec3& extents, Material *material = NULL);
    ~BoxRenderer ();

    void update(float delta);
    void render() const;

    void startBlinkAt(b2Vec2 position);
};

#endif /* defined(__nuPong__BoxRenderer__) */
