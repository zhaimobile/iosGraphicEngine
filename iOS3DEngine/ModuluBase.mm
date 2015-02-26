//
//  ModuluBase.cpp
//  MoEngine
//
//  Created by Mo on 10/11/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#include "ModuluBase.hpp"
#include "TxLoader.h"

#include <iostream>
#include <assert.h>

ModuluBase::ModuluBase(unsigned ID, char *fileName)
{
    this->ID=ID;
    this->szFileName=fileName;
    
    this->vao1=0;
    this->indicesNum=0;
    this->textureID=0;
}

//void ModuluBase::loadDataHard()
//{
//    vertexStruct vertices[36];
//    GLubyte indices[36];
//
//    indicesNum=sizeof(indices)/sizeof(GLubyte);
//    
//    //data
//    vertices[0].position[0] = -0.5f;    vertices[0].position[1] = - 0.5f;   vertices[0].position[2] = -0.5;
//    vertices[0].texture[0]= 0.0;vertices[0].texture[1]= 0.0;
//    vertices[0].normoal[0] = -0.5f;    vertices[0].normoal[1] = - 0.5f;   vertices[0].normoal[2] = -0.5;
//    vertices[0].color[0]= 1.0;vertices[0].color[1]= 0.0;vertices[0].color[2]= 0.0;vertices[0].color[3]= 0.5;
//    
//    vertices[1].position[0] = 0.5f;     vertices[1].position[1] = - 0.5f;   vertices[1].position[2] = -0.5f;
//    vertices[1].texture[0]= 1.0;vertices[1].texture[1]= 0.0;
//    vertices[1].normoal[0] = 0.5f;     vertices[1].normoal[1] = - 0.5f;   vertices[1].normoal[2] = -0.5f;    
//    vertices[1].color[0]= 1.0;vertices[1].color[1]= 0.0;vertices[1].color[2]= 0.0;vertices[1].color[3]= 0.5;
//    
//    vertices[2].position[0] = 0.5f;     vertices[2].position[1] = - 0.5f;   vertices[2].position[2] = 0.5f;
//    vertices[2].texture[0]= 1.0;vertices[2].texture[1]= 1.0;
//    vertices[2].normoal[0] = 0.5f;     vertices[2].normoal[1] = - 0.5f;   vertices[2].normoal[2] = 0.5f;    
//    vertices[2].color[0]= 1.0;vertices[2].color[1]= 0.0;vertices[2].color[2]= 0.0;vertices[2].color[3]= 0.5;
//    
//    
//    //the second triangle
//    vertices[3].position[0] = -0.5f;    vertices[3].position[1] = - 0.5f;   vertices[3].position[2] = -0.5;
//    vertices[3].texture[0]= 0.0;vertices[3].texture[1]= 0.0;
//    vertices[3].normoal[0] = -0.5f;    vertices[3].normoal[1] = - 0.5f;   vertices[3].normoal[2] = -0.5;    
//    vertices[3].color[0]= 1.0;vertices[3].color[1]= 0.0;vertices[3].color[2]= 0.0;vertices[3].color[3]= 0.5;
//    
//    vertices[4].position[0] = -0.5f;    vertices[4].position[1] = - 0.5f;   vertices[4].position[2] = 0.5f;
//    vertices[4].texture[0]= 0.0;vertices[4].texture[1]= 1.0;
//    vertices[4].normoal[0] = -0.5f;    vertices[4].normoal[1] = - 0.5f;   vertices[4].normoal[2] = 0.5f;    
//    vertices[4].color[0]= 1.0;vertices[4].color[1]= 0.0;vertices[4].color[2]= 0.0;vertices[4].color[03]= 0.5;
//
//    vertices[5].position[0] = 0.5f;     vertices[5].position[1] = - 0.5f;   vertices[5].position[2] = 0.5f;
//    vertices[5].texture[0]= 1.0;vertices[5].texture[1]= 1.0;
//    vertices[5].normoal[0] = 0.5f;     vertices[5].normoal[1] = - 0.5f;   vertices[5].normoal[2] = 0.5f;    
//    vertices[5].color[0]= 1.0;vertices[5].color[1]= 0.0;vertices[5].color[2]= 0.0;vertices[5].color[3]= 0.5;
//    
//    
//    //the top face
//    //the first triangle
//    vertices[6].position[0] = -0.5f;    vertices[6].position[1] =  0.5f;   vertices[6].position[2] = -0.5;
//    vertices[6].texture[0]= 0.0;vertices[6].texture[1]= 0.0; 
//    vertices[6].normoal[0] = -0.5f;    vertices[6].normoal[1] =  0.5f;   vertices[6].normoal[2] = -0.5;    
//    vertices[6].color[0]= 0.0;vertices[6].color[1]= 1.0;vertices[6].color[2]= 0.0;vertices[6].color[3]= 0.5;
//    
//    vertices[7].position[0] = 0.5f;     vertices[7].position[1] =  0.5f;   vertices[7].position[2] = -0.5f;
//    vertices[7].texture[0]= 1.0;vertices[7].texture[1]= 0.0;  
//    vertices[7].normoal[0] = 0.5f;     vertices[7].normoal[1] =  0.5f;   vertices[7].normoal[2] = -0.5f;
//    vertices[7].color[0]= 0.0;vertices[7].color[1]= 1.0;vertices[7].color[2]= 0.0;vertices[7].color[3]= 0.5;
//    
//    vertices[8].position[0] = 0.5f;     vertices[8].position[1] =  0.5f;   vertices[8].position[2] = 0.5f;
//    vertices[8].texture[0]= 1.0;vertices[8].texture[1]= 1.0;
//    vertices[8].normoal[0] = 0.5f;     vertices[8].normoal[1] =  0.5f;   vertices[8].normoal[2] = 0.5f;    
//    vertices[8].color[0]= 0.0;vertices[8].color[1]= 1.0;vertices[8].color[2]= 0.0;vertices[8].color[3]= 0.5;
//    
//    //the second triangle
//    vertices[9].position[0] = -0.5f;    vertices[9].position[1] =  0.5f;   vertices[9].position[2] = -0.5;
//    vertices[9].texture[0]= 0.0;vertices[9].texture[1]= 0.0;
//    vertices[9].normoal[0] = -0.5f;    vertices[9].normoal[1] =  0.5f;   vertices[9].normoal[2] = -0.5;    
//    vertices[9].color[0]= 0.0;vertices[9].color[1]= 1.0;vertices[9].color[2]= 0.0;vertices[9].color[3]= 0.5;
//
//    vertices[10].position[0] = -0.5f;    vertices[10].position[1] =  0.5f;   vertices[10].position[2] = 0.5f;
//    vertices[10].texture[0]= 0.0;vertices[10].texture[1]= 1.0;
//    vertices[10].normoal[0] = -0.5f;    vertices[10].normoal[1] =  0.5f;   vertices[10].normoal[2] = 0.5f;
//    vertices[10].color[0]= 0.0;vertices[10].color[1]= 1.0;vertices[10].color[2]= 0.0;vertices[10].color[3]= 0.5;
//    
//    vertices[11].position[0] = 0.5f;     vertices[11].position[1] =  0.5f;   vertices[11].position[2] = 0.5f;
//    vertices[11].texture[0]= 1.0;vertices[11].texture[1]= 1.0;
//    vertices[11].normoal[0] = 0.5f;     vertices[11].normoal[1] =  0.5f;   vertices[11].normoal[2] = 0.5f;
//    vertices[11].color[0]= 0.0;vertices[11].color[1]= 1.0;vertices[11].color[2]= 0.0;vertices[11].color[3]= 0.5;
//    
//    
//    ////the left face
//    //the first triangle
//    vertices[12].position[0] = -0.5f;     vertices[12].position[1] = - 0.5f;   vertices[12].position[2] = -0.5f;
//    vertices[12].texture[0]= 0.0;vertices[12].texture[1]= 0.0;
//    vertices[12].normoal[0] = -0.5f;     vertices[12].normoal[1] = - 0.5f;   vertices[12].normoal[2] = -0.5f;    
//    vertices[12].color[0]= 0.0;vertices[12].color[1]= 0.0;vertices[12].color[2]= 1.0;vertices[12].color[3]= 0.5;
//    
//    vertices[13].position[0] = -0.5f;     vertices[13].position[1] =  -0.5f;   vertices[13].position[2] = 0.5f;
//    vertices[13].texture[0]= 1.0;vertices[13].texture[1]= 0.0;
//    vertices[13].normoal[0] = -0.5f;     vertices[13].normoal[1] =  -0.5f;   vertices[13].normoal[2] = 0.5f;    
//    vertices[13].color[0]= 0.0;vertices[13].color[1]= 0.0;vertices[13].color[2]= 1.0;vertices[13].color[3]= 0.5;
//
//    vertices[14].position[0] = -0.5f;     vertices[14].position[1] = 0.5f;   vertices[14].position[2] = 0.5f;
//    vertices[14].texture[0]= 1.0;vertices[14].texture[1]= 1.0;
//    vertices[14].normoal[0] = -0.5f;     vertices[14].normoal[1] = 0.5f;   vertices[14].normoal[2] = 0.5f;    
//    vertices[14].color[0]= 0.0;vertices[14].color[1]= 0.0;vertices[14].color[2]= 1.0;vertices[14].color[3]= 0.5;
//    
//    //the second triangle
//    vertices[15].position[0] = -0.5f;     vertices[15].position[1] = - 0.5f;   vertices[15].position[2] = -0.5f;
//    vertices[15].texture[0]= 0.0;vertices[15].texture[1]= 0.0;
//    vertices[15].normoal[0] = -0.5f;     vertices[15].normoal[1] = - 0.5f;   vertices[15].normoal[2] = -0.5f;    
//    vertices[15].color[0]= 0.0;vertices[15].color[1]= 0.0;vertices[15].color[2]= 1.0;vertices[15].color[3]= 0.5;
//    
//    vertices[16].position[0] = -0.5f;     vertices[16].position[1] =  0.5f;   vertices[16].position[2] = -0.5f;
//    vertices[16].texture[0]= 0.0;vertices[16].texture[1]= 1.0;
//    vertices[16].normoal[0] = -0.5f;     vertices[16].normoal[1] =  0.5f;   vertices[16].normoal[2] = -0.5f;    
//    vertices[16].color[0]= 0.0;vertices[16].color[1]= 0.0;vertices[16].color[2]= 1.0;vertices[16].color[3]= 0.5;
//    
//    vertices[17].position[0] = -0.5f;     vertices[17].position[1] =  0.5f;   vertices[17].position[2] = 0.5f;
//    vertices[17].texture[0]= 1.0;vertices[17].texture[1]= 1.0;
//    vertices[17].normoal[0] = -0.5f;     vertices[17].normoal[1] =  0.5f;   vertices[17].normoal[2] = 0.5f;    
//    vertices[17].color[0]= 0.0;vertices[17].color[1]= 0.0;vertices[17].color[2]= 1.0;vertices[17].color[3]= 0.5;
//    
//    
//    //the right face   
//    //the first triangle
//    vertices[18].position[0] = 0.5f;     vertices[18].position[1] = - 0.5f;   vertices[18].position[2] = -0.5f;
//    vertices[18].texture[0]= 0.0;vertices[18].texture[1]= 0.0;
//    vertices[18].normoal[0] = 0.5f;     vertices[18].normoal[1] = - 0.5f;   vertices[18].normoal[2] = -0.5f;
//    vertices[18].color[0]= 0.0;vertices[18].color[1]= 1.0;vertices[18].color[2]= 1.0;vertices[18].color[3]= 0.5;
//    
//    vertices[19].position[0] = 0.5f;     vertices[19].position[1] = - 0.5f;   vertices[19].position[2] = 0.5f;
//    vertices[19].texture[0]= 1.0;vertices[19].texture[1]= 0.0;
//    vertices[19].normoal[0] = 0.5f;     vertices[19].normoal[1] = - 0.5f;   vertices[19].normoal[2] = 0.5f;    
//    vertices[19].color[0]= 0.0;vertices[19].color[1]= 1.0;vertices[19].color[2]= 1.0;vertices[19].color[3]= 0.5;
//    
//    vertices[20].position[0] = 0.5f;     vertices[20].position[1] =  0.5f;   vertices[20].position[2] = 0.5f;
//    vertices[20].texture[0]= 1.0;vertices[20].texture[1]= 1.0;
//    vertices[20].normoal[0] = 0.5f;     vertices[20].normoal[1] =  0.5f;   vertices[20].normoal[2] = 0.5f;    
//    vertices[20].color[0]= 0.0;vertices[20].color[1]= 1.0;vertices[20].color[2]= 1.0;vertices[20].color[3]= 0.5;
//    
//    //the second triangle
//    vertices[21].position[0] = 0.5f;     vertices[21].position[1] = - 0.5f;   vertices[21].position[2] = -0.5f;
//    vertices[21].texture[0]= 0.0;vertices[21].texture[1]= 0.0; 
//    vertices[21].normoal[0] = 0.5f;     vertices[21].normoal[1] = - 0.5f;   vertices[21].normoal[2] = -0.5f;    
//    vertices[21].color[0]= 0.0;vertices[21].color[1]= 1.0;vertices[21].color[2]= 1.0;vertices[21].color[3]= 0.5;
//    
//    vertices[22].position[0] = 0.5f;     vertices[22].position[1] =  0.5f;   vertices[22].position[2] = -0.5f;
//    vertices[22].texture[0]= 0.0;vertices[22].texture[1]= 1.0;
//    vertices[22].normoal[0] = 0.5f;     vertices[22].normoal[1] =  0.5f;   vertices[22].normoal[2] = -0.5f;    
//    vertices[22].color[0]= 0.0;vertices[22].color[1]= 1.0;vertices[22].color[2]= 1.0;vertices[22].color[3]= 0.5;
//    
//    vertices[23].position[0] = 0.5f;     vertices[23].position[1] =  0.5f;   vertices[23].position[2] = 0.5f;
//    vertices[23].texture[0]= 1.0;vertices[23].texture[1]= 1.0;   
//    vertices[23].normoal[0] = 0.5f;     vertices[23].normoal[1] =  0.5f;   vertices[23].normoal[2] = 0.5f;
//    vertices[23].color[0]= 0.0;vertices[23].color[1]= 1.0;vertices[23].color[2]= 1.0;vertices[23].color[3]= 0.5;
//    
//    
//    //the back face
//    //the first triangle
//    vertices[24].position[0] = -0.5f;    vertices[24].position[1] = 0.5f;   vertices[24].position[2] = -0.5;
//    vertices[24].texture[0]= 0.0;vertices[24].texture[1]= 0.0;    
//    vertices[24].normoal[0] = -0.5f;    vertices[24].normoal[1] = 0.5f;   vertices[24].normoal[2] = -0.5;    
//    vertices[24].color[0]= 1.0;vertices[24].color[1]= 0.0;vertices[24].color[2]= 1.0;vertices[24].color[3]= -0.5;
//    
//    vertices[25].position[0] = -0.5f;     vertices[25].position[1] = - 0.5f;   vertices[25].position[2] = -0.5f;
//    vertices[25].texture[0]= 1.0;vertices[25].texture[1]= 0.0;    
//    vertices[25].normoal[0] = -0.5f;     vertices[25].normoal[1] = - 0.5f;   vertices[25].normoal[2] = -0.5f;
//    vertices[25].color[0]= 1.0;vertices[25].color[1]= 0.0;vertices[25].color[2]= 1.0;vertices[25].color[3]= -0.5;
//    
//    vertices[26].position[0] = 0.5f;    vertices[26].position[1] =  -0.5f;   vertices[26].position[2] = -0.5;
//    vertices[26].texture[0]= 1.0;vertices[26].texture[1]= 1.0;    
//    vertices[26].normoal[0] = 0.5f;    vertices[26].normoal[1] =  -0.5f;   vertices[26].normoal[2] = -0.5;
//    vertices[26].color[0]= 1.0;vertices[26].color[1]= 0.0;vertices[26].color[2]= 1.0;vertices[26].color[3]= -0.5;
//    
//    //the second triangle
//    vertices[27].position[0] = -0.5f;    vertices[27].position[1] =  0.5f;   vertices[27].position[2] = -0.5;
//    vertices[27].texture[0]= 0.0;vertices[27].texture[1]= 0.0;    
//    vertices[27].normoal[0] = -0.5f;    vertices[27].normoal[1] =  0.5f;   vertices[27].normoal[2] = -0.5;
//    vertices[27].color[0]= 1.0;vertices[27].color[1]= 0.0;vertices[27].color[2]= 1.0;vertices[27].color[3]= -0.5;
//    
//    vertices[28].position[0] = 0.5f;     vertices[28].position[1] =  0.5f;   vertices[28].position[2] = -0.5f;
//    vertices[28].texture[0]= 0.0;vertices[28].texture[1]= 1.0;    
//    vertices[28].normoal[0] = 0.5f;     vertices[28].normoal[1] =  0.5f;   vertices[28].normoal[2] = -0.5f;
//    vertices[28].color[0]= 1.0;vertices[28].color[1]= 0.0;vertices[28].color[2]= 1.0;vertices[28].color[3]= -0.5;  
//    
//    vertices[29].position[0] = 0.5f;     vertices[29].position[1] = - 0.5f;   vertices[29].position[2] = -0.5f;
//    vertices[29].texture[0]= 1.0;vertices[29].texture[1]= 1.0;    
//    vertices[29].normoal[0] = 0.5f;     vertices[29].normoal[1] = - 0.5f;   vertices[29].normoal[2] = -0.5f;   
//    vertices[29].color[0]= 1.0;vertices[29].color[1]= 0.0;vertices[29].color[2]= 1.0;vertices[29].color[3]= -0.5;
//    
//    
//    //the front face    
//    //the first triangle
//    vertices[30].position[0] = -0.5f;    vertices[30].position[1] = 0.5f;   vertices[30].position[2] = 0.5;
//    vertices[30].texture[0]= 0.0;vertices[30].texture[1]= 0.0;    
//    vertices[30].normoal[0] = -0.5f;    vertices[30].normoal[1] = 0.5f;   vertices[30].normoal[2] = 0.5;
//    vertices[30].color[0]= 1.0;vertices[30].color[1]= 1.0;vertices[30].color[2]= 0.0;vertices[30].color[3]= 0.5;
//    
//    vertices[31].position[0] = -0.5f;     vertices[31].position[1] = - 0.5f;   vertices[31].position[2] = 0.5f;
//    vertices[31].texture[0]= 1.0;vertices[31].texture[1]= 0.0;    
//    vertices[31].normoal[0] = -0.5f;     vertices[31].normoal[1] = - 0.5f;   vertices[31].normoal[2] = 0.5f;    
//    vertices[31].color[0]= 1.0;vertices[31].color[1]= 1.0;vertices[31].color[2]= 0.0;vertices[31].color[3]= 0.5;
//    
//    vertices[32].position[0] = 0.5f;    vertices[32].position[1] =  -0.5f;   vertices[32].position[2] = 0.5;
//    vertices[32].texture[0]= 1.0;vertices[32].texture[1]= 1.0;    
//    vertices[32].normoal[0] = 0.5f;    vertices[32].normoal[1] =  -0.5f;   vertices[32].normoal[2] = 0.5;
//    vertices[32].color[0]= 1.0;vertices[32].color[1]= 1.0;vertices[32].color[2]= 0.0;vertices[32].color[3]= 0.5;
//    
//    //the second triangle
//    vertices[33].position[0] = -0.5f;    vertices[33].position[1] =  0.5f;   vertices[33].position[2] = 0.5;
//    vertices[33].texture[0]= 0.0;vertices[33].texture[1]= 0.0;    
//    vertices[33].normoal[0] = -0.5f;    vertices[33].normoal[1] =  0.5f;   vertices[33].normoal[2] = 0.5;
//    vertices[33].color[0]= 1.0;vertices[33].color[1]= 1.0;vertices[33].color[2]= 0.0;vertices[33].color[3]= 0.5;
//    
//    vertices[34].position[0] = 0.5f;     vertices[34].position[1] =  0.5f;   vertices[34].position[2] = 0.5f;
//    vertices[34].texture[0]= 0.0;vertices[34].texture[1]= 1.0;    
//    vertices[34].normoal[0] = 0.5f;     vertices[34].normoal[1] =  0.5f;   vertices[34].normoal[2] = 0.5f;
//    vertices[34].color[0]= 1.0;vertices[34].color[1]= 1.0;vertices[34].color[2]= 0.0;vertices[34].color[3]= 0.5;  
//
//    vertices[35].position[0] = 0.5f;     vertices[35].position[1] = - 0.5f;   vertices[35].position[2] = 0.5f;
//    vertices[35].texture[0]= 1.0;vertices[35].texture[1]= 1.0;    
//    vertices[35].normoal[0] = 0.5f;     vertices[35].normoal[1] = - 0.5f;   vertices[35].normoal[2] = 0.5f;
//    vertices[35].color[0]= 1.0;vertices[35].color[1]= 1.0;vertices[35].color[2]= 0.0;vertices[35].color[3]= 0.5;
//    
//    indices[0]=0;
//    indices[1]=1;
//    indices[2]=2;
//    indices[3]=3;
//    indices[4]=4;
//    indices[5]=5;
//    indices[6]=6;
//    indices[7]=7;
//    indices[8]=8; 
//    indices[9]=9;
//    indices[10]=10;
//    indices[11]=11;
//    indices[12]=12;
//    indices[13]=13;
//    indices[14]=14;
//    indices[15]=15;
//    indices[16]=16;
//    indices[17]=17;
//    indices[18]=18;    
//    indices[19]=19;
//    indices[20]=20;
//    indices[21]=21;
//    indices[22]=22;
//    indices[23]=23;
//    indices[24]=24;
//    indices[25]=25;
//    indices[26]=26;
//    indices[27]=27;
//    indices[28]=28;    
//    indices[29]=29;
//    indices[30]=30;
//    indices[31]=31;
//    indices[32]=32;
//    indices[33]=33;
//    indices[34]=34;
//    indices[35]=35;    
//    
//    
//    //calculate value and pointers
//    GLuint positionSlot = glGetAttribLocation(ShadersManager::getShaders(), "Position");
//    GLuint textureSlot = glGetAttribLocation(ShadersManager::getShaders(), "TextureCoord");
//    GLuint colorSlot = glGetAttribLocation(ShadersManager::getShaders(), "Color");       
//       
//    // Create and bind the vertex array object.
//    glGenVertexArraysOES(1,&vao1);
//    glBindVertexArrayOES(vao1);
//    
//    GLuint vertexBuffer,indexBuffer;
//    
//    glGenBuffers(1, &vertexBuffer);
//    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    
//    glVertexAttribPointer(positionSlot, 3, GL_FLOAT, GL_FALSE, sizeof(vertexStruct), (void*)offsetof(vertexStruct,position));
//    glEnableVertexAttribArray(positionSlot);
//    
//    glVertexAttribPointer(textureSlot, 2, GL_FLOAT, GL_FALSE, sizeof(vertexStruct), (void*)offsetof(vertexStruct,texture));
//    glEnableVertexAttribArray(textureSlot);
//    
//    glVertexAttribPointer(colorSlot, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(vertexStruct), (void*)offsetof(vertexStruct,color));
//    glEnableVertexAttribArray(colorSlot);
//    
//    glGenBuffers(1, &indexBuffer);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    
//    // Bind back to the default state.
//    glBindBuffer(GL_ARRAY_BUFFER,0);
//    glBindVertexArrayOES(0); 
//    
//    //loadTexture();
//
//}

