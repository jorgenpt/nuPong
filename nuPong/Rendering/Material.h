//
//  Material.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Material__
#define __nuPong__Material__

#include <string>

#include <GL/glfw.h>

#include "Shader.h"

class Material {
    static GLuint activeProgram;
    GLuint programHandle;

    static GLuint link(const Shader* vertexShader, const Shader* fragmentShader);
    static std::string getLog(GLuint handle);
    static Shader *loadShader(GLenum type, const std::string& path);
    GLint getUniformLocation(const std::string& name) const;

public:
    static void deactivate();

    Material(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    ~Material();

    void apply() const;
    void setUniform(const std::string& name, float v);
};

#endif /* defined(__nuPong__Shader__) */
