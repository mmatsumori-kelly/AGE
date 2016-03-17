//
//  SceneCamera.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__SceneCamera__
#define __AGE__SceneCamera__


#include "../Matrix.h"
#include "../Handle.h"
#include "../Video/Shader.h"

namespace age {
	namespace scene {
		
		
		
		class ICamera : public IRefCounted {
		public:
			virtual ~ICamera() { }
			
			virtual void Update() = 0;
			virtual void UpdateProgram(video::ShaderProgram *program, const FMat4 &model_matrix) = 0;
		};
	}
}


#endif /* defined(__AGE__SceneCamera__) */
