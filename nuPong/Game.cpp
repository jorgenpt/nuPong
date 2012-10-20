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

#include "Ball.h"
#include "Paddle.h"
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

    // Walls
    staticEntities.push_back(new Wall(world, b2Vec2(0.,           size.y), b2Vec2(0.1,          0.)));
    staticEntities.push_back(new Wall(world, b2Vec2(size.x - 0.1, size.y), b2Vec2(size.x,       0.)));
    staticEntities.push_back(new Wall(world, b2Vec2(0.1,          size.y), b2Vec2(size.x - 0.1, size.y - 0.1)));

    dynamicEntities.push_back(new Ball(world));
    dynamicEntities.push_back(new Paddle(world, PADDLE_INITIAL_WIDTH));
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
