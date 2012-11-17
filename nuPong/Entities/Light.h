//
//  Light.h
//  nuPong
//
//  Created by Jørgen Tjernø on 11/16/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Light__
#define __nuPong__Light__

#include <Box2D.h>

#include "Game.h"

struct Light : public Entity {
    Light (const b2Vec3& position, const b2Vec3& diffuse, const b2Vec3& specular);
};

#endif /* defined(__nuPong__Light__) */
