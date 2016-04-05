//
//  Entity.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Entity__
#define __AGE__Entity__

#include <AGE/Scene/ActorNode.h>
#include <AGE/Scripting/LuaScript.h>
#include <unordered_map>
#include "../Hitbox.h"


namespace shootergame {
	
	class Dimension;
	class Block;
	
	class Entity  {
	protected:
		int entity_id;
		age::scripting::LuaState *state;
		std::unordered_map<std::string, age::scripting::LuaRef> entity_data;
		Dimension *dimension;
		
		
		AABBHitbox hitbox;
		age::FVec3 rotation, velocity;
		
		
	public:
		Entity(Dimension *dimension, int entity_id);
		
		
		/** Returns this entity's hitbox */
		inline const AABBHitbox& GetHitbox() const {
			return hitbox;
		}
		
		
		inline void SetPosition(const age::FVec3 &position) {
			hitbox.center = position;
		}
		inline void SetRotation(const age::FVec3 &rotation) {
			this->rotation = rotation;
		}
		inline void SetVelocity(const age::FVec3 &velocity) {
			this->velocity = velocity;
		}
		inline age::FVec3 GetPosition() {
			return hitbox.center;
		}
		inline age::FVec3 GetRotation() {
			return rotation;
		}
		inline age::FVec3 GetVelocity() {
			return velocity;
		}
		
		
		Block* GetBlockUnderneath() const;
		/** Checks if this entity can move the amount and direction given, and returns a vector describing the amount the entity can move */
		age::FVec3 GetAmountMoveableInDirection(const age::FVec3 &dir, float max_dist);
		
		
		
		virtual void Update(const age::UpdateInfo &info);
		virtual void Render(const age::UpdateInfo &info);
		
	};
	
	
}

#endif /* defined(__AGE__Entity__) */
