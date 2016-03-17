//
//  OBJModel.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/13/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__OBJModel__
#define __AGE__OBJModel__


#include "IModel.h"


namespace age {
	namespace video {
		
		
		
		class OBJModel : public IModel {
			unsigned int vao, vbo;
			std::vector<VertexInfo> vertex_data;
			
		public:
			virtual ~OBJModel();
			/** Loads a simple model from a file */
			static OBJModel* Load(const File &file);
			
			/** Returns the vertices */
			virtual inline std::vector<VertexInfo>& GetVertexInfo() override {
				return vertex_data;
			}
			
			
			/** Renders the model */
			virtual void Render() override;
		};
		
		
	}
}

#endif /* defined(__AGE__OBJModel__) */
