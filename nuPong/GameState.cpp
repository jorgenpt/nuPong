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

GameState::Ball::Ball(b2World& world) {
    quadric = gluNewQuadric();

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(GAME_WIDTH/2., 0.0f);
    bodyDef.bullet = true;

    body = world.CreateBody(&bodyDef);

    b2CircleShape dynamicCircle;
    dynamicCircle.m_radius = BALL_RADIUS;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicCircle;
    fixtureDef.friction = 0.;
    fixtureDef.restitution = 1;

    body->CreateFixture(&fixtureDef);
    body->ResetMassData();

    ApplyRandomForce (5.);
}

void GameState::Ball::ApplyRandomForce (float scale) {
    float angle = rand()/(float)RAND_MAX * 2. * M_PI;
    b2Vec2 vec = b2Rot(angle).GetXAxis();
    body->ApplyLinearImpulse(scale * vec, body->GetPosition());
}

GameState::GameState() :world(b2Vec2_zero), ball(world) {
    walls[0].setDimensions(world, b2Vec2(0, -GAME_HEIGHT_EXTENT), b2Vec2(0.1, GAME_HEIGHT_EXTENT));
    walls[1].setDimensions(world, b2Vec2(GAME_WIDTH - 0.1, -GAME_HEIGHT_EXTENT), b2Vec2(GAME_WIDTH, GAME_HEIGHT_EXTENT));
    walls[2].setDimensions(world, b2Vec2(0.1, GAME_HEIGHT_EXTENT), b2Vec2(GAME_WIDTH - 0.1, GAME_HEIGHT_EXTENT - 0.1));

    paddle.setDimensions(world, b2Vec2((GAME_WIDTH - PADDLE_INITIAL_WIDTH)/2., -GAME_HEIGHT_EXTENT + 0.5),
                        b2Vec2((GAME_WIDTH + PADDLE_INITIAL_WIDTH)/2., -GAME_HEIGHT_EXTENT + 0.25));
}

void GameState::update(float delta) {
    world.Step(delta, 8, 3);
    paddle.update(delta);

    b2Vec2 pos = ball.body->GetPosition();
    if (pos.y < -GAME_HEIGHT_EXTENT)
    {
        ball.body->SetTransform(b2Vec2(GAME_WIDTH/2., 0.), ball.body->GetAngle());
        ball.body->SetLinearVelocity(b2Vec2_zero);
        ball.ApplyRandomForce(5.);
    }
}

void GameState::render()
{
    glColor3f(0.8, 0.8, 0.9);
    for (int i = 0; i < sizeof(walls)/sizeof(walls[0]); ++i) {
        walls[i].render();
    }

    glColor3f(0.9, 0.9, 1.0);
    paddle.render();

    glLoadIdentity();
    b2Vec2 ballPosition = ball.body->GetPosition();
    glTranslatef (ballPosition.x, ballPosition.y, 0.0);
    glColor3f(0., 1., 0.);
    gluSphere(ball.quadric, BALL_RADIUS, 24, 24);

}
