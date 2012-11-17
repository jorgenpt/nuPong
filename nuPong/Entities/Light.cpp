//
//  Light.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 11/16/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Light.h"

#include "LightSource.h"

Light::Light (const b2Vec3& position, const b2Vec3& diffuse, const b2Vec3& specular)
{
    addComponent(new LightSource(*this, position, diffuse, specular));
}
