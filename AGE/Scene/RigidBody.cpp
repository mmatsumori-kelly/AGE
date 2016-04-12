//
//  RigidBody.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/18/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "RigidBody.h"
#include <BulletPhysics/btBulletDynamicsCommon.h>

using namespace age;
using namespace age::scene;







CollisionShape* CollisionShape::NewBoxShape(const FVec3 &half_extents) {
	btCollisionShape *shape = new btBoxShape(btVector3(half_extents.x, half_extents.y, half_extents.z));
	return new CollisionShape(shape);
}
CollisionShape::~CollisionShape() {
	delete collision_shape;
}




RigidBody::RigidBody(CollisionShape *shape, float mass) {
	btDefaultMotionState *motion_state = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
	
	// Calculate local inertia
	btVector3 local_inertia(0, 0, 0);
	shape->GetInternalShape()->calculateLocalInertia(mass, local_inertia);
	
	// Create and return rigidbody
	btRigidBody::btRigidBodyConstructionInfo rbci(mass, motion_state, shape->GetInternalShape(), local_inertia);
	rigidbody = new btRigidBody(rbci);
}


void RigidBody::SetPosition(const FVec3 &pos) {
	btTransform tr;
	tr.setOrigin(btVector3(pos.x, pos.y, pos.z));
	rigidbody->setWorldTransform(tr);
	rigidbody->getMotionState()->setWorldTransform(tr);
}

void RigidBody::SetStatic(bool st) {
	
}
void RigidBody::SetActive(bool active) {
	rigidbody->setActivationState(active ? DISABLE_DEACTIVATION : ISLAND_SLEEPING);
}



