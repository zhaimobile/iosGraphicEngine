//
//  TxLoader.h
//  MoEngine
//
//  Created by Mo on 10/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <string>
#import <iostream>

using namespace std;

@interface TxLoader : NSObject
{
@private
    unsigned txWidth,txHeight;
    CFDataRef imageData;
}

-(unsigned) txWidth;
-(unsigned) txHeight;
    
-(string)GetResourcePath;
-(void*) GetImageData;

-(void)LoadPngImage:(NSString*)name;
-(void)UnloadImage;
    
@end
