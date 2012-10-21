//
//  Game.c
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Game.h"

#include <GL/glfw.h>
#include <stdlib.h>
#include <algorithm>

#include "Ball.h"
#include "Paddle.h"
#include "AutoPaddle.h"
#include "Wall.h"

#define PADDLE_INITIAL_WIDTH 2.0

Game Game::gameInstance;

Game& Game::getInstance()
{
    return gameInstance;
}

Game::Game() { }

void Game::initialize() {
    b2World& world = physics.getWorld();
    b2Vec2 size = getSize();

    staticEntities.push_back(new Wall(world, b2Vec2(0.,           size.y), b2Vec2(0.1,          0.)));
    staticEntities.push_back(new Wall(world, b2Vec2(size.x - 0.1, size.y), b2Vec2(size.x,       0.)));

    Ball *ball = new Ball(world);
    ball->setName("ball");

    dynamicEntities.push_back(ball);
    dynamicEntities.push_back(new Paddle(world, PADDLE_INITIAL_WIDTH));
    dynamicEntities.push_back(new AutoPaddle(world, PADDLE_INITIAL_WIDTH));
}

void Game::update(float delta) {
    physics.update(delta);

    for (auto it = dynamicEntities.begin(); it != dynamicEntities.end(); ++it) {
        (*it)->update(delta);
    }
}

void Game::render()
{
    for (auto it = staticEntities.begin(); it != staticEntities.end(); ++it) {
        (*it)->render();
    }

    for (auto it = dynamicEntities.begin(); it != dynamicEntities.end(); ++it) {
        (*it)->render();
    }
}

void Game::setEntityName(Entity* entity, const std::string& name)
{
    names.insert(std::pair<std::string, Entity*>(name, entity));
}

void Game::removeEntityName(Entity* entity, const std::string& name)
{
    names.erase(name);
}

Entity* Game::getEntityWithName(const std::string& name) const
{
    auto it = names.find(name);
    if (it == names.end())
        return NULL;
    else
        return it->second;
}

void Game::addEntityTag(Entity* entity, const std::string& tag)
{
    auto it = tags.find(tag);
    if (it == tags.end())
    {
        auto inserted = tags.insert(std::pair<std::string, std::list<Entity*>>());
        it = inserted.first;
    }

    it->second.push_back(entity);
}

void Game::removeEntityTag(Entity* entity, const std::string& tag)
{
    auto it = tags.find(tag);
    if (it == tags.end())
        return;

    auto entities = it->second;
    
    auto entityIt = std::find(entities.begin(), entities.end(), entity);
    if (entityIt == entities.end())
        return;

    entities.erase(entityIt);
}

std::list<Entity*> Game::getEntitiesWithTag(const std::string& tag) const
{
    auto it = tags.find(tag);
    if (it == tags.end())
        return std::list<Entity*>();
    else
        return it->second;
}

Entity* Game::getEntityWithTag(const std::string& tag) const
{
    auto entities = getEntitiesWithTag(tag);
    auto it = entities.begin();
    if (it == entities.end())
        return NULL;
    else
        return *it;
}