//
//  Material.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Material.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include "Shader.h"

GLuint Material::activeProgram = 0;

Material::Material(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) :programHandle(0)
{
    // TODO: Use a ShaderManager to load (and re-use) shaders from file.
    Shader *vertexShader = NULL, *fragmentShader = NULL;

    if (vertexShaderPath.length() > 0)
        vertexShader = loadShader(GL_VERTEX_SHADER, vertexShaderPath);
    if (fragmentShaderPath.length() > 0)
        fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentShaderPath);

    if (vertexShader && vertexShader->getType() != GL_VERTEX_SHADER)
    {
        std::cerr << "Got invalid vertex shader, ignoring.";
        vertexShader = NULL;
    }

    if (fragmentShader && fragmentShader->getType() != GL_FRAGMENT_SHADER)
    {
        std::cerr << "Got invalid vertex shader, ignoring.";
        fragmentShader = NULL;
    }

    programHandle = link(vertexShader, fragmentShader);

    // These are no longer needed.
    delete vertexShader;
    delete fragmentShader;
}

Material::~Material()
{
    glDeleteProgram(programHandle);
}

GLint Material::getUniformLocation(const std::string& name) const
{
    // TODO: Cache these?
    return glGetUniformLocation(programHandle, name.c_str());
}

GLuint Material::link(const Shader* vertexShader, const Shader* fragmentShader)
{
    if (!vertexShader && !fragmentShader)
        return 0;

    GLuint handle = glCreateProgram();
    if (!glIsProgram(handle))
        return 0;

    if (vertexShader)
        vertexShader->attachTo(handle);
    if (fragmentShader)
        fragmentShader->attachTo(handle);

    glLinkProgram(handle);

    // Print link log.
    std::cout << "Linking results:" << std::endl;
    std::cout << getLog(handle) << std::endl;

    // Clean up handle if it failed.
    GLint linkStatus;
    glGetProgramiv(handle, GL_LINK_STATUS, &linkStatus);
    if (linkStatus == GL_FALSE)
    {
        glDeleteProgram(handle);
        return 0;
    }

    return handle;
}

std::string Material::getLog(GLuint handle)
{
    GLint logLength;
    glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &logLength);

    GLchar *log = new GLchar[logLength];
    glGetProgramInfoLog(handle, logLength, NULL, log);
    std::string logString(log);
    delete log;

    return logString;
}

void Material::deactivate()
{
    if (activeProgram != 0) {
        glUseProgram(0);
        activeProgram = 0;
    }
}

Shader *Material::loadShader(GLenum type, const std::string& path)
{
    Shader *shader = NULL;

    //First, let us load the vertex shader.
    std::fstream file(path, std::ios::in);
    if (file.is_open()) {
        //This is to help store the file's buffer.
        std::stringstream buffer;
        buffer << file.rdbuf();
        shader = new Shader(type, buffer.str());
    }

    return shader;
}

void Material::apply() const
{
    if (activeProgram != programHandle) {
        glUseProgram(programHandle);
        activeProgram = programHandle;
    }
}

void Material::setUniform(const std::string& name, float v)
{
    apply();

    GLint location = getUniformLocation(name);
    glUniform1f(location, v);
}
