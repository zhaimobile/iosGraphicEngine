//
//  FileSystem.mm
//  MoEngine
//
//  Created by Mo on 10/12/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "FileSystem.h"
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>


#include <iostream>
#include <fstream>
using namespace std;

@implementation FileSystem


unsigned int len;
Byte *bytebinaryArray;

- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

+(void)fileloader:(NSString*)name withID:(unsigned)ID
{
    // Open inFile for reading
    NSString* mainBundlePath = [[NSBundle mainBundle] resourcePath];
    NSString* filePath = [mainBundlePath stringByAppendingPathComponent:name];

    NSFileHandle* inFile = [NSFileHandle fileHandleForReadingAtPath: filePath];
    if (inFile == nil) {
        NSLog (@"Open infile for reading failed");
    }

    NSData *bufferIn=[inFile availableData];

    //unsigned int
    len=[bufferIn length];
    //Byte *
    bytebinaryArray = new Byte[len];
    memcpy(bytebinaryArray, [bufferIn bytes], len);

    //connect the bridge
    ResourceManager::setByteBinaryArrayWithID(len, bytebinaryArray, ID);
}

//dump the main path of the iOS application and subs
+(void)dumpBundle
{    
    NSString* path = [[NSBundle mainBundle] resourcePath];
    NSDirectoryEnumerator *dirEnum = [[NSFileManager defaultManager] enumeratorAtPath: path];
    NSLog (@"Contents of %@", path);
    while ((path = [dirEnum nextObject]) != nil) 
        NSLog (@"%@", path);
    
}


//createFile @ documentsDirectory
+(void)createFile:(NSString*)name
{    
    NSArray *pathArray = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [pathArray objectAtIndex:0];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:name];
 
    // Create the output file first if necessary 
    [[NSFileManager defaultManager] createFileAtPath: filePath contents: nil attributes: nil];
}

//updateFile @ documentsDirectory
+(void)updateFile:(NSString*)name
{
    
    NSFileHandle *inFile, *outFile; 
    NSArray *pathArray = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [pathArray objectAtIndex:0];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:name];
    
    // Create the output file first if necessary 
    [[NSFileManager defaultManager] createFileAtPath: filePath contents: nil attributes: nil];
    
    // Open inFile for reading
    inFile = [NSFileHandle fileHandleForReadingAtPath: filePath];
    if (inFile == nil) {
        NSLog (@"Open infile for reading failed");
    }
    
    // Open outFile for writing
    outFile = [NSFileHandle fileHandleForWritingAtPath: filePath];
    if (outFile == nil) {
        NSLog (@"Open outFile for writing failed");
    }
}

