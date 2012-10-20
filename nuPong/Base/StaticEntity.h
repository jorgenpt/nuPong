//
//  StaticEntity.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__StaticEntity__
#define __nuPong__StaticEntity__

#include "Entity.h"

struct StaticEntity : public Entity {
    void update(float delta) { }
};

#endif /* defined(__nuPong__StaticEntity__) */
