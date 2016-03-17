//
//  SimpleModel.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__SimpleModel__
#define __AGE__SimpleModel__

#include "IModel.h"
#include "../File.h"


namespace age {
	namespace video {
		
		
		
		/** A simple model */
		class SimpleModel : public IModel {
			unsigned int vao, vbo;
			std::vector<VertexInfo> vertex_data;
			
			
			SimpleModel(const std::vector<VertexInfo> &data, unsigned int vao, unsigned int vbo);
			
			
		public:
			virtual ~SimpleModel();
			/** Loads a simple model from a file */
			static SimpleModel* Load(const File &file);
			
			/** Returns the vertices */
			virtual inline std::vector<VertexInfo>& GetVertexInfo() override {
				return vertex_data;
			}
			
			
			/** Renders the model */
			virtual void Render() override;
		};
		
	}
}

#endif /* defined(__AGE__SimpleModel__) */