+(void)fileloader2
{       
    NSFileManager *fm;
    fm = [NSFileManager defaultManager];
    
    //the outFile and inFile are same File but different handle, inFile for Reading outFile for writing
    NSFileHandle *inFile, *outFile; 
    NSArray *pathArray = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [pathArray objectAtIndex:0];
    NSString *outFilePath = [documentsDirectory stringByAppendingPathComponent:@"cube.mo"];
    
    // Create the output file first if necessary 
    [[NSFileManager defaultManager] createFileAtPath: outFilePath contents: nil attributes: nil];
    
    // Open inFile for reading
    inFile = [NSFileHandle fileHandleForReadingAtPath: outFilePath];
    if (inFile == nil) {
        NSLog (@"Open infile for reading failed");
    }
    
    // Open outFile for writing
    outFile = [NSFileHandle fileHandleForWritingAtPath: outFilePath];
    if (outFile == nil) {
        NSLog (@"Open outFile for writing failed");
    }
    
    ////////////////////////////////////////////////
    typedef struct _vertexStruct
    {
        float position[3];
        float color[4];
        float texture[2];
        float normoal[3];
    } vertexStruct;
    
    struct Triangle
    {
        unsigned short v1;
        unsigned short v2;
        unsigned short v3;
    };
    
    vertexStruct vertices[36];
    Triangle indices[12];

    //unsigned short indices[36];
    
    //indicesNum=sizeof(indices)/sizeof(GLubyte);
    
    //data
    vertices[0].position[0] = -0.5f;    vertices[0].position[1] = - 0.5f;   vertices[0].position[2] = -0.5;
    vertices[0].texture[0]= 0.0;vertices[0].texture[1]= 0.0;
    vertices[0].normoal[0] = -0.5f;    vertices[0].normoal[1] = - 0.5f;   vertices[0].normoal[2] = -0.5;
    vertices[0].color[0]= 1.0;vertices[0].color[1]= 0.0;vertices[0].color[2]= 0.0;vertices[0].color[3]= 0.5;
    
    vertices[1].position[0] = 0.5f;     vertices[1].position[1] = - 0.5f;   vertices[1].position[2] = -0.5f;
    vertices[1].texture[0]= 1.0;vertices[1].texture[1]= 0.0;
    vertices[1].normoal[0] = 0.5f;     vertices[1].normoal[1] = - 0.5f;   vertices[1].normoal[2] = -0.5f;    
    vertices[1].color[0]= 1.0;vertices[1].color[1]= 0.0;vertices[1].color[2]= 0.0;vertices[1].color[3]= 0.5;
    
    vertices[2].position[0] = 0.5f;     vertices[2].position[1] = - 0.5f;   vertices[2].position[2] = 0.5f;
    vertices[2].texture[0]= 1.0;vertices[2].texture[1]= 1.0;
    vertices[2].normoal[0] = 0.5f;     vertices[2].normoal[1] = - 0.5f;   vertices[2].normoal[2] = 0.5f;    
    vertices[2].color[0]= 1.0;vertices[2].color[1]= 0.0;vertices[2].color[2]= 0.0;vertices[2].color[3]= 0.5;
    
    
    //the second triangle
    vertices[3].position[0] = -0.5f;    vertices[3].position[1] = - 0.5f;   vertices[3].position[2] = -0.5;
    vertices[3].texture[0]= 0.0;vertices[3].texture[1]= 0.0;
    vertices[3].normoal[0] = -0.5f;    vertices[3].normoal[1] = - 0.5f;   vertices[3].normoal[2] = -0.5;    
    vertices[3].color[0]= 1.0;vertices[3].color[1]= 0.0;vertices[3].color[2]= 0.0;vertices[3].color[3]= 0.5;
    
    vertices[4].position[0] = -0.5f;    vertices[4].position[1] = - 0.5f;   vertices[4].position[2] = 0.5f;
    vertices[4].texture[0]= 0.0;vertices[4].texture[1]= 1.0;
    vertices[4].normoal[0] = -0.5f;    vertices[4].normoal[1] = - 0.5f;   vertices[4].normoal[2] = 0.5f;    
    vertices[4].color[0]= 1.0;vertices[4].color[1]= 0.0;vertices[4].color[2]= 0.0;vertices[4].color[03]= 0.5;
    
    vertices[5].position[0] = 0.5f;     vertices[5].position[1] = - 0.5f;   vertices[5].position[2] = 0.5f;
    vertices[5].texture[0]= 1.0;vertices[5].texture[1]= 1.0;
    vertices[5].normoal[0] = 0.5f;     vertices[5].normoal[1] = - 0.5f;   vertices[5].normoal[2] = 0.5f;    
    vertices[5].color[0]= 1.0;vertices[5].color[1]= 0.0;vertices[5].color[2]= 0.0;vertices[5].color[3]= 0.5;
    
    
    //the top face
    //the first triangle
    vertices[6].position[0] = -0.5f;    vertices[6].position[1] =  0.5f;   vertices[6].position[2] = -0.5;
    vertices[6].texture[0]= 0.0;vertices[6].texture[1]= 0.0; 
    vertices[6].normoal[0] = -0.5f;    vertices[6].normoal[1] =  0.5f;   vertices[6].normoal[2] = -0.5;    
    vertices[6].color[0]= 0.0;vertices[6].color[1]= 1.0;vertices[6].color[2]= 0.0;vertices[6].color[3]= 0.5;
    
    vertices[7].position[0] = 0.5f;     vertices[7].position[1] =  0.5f;   vertices[7].position[2] = -0.5f;
    vertices[7].texture[0]= 1.0;vertices[7].texture[1]= 0.0;  
    vertices[7].normoal[0] = 0.5f;     vertices[7].normoal[1] =  0.5f;   vertices[7].normoal[2] = -0.5f;
    vertices[7].color[0]= 0.0;vertices[7].color[1]= 1.0;vertices[7].color[2]= 0.0;vertices[7].color[3]= 0.5;
    
    vertices[8].position[0] = 0.5f;     vertices[8].position[1] =  0.5f;   vertices[8].position[2] = 0.5f;
    vertices[8].texture[0]= 1.0;vertices[8].texture[1]= 1.0;
    vertices[8].normoal[0] = 0.5f;     vertices[8].normoal[1] =  0.5f;   vertices[8].normoal[2] = 0.5f;    
    vertices[8].color[0]= 0.0;vertices[8].color[1]= 1.0;vertices[8].color[2]= 0.0;vertices[8].color[3]= 0.5;
    
    //the second triangle
    vertices[9].position[0] = -0.5f;    vertices[9].position[1] =  0.5f;   vertices[9].position[2] = -0.5;
    vertices[9].texture[0]= 0.0;vertices[9].texture[1]= 0.0;
    vertices[9].normoal[0] = -0.5f;    vertices[9].normoal[1] =  0.5f;   vertices[9].normoal[2] = -0.5;    
    vertices[9].color[0]= 0.0;vertices[9].color[1]= 1.0;vertices[9].color[2]= 0.0;vertices[9].color[3]= 0.5;
    
    vertices[10].position[0] = -0.5f;    vertices[10].position[1] =  0.5f;   vertices[10].position[2] = 0.5f;
    vertices[10].texture[0]= 0.0;vertices[10].texture[1]= 1.0;
    vertices[10].normoal[0] = -0.5f;    vertices[10].normoal[1] =  0.5f;   vertices[10].normoal[2] = 0.5f;
    vertices[10].color[0]= 0.0;vertices[10].color[1]= 1.0;vertices[10].color[2]= 0.0;vertices[10].color[3]= 0.5;
    
    vertices[11].position[0] = 0.5f;     vertices[11].position[1] =  0.5f;   vertices[11].position[2] = 0.5f;
    vertices[11].texture[0]= 1.0;vertices[11].texture[1]= 1.0;
    vertices[11].normoal[0] = 0.5f;     vertices[11].normoal[1] =  0.5f;   vertices[11].normoal[2] = 0.5f;
    vertices[11].color[0]= 0.0;vertices[11].color[1]= 1.0;vertices[11].color[2]= 0.0;vertices[11].color[3]= 0.5;
    
    
    ////the left face
    //the first triangle
    vertices[12].position[0] = -0.5f;     vertices[12].position[1] = - 0.5f;   vertices[12].position[2] = -0.5f;
    vertices[12].texture[0]= 0.0;vertices[12].texture[1]= 0.0;
    vertices[12].normoal[0] = -0.5f;     vertices[12].normoal[1] = - 0.5f;   vertices[12].normoal[2] = -0.5f;    
    vertices[12].color[0]= 0.0;vertices[12].color[1]= 0.0;vertices[12].color[2]= 1.0;vertices[12].color[3]= 0.5;
    
    vertices[13].position[0] = -0.5f;     vertices[13].position[1] =  -0.5f;   vertices[13].position[2] = 0.5f;
    vertices[13].texture[0]= 1.0;vertices[13].texture[1]= 0.0;
    vertices[13].normoal[0] = -0.5f;     vertices[13].normoal[1] =  -0.5f;   vertices[13].normoal[2] = 0.5f;    
    vertices[13].color[0]= 0.0;vertices[13].color[1]= 0.0;vertices[13].color[2]= 1.0;vertices[13].color[3]= 0.5;
    
    vertices[14].position[0] = -0.5f;     vertices[14].position[1] = 0.5f;   vertices[14].position[2] = 0.5f;
    vertices[14].texture[0]= 1.0;vertices[14].texture[1]= 1.0;
    vertices[14].normoal[0] = -0.5f;     vertices[14].normoal[1] = 0.5f;   vertices[14].normoal[2] = 0.5f;    
    vertices[14].color[0]= 0.0;vertices[14].color[1]= 0.0;vertices[14].color[2]= 1.0;vertices[14].color[3]= 0.5;
    
    //the second triangle
    vertices[15].position[0] = -0.5f;     vertices[15].position[1] = - 0.5f;   vertices[15].position[2] = -0.5f;
    vertices[15].texture[0]= 0.0;vertices[15].texture[1]= 0.0;
    vertices[15].normoal[0] = -0.5f;     vertices[15].normoal[1] = - 0.5f;   vertices[15].normoal[2] = -0.5f;    
    vertices[15].color[0]= 0.0;vertices[15].color[1]= 0.0;vertices[15].color[2]= 1.0;vertices[15].color[3]= 0.5;
    
    vertices[16].position[0] = -0.5f;     vertices[16].position[1] =  0.5f;   vertices[16].position[2] = -0.5f;
    vertices[16].texture[0]= 0.0;vertices[16].texture[1]= 1.0;
    vertices[16].normoal[0] = -0.5f;     vertices[16].normoal[1] =  0.5f;   vertices[16].normoal[2] = -0.5f;    
    vertices[16].color[0]= 0.0;vertices[16].color[1]= 0.0;vertices[16].color[2]= 1.0;vertices[16].color[3]= 0.5;
    
    vertices[17].position[0] = -0.5f;     vertices[17].position[1] =  0.5f;   vertices[17].position[2] = 0.5f;
    vertices[17].texture[0]= 1.0;vertices[17].texture[1]= 1.0;
    vertices[17].normoal[0] = -0.5f;     vertices[17].normoal[1] =  0.5f;   vertices[17].normoal[2] = 0.5f;    
    vertices[17].color[0]= 0.0;vertices[17].color[1]= 0.0;vertices[17].color[2]= 1.0;vertices[17].color[3]= 0.5;
    
    //the right face   
    //the first triangle
    vertices[18].position[0] = 0.5f;     vertices[18].position[1] = - 0.5f;   vertices[18].position[2] = -0.5f;
    vertices[18].texture[0]= 0.0;vertices[18].texture[1]= 0.0;
    vertices[18].normoal[0] = 0.5f;     vertices[18].normoal[1] = - 0.5f;   vertices[18].normoal[2] = -0.5f;
    vertices[18].color[0]= 0.0;vertices[18].color[1]= 1.0;vertices[18].color[2]= 1.0;vertices[18].color[3]= 0.5;
    
    vertices[19].position[0] = 0.5f;     vertices[19].position[1] = - 0.5f;   vertices[19].position[2] = 0.5f;
    vertices[19].texture[0]= 1.0;vertices[19].texture[1]= 0.0;
    vertices[19].normoal[0] = 0.5f;     vertices[19].normoal[1] = - 0.5f;   vertices[19].normoal[2] = 0.5f;    
    vertices[19].color[0]= 0.0;vertices[19].color[1]= 1.0;vertices[19].color[2]= 1.0;vertices[19].color[3]= 0.5;
    
    vertices[20].position[0] = 0.5f;     vertices[20].position[1] =  0.5f;   vertices[20].position[2] = 0.5f;
    vertices[20].texture[0]= 1.0;vertices[20].texture[1]= 1.0;
    vertices[20].normoal[0] = 0.5f;     vertices[20].normoal[1] =  0.5f;   vertices[20].normoal[2] = 0.5f;    
    vertices[20].color[0]= 0.0;vertices[20].color[1]= 1.0;vertices[20].color[2]= 1.0;vertices[20].color[3]= 0.5;
    
    //the second triangle
    vertices[21].position[0] = 0.5f;     vertices[21].position[1] = - 0.5f;   vertices[21].position[2] = -0.5f;
    vertices[21].texture[0]= 0.0;vertices[21].texture[1]= 0.0; 
    vertices[21].normoal[0] = 0.5f;     vertices[21].normoal[1] = - 0.5f;   vertices[21].normoal[2] = -0.5f;    
    vertices[21].color[0]= 0.0;vertices[21].color[1]= 1.0;vertices[21].color[2]= 1.0;vertices[21].color[3]= 0.5;
    
    vertices[22].position[0] = 0.5f;     vertices[22].position[1] =  0.5f;   vertices[22].position[2] = -0.5f;
    vertices[22].texture[0]= 0.0;vertices[22].texture[1]= 1.0;
    vertices[22].normoal[0] = 0.5f;     vertices[22].normoal[1] =  0.5f;   vertices[22].normoal[2] = -0.5f;    
    vertices[22].color[0]= 0.0;vertices[22].color[1]= 1.0;vertices[22].color[2]= 1.0;vertices[22].color[3]= 0.5;
    
    vertices[23].position[0] = 0.5f;     vertices[23].position[1] =  0.5f;   vertices[23].position[2] = 0.5f;
    vertices[23].texture[0]= 1.0;vertices[23].texture[1]= 1.0;   
    vertices[23].normoal[0] = 0.5f;     vertices[23].normoal[1] =  0.5f;   vertices[23].normoal[2] = 0.5f;
    vertices[23].color[0]= 0.0;vertices[23].color[1]= 1.0;vertices[23].color[2]= 1.0;vertices[23].color[3]= 0.5;
    
    //the back face
    //the first triangle
    vertices[24].position[0] = -0.5f;    vertices[24].position[1] = 0.5f;   vertices[24].position[2] = -0.5;
    vertices[24].texture[0]= 0.0;vertices[24].texture[1]= 0.0;    
    vertices[24].normoal[0] = -0.5f;    vertices[24].normoal[1] = 0.5f;   vertices[24].normoal[2] = -0.5;    
    vertices[24].color[0]= 1.0;vertices[24].color[1]= 0.0;vertices[24].color[2]= 1.0;vertices[24].color[3]= -0.5;
    
    vertices[25].position[0] = -0.5f;     vertices[25].position[1] = - 0.5f;   vertices[25].position[2] = -0.5f;
    vertices[25].texture[0]= 1.0;vertices[25].texture[1]= 0.0;    
    vertices[25].normoal[0] = -0.5f;     vertices[25].normoal[1] = - 0.5f;   vertices[25].normoal[2] = -0.5f;
    vertices[25].color[0]= 1.0;vertices[25].color[1]= 0.0;vertices[25].color[2]= 1.0;vertices[25].color[3]= -0.5;
    
    vertices[26].position[0] = 0.5f;    vertices[26].position[1] =  -0.5f;   vertices[26].position[2] = -0.5;
    vertices[26].texture[0]= 1.0;vertices[26].texture[1]= 1.0;    
    vertices[26].normoal[0] = 0.5f;    vertices[26].normoal[1] =  -0.5f;   vertices[26].normoal[2] = -0.5;
    vertices[26].color[0]= 1.0;vertices[26].color[1]= 0.0;vertices[26].color[2]= 1.0;vertices[26].color[3]= -0.5;
    
    //the second triangle
    vertices[27].position[0] = -0.5f;    vertices[27].position[1] =  0.5f;   vertices[27].position[2] = -0.5;
    vertices[27].texture[0]= 0.0;vertices[27].texture[1]= 0.0;    
    vertices[27].normoal[0] = -0.5f;    vertices[27].normoal[1] =  0.5f;   vertices[27].normoal[2] = -0.5;
    vertices[27].color[0]= 1.0;vertices[27].color[1]= 0.0;vertices[27].color[2]= 1.0;vertices[27].color[3]= -0.5;
    
    vertices[28].position[0] = 0.5f;     vertices[28].position[1] =  0.5f;   vertices[28].position[2] = -0.5f;
    vertices[28].texture[0]= 0.0;vertices[28].texture[1]= 1.0;    
    vertices[28].normoal[0] = 0.5f;     vertices[28].normoal[1] =  0.5f;   vertices[28].normoal[2] = -0.5f;
    vertices[28].color[0]= 1.0;vertices[28].color[1]= 0.0;vertices[28].color[2]= 1.0;vertices[28].color[3]= -0.5;  
    
    vertices[29].position[0] = 0.5f;     vertices[29].position[1] = - 0.5f;   vertices[29].position[2] = -0.5f;
    vertices[29].texture[0]= 1.0;vertices[29].texture[1]= 1.0;    
    vertices[29].normoal[0] = 0.5f;     vertices[29].normoal[1] = - 0.5f;   vertices[29].normoal[2] = -0.5f;   
    vertices[29].color[0]= 1.0;vertices[29].color[1]= 0.0;vertices[29].color[2]= 1.0;vertices[29].color[3]= -0.5;
    
    //the front face    
    //the first triangle
    vertices[30].position[0] = -0.5f;    vertices[30].position[1] = 0.5f;   vertices[30].position[2] = 0.5;
    vertices[30].texture[0]= 0.0;vertices[30].texture[1]= 0.0;    
    vertices[30].normoal[0] = -0.5f;    vertices[30].normoal[1] = 0.5f;   vertices[30].normoal[2] = 0.5;
    vertices[30].color[0]= 1.0;vertices[30].color[1]= 1.0;vertices[30].color[2]= 0.0;vertices[30].color[3]= 0.5;
    
    vertices[31].position[0] = -0.5f;     vertices[31].position[1] = - 0.5f;   vertices[31].position[2] = 0.5f;
    vertices[31].texture[0]= 1.0;vertices[31].texture[1]= 0.0;    
    vertices[31].normoal[0] = -0.5f;     vertices[31].normoal[1] = - 0.5f;   vertices[31].normoal[2] = 0.5f;    
    vertices[31].color[0]= 1.0;vertices[31].color[1]= 1.0;vertices[31].color[2]= 0.0;vertices[31].color[3]= 0.5;
    
    vertices[32].position[0] = 0.5f;    vertices[32].position[1] =  -0.5f;   vertices[32].position[2] = 0.5;
    vertices[32].texture[0]= 1.0;vertices[32].texture[1]= 1.0;    
    vertices[32].normoal[0] = 0.5f;    vertices[32].normoal[1] =  -0.5f;   vertices[32].normoal[2] = 0.5;
    vertices[32].color[0]= 1.0;vertices[32].color[1]= 1.0;vertices[32].color[2]= 0.0;vertices[32].color[3]= 0.5;
    
    //the second triangle
    vertices[33].position[0] = -0.5f;    vertices[33].position[1] =  0.5f;   vertices[33].position[2] = 0.5;
    vertices[33].texture[0]= 0.0;vertices[33].texture[1]= 0.0;    
    vertices[33].normoal[0] = -0.5f;    vertices[33].normoal[1] =  0.5f;   vertices[33].normoal[2] = 0.5;
    vertices[33].color[0]= 1.0;vertices[33].color[1]= 1.0;vertices[33].color[2]= 0.0;vertices[33].color[3]= 0.5;
    
    vertices[34].position[0] = 0.5f;     vertices[34].position[1] =  0.5f;   vertices[34].position[2] = 0.5f;
    vertices[34].texture[0]= 0.0;vertices[34].texture[1]= 1.0;    
    vertices[34].normoal[0] = 0.5f;     vertices[34].normoal[1] =  0.5f;   vertices[34].normoal[2] = 0.5f;
    vertices[34].color[0]= 1.0;vertices[34].color[1]= 1.0;vertices[34].color[2]= 0.0;vertices[34].color[3]= 0.5;  
    
    vertices[35].position[0] = 0.5f;     vertices[35].position[1] = - 0.5f;   vertices[35].position[2] = 0.5f;
    vertices[35].texture[0]= 1.0;vertices[35].texture[1]= 1.0;    
    vertices[35].normoal[0] = 0.5f;     vertices[35].normoal[1] = - 0.5f;   vertices[35].normoal[2] = 0.5f;
    vertices[35].color[0]= 1.0;vertices[35].color[1]= 1.0;vertices[35].color[2]= 0.0;vertices[35].color[3]= 0.5;
    
    indices[0].v1=0;
    indices[0].v2=1;
    indices[0].v3=2;
    indices[1].v1=3;
    indices[1].v2=4;
    indices[1].v3=5;
    indices[2].v1=6;
    indices[2].v2=7;
    indices[2].v3=8;    
    indices[3].v1=9;
    indices[3].v2=10;
    indices[3].v3=11;
    indices[4].v1=12;
    indices[4].v2=13;
    indices[4].v3=14;
    indices[5].v1=15;
    indices[5].v2=16;
    indices[5].v3=17;
    indices[6].v1=18;    
    indices[6].v2=19;
    indices[6].v3=20;
    indices[7].v1=21;
    indices[7].v2=22;
    indices[7].v3=23;
    indices[8].v1=24;
    indices[8].v2=25;
    indices[8].v3=26;
    indices[9].v1=27;
    indices[9].v2=28;    
    indices[9].v3=29;
    indices[10].v1=30;
    indices[10].v2=31;
    indices[10].v3=32;
    indices[11].v1=33;
    indices[11].v2=34;
    indices[11].v3=35; 
    
    unsigned verticesSize=sizeof(vertices);
    unsigned indicesSize=sizeof(indices);
        
    unsigned sizeOfbinaryArray = sizeof(unsigned)*2 + verticesSize + indicesSize;
    
    Byte * binaryArray = new Byte[sizeOfbinaryArray];        
    
    *((unsigned int*)binaryArray)=verticesSize;
    *((unsigned int*)binaryArray+1)=indicesSize;
    
    memcpy(binaryArray + sizeof(unsigned int)*2, vertices, sizeof(vertices));
    memcpy(binaryArray+sizeof(vertices) + sizeof(unsigned int)*2, indices, sizeof(indices));
    
    NSData *bufferOut = [NSData dataWithBytes: binaryArray length: sizeOfbinaryArray];
    delete[] binaryArray;
    ////////////////////////////////////////////////////
    
    
    ///////////////////////////////////////////////////////////
    //write the binaryArray to the file.
    [outFile truncateFileAtOffset: 0];
    [outFile writeData: bufferOut];
    
    NSData *bufferIn=[inFile availableData];
    //bool s=[bufferIn isEqualToData:bufferOut];
    
    
    
    //unsigned int 
    len=[bufferIn length];
    //Byte *
    bytebinaryArray = new Byte[len];
    memcpy(bytebinaryArray, [bufferIn bytes], len);
    
    
    //////////////////////////////////////////////////////////////
    
    //[bufferOut release];
    //[bufferIn release];
    //[bufferIn release];
    //[bufferIn release];
    
    
    
    //    unsigned verticesSize2=*((unsigned int*)[bufferIn bytes]);
    //    unsigned indicesSize2= *((unsigned int*)[bufferIn bytes]+1);
    //    
    //    vertexStruct vertices2[6]; //= new vertexStruct[verticesSize2/sizeof(vertexStruct)];
    //    GLubyte indices2[6];// = new GLubyte[indicesSize2/sizeof(GLubyte)];
    //    
    //    memcpy(vertices2, (void*)((char*)[bufferIn bytes]+ sizeof(unsigned int)*2), verticesSize2);
    //    memcpy(indices2, (char*)[bufferIn bytes]+sizeof(vertices2) + sizeof(unsigned int)*2, indicesSize2);
    
    //Close the two files
    [inFile closeFile];
    [outFile closeFile];
    
    //ResourceManager::setByteBinaryArrayWithID(len, bytebinaryArray, 0);
    

    
//    NSString * nam=@"myfile.txt";
//    NSArray *pArray = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
//    NSString *docDirectory = [pArray objectAtIndex:0];
//    NSString *filePath2 = [docDirectory stringByAppendingPathComponent:nam];
//    const char* cfilePath = [filePath2 UTF8String];
//
//
//    FILE * pFile;
//    pFile = fopen (cfilePath,"w");
//    if (pFile!=NULL)
//    {
//        fputs ("fopen example",pFile);
//        fclose (pFile);
//    }
//    
//    
//    
//    unsigned bufferLen=8;
//    char * buffer = new char[bufferLen];
//    
//    *((unsigned int*)buffer)=32;
//    *((unsigned int*)(buffer+4))=127;
//
//
//
//    ofstream os;
//    os.open(cfilePath,ios::binary);
//    os.write(buffer, bufferLen);
//    os.close();    

////////////////////////////////
    ///////////////////////    
    //    NSString * nam=@"vvvvv";
    //    NSString* mainBundlePath = [[NSBundle mainBundle] resourcePath];
    //    NSString* filePath2 = [mainBundlePath stringByAppendingPathComponent:nam];
    //    const char* cfilePath = [filePath2 UTF8String];
    //    
    //    ifstream is;
    //    is.open(cfilePath, ios::binary);
    //    is.seekg(0,ios::end);
    //    unsigned bufferLen2=(unsigned)is.tellg();
    //    is.seekg(0,ios::beg);
    //    char * binaryArray2 = new char[bufferLen2];
    //    is.read(binaryArray2,bufferLen2);
    //    is.close();
    //    
    //    unsigned verticesSize2=*((unsigned int*)binaryArray2);
    //    unsigned indicesSize2=*((unsigned int*)(binaryArray2+4));
    //    
    //    vertexStruct * vertices2= new  vertexStruct[verticesSize2/sizeof(vertexStruct)];
    //    Triangle * indices2 = new Triangle[indicesSize2/sizeof(Triangle)];
    //    
    //    memcpy(vertices2, (void*)((char*)binaryArray2+ sizeof(unsigned int)*2), verticesSize);
    //    memcpy(indices2, (char*)binaryArray2 + verticesSize + sizeof(unsigned int)*2, indicesSize);
    
    ///////////////////////   
    
}

