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


BoxRenderer::BoxRenderer (Entity& owner, const b2Vec3& extents, Material *material_)
    : Component(owner), blink(false), material(material_)
{
    mesh = ProgrammaticGeometry::uploadBox(extents);
    if (material)
        material->setUniform("blink_t", 2.);
}

BoxRenderer::~BoxRenderer ()
{
    delete material;
    delete mesh;
}

void BoxRenderer::render() const
{
    const b2Body* body = getBody();
    if (body == NULL) {
        // TODO: Log error.
        return;
    }

    if (material)
        material->apply();

    const b2Vec2 position = body->GetPosition();
    glLoadIdentity();
    glTranslatef(position.x, position.y, 0.5);
    glColor3f(0.9, 0.9, 1.0);

    mesh->render();

    if (material)
        Material::deactivate();
}

void BoxRenderer::update(float delta)
{
    // XXX: Ugh. This depends on a "correct" material being passed in.
    if (blink) {
        double timePassed = glfwGetTime() - blinkStart;
        material->setUniform("blink_t", timePassed);
        if (timePassed > 1.) {
            blink = false;
        }
    }
}

void BoxRenderer::startBlinkAt(b2Vec2 position)
{
    if (material != NULL) {
        blink = true;
        printf("%f", position.y);
        material->setUniform("blink_y", position.y);
        blinkStart = glfwGetTime();
    }
}
