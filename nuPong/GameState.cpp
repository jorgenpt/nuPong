//
//  GameState.c
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include <GL/glfw.h>

#include <stdlib.h>

#include "GameState.h"

#define GAME_WIDTH 10.
#define GAME_HEIGHT_EXTENT 3.75

#define BALL_RADIUS 0.1

#define PADDLE_INITIAL_WIDTH 2.0
#define PADDLE_INITIAL_SPEED 8.0

GameState::Paddle::Paddle() :
    location((GAME_WIDTH - PADDLE_INITIAL_WIDTH)/2.),
    speed(PADDLE_INITIAL_SPEED), width(PADDLE_INITIAL_WIDTH)
{ }

GameState::Ball::Ball(b2World& world) {
    quadric = gluNewQuadric();

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(GAME_WIDTH/2., 0.0f);

    body = world.CreateBody(&bodyDef);
    body->SetLinearVelocity(b2Vec2(3.8, 3.8));

    b2CircleShape dynamicCircle;
    dynamicCircle.m_radius = BALL_RADIUS;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicCircle;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.;
    fixtureDef.restitution = 1;

    body->CreateFixture(&fixtureDef);
}

GameState::GameState() :world(b2Vec2_zero), ball(world) {
    walls[0] = new Wall(world, b2Vec2(0, GAME_HEIGHT_EXTENT), b2Vec2(0.1, -GAME_HEIGHT_EXTENT));
    walls[1] = new Wall(world, b2Vec2(GAME_WIDTH - 0.1, GAME_HEIGHT_EXTENT), b2Vec2(GAME_WIDTH, -GAME_HEIGHT_EXTENT));
    walls[2] = new Wall(world, b2Vec2(0.1, GAME_HEIGHT_EXTENT), b2Vec2(GAME_WIDTH - 0.1, GAME_HEIGHT_EXTENT - 0.1));
}

void GameState::update(float delta) {
    world.Step(delta, 6, 2);

    if (glfwGetKey(GLFW_KEY_LEFT))
    {
        paddle.location -= (paddle.speed * delta);
        if (paddle.location < 0.) {
            paddle.location = 0.;
        }
    }

    if (glfwGetKey(GLFW_KEY_RIGHT))
    {
        paddle.location += (paddle.speed * delta);
        if (paddle.location + paddle.width > GAME_WIDTH) {
            paddle.location = GAME_WIDTH - paddle.width;
        }
    }
}

void GameState::render()
{
    glColor3f(0.8, 0.8, 0.9);
    for (int i = 0; i < sizeof(walls)/sizeof(walls[0]); ++i) {
        walls[i]->render();
    }

    glLineWidth(2);
    glBegin(GL_LINES);
    {
        glColor3f(1., 0., 0.);
        glVertex2f(paddle.location, -GAME_HEIGHT_EXTENT + 0.5);
        glVertex2f(paddle.location + paddle.width, -GAME_HEIGHT_EXTENT + 0.5);
    }
    glEnd();

    b2Vec2 ballPosition = ball.body->GetPosition();
    glTranslatef (ballPosition.x, ballPosition.y, 0.0);
    glColor3f(0., 1., 0.);
    gluSphere(ball.quadric, BALL_RADIUS, 24, 24);

}
