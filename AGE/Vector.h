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
	
	// Vector typedefs
	typedef glm::ivec2 IVec2;
	typedef glm::fvec2 FVec2;
	typedef glm::dvec2 DVec2;
	typedef glm::ivec3 IVec3;
	typedef glm::fvec3 FVec3;
	typedef glm::dvec3 DVec3;
	typedef glm::ivec4 IVec4;
	typedef glm::fvec4 FVec4;
	typedef glm::dvec4 DVec4;
	
	
	// Angle unit conversions
	inline float ToRadians(float degrees) {
		return glm::radians(degrees);
	}
	inline float ToDegrees(float radians) {
		return glm::degrees(radians);
	}
	
	/** Calculates the length of a vector */
	template <typename Vec>
	inline float VectorLength(const Vec &vec) {
		return glm::length(vec);
	}
	
	
	/** Normalizes a vector. A zero vector returns a zero vector */
	template <typename Vec>
	inline Vec VectorNormalize(const Vec &vec) {
		if ( VectorLength(vec) == 0 ) return vec;
		else return glm::normalize(vec);
	}
	
}

#endif /* defined(__AGE__Size__) */
