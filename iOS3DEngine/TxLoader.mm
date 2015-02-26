#import "TxLoader.h"

@implementation TxLoader

- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

-(unsigned) txWidth
{
    return txWidth;
}

-(unsigned)txHeight
{
    return txHeight;
}

-(string) GetResourcePath
{
    NSString* bundlePath =[[NSBundle mainBundle] resourcePath];
    return [bundlePath UTF8String];
}

-(void*) GetImageData
{
    return (void*) CFDataGetBytePtr(imageData);
}

-(void) LoadPngImage:(NSString *)name
{
    NSBundle* mainBundle = [NSBundle mainBundle];
    NSString* fullPath = [mainBundle pathForResource:name ofType:@"png"];
        
    UIImage* uiImage = [[UIImage alloc] initWithContentsOfFile:fullPath];
    CGImageRef cgImage = uiImage.CGImage;
    txWidth = CGImageGetWidth(cgImage);
    txHeight = CGImageGetHeight(cgImage);
    imageData = CGDataProviderCopyData(CGImageGetDataProvider(cgImage));
        
    [uiImage release];
}

-(void)UnloadImage
{
    CFRelease(imageData);
}

@end
