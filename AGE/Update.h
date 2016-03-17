//
//  Update.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/26/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Update__
#define __AGE__Update__

#include "Timing.h"

namespace age {
	class AGEDevice;
	
	struct UpdateInfo {
		AGEDevice *device;
		Duration delta_time;
	};
	
	
	class Updatable {
	public:
		virtual void Update(const UpdateInfo &info) { }
	};
	class Renderable {
	public:
		virtual void Render(const UpdateInfo &info) { }
	};
	
	
}

#endif /* defined(__AGE__Update__) */
