//
//  ShadersManager.h
//  MoEngine
//
//  Created by Mo on 10/11/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef MoEngine_ShadersManager_h
#define MoEngine_ShadersManager_h

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

class ShadersManager
{    
private:    
    GLuint shaderProgram;
    bool isInited;
    
	ShadersManager();
    
    //sigleton-inline
	static ShadersManager* instance()
	{
		static ShadersManager instance;
		return &instance;
	}    
    
    static GLuint buildShader(const char*, GLenum);
    static GLuint buildProgram(const char*, const char*);
    static bool initShaders();
    
public:    
    static GLuint getShaders();
};

#endif
