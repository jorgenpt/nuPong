//
//  LightSource.h
//  nuPong
//
//  Created by Jørgen Tjernø on 11/16/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__LightSource__
#define __nuPong__LightSource__

#include "Component.h"

#include <Box2D.h>

struct LightSource : public Component
{
    static int lightSources;

    LightSource (Entity& owner, const b2Vec3& position, const b2Vec3& diffuse, const b2Vec3& specular);
};

#endif /* defined(__nuPong__LightSource__) */
