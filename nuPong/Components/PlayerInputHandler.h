//
//  PlayerInputHandler.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__PlayerInputHandler__
#define __nuPong__PlayerInputHandler__

#include "Component.h"

struct PlayerInputHandler : public Component
{
    PlayerInputHandler(Entity& owner, float speed);

    float mSpeed;

    void update(float delta);
};

#endif /* defined(__nuPong__PlayerInputHandler__) */
