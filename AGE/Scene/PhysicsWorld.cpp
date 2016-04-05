//
//  PhysicsManager.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "PhysicsWorld.h"
#include <BulletPhysics/btBulletDynamicsCommon.h>

using namespace age;
using namespace age::scene;




PhysicsWorld::PhysicsWorld() {
	broadphase = new btDbvtBroadphase();
	collision_config = new btDefaultCollisionConfiguration();
	collision_dispatcher = new btCollisionDispatcher(collision_config);
	solver = new btSequentialImpulseConstraintSolver();
	dynamics_world = new btDiscreteDynamicsWorld(collision_dispatcher, broadphase, solver, collision_config);
	dynamics_world->setGravity(btVector3(0, -10, 0));
	
}
PhysicsWorld::~PhysicsWorld() {
	delete dynamics_world;
	delete solver;
	delete collision_dispatcher;
	delete collision_config;
	delete broadphase;
}



void PhysicsWorld::AddRigidBody(age::scene::RigidBody *rigidbody) {
	dynamics_world->addRigidBody(rigidbody->GetInternalRigidBody());
}
void PhysicsWorld::RemoveRigidBody(age::scene::RigidBody *rigidbody) {
	dynamics_world->removeRigidBody(rigidbody->GetInternalRigidBody());
}
void PhysicsWorld::SetGravity(const FVec3 &gravity) {
	dynamics_world->setGravity(btVector3(gravity.x, gravity.y, gravity.z));
}



void PhysicsWorld::Update(const age::UpdateInfo &info) {
	dynamics_world->stepSimulation(info.delta_time.Seconds());
}

