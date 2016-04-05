//
//  Game.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Game__
#define __AGE__Game__

#include "AGE.h"
#include "World.h"

namespace shootergame {
	
	
	
	
	class Game {
		static Game instance;
		age::AGEDevice *device;
		
		World* world;
		
		age::File game_folder;
		
		
	public:
		Game();
		~Game();
		
		
		static inline Game* Current() {
			return &instance;
		}
		inline age::AGEDevice* GetDevice() {
			return device;
		}
		
		/** Returns the game folder */
		inline const age::File& GetGameFolder() const {
			return game_folder;
		}
		/** Returns the models folder */
		inline age::File GetModelFolder() const {
			return game_folder.GetChild("Resources/Models");
		}
		/** Returns the shaders folder */
		inline age::File GetShaderFolder() const {
			return game_folder.GetChild("Resources/Shaders");
		}
		/** Returns the textures folder */
		inline age::File GetTextureFolder() const {
			return game_folder.GetChild("Resources/Textures");
		}
		/** Returns the scripts folder */
		inline age::File GetScriptFolder() const {
			return game_folder.GetChild("Resources/Scripts");
		}
		
		
		
		void Start();
		static void Exit();
		static void Update(const age::UpdateInfo &info);
		static void Render(const age::UpdateInfo &info);
		
	};
	
	
	
}

#endif /* defined(__AGE__Game__) */
