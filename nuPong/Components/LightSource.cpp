//
//  LightSource.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 11/16/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "LightSource.h"

#include <GL/glfw.h>

int LightSource::lightSources = 0;

LightSource::LightSource (Entity& owner, const b2Vec3& position, const b2Vec3& diffuse, const b2Vec3& specular)
    : Component(owner)
{
    float position4[] = {position.x, position.y, position.z, 0.0};
    float diffuse4[] = {diffuse.x, diffuse.y, diffuse.z, 0.0};
    float specular4[] = {specular.x, specular.y, specular.z, 0.0};

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, position4);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse4);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular4);
}
