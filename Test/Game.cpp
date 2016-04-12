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
#include <AGE/Environment.h>

using namespace age;
using namespace age::video;
using namespace shootergame;





Game *Game::instance = nullptr;
Game::Game() {
	instance = this;
	game_folder = Environment::Current()->GetUserFolder().GetChild("Desktop/AGE/Game");
}
Game::~Game() {
	
}


void Game::Start() {
	device = AGEDevice::New();
	
	if ( device != nullptr ) {
		device->GetDisplay()->SetTitle("ShooterGame");
		device->GetDisplay()->Maximize();
		
		device->SetUpdateCallback(Game::Update);
		device->SetRenderCallback(Game::Render);
		device->SetExitCallback(Game::Exit);
		
		
		// Load the texture atlases
		TextureAtlas<TEXTURE_ATLAS_BLOCK>::SetTexture(Texture::Load(GetTextureFolder().GetChild("block.png")));
		TextureAtlas<TEXTURE_ATLAS_BLOCK>::SetTileSize(512);
		
		
		// Load the block registry
		LoadRegistry();
		
		
		// Set up the world
		world = World::New(game_folder.GetChild("/Saves/World1"));
		
		
		
	
		
		// Start the device
		device->Start();
	}
}
void Game::Exit() {
	UnloadRegistry();
}


void Game::Update(const age::UpdateInfo &info) {
	
	World *world = Game::Current()->world;
	if ( world != nullptr )
		world->Update(info);
	
}
void Game::Render(const age::UpdateInfo &info) {
	
	World *world = Game::Current()->world;
	if ( world != nullptr )
		world->Render(info);
	
}



