//
//  ShadersManager.cpp
//  MoEngine
//
//  Created by Mo on 10/11/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ShadersManager.hpp"

//include the Shaders
#define STRINGIFY(A)  #A
#include "../Shaders/SimpleVBO.vert"
#include "../Shaders/SimpleVBO.frag"

ShadersManager::ShadersManager()
{
    shaderProgram=0;
    isInited=false;
}

GLuint ShadersManager::buildShader(const char* source, GLenum shaderType) 
{
    GLuint shaderHandle = glCreateShader(shaderType);
    glShaderSource(shaderHandle, 1, &source, 0);
    glCompileShader(shaderHandle);
    
    GLint compileSuccess;
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileSuccess);
    
    if (compileSuccess == GL_FALSE) {
        GLchar messages[256];
        glGetShaderInfoLog(shaderHandle, sizeof(messages), 0, &messages[0]);
        std::cout << messages;
        exit(1);
    }
    
    return shaderHandle;
}

GLuint ShadersManager::buildProgram(const char* vertexShaderSource, const char* fragmentShaderSource) 
{
    GLuint vertexShader = buildShader(vertexShaderSource, GL_VERTEX_SHADER);
    GLuint fragmentShader = buildShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
    
    GLuint programHandle = glCreateProgram();
    glAttachShader(programHandle, vertexShader);
    glAttachShader(programHandle, fragmentShader);
    glLinkProgram(programHandle);
    
    GLint linkSuccess;
    glGetProgramiv(programHandle, GL_LINK_STATUS, &linkSuccess);
    if (linkSuccess == GL_FALSE) {
        GLchar messages[256];
        glGetProgramInfoLog(programHandle, sizeof(messages), 0, &messages[0]);
        std::cout << messages;
        exit(1);
    }
    
    return programHandle;
}

bool ShadersManager::initShaders()
{
    if(instance()->isInited) 
        return false;
    
    // Build the GLSL program.
    instance()->shaderProgram= ShadersManager::buildProgram(SimpleVertexShaderVBO, SimpleFragmentShaderVBO);
    glUseProgram(instance()->shaderProgram);
    
    instance()->isInited=true;
    
    return true;   
}

GLuint ShadersManager::getShaders()
{
    if(instance()->isInited)
        return instance()->shaderProgram;
    else
    {
        initShaders();
        return instance()->shaderProgram;
    }
}