//
//  GraphicEngineES2.cpp
//  iOS3DEngine
//
//  Created by Mo on 9/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#include "GraphicEngine.hpp"

#include "Matrix2.hpp"

#include MathEngine.hpp

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#include <vector>
#include <iostream>
using namespace std;

//include the Shaders
#define STRINGIFY(A)  #A
#include "../Shaders/Simple.vert"
#include "../Shaders/Simple.frag"

struct Stride {
    float Position[3];
    float Texture[2];
    float Normoal[3];
    float Color[4];
};

class GraphicEngineES2: public GraphicEngine
{
private:
    //GLuint framebuffer, renderbuffer; this are just used in M1
    
    GLuint sharderProgram;
    GLuint framebuffer;
    
    GLuint colorRenderbuffer;  //?????why renderbuffer need two???
    GLuint depthRenderbuffer;
    
    vector<Stride> m_disk;
    
private:    
    GLuint buildShader(const char* source, GLenum shaderType) const;
    GLuint buildProgram(const char* vShader, const char* fShader) const;
    
public:
    GraphicEngineES2();
    void initEngine(int width, int height, DeviceOrientation orientation);
    void loadData();
    void render() const;
    void onRotate(DeviceOrientation newOrientation);
    void updateAnimation(float timeStep);
    
};

GraphicEngine* createGraphicEngineUsingES2()
{
    return new GraphicEngineES2();
}

GraphicEngineES2::GraphicEngineES2()
{
    // Create & bind the color buffer so that the caller can allocate its space.
    glGenRenderbuffers(1, &colorRenderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbuffer);
}

void GraphicEngineES2::initEngine(int width, int height, DeviceOrientation orientation)
{
    // Create the depth buffer.
    glGenRenderbuffers(1, &depthRenderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, depthRenderbuffer);
    glRenderbufferStorage(GL_RENDERBUFFER,
                          GL_DEPTH_COMPONENT16,
                          width,
                          height);
    
    // Create the framebuffer object; attach the depth and color buffers.
    glGenFramebuffers(1, &framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_COLOR_ATTACHMENT0,
                              GL_RENDERBUFFER,
                              colorRenderbuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,
                              GL_DEPTH_ATTACHMENT,
                              GL_RENDERBUFFER,
                              depthRenderbuffer);
    
    // Bind the color buffer for rendering.
    glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbuffer);
    
    // Set up some GL state.
    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);
    
    // Build the GLSL program.
    sharderProgram = buildProgram(SimpleVertexShader, SimpleFragmentShader);
    glUseProgram(sharderProgram);
    
    // Set the projection matrix.
    GLint projectionUniform = glGetUniformLocation(sharderProgram, "Projection");
    mat4 projectionMatrix = mat4::Frustum(-1.6f, 1.6, -2.4, 2.4, 2.0, 20);
    glUniformMatrix4fv(projectionUniform, 1, 0, projectionMatrix.Pointer());
    
    //read data
    this->loadData();
}

