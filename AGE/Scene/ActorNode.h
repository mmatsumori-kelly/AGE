//
//  ActorNode.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__ActorNode__
#define __AGE__ActorNode__

#include "ISceneNode.h"
#include "../Video/IModel.h"
#include "../Video/Shader.h"
#include "../Video/Texture.h"
#include "../Vector.h"

namespace age {
	namespace scene {
		
		
		/** An actor */
		class ActorNode : public ISceneNode {
		protected:
			FVec3 position, rotation;
			FVec3 velocity;
			
			video::IModel *model;
			video::ShaderProgram *shader;
			video::Texture *texture;
			
			
			
			
		public:
			ActorNode();
			~ActorNode();
			
			
			void SetPosition(const FVec3 &position) {
				this->position = position;
			}
			void SetRotation(const FVec3 &rotation) {
				this->rotation = rotation;
			}
			void SetVelocity(const FVec3 &velocity) {
				this->velocity = velocity;
			}
			FVec3 GetPosition() const {
				return position;
			}
			FVec3 GetRotation() const {
				return rotation;
			}
			FVec3 GetVelocity() const {
				return velocity;
			}
			
			void SetModel(video::IModel *model) {
				this->model = model;
			}
			void SetShaderProgram(video::ShaderProgram *program) {
				shader = program;
			}
			void SetTexture(video::Texture *texture) {
				this->texture = texture;
			}
			
			
			virtual void Update(const UpdateInfo &info) override;
			virtual void Render(const UpdateInfo &info) override;
		};
		
		
		
	}
}

#endif /* defined(__AGE__ActorNode__) */
