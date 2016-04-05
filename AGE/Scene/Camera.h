//
//  SceneCamera.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__SceneCamera__
#define __AGE__SceneCamera__


#include "../Matrix.h"
#include "../Handle.h"
#include "../Video/Shader.h"

namespace age {
	namespace scene {
		
		
		
		class Camera : public IRefCounted {
			const float MAX_X_ROTATION = 87.0f;
			FVec3 position, rotation;
			FMat4 orientation, view_matrix, projection_matrix, vp_matrix;
			float aspect_ratio, fov;
			float near_z, far_z;
			
			void NormalizeAngles();
			void CalculateOrientation();
			void CalculateMatrices();
			
		public:
			Camera(float aspect_ratio, float fov, float near_z, float far_z);
			
			
			void Move(const FVec3 &offset) {
				position += offset;
			}
			void Rotate(const FVec3 &offset) {
				rotation += offset;
				NormalizeAngles();
			}
			
			
			/** Returns the orientation matrix */
			inline const FMat4& GetOrientationMatrix() const {
				return orientation;
			}
			/** Returns the view matrix */
			inline const FMat4& GetViewMatrix() const {
				return view_matrix;
			}
			/** Returns the projection matrix */
			inline const FMat4& GetProjectionMatrix() const {
				return projection_matrix;
			}
			/** Returns the View matrix * Projection Matrix */
			inline const FMat4& GetVPMatrix() const {
				return vp_matrix;
			}
			
			
			/** Returns the camera's position */
			inline const FVec3& GetPosition() const {
				return position;
			}
			/** Returns the camera's rotation */
			inline const FVec3& GetRotation() const {
				return rotation;
			}
			
			/** Sets the camera's position */
			inline void SetPosition(const FVec3 &position) {
				this->position = position;
			}
			/** Sets the camera's rotation */
			inline void SetRotation(const FVec3 &rotation) {
				this->rotation = rotation;
			}
			
			
			
			/** Returns a vector describing where the camera is looking at */
			inline FVec3 GetForwardVector() {
				return glm::vec3(glm::inverse(GetOrientationMatrix()) * glm::vec4(0, 0, -1, 1));
			}
			/** Returns a vector pointing the opposite direction of the forward vector */
			inline FVec3 GetBackwardVector() {
				return -GetForwardVector();
			}
			/** Returns a vector pointing to the right of the forward vector */
			inline FVec3 GetRightVector() {
				return glm::vec3(glm::inverse(GetOrientationMatrix()) * glm::vec4(1, 0, 0, 1));
			}
			/** Returns a vector pointing to the left of the forward vector */
			inline FVec3 GetLeftVector() {
				return -GetRightVector();
			}
			/** Returns a vector pointing above the camera */
			inline FVec3 GetUpVector() {
				return glm::vec3(glm::inverse(GetOrientationMatrix()) * glm::vec4(0, 1, 0, 1));
			}
			/** Returns a vector pointing below the camera */
			inline FVec3 GetDownVector() {
				return -GetUpVector();
			}
			
			
			
			
			
			/** Updates the camera (recalculates matrices) */
			virtual void Update();
			/** Updates a shader program's uniforms */
			virtual void UpdateProgram(video::ShaderProgram *program, const FMat4 &model_matrix);
		};
	}
}


#endif /* defined(__AGE__SceneCamera__) */
