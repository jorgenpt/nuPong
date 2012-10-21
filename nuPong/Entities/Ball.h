//
//  Ball.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Ball__
#define __nuPong__Ball__

#include "Game.h"

#include <OpenGL/glu.h>

struct Ball : public Entity {
    Ball (b2World& world);
};


#endif /* defined(__nuPong__Ball__) */
