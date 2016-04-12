//
//  Matrix.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Matrix__
#define __AGE__Matrix__

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Vector.h"

namespace age {
	
	// Matrix Typedefs
	typedef glm::fmat2 FMat2;
	typedef glm::fmat3 FMat3;
	typedef glm::fmat4 FMat4;
	
	
	
	/** Applies a rotation transformation to a matrix */
	inline FMat4 MatrixRotate(const FMat4 &matrix, float angle, const FVec3 &axis) {
		return glm::rotate(matrix, angle, axis);
	}
	/** Applies a linear translation to a matrix */
	inline FMat4 MatrixTranslate(const FMat4 &matrix, const FVec3 &translation) {
		return glm::translate(matrix, translation);
	}
	
	
	
	
}

#endif /* defined(__AGE__Matrix__) */
