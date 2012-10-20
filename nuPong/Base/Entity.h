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

class Component;

class Entity {
protected:
    std::string mName;
    std::set<std::string> mTags;

    std::list<Component*> mComponents;
    friend class Component;

public:
    Entity();
    ~Entity();
    void update(float delta);
    void render();

    // Component management
    template<typename T>
    T* getComponent() const;
    template<typename T>
    void createComponent();
    void addComponent(Component *component);

    // Entity registration
    void setName(const std::string& name);
    void addTag(const std::string& tag);
    void removeTag(const std::string& tag);
};


#include "Entity.inl"

#endif /* defined(__nuPong__Entity__) */
