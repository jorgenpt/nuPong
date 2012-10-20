//
//  IStaticEntity.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__IStaticEntity__
#define __nuPong__IStaticEntity__

#include "IDynamicEntity.h"

struct IStaticEntity : public IDynamicEntity {
    void update(float delta) { }
};

#endif /* defined(__nuPong__IStaticEntity__) */
