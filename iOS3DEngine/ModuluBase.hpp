//
//  ModuluBase.hpp
//  MoEngine
//
//  Created by Mo on 10/11/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef MoEngine_ModuluBase_hpp
#define MoEngine_ModuluBase_hpp

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#include "MathEngine.hpp"
#include "ShadersManager.hpp"
#include "ResourceManager.hpp"


struct  Vertex
{
    float x;
    float y;
    float z;
    float r;
    float g;    
    float b;    
    float a;
    float s;    
    float t;
    float nx;
    float ny;
    float nz;
};

struct Triangle
{
    unsigned short v1;
    unsigned short v2;
    unsigned short v3;
};

class ModuluBase
{
private:   
    unsigned ID;
    char* szFileName;
    GLuint vao1;
    GLsizei indicesNum;   
    GLuint	textureID;

public:
    ModuluBase(unsigned, char*);

    void loadDataHard();
    void loadData();
    bool loadTexture();
    void updateAndDraw(Matrix);
};
#endif
