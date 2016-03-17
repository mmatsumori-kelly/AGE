//
//  Game.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Game.h"
#include "World/TypeRegistry.h"
#include "World/TextureAtlas.h"

using namespace age;
using namespace age::video;
using namespace shootergame;





Game Game::instance = Game();
Game::Game() {
	game_folder = File("/Users/mmatsumori-kelly17/Desktop/AGE/Game");
}
Game::~Game() {
	UnloadRegistry();
}


void Game::Start() {
	device = AGEDevice::New();
	
	if ( device != nullptr ) {
		device->GetDisplay()->SetTitle("ShooterGame");
		device->GetDisplay()->Maximize();
		
		
		// Load the block registry
		LoadRegistry();
		
		device->SetUpdateCallback(Game::Update);
		device->SetRenderCallback(Game::Render);
		
		
		// Load the texture atlases
		TextureAtlas<TEXTURE_ATLAS_BLOCK>::SetTexture(Texture::Load(GetTextureFolder().GetChild("block.png")));
		TextureAtlas<TEXTURE_ATLAS_BLOCK>::SetTileSize(512);
		
		
		// Set up the world
		world = World::New(File("/Users/mmatsumori-kelly17/Desktop/AGE/Game/Saves/World1"));
		device->GetSceneManager()->GetParentNode()->AddChild("World", world);
		
		
		
	
		
		// Start the device
		device->Start();
	}
}
void Game::Update(const age::UpdateInfo &info) {
	
	World *world = Game::Current()->world;
	if ( world != nullptr ) {
		world->Update(info);
	}
}
void Game::Render(const age::UpdateInfo &info) {
	World *world = Game::Current()->world;
	if ( world != nullptr ) {
		world->Render(info);
	}
}


