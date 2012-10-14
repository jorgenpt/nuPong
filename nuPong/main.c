//
//  main.c
//  nuPong
//
//  Created by Jørgen Tjernø on 10/14/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include <GL/glfw.h>
#include <stdlib.h>
#include <math.h>

#include "game.h"

#define MAX_DELTA_TIME (1./60.)

int main(void)
{
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    if (!glfwOpenWindow(800, 600, 0, 0, 0, 0, 0, 0, GLFW_WINDOW))
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    game_data* game = game_init();

    double currentTime = glfwGetTime();
    int running = GL_TRUE;
    while (running)
    {
        double newTime = glfwGetTime();
        double frameTime = newTime - currentTime;
        currentTime = newTime;
        
        while (frameTime > 0.0)
        {
            const float deltaTime = fmin(frameTime, MAX_DELTA_TIME);
            game_update(game, deltaTime);
            frameTime -= deltaTime;
        }

        glClear(GL_COLOR_BUFFER_BIT);
        game_render(game);
        glfwSwapBuffers();

        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }

    glfwTerminate();

    return 0;
}