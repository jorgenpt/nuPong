//
//  game.c
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include <GL/glfw.h>

#include <stdlib.h>

#include "vector2.h"

#define GAME_WIDTH 1.
#define PADDLE_INITIAL_WIDTH 0.2
#define PADDLE_INITIAL_SPEED 0.8

#define WALL_POSITION 0.95

typedef struct {
    float location;
    float speed;
    float width;
} paddle_t;

typedef struct {
    vector2_t position;
    vector2_t velocity;
} ball_t;

typedef struct {
    ball_t ball;
    paddle_t paddle;
} game_t;


void game_paddle_init(paddle_t *paddle) {
    paddle->location = (GAME_WIDTH - PADDLE_INITIAL_WIDTH)/2.;
    paddle->speed = PADDLE_INITIAL_SPEED;
    paddle->width = PADDLE_INITIAL_WIDTH;
}

void game_ball_init(ball_t *ball) {
    ball->position.x = 0.5;
    ball->position.y = 0.0;

    ball->velocity.x = 0.8;
    ball->velocity.y = 0.8;
}

game_t* game_init()
{
    game_t* game = (game_t*)calloc(1, sizeof(game_t));
    game_paddle_init(&game->paddle);
    game_ball_init(&game->ball);
    return game;
}

void game_ball_update(ball_t* ball, float delta)
{
    ball->position = vector2_add(ball->position, vector2_scale(ball->velocity, delta));
    if (ball->position.x >= GAME_WIDTH) {
        ball->position.x = GAME_WIDTH;
        ball->velocity.x = -ball->velocity.x;
    } else if (ball->position.x <= 0) {
        ball->position.x = 0;
        ball->velocity.x = -ball->velocity.x;
    }

    if (ball->position.y >= WALL_POSITION) {
        ball->position.y = WALL_POSITION;
        ball->velocity.y = -ball->velocity.y;
    }
}

void game_paddle_update(paddle_t* paddle, float delta)
{
    if (glfwGetKey(GLFW_KEY_LEFT))
    {
        paddle->location -= (paddle->speed * delta);
        if (paddle->location < 0.) {
            paddle->location = 0.;
        }
    }

    if (glfwGetKey(GLFW_KEY_RIGHT))
    {
        paddle->location += (paddle->speed * delta);
        if (paddle->location + paddle->width > GAME_WIDTH) {
            paddle->location = GAME_WIDTH - paddle->width;
        }
    }
}

void game_update(game_t* game, float delta)
{
    game_paddle_update(&game->paddle, delta);
    game_ball_update(&game->ball, delta);
}

void game_render(game_t* game)
{
    glLineWidth(2);
    glBegin(GL_LINES);
    {
        glColor3f(1., 0., 0.);
        glVertex2f(game->paddle.location, -0.95);
        glVertex2f(game->paddle.location + game->paddle.width, -0.95);

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
        glVertex2f(game->ball.position.x, game->ball.position.y);
    }
    glEnd();
}