void ModuluBase::loadData()
{    
    //get the bytebinaryArray and bytebinaryArrayLen from the ResourceManager
    //the ResourceManager is a singleton which will called by both OS sider and the Engine side
    
    unsigned char* bytebinaryArray=ResourceManager::getbinaryArray(ID).bytebinaryArray;
    unsigned bytebinaryArrayLen=ResourceManager::getbinaryArray(ID).bytebinaryArrayLen;
    
    //copy what we need for the VBO, here are some code redundancy for robustness
    unsigned verticesSize=*((unsigned *)bytebinaryArray);
    unsigned indicesSize= *((unsigned *)bytebinaryArray+1);
    
    if(bytebinaryArrayLen<verticesSize+indicesSize)
        assert(0);
        
    Vertex * vertices2= new  Vertex[verticesSize/sizeof(Vertex)];
    Triangle * indices2 = new Triangle[indicesSize/sizeof(Triangle)];
    //GLubyte * indices2 = new GLubyte[indicesSize/sizeof(GLubyte)];
        
    memcpy(vertices2, (void*)((char*)bytebinaryArray+ sizeof(unsigned int)*2), verticesSize);
    memcpy(indices2, (char*)bytebinaryArray + verticesSize + sizeof(unsigned int)*2, indicesSize);
    
    
    indicesNum= indicesSize/sizeof(unsigned short);

    
    //calculate value and pointers
    //need to hard coding later for speedind
    GLuint positionSlot = glGetAttribLocation(ShadersManager::getShaders(), "Position");
    GLuint colorSlot = glGetAttribLocation(ShadersManager::getShaders(), "Color");        
    GLuint textureSlot = glGetAttribLocation(ShadersManager::getShaders(), "TextureCoord");
    GLuint normalSlot = glGetAttribLocation(ShadersManager::getShaders(), "NormalCoord");
    
    //from here to the end of this method is building the VBO and saving the VAO index
    // Create and bind the vertex array object.
    glGenVertexArraysOES(1,&vao1);
    glBindVertexArrayOES(vao1);
    
    GLuint vertexBuffer,indexBuffer;
    
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices2, GL_STATIC_DRAW);
    
    glVertexAttribPointer(positionSlot, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex), (char*)0);
    glVertexAttribPointer(colorSlot, 4, GL_FLOAT, GL_FALSE, sizeof( Vertex), (char*)12);
    glVertexAttribPointer(textureSlot, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex), (char*)28);
    glVertexAttribPointer(normalSlot, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex), (char*)36);

    glEnableVertexAttribArray(positionSlot);
    glEnableVertexAttribArray(colorSlot);
    glEnableVertexAttribArray(textureSlot);
    glEnable(GL_DEPTH_TEST);

    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices2, GL_STATIC_DRAW);
    
    // Bind back to the default state.
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArrayOES(0);  
    
    loadTexture();
}

