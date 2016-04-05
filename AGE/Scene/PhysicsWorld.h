//
//  PhysicsManager.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__PhysicsManager__
#define __AGE__PhysicsManager__

#include "ParentNode.h"
#include "ActorNode.h"
#include "RigidBody.h"


class btBroadphaseInterface;
class btDefaultCollisionConfiguration;
class btCollisionDispatcher;
class btSequentialImpulseConstraintSolver;
class btDiscreteDynamicsWorld;
class btRigidBody;

namespace age {
	namespace scene {
		
		
		
		
		class PhysicsWorld {
			btBroadphaseInterface *broadphase;
			btDefaultCollisionConfiguration *collision_config;
			btCollisionDispatcher *collision_dispatcher;
			btSequentialImpulseConstraintSolver *solver;
			btDiscreteDynamicsWorld *dynamics_world;
			
			
		public:
			PhysicsWorld();
			virtual ~PhysicsWorld();
			
			
			
			void AddRigidBody(RigidBody *rigidbody);
			void RemoveRigidBody(RigidBody *rigidbody);
			void SetGravity(const FVec3 &gravity);
			
			
			void Update(const UpdateInfo &info);
			
		};
		
		
	}
}

#endif /* defined(__AGE__PhysicsManager__) */
