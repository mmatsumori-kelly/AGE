//
//  Shader.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/26/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Shader__
#define __AGE__Shader__

#include "../File.h"
#include "../Matrix.h"
#include "../Handle.h"

namespace age {
	namespace video {
		
		/** Shader type */
		enum ShaderType {
			AGE_SHADER_VERTEX,
			AGE_SHADER_FRAGMENT,
		};
		
		
		/** A source object for a shader program */
		class ShaderSource {
			unsigned int source_id;
			
			
			inline ShaderSource(unsigned int source_id) : source_id(source_id) { }
			
		public:
			~ShaderSource();
			
			/** Loads a shader from a file */
			static ShaderSource* Load(const File &file, ShaderType shader_type);
			/** Loads a shader from a string */
			static ShaderSource* New(const std::string &shader_source, ShaderType shader_type);
			
			/** Returns the ID */
			inline unsigned int GetID() const {
				return source_id;
			}
		};
		
		
		
		/** A shader program */
		class ShaderProgram : public IRefCounted {
			unsigned int program_id;
			bool created;
			
		public:
			ShaderProgram();
			~ShaderProgram();
			
			/** Checks if the program has been linked yet */
			inline bool IsLinked() const {
				return created;
			}
			
			/** Attachs a shader source */
			void AttachShader(ShaderSource *source);
			/** Links the shader program */
			bool LinkProgram();
			/** Uses the shader program */
			void UseProgram();
			/** Stops using the shader program */
			static void UnbindProgram();
			
			
			/** Sets the model matrix uniform */
			void SetModelMatrix(const FMat4 &model_matrix) {
				SetUniform("M", model_matrix);
			}
			/** Sets the view matrix uniform */
			void SetViewMatrix(const FMat4 &view_matrix) {
				SetUniform("V", view_matrix);
			}
			/** Sets the model-view-projection matrix uniform */
			void SetMVPMatrix(const FMat4 &mvp_matrix) {
				SetUniform("MVP", mvp_matrix);
			}
			/** Sets the camera position uniform */
			void SetCameraPosition(const FVec3 &position) {
				SetUniform("camera_position", position);
			}
			
			
			
			
			/** Uniforms */
			void SetUniform(const std::string &name, float* values, int count);
			void SetUniform(const std::string &name, const float value);
			void SetUniform(const std::string &name, glm::vec2* vectors, int count);
			void SetUniform(const std::string &name, const glm::vec2 &vector);
			void SetUniform(const std::string &name, glm::vec3* vectors, int count);
			void SetUniform(const std::string &name, const glm::vec3 &vector);
			void SetUniform(const std::string &name, glm::vec4* vectors, int count);
			void SetUniform(const std::string &name, const glm::vec4 &vector);
			void SetUniform(const std::string &name, glm::mat3* matrices, int count);
			void SetUniform(const std::string &name, const glm::mat3 &matrix);
			void SetUniform(const std::string &name, glm::mat4* matrices, int count);
			void SetUniform(const std::string &name, const glm::mat4 &matrix);
			void SetUniform(const std::string &name, int* values, int count);
			void SetUniform(const std::string &name, const int value);
		};
		
		
	}
}

#endif /* defined(__AGE__Shader__) */
