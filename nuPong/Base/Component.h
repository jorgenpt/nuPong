//
//  Component.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Component__
#define __nuPong__Component__

#include "Entity.h"

class Component {
    Entity& mOwner;
public:
    Component(Entity& owner) :mOwner(owner) { }
    virtual ~Component() {}

    virtual void render() = 0;
    virtual void update(float delta) = 0;

    template<typename T>
    T* getComponent() const;
    template<typename T>
    void createComponent();
    void addComponent(Component *component);
    Entity& getEntity();
};

#include "Component.inl"

#endif /* defined(__nuPong__Component__) */
