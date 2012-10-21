//
//  Shader.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Shader.h"

#include <iostream>

Shader::Shader(GLenum type, const std::string& source) :shaderHandle(0)
{
    shaderHandle = load(type, source);
}

Shader::~Shader()
{
    glDeleteShader(shaderHandle);
}

GLuint Shader::load(GLenum type, const std::string& source)
{
    GLuint handle = glCreateShader(type);
    if (!glIsShader(handle))
        return handle;

    const GLchar *sources[] = { source.c_str() };
    const GLint lengths[] = { (GLint)source.length() };

    // Try to load and compile the shader.
    glShaderSource(handle, 1, sources, lengths);
    glCompileShader(handle);

    // Print compilation log.
    std::string log = getLog(handle);
    if (!log.empty())
    {
        std::cout << "Compilation results:" << std::endl;
        std::cout << log << std::endl;
    }

    // Clean up handle if it failed.
    GLint compileStatus;
    glGetShaderiv(handle, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == GL_FALSE)
    {
        glDeleteShader(handle);
        return 0;
    }

    return handle;
}

std::string Shader::getLog(GLuint handle)
{
    GLint logLength;
    glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &logLength);

    GLchar *log = new GLchar[logLength];
    glGetShaderInfoLog(handle, logLength, NULL, log);
    std::string logString(log);
    delete log;

    return logString;
}

void Shader::attachTo(GLuint shaderProgram) const
{
    if (glIsShader(shaderHandle))
        glAttachShader(shaderProgram, shaderHandle);
}

GLenum Shader::getType() const
{
    if (!glIsShader(shaderHandle))
        return GL_FALSE;

    GLint type = 0;
    glGetShaderiv(shaderHandle, GL_SHADER_TYPE, &type);
    return (GLenum)type;
}
