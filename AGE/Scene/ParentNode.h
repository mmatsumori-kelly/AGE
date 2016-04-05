//
//  ParentNode.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__ParentNode__
#define __AGE__ParentNode__

#include "ISceneNode.h"
#include <unordered_map>
#include <string>

namespace age {
	namespace scene {
		class SceneManager;
		
		
		class ParentNode : public ISceneNode {
			friend class SceneManager;
		protected:
			std::unordered_map<std::string, ISceneNode*> children;
			SceneManager *scene_manager;
			
		public:
			
			virtual ~ParentNode();
			
			/** Reserves some number of child objects */
			void ReserveChildren(long reservation) {
				children.reserve(reservation);
			}
			
			
			/** Transfers ownership to this parent node */
			virtual void AddChild(const std::string &name, ISceneNode* node)    {
				if ( node != nullptr ) {
					children[name] = node;
					node->parent = this;
				}
			}
			virtual void RemoveChild(const std::string &name) {
				children.erase(name);
			}
			inline bool ContainsChild(const std::string &name) const {
				return children.count(name) != 0;
			}
			inline ISceneNode* GetChild(const std::string &name) {
				return children[name];
			}
			
			
			inline SceneManager* GetSceneManager() {
				if ( parent != nullptr ) return parent->GetSceneManager();
				return scene_manager;
			}
			
			
			virtual void Update(const UpdateInfo &info) override;
			virtual void Render(const UpdateInfo &info) override;
		};
		
		
	}
}

#endif /* defined(__AGE__ParentNode__) */
