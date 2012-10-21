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

#include "Entity.h"

#include <list>
#include <map>

class Game {
    static Game gameInstance;

    std::list<Entity*> entities;
    std::map<std::string, Entity*> names;
    std::map<std::string, std::list<Entity*>> tags;
    Physics physics;

    Game();

public:
    static Game& getInstance();
    static b2Vec2 getSize() { return b2Vec2(10., 7.5); }

    // Game lifecycle
    void initialize();
    void update(float delta);
    void render();

    // Game state
    Physics& getPhysics() { return physics; }
    
    void setEntityName(Entity* entity, const std::string& name);
    void removeEntityName(Entity* entity, const std::string& name);
    Entity* getEntityWithName(const std::string& name) const;

    void addEntityTag(Entity* entity, const std::string& tag);
    void removeEntityTag(Entity* entity, const std::string& tag);
    std::list<Entity*> getEntitiesWithTag(const std::string& tag) const;
    Entity* getEntityWithTag(const std::string& tag) const;
};

#endif