void GraphicEngineES2::loadData()
{
    // Initialize the center vertex of the triangles
    {    
        m_disk.resize(36);
        vector<Stride>::iterator vertex = m_disk.begin();
        
        //the bottom face
        //the first triangle
        vertex->Position[0] = -0.5f;    vertex->Position[1] = - 0.5f;   vertex->Position[2] = -0.5;
        vertex->Color[0]= 1.0;vertex->Color[1]= 0.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 0
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] = - 0.5f;   vertex->Position[2] = -0.5f;
        vertex->Color[0]= 1.0;vertex->Color[1]= 0.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 1
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] = - 0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 1.75;vertex->Color[1]= 0.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 2
        
        //the second triangle
        vertex->Position[0] = -0.5f;    vertex->Position[1] = - 0.5f;   vertex->Position[2] = -0.5;
        vertex->Color[0]= 1.0;vertex->Color[1]= 0.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 0
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] = - 0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 1.0;vertex->Color[1]= 0.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 2
        
        vertex->Position[0] = -0.5f;    vertex->Position[1] = - 0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 1.0;vertex->Color[1]= 0.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 3  
        
        //the top face
        //the first triangle
        vertex->Position[0] = -0.5f;    vertex->Position[1] =  0.5f;   vertex->Position[2] = -0.5;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 4
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] =  0.5f;   vertex->Position[2] = -0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 5
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] =  0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 6
        
        //the second triangle
        vertex->Position[0] = -0.5f;    vertex->Position[1] =  0.5f;   vertex->Position[2] = -0.5;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 4
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] =  0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 6
        
        vertex->Position[0] = -0.5f;    vertex->Position[1] =  0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 7  
        
        ////the left face
        //the first triangle
        vertex->Position[0] = -0.5f;    vertex->Position[1] = - 0.5f;   vertex->Position[2] = -0.5;
        vertex->Color[0]= 0.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 0
        
        vertex->Position[0] = -0.5f;    vertex->Position[1] = - 0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 3
        
        vertex->Position[0] = -0.5f;    vertex->Position[1] =  0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 7 
        
        //the second triangle
        vertex->Position[0] = -0.5f;    vertex->Position[1] = - 0.5f;   vertex->Position[2] = -0.5;
        vertex->Color[0]= 0.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 0
        
        vertex->Position[0] = -0.5f;    vertex->Position[1] =  0.5f;   vertex->Position[2] = -0.5;
        vertex->Color[0]= 0.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 4
        
        vertex->Position[0] = -0.5f;    vertex->Position[1] =  0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 7 
        
        //the right face   
        //the first triangle
        vertex->Position[0] = 0.5f;     vertex->Position[1] = - 0.5f;   vertex->Position[2] = -0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 1
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] = - 0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 2
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] =  0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 6
        
        //the second triangle
        vertex->Position[0] = 0.5f;     vertex->Position[1] = - 0.5f;   vertex->Position[2] = -0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 1
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] =  0.5f;   vertex->Position[2] = -0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 5
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] =  0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 0.0;vertex->Color[1]= 1.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 6
        
        //the back face
        //the first triangle
        vertex->Position[0] = -0.5f;    vertex->Position[1] = - 0.5f;   vertex->Position[2] = -0.5;
        vertex->Color[0]= 1.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 0
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] = - 0.5f;   vertex->Position[2] = -0.5f;
        vertex->Color[0]= 1.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 1
        
        vertex->Position[0] = -0.5f;    vertex->Position[1] =  0.5f;   vertex->Position[2] = -0.5;
        vertex->Color[0]= 1.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 4
        
        //the second triangle
        vertex->Position[0] = 0.5f;     vertex->Position[1] = - 0.5f;   vertex->Position[2] = -0.5f;
        vertex->Color[0]= 1.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 1
        
        vertex->Position[0] = -0.5f;    vertex->Position[1] =  0.5f;   vertex->Position[2] = -0.5;
        vertex->Color[0]= 1.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 4
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] =  0.5f;   vertex->Position[2] = -0.5f;
        vertex->Color[0]= 1.0;vertex->Color[1]= 0.0;vertex->Color[2]= 1.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 5
        
        //the front face    
        //the first triangle
        vertex->Position[0] = -0.5f;    vertex->Position[1] = - 0.5f;   vertex->Position[2] = 0.5;
        vertex->Color[0]= 1.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 3
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] = - 0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 1.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 2
        
        vertex->Position[0] = -0.5f;    vertex->Position[1] =  0.5f;   vertex->Position[2] = 0.5;
        vertex->Color[0]= 1.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 7
        
        //the second triangle
        vertex->Position[0] = 0.5f;     vertex->Position[1] = - 0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 1.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 2
        
        vertex->Position[0] = -0.5f;    vertex->Position[1] =  0.5f;   vertex->Position[2] = 0.5;
        vertex->Color[0]= 1.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 7
        
        vertex->Position[0] = 0.5f;     vertex->Position[1] =  0.5f;   vertex->Position[2] = 0.5f;
        vertex->Color[0]= 1.0;vertex->Color[1]= 1.0;vertex->Color[2]= 0.0;vertex->Color[03]= 0.5;
        vertex++;//vertex 6
    }    
}

void GraphicEngineES2::render() const
{
    //set up the modelview_Matrix | should not be here!!!!!
    //mat4 rotation(m_animation.Current.ToMatrix());
    
    static float v;
    v += 1.5; 
    mat4 rotation = mat4::Rotate(v);
    mat4 rotation2 = mat4::Rotate(v*5);
    mat4 translation = mat4::Translate(2, 2, -3.5);
    mat4 modelviewMatrix = rotation2 * translation;// * rotation;
    
    // Set the model-view matrix.
    GLint modelviewUniform = glGetUniformLocation(sharderProgram, "Modelview");
    glUniformMatrix4fv(modelviewUniform, 1, 0, modelviewMatrix.Pointer());
    
    GLuint positionSlot = glGetAttribLocation(sharderProgram, "Position");
    GLuint colorSlot = glGetAttribLocation(sharderProgram, "Color");
    
    
    //clear....
    glClearColor(1.0f, 0.5f, 0.0f, 0.35);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //bind data pos color and etc... should use better way like vbo....
    glEnableVertexAttribArray(positionSlot);
    glEnableVertexAttribArray(colorSlot);
    
    // Draw 
    GLsizei strideSize = sizeof(Stride);
    const GLvoid* pCoords = &(m_disk[0].Position);
    const GLvoid* pColors = &(m_disk[0].Color);
    glVertexAttribPointer(positionSlot, 3, GL_FLOAT, GL_FALSE, strideSize, pCoords);
    glVertexAttribPointer(colorSlot, 4, GL_FLOAT, GL_FALSE, strideSize, pColors);
    glDrawArrays(GL_TRIANGLES, 0, m_disk.size());
    
    glDisableVertexAttribArray(positionSlot);
    glDisableVertexAttribArray(colorSlot);

}

void GraphicEngineES2::onRotate(DeviceOrientation newOrientation)
{
    
}

void GraphicEngineES2::updateAnimation(float timeStep)
{
    
}


GLuint GraphicEngineES2::buildShader(const char* source, GLenum shaderType) const
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

GLuint GraphicEngineES2::buildProgram(const char* vertexShaderSource, const char* fragmentShaderSource) const
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
