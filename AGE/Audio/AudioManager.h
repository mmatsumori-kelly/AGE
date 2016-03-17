//
//  AudioManager.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/14/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__AudioManager__
#define __AGE__AudioManager__


#include "AudioSource.h"
#include "../Vector.h"

namespace age {
	class AGEDevice;
	
	
	namespace audio {
		
		
		/** Manages audio playback */
		class AudioManager {
			AGEDevice *device;
			void *al_context, *al_device;
			
			AudioManager(AGEDevice *Device, void *al_context, void *al_device);
			
		public:
			static AudioManager* New(AGEDevice *device);
			
			
			
			/** Sets the listener position */
			void SetListenerPosition(const FVec3 &position);
			/** Sets the listener velocity */
			void SetListenerVelocity(const FVec3 &velocity);
			/** Sets the listener rotation */
			void SetListenerRotation(const FVec3 &rotation);
			
		};
		
	}
}

#endif /* defined(__AGE__AudioManager__) */
