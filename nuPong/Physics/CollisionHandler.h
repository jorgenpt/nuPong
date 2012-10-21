//
//  CollisionHandler.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__CollisionHandler__
#define __nuPong__CollisionHandler__

#include <functional>
#include <map>

#include <Box2D.h>

#include "Entity.h"

struct CollisionHandler : b2ContactListener {
    typedef std::function<void(Entity*, b2Contact*)> Handler;
    std::map<b2Body*, Handler> handlers;

    void handleCollision(b2Contact* contact, b2Body* first, b2Body* second);
    
	virtual void BeginContact(b2Contact* contact);
};

#endif /* defined(__nuPong__CollisionHandler__) */
