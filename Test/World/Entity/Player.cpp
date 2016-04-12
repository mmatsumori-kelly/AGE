//
//  Player.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Player.h"
#include "../../Game.h"
#include "../Raycast.h"

using namespace age;
using namespace age::gui;
using namespace age::scene;
using namespace shootergame;





Player::Player(Dimension *dimension) : Entity(dimension, 0), movement_speed(0.3f) {
	Game::Current()->GetDevice()->GetDisplay()->CaptureMouse(true);
	
	SetPosition(FVec3(0, 20, 0));
}



void Player::MouseDown(int button) {
	if ( button == 0 ) {
		age::error << "Hello" << age::endline;
		if ( selected_block != nullptr ) {
			age::error << "Hello2" << age::endline;
			selected_block->RemoveSelf();
			selected_block = nullptr;
		}
	}
}
void Player::MouseUp(int button) {
	
}



void Player::Update(const age::UpdateInfo &info) {
	Entity::Update(info);
	
	AGEDevice *device = Game::Current()->GetDevice();
	
	// Store some useful variables...
	Camera *camera = device->GetSceneManager()->GetCamera();
	Mouse *mouse = device->GetDisplay()->GetMouse();
	Keyboard *keyboard = device->GetDisplay()->GetKeyboard();
	
	
	/*======= MOUSE =======*/
	
	// Camera Rotation
	FVec3 rotation;
	rotation.x += mouse->GetDeltaY() * info.delta_time.Seconds() * 5;
	rotation.y += mouse->GetDeltaX() * info.delta_time.Seconds() * 5;
	camera->Rotate(rotation);
	
	rotation = camera->GetRotation();
	
	// Mouse button presses
	for (int i = 0; i < 3; ++i) {
		is_mouse_down[i] = mouse->IsButtonPressed((MouseButton)i);
		
		
		if ( is_mouse_down[i] && !was_mouse_down[i] ) {
			MouseDown(i);
			was_mouse_down[i] = true;
		}
		else if ( !is_mouse_down[i] && was_mouse_down[i] ) {
			MouseUp(i);
			was_mouse_down[i] = false;
		}
	}
	
	// Looked at block
	selected_block = WorldRaycastTest(dimension, camera->GetPosition(), camera->GetForwardVector(), 10);
	
	
	
	/*======= KEYBOARD =======*/
	
	// Change position
	float xm = 0, zm = 0;
	if ( keyboard->IsKeyPressed(AGE_KEY_W) ) zm++;
	if ( keyboard->IsKeyPressed(AGE_KEY_S) ) zm--;
	if ( keyboard->IsKeyPressed(AGE_KEY_D) ) xm++;
	if ( keyboard->IsKeyPressed(AGE_KEY_A) ) xm--;
	
	
	if ( keyboard->IsKeyPressed(AGE_KEY_SPACE) ) velocity.y = 5;
//	if ( keyboard->IsKeyPressed(AGE_KEY_LEFT_SHIFT) );
	
	
	FVec3 forward = camera->GetForwardVector(); forward.y = 0;
	if ( forward.length() != 0 ) forward = VectorNormalize(forward);
	velocity += forward * zm * movement_speed;
	velocity += camera->GetRightVector()   * xm * movement_speed;
	velocity.y += -9.8f * info.delta_time.Seconds();
	
	
}
void Player::Render(const age::UpdateInfo &info) {
	Camera *camera = Game::Current()->GetDevice()->GetSceneManager()->GetCamera();
	
	camera->SetPosition(GetPosition() + FVec3(0, 1, 0));
	camera->Update();
	
	Entity::Render(info);
}






