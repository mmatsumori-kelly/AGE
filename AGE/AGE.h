/*
 *  AGE.h
 *  Abstracted Game Engine
 *
 *  Created by Mitchell Matsumori-Kelly on 2/22/16.
 *  Copyright (c) 2016 Phoenix. All rights reserved.
 *
 */

#ifndef AGE_
#define AGE_

/* The classes below are exported */
#pragma GCC visibility push(default)


#include "GUI/Display.h"
#include "Thread.h"
#include "Update.h"

#include "AGE_Everything.h"


namespace age {
	class AGEDevice;
	
	// Callback typedefs
	typedef void (*InitCallback)(void);
	typedef void (*ExitCallback)(void);
	typedef void (*UpdateCallback)(const UpdateInfo &info);
	typedef void (*RenderCallback)(const UpdateInfo &info);
	
	
	
	/** The game engine */
	class AGEDevice {
		// Important classes
		scene::SceneManager *scene_manager;
		audio::AudioManager *audio_manager;
		gui::Display *display;
		
		// Updates and Renders
		Timer  update_timer, ups_timer;
		Timer  render_timer, fps_timer;
		Thread update_thread;
		UpdateCallback update_callback = nullptr;
		RenderCallback render_callback = nullptr;
		InitCallback   init_callback = nullptr;
		ExitCallback   exit_callback = nullptr;
		
		// Timing
		Atomic<int> fps, ups, locked_fps, locked_ups;
		
		// Flags
		Atomic<bool> print_fps, print_ups;
		
		bool running, started;
		
		static void UpdateLoopStarter(void *device);
		void UpdateLoop();
		void RenderLoop();
		
		
		AGEDevice(gui::Display *display);
		
	public:
		static AGEDevice *New();
		
		
		
		/** Returns the framerate */
		inline int GetFPS() const {
			return fps;
		}
		/** Returns the updaterate */
		inline int GetUPS() const {
			return ups;
		}
		/** Returns the locked framerate */
		inline int GetLockedFrameRate() const {
			return locked_fps;
		}
		/** Returns the locked update rate */
		inline int GetLockedUpdateRate() const {
			return locked_ups;
		}
		/** Checks if the framerate is locked */
		inline bool IsFrameRateLocked() const {
			return locked_fps > 0;
		}
		/** Checks if the update rate is locked */
		inline bool IsUpdateRateLocked() const {
			return locked_ups > 0;
		}
		/** Locks the framerate. Use a value <= 0 for no lock */
		inline void LockFrameRate(int framerate) {
			locked_fps = framerate;
		}
		/** Locks the update rate. Use a value <= 0 for no lock */
		inline void LockUpdateRate(int updaterate) {
			locked_ups = updaterate;
		}
		
		/** Checks if the device is running */
		inline bool IsRunning() const {
			return running;
		}
		
		
		/** Sets the update callback */
		inline void SetUpdateCallback(UpdateCallback callback) {
			update_callback = callback;
		}
		/** Sets the render callback */
		inline void SetRenderCallback(RenderCallback callback) {
			render_callback = callback;
		}
		/** Sets the exit callback */
		inline void SetExitCallback(ExitCallback callback) {
			exit_callback = callback;
		}
		
		
		/** Returns the scene manager */
		inline scene::SceneManager* GetSceneManager() {
			return scene_manager;
		}
		/** Returns the audio manager */
		inline audio::AudioManager* GetAudioManager() {
			return audio_manager;
		}
		/** Returns the display */
		inline gui::Display* GetDisplay() {
			return display;
		}
		
		
		
		
		
		
		/** Starts the device */
		void Start();
		/** Stops the device */
		void Stop();
		
		
	};
};


#pragma GCC visibility pop
#endif
