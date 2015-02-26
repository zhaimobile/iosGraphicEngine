
//  FileSystem.h
//  MoEngine
//
//  Created by Mo on 10/12/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ResourceManager.hpp"

@interface FileSystem : NSObject
{
}

+(void)fileloader:(NSString*)name withID:(unsigned)ID;
+(void)dumpBundle;
+(void)createFile:(NSString*)name;
+(void)updateFile:(NSString*)name;

+(void)fileloader2;
+(void)fileloader3;

@end
