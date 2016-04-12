//
//  TextureAtlas.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/9/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__TextureAtlas__
#define __AGE__TextureAtlas__

#include <AGE/Video/Texture.h>
#include <AGE/Vector.h>


namespace shootergame {
	
	
	enum TextureAtlasType {
		TEXTURE_ATLAS_BLOCK,
		TEXTURE_ATLAS_ITEM,
		TEXTURE_ATLAS_GUI
		
		
	};
	
	
	
	/** A texture atlas for rendering spritesheets */
	template <TextureAtlasType T> class TextureAtlas {
		static age::video::Texture *texture;
		static int tile_size;
		
		
		TextureAtlas() = delete;
	public:
		
		
		/** Gets the texture */
		static age::video::Texture* GetTexture() {
			return texture;
		}
		/** Sets the texture */
		static void SetTexture(age::video::Texture *texture) {
			TextureAtlas::texture = texture;
		}
		
		
		/** Sets the tile size of this atlas */
		static void SetTileSize(int tile_size) {
			TextureAtlas::tile_size = tile_size;
		}
		/** Returns texture coordinates */
		static age::FVec2 GetTextureCoords(float tile_x, float tile_y) {
			if ( tile_x < 0 ) tile_x = 0;
			if ( tile_y < 0 ) tile_y = 0;
			if ( tile_x * tile_size > texture->GetWidth() ) tile_x = texture->GetWidth() / tile_size;
			if ( tile_y * tile_size > texture->GetHeight() ) tile_y = texture->GetHeight() / tile_size;
			return age::FVec2((float)tile_x * tile_size / texture->GetWidth(), (float)tile_y * tile_size / texture->GetHeight());
		}
	};
	template <TextureAtlasType T> age::video::Texture* TextureAtlas<T>::texture = nullptr;
	template <TextureAtlasType T> int TextureAtlas<T>::tile_size = 0;
	

	
}

#endif /* defined(__AGE__TextureAtlas__) */
