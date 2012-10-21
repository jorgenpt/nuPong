//
//  AutoPaddle.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__AutoPaddle__
#define __nuPong__AutoPaddle__

#include "Paddle.h"

struct AutoPaddle : public Paddle {
    AutoPaddle(b2World& world, float width);
};

#endif /* defined(__nuPong__AutoPaddle__) */
