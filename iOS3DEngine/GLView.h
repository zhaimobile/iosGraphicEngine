//
//  GLView.h
//  iOS3DEngine
//
//  Created by Mo on 9/21/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#import <QuartzCore/QuartzCore.h>
#import "GraphicEngine.hpp"
#import "FileSystem.h"

@interface GLView : UIView {
@private
    EAGLContext * m_context;
    GraphicEngine * m_graphicEngine;
    float m_lastTimeStamp;
}

-(void) updateAndRender:(CADisplayLink*)displayLink;
-(void) didRotate: (NSNotification*) notification;

@end