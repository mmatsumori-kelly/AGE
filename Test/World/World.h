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
	
	
	
	class World {
		age::File world_folder;
		
		Dimension *current_dimension;
		std::vector<Dimension*> loaded_dimensions;
		
		World(const age::File &world_folder);
		
	public:
		static World* New(const age::File &world_folder);
		static World* Load(const age::File &world_folder);
		~World();
		
		
		/** Returns the world folder */
		inline const age::File& GetSaveFolder() const {
			return world_folder;
		}
		
		
		
		
		/** Loads the given dimension */
		void ChangeDimension(const std::string &name);
		/** Loads the given dimension */
		Dimension* LoadDimension(const std::string &name);
		/** Returns the current dimension */
		inline Dimension* GetCurrentDimension() const {
			return current_dimension;
		}
		/** Checks if the given dimension is loaded */
		inline bool IsDimensionLoaded(const std::string &name) const {
			for (auto dim : loaded_dimensions)
				if ( dim->GetName().compare(name) == 0 ) return true;
			return false;
		}
		
		
		
		void Update(const age::UpdateInfo &info);
		void Render(const age::UpdateInfo &info);
	};
	
	
}

#endif /* defined(__AGE__World__) */
