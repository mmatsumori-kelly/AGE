//
//  HeightmapNode.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/6/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__HeightmapNode__
#define __AGE__HeightmapNode__

#include "../Video/IModel.h"
#include <vector>

namespace age {
	namespace scene {
		
		
		
		
		class HeightmapNode {
			
			
		public:
			
			HeightmapNode(const std::vector<FVec3> &heightmap);
			
		};
		
		
		
	}
}

#endif /* defined(__AGE__HeightmapNode__) */
