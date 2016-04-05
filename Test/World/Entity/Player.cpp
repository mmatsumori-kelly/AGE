//
//  Player.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Player.h"
#include "../../Game.h"
#include <BulletPhysics/btBulletDynamicsCommon.h>

using namespace age;
using namespace age::gui;
using namespace age::scene;
using namespace shootergame;





Player::Player(Dimension *dimension) : Entity(dimension, 0), movement_speed(1.0f), is_mouse_down(false), was_mouse_down(false) {
	Game::Current()->GetDevice()->GetDisplay()->CaptureMouse(true);
	
	SetPosition(FVec3(0, 20, 0));
}


void Player::Update(const age::UpdateInfo &info) {
	Entity::Update(info);
	
	AGEDevice *device = Game::Current()->GetDevice();
	
	// Store some useful variables...
	Camera *camera = device->GetSceneManager()->GetCamera();
	Mouse *mouse = device->GetDisplay()->GetMouse();
	Keyboard *keyboard = device->GetDisplay()->GetKeyboard();
	
	// Change rotation
	FVec3 rotation;
	rotation.x += mouse->GetDeltaY() * info.delta_time.Seconds() * 5;
	rotation.y += mouse->GetDeltaX() * info.delta_time.Seconds() * 5;
	camera->Rotate(rotation);
	
	rotation = camera->GetRotation();
	
	
	
	
	// Change position
	float xm = 0, zm = 0;
	if ( keyboard->IsKeyPressed(AGE_KEY_W) ) zm++;
	if ( keyboard->IsKeyPressed(AGE_KEY_S) ) zm--;
	if ( keyboard->IsKeyPressed(AGE_KEY_D) ) xm++;
	if ( keyboard->IsKeyPressed(AGE_KEY_A) ) xm--;
	
	
	if ( keyboard->IsKeyPressed(AGE_KEY_SPACE) ) velocity.y = 10;
//	if ( keyboard->IsKeyPressed(AGE_KEY_LEFT_SHIFT) );
	
	
	FVec3 forward = camera->GetForwardVector(); forward.y = 0;
	velocity += forward * zm * movement_speed;
	velocity += camera->GetRightVector()   * xm * movement_speed;
	velocity.y += -9.8f * info.delta_time.Seconds();
	
	
	// Mouse
	is_mouse_down = mouse->IsButtonPressed(AGE_MOUSE_LEFT);
	if ( is_mouse_down && !was_mouse_down ) {
		was_mouse_down = true;
	}
	
}
void Player::Render(const age::UpdateInfo &info) {
	Camera *camera = Game::Current()->GetDevice()->GetSceneManager()->GetCamera();
	
	camera->SetPosition(GetPosition() + FVec3(0, 1, 0));
	camera->Update();
	
	Entity::Render(info);
}






