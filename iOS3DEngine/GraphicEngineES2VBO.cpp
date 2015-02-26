//
//  GraphicEngineES2VBO.cpp
//  iOS3DEngine
//
//  Created by Mo on 10/3/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.

#include "GraphicEngine.hpp"

class GraphicEngineES2VBO: public GraphicEngine
{
private:
    GLuint framebuffer;
    
    GLuint colorRenderbuffer;  //?????why renderbuffer need two???
    GLuint depthRenderbuffer;

public:
    GraphicEngineES2VBO();
    void initEngine(int width, int height);
    
    void render() const;
    void update(float duration);

    ModuluBase * cube;
    ModuluBase * bear;
    ModuluBase * boy;
    
};

GraphicEngine* createGraphicEngineUsingES2VBO()
{
    return new GraphicEngineES2VBO();
}

GraphicEngineES2VBO::GraphicEngineES2VBO()
{
    // Create & bind the color buffer so that the caller can allocate its space.
    glGenRenderbuffers(1, &colorRenderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbuffer);
    
    cube = new ModuluBase(0, (char*)"emmy");
    bear = new ModuluBase(1, (char*)"bear");
    boy = new ModuluBase(2, (char*)"boy");
}

void GraphicEngineES2VBO::initEngine(int width, int height)
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
    
    // Set the projection matrix.
    GLint projectionUniform = glGetUniformLocation( ShadersManager::getShaders(), "Projection");
    Matrix projectionMatrix = Matrix::Frustum(-1.6f, 1.6, -2.4, 2.4, 2, 400);
    glUniformMatrix4fv(projectionUniform, 1, 0, projectionMatrix.Pointer());
    
    
    //load data
    this->cube->loadData();//this->cube->loadDataHard();
    this->bear->loadData();
    this->boy->loadData();
}

void GraphicEngineES2VBO::render() const
{    
    //clear....
    glClearColor(1.0f, 0.5f, 0.0f, 0.35);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    static float v;
    v += 0.05; 

    
    Matrix cubeT= Matrix(TRANS,0, 6, -6);
    this->cube->updateAndDraw(Matrix(ROT_Z,v)*Matrix(TRANS,8, 0, 0)*Matrix(ROT_Y,v/3)*cubeT);
    
    this->cube->updateAndDraw(Matrix(ROT_Z,-v)*Matrix(ROT_Y,v)*Matrix(TRANS,0, 1, -3));

    
    Matrix bearT = Matrix(TRANS, -100, -150, -300);
    this->bear ->updateAndDraw(Matrix(ROT_Z,v)*Matrix(ROT_X,-90)*bearT);
    
    Matrix boyT = Matrix(TRANS, 100, -70, -350);
    this->boy->updateAndDraw(Matrix(ROT_Z,v)*Matrix(ROT_X,-90)*boyT);//Matrix(ROT_Y,90)*
}

void GraphicEngineES2VBO::update(float duration)
{
    
}