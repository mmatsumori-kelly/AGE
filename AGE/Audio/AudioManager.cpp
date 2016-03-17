//
//  AudioManager.cpp
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/14/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#include "AudioManager.h"

#include <OpenAL/al.h>
#include <OpenAL/alc.h>


using namespace age;
using namespace age::audio;


AudioManager::AudioManager(AGEDevice *device, void *al_context, void *al_device) : device(device), al_context(al_context), al_device(al_device) {
	
}
AudioManager* AudioManager::New(age::AGEDevice *device) {
	
	// Open a new audio device
	ALCdevice *al_device = alcOpenDevice(alcGetString(nullptr, ALC_DEFAULT_DEVICE_SPECIFIER));
	if ( device == nullptr ) return nullptr;
	
	ALCcontext *al_context = alcCreateContext(al_device, nullptr);
	alcMakeContextCurrent(al_context);
	
	
	alListener3f(AL_POSITION, 0, 0, 0);
	alListener3f(AL_VELOCITY, 0, 0, 0);
	alListener3f(AL_ORIENTATION, 0, 0, -1);
	
	
	return new AudioManager(device, al_context, al_device);
}




