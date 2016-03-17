//
//  Player.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Player.h"
#include "../../Game.h"

using namespace age;
using namespace age::gui;
using namespace age::scene;
using namespace shootergame;





Player::Player() {
	FPSCamera *camera = new FPSCamera(1.66f, 45, 0.1f, 100.0f);
	Game::Current()->GetDevice()->GetSceneManager()->SetCamera(camera);
	Game::Current()->GetDevice()->GetDisplay()->CaptureMouse(true);
	
	position = FVec3(8, 20, 8);
}


void Player::Update(const age::UpdateInfo &info) {
	Entity::Update(info);
}
void Player::Render(const age::UpdateInfo &info) {
	Entity::Render(info);
	
	AGEDevice *device = GetParent()->GetSceneManager()->GetDevice();
	
	// Store some useful variables...
	FPSCamera *camera = (FPSCamera*)device->GetSceneManager()->GetCamera();
	Mouse &mouse = device->GetDisplay()->GetMouse();
	Keyboard &keyboard = device->GetDisplay()->GetKeyboard();
	
	// Change rotation
	FVec3 rotation;
	rotation.x += mouse.GetDeltaY() / 10.0;
	rotation.y += mouse.GetDeltaX() / 10.0;
	rotation.z = 0;
	camera->Rotate(rotation);
	
	rotation = camera->GetRotation();
	
	
	
	
	// Change position
	float xm = 0, zm = 0;
	if ( keyboard.IsKeyPressed(AGE_KEY_W) ) zm++;
	if ( keyboard.IsKeyPressed(AGE_KEY_S) ) zm--;
	if ( keyboard.IsKeyPressed(AGE_KEY_D) ) xm++;
	if ( keyboard.IsKeyPressed(AGE_KEY_A) ) xm--;
	
	
	FVec3 movement;
	
	movement += camera->GetForwardVector() * (float)info.delta_time.Seconds() * zm * 2.0f;
	movement += camera->GetRightVector() * (float)info.delta_time.Seconds() * xm * 2.0f;
	movement.y = 0;
	
	if ( keyboard.IsKeyPressed(AGE_KEY_SPACE) ) movement.y = 5 * (float)info.delta_time.Seconds();
	if ( keyboard.IsKeyPressed(AGE_KEY_LEFT_SHIFT) ) movement.y = -5 * (float)info.delta_time.Seconds();
	
	position += movement;
	
	camera->SetPosition(position + 2.0f);
}






