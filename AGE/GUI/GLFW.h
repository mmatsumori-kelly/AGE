//
//  GLFW.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/25/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__GLFW__
#define __AGE__GLFW__

#include <GLFW/glfw3.h>

namespace age {
	namespace gui {
		
		
		
		
		
		
		/** GLFW access */
		class GLFW {
			static GLFW instance;
			bool init;
			
			GLFW();
			~GLFW();
			
		public:
			
			
			static void Init();
			static inline bool IsInit() {
				return instance.init;
			}
			
		};
		
	}
}

#endif /* defined(__AGE__GLFW__) */
