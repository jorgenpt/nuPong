//
//  IDynamicEntity.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__IDynamicEntity__
#define __nuPong__IDynamicEntity__

struct IDynamicEntity {
    virtual void update(float delta) = 0;
    virtual void render() = 0;
};

#endif /* defined(__nuPong__IDynamicEntity__) */
