//
//  GLView.mm
//  iOS3DEngine
//
//  Created by Mo on 9/21/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "GLView.h"
#ifndef GL_RENDERBUFFER
#define GL_RENDERBUFFER 0x8d41  //#import <OpenGLES/ES2/gl.h>   //#import <OpenGLES/ES2/glext.h>
#endif

@implementation GLView

static EAGLRenderingAPI api = kEAGLRenderingAPIOpenGLES2;

+ (Class) layerClass
{
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame{
    if (self = [super initWithFrame:frame]) {
        
        [FileSystem fileloader:@"cube.mo"withID:0];
        [FileSystem fileloader:@"bear.mo"withID:1];
        [FileSystem fileloader:@"boy.mo"withID:2];

        
        //[FileSystem fileloader2];
        //[FileSystem fileloader3];
        
        [FileSystem dumpBundle];
        
        CAEAGLLayer* eaglLayer = (CAEAGLLayer*) super.layer; 
        eaglLayer.opaque = YES;//do not use Quartz to handle transparency
          
        
        m_context = [[EAGLContext alloc] initWithAPI:api];
        
        if (!m_context || ![EAGLContext setCurrentContext:m_context]) { 
            [self release];
            return nil;
        }
            
        //create and init the graphicEngine
        m_graphicEngine = createGraphicEngineUsingES2VBO(); 

    
        m_graphicEngine->initEngine(CGRectGetWidth(frame), CGRectGetHeight(frame));
            
        //link renderbufferStorage to Drawable
        [m_context renderbufferStorage:GL_RENDERBUFFER fromDrawable: eaglLayer];
            
            
        //init time and set up CADisplayLink which can callback the event selected  
        m_lastTimeStamp=CACurrentMediaTime();
        CADisplayLink* displayLink;
        displayLink = [CADisplayLink 
                           displayLinkWithTarget:self
                           selector:@selector(updateAndRender:)];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    
            
        //set up the screen Orientation Notifications 
        [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
        [[NSNotificationCenter defaultCenter] 
            addObserver:self
            selector:@selector(didRotate:)
            name:UIDeviceOrientationDidChangeNotification 
            object:nil];           
     
        //[self updateAndRender:nil];
        }
    return self;
}

- (void) didRotate: (NSNotification*) notification
{
//  UIDeviceOrientation orientation = [[UIDevice currentDevice] orientation];     
    [self updateAndRender: nil];
}

-(void) updateAndRender:(CADisplayLink*)displayLink
{
    //update    
    if(displayLink !=nil)
    {
        float deltaTime = [displayLink timestamp] - m_lastTimeStamp;   
        m_lastTimeStamp = [displayLink timestamp];
        m_graphicEngine->update(deltaTime);
    }
    
    //render
    m_graphicEngine->render();
    [m_context presentRenderbuffer:GL_RENDERBUFFER];//became the std in es2      
}

-(void) dealloc
{
    if ([EAGLContext currentContext] == m_context)
        [EAGLContext setCurrentContext:nil];
    [m_context release];
    [super dealloc];
}

@end
