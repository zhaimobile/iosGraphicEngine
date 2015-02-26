//
//  GraphicEngine.hpp
//  iOS3DEngine
//
//  Created by Mo on 9/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef iOS3DEngine_GraphicEngine_hpp
#define iOS3DEngine_GraphicEngine_hpp

#include "MathEngine.hpp"
#include "ModuluBase.hpp"
#include "ShadersManager.hpp"
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>


// Interface to the OpenGL ES renderer; consumed by GLView.
struct GraphicEngine {
    virtual void initEngine(int width, int height) = 0;    
    virtual void render() const = 0;
    virtual void update(float duration) = 0;    
    virtual ~GraphicEngine(){}
};

GraphicEngine* createGraphicEngineUsingES2VBO();

#endif