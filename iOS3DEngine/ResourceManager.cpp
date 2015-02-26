//
//  ResourceManager.cpp
//  MoEngine
//
//  Created by Mo on 10/11/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ResourceManager.hpp"

ResourceManager::ResourceManager()
{
}

void ResourceManager::setByteBinaryArrayWithID(unsigned int l, unsigned char * bba, unsigned inID)
{
    binaryArray newbinaryArray;
    newbinaryArray.bytebinaryArrayLen=l;
    newbinaryArray.bytebinaryArray=bba;
    newbinaryArray.ID=inID;
    
    instance()->biaList.push_back(newbinaryArray);
}

binaryArray ResourceManager:: getbinaryArray(unsigned ID)
{
    return instance()->biaList[ID];
}


