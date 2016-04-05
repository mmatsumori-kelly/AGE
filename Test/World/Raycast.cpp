//
//  Raycast.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/31/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Raycast.h"
#include "Dimension.h"

using namespace age;
using namespace shootergame;







Block* shootergame::WorldRaycastTest(Dimension *dimension, const age::FVec3 &ray_start, const age::FVec3 &dir, float radius) {
	FVec3 direction = VectorNormalize(dir);
	
	for (float t = 0; t <= radius; t += 0.1) {
		FVec3 t_position = ray_start + (direction * t);
		
		// Get the block whoes space (1, 1, 1) contains this point
		Block *block_at_t = dimension->GetBlockByCoord((long)t_position.x, (long)t_position.y, (long)t_position.z, false);
		if ( block_at_t != nullptr ) {
			const AABBHitbox &hitbox = block_at_t->GetHitbox();
			
			// Check the block's hitbox to make sure the given point is contained inside it */
			if ( hitbox.ContainsPoint(t_position) ) return block_at_t;
			else continue; // The hitbox doesn't contain it
		}
	}
	
	return nullptr;
}

Block* shootergame::WorldRaycastTestHitbox(Dimension *dimension, const AABBHitbox &hitbox, const age::FVec3 &ray_start,
										   const age::FVec3 &dir, float radius) {
	FVec3 direction = VectorNormalize(dir);
	
	for (float t = 0; t <= radius; t += 0.1) {
		FVec3 t_position = ray_start + (direction * t);
		AABBHitbox t_hitbox = hitbox + (direction * t);
		
		// Get the block whoes space (1, 1, 1) contains this point
		Block *block_at_t = dimension->GetBlockByCoord((long)t_position.x, (long)t_position.y, (long)t_position.z, false);
		if ( block_at_t != nullptr ) {
			const AABBHitbox &block_hitbox = block_at_t->GetHitbox();
			
			// Check the block's hitbox to make sure the given point is contained inside it */
			if ( block_hitbox.Intersects(t_hitbox) ) return block_at_t;
			else continue; // The hitbox doesn't contain it
		}
	}
	
	return nullptr;
}


glm::vec3 shootergame::WorldRaycastGetContactPoint(Dimension* dimension, glm::vec3 ray_start, glm::vec3 direction, float radius) {
	direction = normalize(direction);
	
	
	float t;
	for ( t = 0; t <= radius; t += 0.1 ) {
		glm::vec3 t_position = ray_start + (direction * t);
		
		// Get the block whoes space (1, 1, 1) contains this point
		Block *block_at_t = dimension->GetBlockByCoord((long)t_position.x, (long)t_position.y, (long)t_position.z, false);
		const AABBHitbox &hitbox = block_at_t->GetHitbox();
		
		// Check the block's hitbox to make sure the given point is contained inside it */
		if ( hitbox.ContainsPoint(t_position) ) {
			return t_position;
		}
		else continue; // The hitbox doesn't contain it
	}
	
	
	// There is no block in the way, so we can return the full distance
	return direction * radius;
}



glm::vec3 shootergame::WorldRaycastGetContactPoint_PRECISE(Dimension* dimension, glm::vec3 ray_start, glm::vec3 direction, float radius) {
	direction = normalize(direction);
	
	
	// Number of times the value of "t" increment is halved
	const int max_num_iterations = 2;
	
	
	
	
	float t;
	float inc_amt = 0.1, iteration_count = 0;
	for ( t = 0; t <= radius; t += inc_amt ) {
		glm::vec3 t_position = ray_start + (direction * t);
		
		// Get the block whoes space (1, 1, 1) contains this point
		Block *block_at_t = dimension->GetBlockByCoord((long)t_position.x, (long)t_position.y, (long)t_position.z, false);
		
		if ( block_at_t != nullptr ) {
			const AABBHitbox &hitbox = block_at_t->GetHitbox();
			
			
			// Check the block's hitbox to make sure the given point is contained inside it */
			if ( hitbox.ContainsPoint(t_position) ) {
				t -= inc_amt;   // Move back a bit
				inc_amt /= 2.0; // halve the increment value
				
				// Return the position ONLY if we have reached the correct number of iterations
				if ( (iteration_count++) == max_num_iterations ) return t_position; // Reached the number of iterations needed to be precise
			}
			else continue; // The hitbox doesn't contain it
		}
	}
	
	
	
	// There is no block in the way, so we can return the full distance
	return direction * radius;
}





