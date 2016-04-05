//
//  Raycast.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/31/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Raycast__
#define __AGE__Raycast__


#include <AGE/Vector.h>
#include "Hitbox.h"

namespace shootergame {
	class Block;
	class Dimension;
	
	
	/** Performs a simple raycast test to determine the first block that lies along the ray formed by a point and a direction */
	Block* WorldRaycastTest(Dimension *dimension, const age::FVec3 &ray_start, const age::FVec3 &direction, float max_distance);
	/** Performs a simple raycast test to determine the first block that lies along the ray formed by a point and a direction */
	Block* WorldRaycastTestHitbox(Dimension *dimension, const AABBHitbox &hitbox, const age::FVec3 &ray_start, const age::FVec3 &direction, float max_distance);
	/** Performs a simple raycast test to determine the contact point of the first block that lines along the ray given */
	glm::vec3 WorldRaycastGetContactPoint(Dimension* dimension, glm::vec3 ray_start, glm::vec3 direction, float max_move_amt);
	
	
	
	/** Performs a very precise raycast. Acts the same as the less-precise version of this function, but is more precise and takes longer to perform */
	glm::vec3 WorldRaycastGetContactPoint_PRECISE(Dimension* dimension, glm::vec3 ray_start, glm::vec3 direction, float max_move_amt);
	
}

#endif /* defined(__AGE__Raycast__) */
