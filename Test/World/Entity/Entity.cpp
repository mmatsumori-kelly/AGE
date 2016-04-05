//
//  Entity.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Entity.h"
#include "../Dimension.h"
#include "../TypeRegistry.h"
#include "../Raycast.h"
#include <BulletPhysics/btBulletDynamicsCommon.h>

using namespace age;
using namespace age::scene;
using namespace shootergame;



Entity::Entity(Dimension *dimension, int entity_id)
: dimension(dimension), entity_id(entity_id), hitbox(FVec3(0, 0, 0), FVec3(1, 1, 1)) {
	state = &GetEntityState(entity_id);
	state->GetGlobal("NewInstance")(this);
	
}


Block* Entity::GetBlockUnderneath() const {
	return WorldRaycastTestHitbox(dimension, hitbox, hitbox.center + FVec3(0, -hitbox.half_extents.y, 0), FVec3(0, -1, 0), 0.5f);
}
/** Checks if this entity can move the amount and direction given, and returns a vector describing the amount the entity can move */
FVec3 Entity::GetAmountMoveableInDirection(const FVec3 &dir, float max_dist) {
	return WorldRaycastGetContactPoint(dimension, hitbox.center - hitbox.half_extents.y, dir, max_dist) - GetPosition();
}

void Entity::Update(const age::UpdateInfo &info) {
	state->GetGlobal("Update")(this, &info);
	
	
	Block *test_block = GetBlockUnderneath();
	if ( velocity.y < 0 && test_block != nullptr ) {
		velocity.y = 0;
		hitbox.center.y = test_block->GetHitbox().center.y + test_block->GetHitbox().half_extents.y + hitbox.half_extents.y;
	}
	
	test_block = WorldRaycastTestHitbox(dimension, hitbox, hitbox.center + FVec3(0, -hitbox.half_extents.y, 0), velocity, 0.5f);
//	if ( test_block != nullptr ) {
//		if ( test_block->GetAbsoluteX() > GetPosition().x ) velocity.x
//		
//	}
	
	
	
	// Friction
	velocity.x *= (1.0 / info.delta_time.Seconds()) * (1 / 130.0);
	velocity.z *= (1.0 / info.delta_time.Seconds()) * (1 / 130.0);
	
	
	// Position updates
	hitbox.center.x += velocity.x * info.delta_time.Seconds();
	hitbox.center.y += velocity.y * info.delta_time.Seconds();
	hitbox.center.z += velocity.z * info.delta_time.Seconds();
	
	
}
void Entity::Render(const age::UpdateInfo &info) {
	
}



