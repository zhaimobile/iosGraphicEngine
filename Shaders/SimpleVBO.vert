const char* SimpleVertexShaderVBO = STRINGIFY(

attribute vec4 Position;
                                              
attribute vec4 Color;
varying vec4 DestinationColor;

attribute vec2 TextureCoord;
varying vec2 TextureCoordOut;
                                              
attribute vec4 NormalCoord;                                                                                                 
                                              
uniform mat4 Projection;
uniform mat4 Modelview;

void main(void)
{
    gl_Position = Projection * Modelview * Position;
    DestinationColor = Color;
    TextureCoordOut = TextureCoord;
    NormalCoord;
}
);