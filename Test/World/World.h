//
//  World.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/28/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__World__
#define __AGE__World__

#include "Player.h"
#include "Dimension.h"

namespace shootergame {
	
	
	
	class World : public age::scene::ParentNode {
		age::File world_folder;
		
		Player *player;
		Dimension *current_dimension;
		
		
		World(const age::File &world_folder);
		
	public:
		static World* New(const age::File &world_folder);
		static World* Load(const age::File &world_folder);
		~World();
		
		
		/** Returns the world folder */
		inline const age::File& GetSaveFolder() const {
			return world_folder;
		}
		
		/** Returns the player */
		inline Player* GetPlayer() const {
			return player;
		}
		
		
		
		/** Returns the current dimension */
		inline Dimension* GetCurrentDimension() const {
			return current_dimension;
		}
		/** Loads the given dimension */
		void ChangeDimension(const std::string &name);
		/** Loads the given dimension */
		Dimension* LoadDimension(const std::string &name);
		/** Checks if the given dimension is loaded */
		inline bool IsDimensionLoaded(const std::string &name) const {
			return ContainsChild(name);
		}
		
		
		virtual void Update(const age::UpdateInfo &info) override;
		virtual void Render(const age::UpdateInfo &info) override;
	};
	
	
}

#endif /* defined(__AGE__World__) */
