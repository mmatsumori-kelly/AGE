//
//  Hitbox.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/26/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Hitbox__
#define __AGE__Hitbox__

#include <AGE/Vector.h>

namespace shootergame {
	
	
	struct AABBHitbox {
		age::FVec3 center, half_extents;
		
	public:
		AABBHitbox() : center(), half_extents() { }
		AABBHitbox(const age::FVec3 &center, const age::FVec3 &he) : center(center), half_extents(he) { }
		
		inline bool ContainsPoint(const age::FVec3 &point) const {
//			age::FVec3 distance = center - point;
//			return (fabs(distance.x) < half_extents.x) & (fabs(distance.y) < half_extents.y) & (fabs(distance.z) < half_extents.z);
			
			return (point.x > (center.x - half_extents.x) && point.x < (center.x + half_extents.x) &&
					point.y > (center.y - half_extents.y) && point.y < (center.y + half_extents.y) &&
					point.z > (center.z - half_extents.z) && point.z < (center.z + half_extents.z));
		}
		inline bool Intersects(const AABBHitbox &other) const {
			if ( fabs(center.x - other.center.x) > (half_extents.x + other.half_extents.x) ) return false;
			if ( fabs(center.y - other.center.y) > (half_extents.y + other.half_extents.y) ) return false;
			if ( fabs(center.z - other.center.z) > (half_extents.z + other.half_extents.z) ) return false;
			return true;
		}
		
		
		inline AABBHitbox operator +(const age::FVec3 &move) const {
			return AABBHitbox(center + move, half_extents);
		}
		
	};
	
}

#endif /* defined(__AGE__Hitbox__) */
