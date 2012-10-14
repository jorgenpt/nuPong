//
//  main.c
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include <GL/glfw.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "game.h"

#define WINDOW_WIDTH (800.)
#define WINDOW_HEIGHT (600.)
#define MAX_DELTA_TIME (1./60.)

void GLFWCALL window_resized(int width, int height) {
    glViewport(0, 0, width, height);
}

void render(game_t* game) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    game_render(game);
    glfwSwapBuffers();
}

void check_errors() {
    GLenum error;
    while ((error = glGetError()) != GL_NO_ERROR) {
        fprintf(stderr, "GL error: %s\n", gluErrorString(error));
    }
}

void setup() {
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    if (!glfwOpenWindow(WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0, 0, 0, 0, 0, GLFW_WINDOW))
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetWindowSizeCallback(&window_resized);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0., 1., -1., 1., -1., 1.);
}

int main(void)
{
    setup();

    game_t* game = game_init();

    double currentTime = glfwGetTime();
    int running = GL_TRUE;
    while (running)
    {
        // Semi-fixed delta state update - breaks frametime up into MAX_DELTA_TIME chunks.
        double newTime = glfwGetTime();
        double frameTime = newTime - currentTime;
        currentTime = newTime;
        while (frameTime > 0.0)
        {
            const float deltaTime = fmin(frameTime, MAX_DELTA_TIME);
            game_update(game, deltaTime);
            frameTime -= deltaTime;
        }

        render(game);
        check_errors();

        // Check for exit condition.
        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }

    glfwTerminate();

    return 0;
}
