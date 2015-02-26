//
//  EngineDelegate.h
//  iOS3DEngine
//
//  Created by Mo on 9/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "GLView.h"

@interface EngineDelegate: NSObject <UIApplicationDelegate>{
    UIWindow* m_window;
    GLView* m_view;
}

@end