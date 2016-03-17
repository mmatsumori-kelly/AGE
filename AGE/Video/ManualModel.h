//
//  ManualModel.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/9/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__ManualModel__
#define __AGE__ManualModel__

#include "IModel.h"

namespace age {
	namespace video {
		
		
		/** A model with manually added vertex data */
		class ManualModel : public IModel {
			unsigned int vao, vbo;
			bool created;
			
			std::vector<VertexInfo> vertex_data;
			
			
		public:
			ManualModel() : created(false) { }
			virtual ~ManualModel();
			
			
			inline void ReserveData(long count) {
				vertex_data.reserve(count);
			}
			inline void AddVertexData(const VertexInfo &info) {
				vertex_data.push_back(info);
			}
//			inline void AddVertexData(const FVec3 &vertex, const FVec3 &normal, const FVec2 &uv) {
//				vertex_data.push_back(VertexInfo(vertex, normal, uv));
//			}
			
			/** Create the VAO */
			bool Create();
			/** Destroy the VAO for reuse */
			void Destroy();
			/** Checks if the VAO was created */
			inline bool IsCreated() const {
				return created;
			}
			
			
			virtual inline std::vector<VertexInfo>& GetVertexInfo() override {
				return vertex_data;
			}
			
			
			/** Render the model */
			virtual void Render() override;
		};
		
		
	}
}

#endif /* defined(__AGE__ManualModel__) */
