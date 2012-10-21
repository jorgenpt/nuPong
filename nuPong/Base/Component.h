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

    virtual void initialize() {}
    virtual void render() const = 0;
    virtual void update(float delta) = 0;

    Entity& getEntity();
    void setBody(b2Body* body);
    const b2Body* getBody() const;
    b2Body* getBody();

    template<typename T>
    T* getComponent() const;
    void addComponent(Component *component);
};

#include "Component.inl"

#endif /* defined(__nuPong__Component__) */
