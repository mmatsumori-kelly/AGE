//
//  RigidBody.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/18/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__RigidBody__
#define __AGE__RigidBody__

#include "../Vector.h"

class btCollisionShape;
class btRigidBody;

namespace age {
	namespace scene {
		class PhysicsWorld;
		
		
		
		/** Collision shape for rigidbody */
		class CollisionShape {
			btCollisionShape *collision_shape;
			
			inline CollisionShape(btCollisionShape *shape) : collision_shape(shape) { }
			
		public:
			~CollisionShape();
			
			inline btCollisionShape* GetInternalShape() const {
				return collision_shape;
			}
			
			
			/** Creates a new box shape */
			static CollisionShape* NewBoxShape(const FVec3 &half_extents);
		};
		
		
		/** Rigidbody for physics */
		class RigidBody {
			btRigidBody *rigidbody;
			
			
			
			
		public:
			RigidBody(CollisionShape *shape, float mass);
			
			
			/** Sets whether the body is static */
			void SetStatic(bool st);
			/** Sets whether the body is active */
			void SetActive(bool active);
			/** Sets the position of the body */
			void SetPosition(const FVec3 &pos);
			
			
			/** returns the internal rigidbody */
			inline btRigidBody* GetInternalRigidBody() const {
				return rigidbody;
			}
			
		};
		
		
		
		
		
		
	}
}

#endif /* defined(__AGE__RigidBody__) */
