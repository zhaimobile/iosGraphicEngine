const char* SimpleFragmentShaderVBO = STRINGIFY(

varying lowp vec4 DestinationColor;
varying mediump vec2 TextureCoordOut;                                             
                                                
uniform sampler2D Texture;
                                                
void main(void)
{
    gl_FragColor =texture2D(Texture, TextureCoordOut);//*DestinationColor*0.5+ DestinationColor*0.5;
    //gl_FragColor =vec4(1,1,0,0);
}
);