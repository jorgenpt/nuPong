//
//  Game.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef nuPong_game_state_h
#define nuPong_game_state_h

#include "Physics.h"

#include "IStaticEntity.h"
#include "IDynamicEntity.h"

#include <list>

class Game {
    static Game gameInstance;

    std::list<IDynamicEntity*> dynamicEntities;
    std::list<IStaticEntity*> staticEntities;
    Physics physics;

    Game();

public:
    static Game& getInstance();

    void initialize();
    void update(float delta);
    void render();

    static b2Vec2 getSize() { return b2Vec2(10., 7.5); }
};

#endif
