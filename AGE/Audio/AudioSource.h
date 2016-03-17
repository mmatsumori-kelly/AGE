//
//  AudioSource.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/14/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__AudioSource__
#define __AGE__AudioSource__

#include "../File.h"

namespace age {
	namespace audio {
		
		
		class AudioSource {
			
			
			
		public:
			/** Loads an audio file */
			static AudioSource* Load(const File &audio_file);
			
		};
		
		
	}
}

#endif /* defined(__AGE__AudioSource__) */
