//
//  Texture.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/7/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "Texture.h"
#include "../Debug.h"

#include <OpenGL/gl3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>


using namespace age;
using namespace age::video;






Texture *Texture::Load(const age::File &file) {
	if ( !file.Exists() ) {
		error << "Could not load file \"" << file << "\"" << endline;
		return nullptr;
	}
	else {
		unsigned char *image;
		
		int width, height, comp;
		image = stbi_load(file, &width, &height, &comp, STBI_rgb_alpha);
		
		
		if ( image == nullptr ) {
			error << "Error loading image at \"" << file << "\"" << endline;
			return nullptr;
		}
		else {
			GLuint tex_id;
			glGenTextures(0, &tex_id);
			glBindTexture(GL_TEXTURE_2D, tex_id);
			
			// Upload texture
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			
			// Set texture parameters
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			
			// Finish up
			glBindTexture(GL_TEXTURE_2D, 0);
			stbi_image_free(image);
			
			return new Texture(tex_id, width, height);
		}
	}
}


void Texture::BindTexture() {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex_id);
}
void Texture::UnbindTexture() {
	glBindTexture(GL_TEXTURE_2D, 0);
}



