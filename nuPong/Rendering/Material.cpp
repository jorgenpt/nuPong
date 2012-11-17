//
//  Material.cpp
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#include "Material.h"

#include <iostream>

#include "Shader.h"
#include "Filesystem.h"
#include "Strings.h"

GLuint Material::activeProgram = 0;

Material::Material(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) :programHandle(0)
{
    // TODO: Use a ShaderManager to load (and re-use) shaders from file.
    Shader *vertexShader = NULL, *fragmentShader = NULL;

    if (vertexShaderPath.length() > 0)
        vertexShader = loadShader(GL_VERTEX_SHADER, "Shaders/Common", "Shaders/" + vertexShaderPath);
    if (vertexShader && vertexShader->getType() != GL_VERTEX_SHADER)
    {
        std::cerr << "Got invalid vertex shader, ignoring." << std::endl;
        vertexShader = NULL;
    }

    if (fragmentShaderPath.length() > 0)
        fragmentShader = loadShader(GL_FRAGMENT_SHADER, "Shaders/Common", "Shaders/" + fragmentShaderPath);
    if (fragmentShader && fragmentShader->getType() != GL_FRAGMENT_SHADER)
    {
        std::cerr << "Got invalid vertex shader, ignoring." << std::endl;
        fragmentShader = NULL;
    }

    programHandle = link(vertexShader, fragmentShader);

    // These are no longer needed.
    delete vertexShader;
    delete fragmentShader;
}

Material::~Material()
{
    if (activeProgram == programHandle)
        deactivate();

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
    std::string log = getLog(handle);
    if (!log.empty())
    {
        std::cout << "Linking results:" << std::endl;
        std::cout << log << std::endl;
    }

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

Shader *Material::loadShader(GLenum type, const std::string& commonPath, const std::string& path)
{
    std::string shaderContent, commonShadersContent;
    std::string extension(type == GL_VERTEX_SHADER ? ".vert" : ".frag");
    std::vector<std::string> commonShaders;

    if (Filesystem::entries(commonPath, &commonShaders)) {
        std::sort(commonShaders.begin(), commonShaders.end());

        for (auto commonShader : commonShaders) {
            if (!Strings::endsWith(commonShader, extension))
                continue;

            std::string commonShaderContent;
            if (Filesystem::readFile(commonPath + "/" + commonShader, &commonShaderContent)) {
                commonShadersContent += commonShaderContent + "\n";
            }
        }
    }

    Shader *shader = NULL;
    if (Filesystem::readFile(path, &shaderContent)) {
        shader = new Shader(type, commonShadersContent + shaderContent);
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
