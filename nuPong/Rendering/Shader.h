//
//  Shader.h
//  nuPong
//
//  Created by Jørgen Tjernø on 10/20/12.
//  Copyright (c) 2012 bitSpatter. All rights reserved.
//

#ifndef __nuPong__Shader__
#define __nuPong__Shader__

#include <string>
#include <GL/glfw.h>

class Shader {
    GLuint shaderHandle;

    static GLuint load(GLenum type, const std::string& source);
    static std::string getLog(GLuint handle);

public:
    Shader(GLenum type, const std::string& source);
    ~Shader();

    void attachTo(GLuint shaderProgram) const;
    GLenum getType() const;
};

#endif /* defined(__nuPong__Shader__) */