+(void)fileloader3
{
    NSFileManager *fm;
    fm = [NSFileManager defaultManager];
    
    //the outFile and inFile are same File but different handle, inFile for Reading outFile for writing
    NSFileHandle *inFile, *outFile; 
    NSArray *pathArray = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [pathArray objectAtIndex:0];
    NSString *outFilePath = [documentsDirectory stringByAppendingPathComponent:@"boy.mo"];
    
    // Create the output file first if necessary 
    [[NSFileManager defaultManager] createFileAtPath: outFilePath contents: nil attributes: nil];
    
    // Open inFile for reading
    inFile = [NSFileHandle fileHandleForReadingAtPath: outFilePath];
    if (inFile == nil) {
        NSLog (@"Open infile for reading failed");
    }
    
    // Open outFile for writing
    outFile = [NSFileHandle fileHandleForWritingAtPath: outFilePath];
    if (outFile == nil) {
        NSLog (@"Open outFile for writing failed");
    }
    
    ////////////////////////////////////////////////
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
    
    
    NSString * nam=@"uuu";
    NSString* mainBundlePath = [[NSBundle mainBundle] resourcePath];
    NSString* filePath2 = [mainBundlePath stringByAppendingPathComponent:nam];
    const char* cfilePath = [filePath2 UTF8String];

    ifstream is;
    is.open(cfilePath, ios::binary);
    is.seekg(0,ios::end);
    unsigned bufferLen2=(unsigned)is.tellg();
    is.seekg(0,ios::beg);
    char * binaryArray2 = new char[bufferLen2];
    is.read(binaryArray2,bufferLen2);
    is.close();
        
    unsigned verticesSize2=*((unsigned int*)binaryArray2);
    unsigned indicesSize2=*((unsigned int*)(binaryArray2+4));

    Vertex * vertices2= new  Vertex[verticesSize2/sizeof(Vertex)];
    Triangle * indices2 = new Triangle[indicesSize2/sizeof(Triangle)];

    memcpy(vertices2, (void*)((char*)binaryArray2+ sizeof(unsigned int)*2), verticesSize2);
    memcpy(indices2, (char*)binaryArray2 + verticesSize2 + sizeof(unsigned int)*2, indicesSize2);
    
    
    
    
    unsigned sizeOfbinaryArray = sizeof(unsigned)*2 + verticesSize2 + indicesSize2;
    
    Byte * binaryArray = new Byte[sizeOfbinaryArray];        
    
    *((unsigned int*)binaryArray)=verticesSize2;
    *((unsigned int*)binaryArray+1)=indicesSize2;
    
    memcpy(binaryArray + sizeof(unsigned int)*2, vertices2, verticesSize2);
    memcpy(binaryArray+ verticesSize2+ sizeof(unsigned int)*2, indices2, indicesSize2);
    
    NSData *bufferOut = [NSData dataWithBytes: binaryArray length: sizeOfbinaryArray];
    delete[] binaryArray;
    
    //write the binaryArray to the file.
    [outFile truncateFileAtOffset: 0];
    [outFile writeData: bufferOut];
    
    //NSData *bufferIn=[inFile availableData];
    //bool s=[bufferIn isEqualToData:bufferOut];
    
    //Close the two files
    [inFile closeFile];
    [outFile closeFile];
}

@end







