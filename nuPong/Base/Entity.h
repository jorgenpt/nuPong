//
//  Entity.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Entity__
#define __nuPong__Entity__

#include <list>
#include <set>
#include <string>

#include <Box2D.h>

class Component;

class Entity {
    std::string mName;
    std::set<std::string> mTags;

    std::list<Component*> mComponents;

public:
    b2Body* body;

    Entity();
    ~Entity();
    void update(float delta);
    void render();

    b2AABB getAABB () const;

    // Component management
    template<typename T>
    T* getComponent() const;
    void addComponent(Component *component);

    // Entity registration
    void setName(const std::string& name);
    void addTag(const std::string& tag);
    void removeTag(const std::string& tag);
};


#include "Entity.inl"

#endif /* defined(__nuPong__Entity__) */
