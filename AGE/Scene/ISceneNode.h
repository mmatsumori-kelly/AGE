//
//  ISceneNode.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/22/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__ISceneNode__
#define __AGE__ISceneNode__

#include "../Update.h"
#include "../Handle.h"

namespace age {
	namespace scene {
		class ParentNode;
		
		
		class ISceneNode : public IRefCounted {
			friend class ParentNode;
			
		protected:
			ParentNode *parent;
			
		public:
			ISceneNode() : parent(nullptr) { }
			virtual ~ISceneNode() { }
			
			
			inline ParentNode* GetParent() {
				return parent;
			}
			
			
			virtual void Update(const UpdateInfo &info) = 0;
			virtual void Render(const UpdateInfo &info) = 0;
		};
		
		
		
	}
}

#endif /* defined(__AGE__ISceneNode__) */
