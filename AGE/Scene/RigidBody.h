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
		
		
		
		class RigidBody {
			btRigidBody *rigidbody;
			
			
			
			
		public:
			RigidBody(CollisionShape *shape, float mass);
			
			
			void SetStatic(bool st);
			void SetActive(bool active);
			
			void SetPosition(const FVec3 &pos);
			
			
			inline btRigidBody* GetInternalRigidBody() const {
				return rigidbody;
			}
			
		};
		
		
		
		
		
		
	}
}

#endif /* defined(__AGE__RigidBody__) */
