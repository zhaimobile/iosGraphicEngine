//
//  EngineDelegate.m
//  iOS3DEngine
//
//  Created by Mo on 9/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "EngineDelegate.h" 
#import <UIKit/UIKit.h>
#import "GLView.h"

@implementation EngineDelegate

- (BOOL) application: (UIApplication*) application
didFinishLaunchingWithOptions: (NSDictionary*) launchOptions 
{
    CGRect screenBounds = [[UIScreen mainScreen] bounds];
    
    m_window = [[UIWindow alloc] initWithFrame: screenBounds]; 
    m_view = [[GLView alloc] initWithFrame: screenBounds];
    
    [m_window addSubview: m_view]; 
    [m_window makeKeyAndVisible]; 
    return YES;
}

- (void) dealloc
{
    [m_view release]; 
    [m_window release]; 
    [super dealloc];
} 

@end