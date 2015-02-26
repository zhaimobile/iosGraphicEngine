//
//  ResourceManager.hpp
//  MoEngine
//
//  Created by Mo on 10/11/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef MoEngine_ResourceManager_hpp
#define MoEngine_ResourceManager_hpp

#include <vector>
using std::vector;

struct binaryArray{
    unsigned int bytebinaryArrayLen; 
    unsigned char * bytebinaryArray;
    unsigned ID;
};

class ResourceManager
{
private:
    ResourceManager();

    //sigleton-inline
	static ResourceManager* instance()
	{
		static ResourceManager instance;
		return &instance;
	}
    
    vector<binaryArray> biaList;
    
public:        
    static void setByteBinaryArrayWithID(unsigned int, unsigned char *, unsigned ID);
    static binaryArray getbinaryArray(unsigned ID);
};

#endif