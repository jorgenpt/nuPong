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
#include "vector2.h"

#define GAME_WIDTH 1.
#define PADDLE_INITIAL_WIDTH 0.2
#define PADDLE_INITIAL_SPEED 0.8

#define WALL_POSITION 0.95

GameState::Paddle::Paddle() :
    location((GAME_WIDTH - PADDLE_INITIAL_WIDTH)/2.),
    speed(PADDLE_INITIAL_SPEED), width(PADDLE_INITIAL_WIDTH)
{ }

GameState::Ball::Ball() {
    position.x = 0.5;
    position.y = 0.0;

    velocity.x = 0.8;
    velocity.y = 0.8;
}

void GameState::update(float delta) {
    ball.position = vector2_add(ball.position, vector2_scale(ball.velocity, delta));
    if (ball.position.x >= GAME_WIDTH) {
        ball.position.x = GAME_WIDTH;
        ball.velocity.x = -ball.velocity.x;
    } else if (ball.position.x <= 0) {
        ball.position.x = 0;
        ball.velocity.x = -ball.velocity.x;
    }

    if (ball.position.y >= WALL_POSITION) {
        ball.position.y = WALL_POSITION;
        ball.velocity.y = -ball.velocity.y;
    }

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
    glLineWidth(2);
    glBegin(GL_LINES);
    {
        glColor3f(1., 0., 0.);
        glVertex2f(paddle.location, -0.95);
        glVertex2f(paddle.location + paddle.width, -0.95);

        glColor3f(0.9, 0.9, 0.9);
        glVertex2f(0.001, WALL_POSITION);
        glVertex2f(0.999, WALL_POSITION);
        glVertex2f(0.001, WALL_POSITION);
        glVertex2f(0.001, -0.95);
        glVertex2f(0.999, WALL_POSITION);
        glVertex2f(0.999, -0.95);
    }
    glEnd();

    glPointSize(8.);
    glBegin(GL_POINTS);
    {
        glColor3f(0., 1., 0.);
        glVertex2f(ball.position.x, ball.position.y);
    }
    glEnd();
}
