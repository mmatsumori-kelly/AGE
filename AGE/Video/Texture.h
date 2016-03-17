//
//  Texture.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/7/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Texture__
#define __AGE__Texture__

#include "../File.h"

namespace age {
	namespace video {
		
		
		/** A class used to texture a model */
		class Texture {
			unsigned int tex_id;
			int width, height;
			
			inline Texture(unsigned int tex_id, int width, int height) : tex_id(tex_id), width(width), height(height) { }
			
		public:
			static Texture *Load(const File &file);
			
			
			
			/** Returns the width of the texture */
			inline int GetWidth() const {
				return width;
			}
			/** Returns the height of the texture */
			inline int GetHeight() const {
				return height;
			}
			
			
			/** returns the texture id */
			
			
			/** Binds this texture */
			void BindTexture();
			/** Unbinds texture */
			static void UnbindTexture();
			
		};
		
		
	}
}

#endif /* defined(__AGE__Texture__) */
