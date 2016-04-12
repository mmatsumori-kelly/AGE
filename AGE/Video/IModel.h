//
//  IModel.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__IModel__
#define __AGE__IModel__

#include "../Vector.h"
#include "../Handle.h"
#include "../File.h"


namespace age {
	namespace video {
		
		enum ModelType {
			AGE_MODEL_AUTO,
			
			AGE_MODEL_SMDL, // Simple Model
		};
		
		
		/** Information about a vertex */
		struct VertexInfo {
			FVec3 vertex;
			FVec2 uv;
			FVec3 normal;
			
			VertexInfo() : vertex(), normal(), uv() { }
			VertexInfo(const FVec3 &vertex, const FVec3 &normal, const FVec2 &uv) : vertex(vertex), normal(normal), uv(uv) { }
		};
		
		
		/** Model interface */
		class IModel : public IRefCounted {
		public:
			virtual ~IModel() { }
			
			/** Returns this model's vertex info */
			virtual std::vector<VertexInfo>& GetVertexInfo() = 0;
			/** Renders the model */
			virtual void Render() = 0;
		};
		
		
		/** Loads a model */
		IModel* LoadModel(const File &file, ModelType type = AGE_MODEL_AUTO);
		
	}
}

#endif /* defined(__AGE__IModel__) */
