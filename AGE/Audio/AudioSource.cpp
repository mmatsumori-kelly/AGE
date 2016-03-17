//
//  AudioSource.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/14/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "AudioSource.h"
#include <OpenAL/al.h>
#include <OpenAL/alc.h>

using namespace age;
using namespace age::audio;




AudioSource* AudioSource::Load(const age::File &audio_file) {
	if ( !audio_file.Exists() ) return nullptr;
	else {
		
		
		ALuint source;
		alGenSources(1, &source);
		
		alSourcef(source, AL_PITCH, 1);
		alSourcef(source, AL_GAIN, 1);
		alSource3f(source, AL_POSITION, 0, 0, 0);
		alSource3f(source, AL_VELOCITY, 0, 0, 0);
		alSourcei(source, AL_LOOPING, AL_FALSE);
		
		
		ALuint buffer;
		alGenBuffers(1, &buffer);
		alSourcei(source, AL_BUFFER, buffer);
		
		
		return nullptr;
		
	}
}



