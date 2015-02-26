//
//  GraphicEngineES1.cpp
//  iOS3DEngine
//
//  Created by Mo on 9/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "GraphicEngine.hpp"

#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>


typedef struct _vertexStruct
{
    GLfloat position[3];
    GLfloat texture[2];
    GLfloat normoal[3];
    GLubyte color[4];
} vertexStruct;


struct Stride {
    float Position[2];
    float Color[4];
};

static const Stride vertices[] = {
    -0.5, -0.5,     1, 0, 0.5f, 0.1,
    0.5, -0.5,1,    0.5, 0.5f, 0.1,
    0, 0.5, 0.2,    0.8, 0.5f, 0.1,
};

static const float revolutionsPerSecond = 3 ;

class GraphicEngineES1: public GraphicEngine
{
private:
    GLuint framebuffer, renderbuffer;
    float currentAngle;
    float correctAngle;
    
public:
    GraphicEngineES1();
    void initEngine(int width, int height, DeviceOrientation orientation);    
    void render() const;
    void onRotate(DeviceOrientation newOrientation);
    float rotationDirection() const;
    void updateAnimation(float timeStep);
    
};

GraphicEngine* createGraphicEngineUsingES1()
{
    return new GraphicEngineES1();
}

GraphicEngineES1::GraphicEngineES1()
{   
    glGenRenderbuffersOES(1, &renderbuffer);
    glGenFramebuffersOES(1, &framebuffer);
    currentAngle=correctAngle=0;
}

void GraphicEngineES1::initEngine(int width, int height, DeviceOrientation orientation)
{
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, renderbuffer);
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, framebuffer); 
    glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, renderbuffer);  
    
    //need width and height
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    
    // Initialize the projection matrix.
    const float maxX = 2;
    const float maxY = 3;
    glOrthof(-maxX, +maxX, -maxY, +maxY, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    
    // Initialize ratation angles 
    // Initialize the rotation animation state. 
    onRotate(orientation); 
    currentAngle = correctAngle;
}

void GraphicEngineES1::render() const
{
    glClearColor(1.0f, 0.5f, 0.0f, 1); 
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix(); 
    glRotatef(currentAngle, 0, 0, 1);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glVertexPointer(2, GL_FLOAT, sizeof(Stride), &vertices[0].Position[0]);
    glColorPointer(4, GL_FLOAT, sizeof(Stride), &vertices[0].Color[0]);
    
    GLsizei vertexCount = sizeof(vertices) / sizeof(Stride);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY); 
    
    glPopMatrix();
}

float GraphicEngineES1::rotationDirection() const
{
    float delta = correctAngle - currentAngle; 
    if (delta == 0)
        return 0;
    return ((delta > 0 && delta <= 180) || (delta < -180)) ? +1 : -1; 
}


void GraphicEngineES1::updateAnimation(float timeStep)
{
    float direction = rotationDirection(); 
    if (direction == 0)
        return;
    
    float degrees = timeStep * 360 / revolutionsPerSecond; 
    currentAngle += degrees * direction;
    
    // Ensure that the angle stays within [0, 360). 
    if (currentAngle >= 360)
        currentAngle -= 360; 
    else if (currentAngle < 0)
        currentAngle += 360;
    // If the rotation direction changed, then we overshot the desired angle. 
    if (rotationDirection() != direction)
        currentAngle = correctAngle;

}

void GraphicEngineES1::onRotate(DeviceOrientation orientation)
{
    switch (orientation) {
        case DeviceOrientation_LandscapeRight: 
            correctAngle = 90;
            break;
        case DeviceOrientation_UpsideDown: 
            correctAngle = 180;
            break;    
        case DeviceOrientation_LandscapeLeft:
            correctAngle = 270;
            break;
        default:
            correctAngle=0;   
            break;
    }
}