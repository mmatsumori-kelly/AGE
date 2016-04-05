//
//  SceneManager.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/22/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__SceneManager__
#define __AGE__SceneManager__

#include "ParentNode.h"
#include "../Update.h"
#include "Camera.h"
#include "PhysicsWorld.h"

namespace age {
	class AGEDevice;
	
	
	namespace scene {
		class SceneManager : public Updatable, public Renderable, public IRefCounted {
			ParentNode *parent_node;
			AGEDevice *device;
			Camera *camera;
			
			
		public:
			SceneManager(AGEDevice *device);
			~SceneManager();
			
			
			/** Returns the parent node */
			inline ParentNode* GetParentNode() {
				return parent_node;
			}
			/** Returns the AGEDevice associated with this scene manager */
			inline AGEDevice *GetDevice() {
				return device;
			}
			
			
			/** Returns the camera */
			inline Camera* GetCamera() {
				return camera;
			}
			/** Sets the camera. This takes ownership of the camera */
			inline void SetCamera(Camera *camera) {
				delete this->camera;
				this->camera = camera;
			}
			
			
			
			
			/** Updates the scene */
			void Update(const UpdateInfo &info);
			/** Renders the scene */
			void Render(const UpdateInfo &info);
			
			
		};
	}
	
	
}

#endif /* defined(__AGE__SceneManager__) */