// Load the texture
bool ModuluBase::loadTexture()
{
    if(!szFileName) return false;
    NSString* nsfilename = [NSString stringWithUTF8String: szFileName];
    
    GLuint Texture  = glGetUniformLocation(ShadersManager::getShaders(), "Texture");
    
	// Set the active sampler to stage 0.  The uniform defaults to zero anyway.
	glActiveTexture(GL_TEXTURE0);
    glUniform1i(Texture, 0);
	
    // Load the texture.
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    
    TxLoader* tx =[[TxLoader alloc] init];
    [tx LoadPngImage:nsfilename];    
    int w=[tx txWidth];
    int h=[tx txHeight];
    void* pixels = [tx GetImageData];
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    //printf("\n%p:>(%d,%d)\n",pixels,w,h);//just for debug
    [tx UnloadImage];
    glGenerateMipmap(GL_TEXTURE_2D);

	return true;
}

void ModuluBase::updateAndDraw(Matrix inModelviewMatrix)
{
    
    // Set the model-view matrix.
    GLint modelviewUniform = glGetUniformLocation(ShadersManager::getShaders(), "Modelview");
    glUniformMatrix4fv(modelviewUniform, 1, 0, inModelviewMatrix.Pointer());

    //GLuint texture = glGetUniformLocation(ShadersManager::getShaders(), "Texture");
    //glUniform1i(texture, 0);
    
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glBindVertexArrayOES(vao1);
    
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    
    //draw
    glDrawElements(GL_TRIANGLES, indicesNum, GL_UNSIGNED_SHORT, (void*)0);
    //glDrawElements(GL_TRIANGLES, indicesNum, GL_UNSIGNED_BYTE, (void*)0);

}