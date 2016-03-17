//
//  Size.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/25/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Size__
#define __AGE__Size__

#include <cmath>
#include <glm/glm.hpp>

namespace age {
	
	
	typedef glm::ivec2 IVec2;
	typedef glm::fvec2 FVec2;
	typedef glm::dvec2 DVec2;
	typedef glm::ivec3 IVec3;
	typedef glm::fvec3 FVec3;
	typedef glm::dvec3 DVec3;
	typedef glm::ivec4 IVec4;
	typedef glm::fvec4 FVec4;
	typedef glm::dvec4 DVec4;
	
	
	inline float ToRadians(float degrees) {
		return glm::radians(degrees);
	}
	inline float ToDegrees(float radians) {
		return glm::degrees(radians);
	}
	
	
	template <typename Vec>
	inline Vec VectorNormalize(const Vec &vec) {
		return glm::normalize(vec);
	}
	
}

#endif /* defined(__AGE__Size__) */
