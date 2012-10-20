//
//  Entity.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Entity.h"

#include "Component.h"
#include "Game.h"

Entity::Entity() :mName("")
{

}

Entity::~Entity()
{
    for (auto it = mComponents.begin(); it != mComponents.end(); ++it)
    {
        delete *it;
    }
}

void Entity::addComponent(Component *component)
{
    mComponents.push_back(component);
}

void Entity::setName(const std::string& name)
{
    Game& game = Game::getInstance();
    if (name.length() > 0) {
        if (mName.length() > 0)
            game.removeEntityName(this, mName);

        game.setEntityName(this, name);
    } else if (mName.length() > 0) {
        game.removeEntityName(this, mName);
    }

    mName = name;
}

void Entity::addTag(const std::string& tag)
{
    if (mTags.count(tag) > 0)
        return;

    mTags.insert(tag);
    Game::getInstance().addEntityTag(this, tag);
}

void Entity::removeTag(const std::string& tag)
{
    auto tagIterator = mTags.find(tag);
    if (tagIterator == mTags.end())
        return;

    mTags.erase(tagIterator);
    Game::getInstance().removeEntityTag(this, tag);
}

void Entity::render()
{
    for (auto it = mComponents.begin(); it != mComponents.end(); ++it)
        (*it)->render();
}

void Entity::update(float delta)
{
    for (auto it = mComponents.begin(); it != mComponents.end(); ++it)
        (*it)->update(delta);
}
