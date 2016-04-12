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
			
			/** Sets the position of the actor */
			void SetPosition(const FVec3 &position) {
				this->position = position;
			}
			/** Sets the rotation of the actor */
			void SetRotation(const FVec3 &rotation) {
				this->rotation = rotation;
			}
			/** Sets the velocity of the actor */
			void SetVelocity(const FVec3 &velocity) {
				this->velocity = velocity;
			}
			/** Returns the position of the actor */
			FVec3 GetPosition() const {
				return position;
			}
			/** Returns the rotation of the actor */
			FVec3 GetRotation() const {
				return rotation;
			}
			/** Returns the velocity of the actor */
			FVec3 GetVelocity() const {
				return velocity;
			}
			
			/** Sets the actor's model */
			void SetModel(video::IModel *model) {
				this->model = model;
			}
			/** Sets the actor's shader */
			void SetShaderProgram(video::ShaderProgram *program) {
				shader = program;
			}
			/** Sets the actor's texture */
			void SetTexture(video::Texture *texture) {
				this->texture = texture;
			}
			
			
			/** Updates this actor */
			virtual void Update(const UpdateInfo &info) override;
			/** Renders this actor */
			virtual void Render(const UpdateInfo &info) override;
		};
		
		
		
	}
}

#endif /* defined(__AGE__ActorNode__) */
