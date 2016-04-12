#include "AGE.h"

using namespace age;
using namespace age::gui;






AGEDevice::AGEDevice(Display *display) : display(display) {
	
	// Initialize engine variables
	fps = 0;
	ups = 0;
	locked_fps = -1;
	locked_ups = 120;
	
	print_fps = true;
	print_ups = false;
	
	running = false;
	started = false;
	
	scene_manager = new scene::SceneManager(this);
//	audio_manager = new audio::AudioManager(this);
}


AGEDevice* AGEDevice::New() {
	
	// Create new display
	Display *display = Display::New();
	if ( display == nullptr ) {
		error << "Could not create AGE device" << endline;
		return nullptr;
	}
	else {
		
		// Make display current and return it
		display->MakeCurrent();
		AGEDevice *device = new AGEDevice(display);
		
		return device;
	}
}





void AGEDevice::UpdateLoopStarter(void *device) {
	((AGEDevice*)device)->UpdateLoop();
}
void AGEDevice::Start() {
	if ( !IsRunning() && !started ) {
		running = started = true;
		LogMessage("Started AGE Device");
		
		// Start the two loops
		update_thread.Start(UpdateLoopStarter, this, true);
		RenderLoop();
	}
}
void AGEDevice::Stop() {
	if ( IsRunning() ) {
		LogMessage("Stopping engine");
		
		
		
		// Get the update thread to stop too
		running = false;
		update_thread.Join();
		
		// Call the exit callback if it exists
		if ( exit_callback != nullptr )
			exit_callback();
		
		delete scene_manager;
		delete display;
		
		// Exit the engine
		exit(0);
	}
}


void AGEDevice::UpdateLoop() {
	
	// Start the update timer
	update_timer.Start();
	ups_timer   .Start();
	
	
	double update_delta_time = 0;
	int update_count = 0;
	
	
	
	// Logic loop
	while ( IsRunning() ) {
		
		UpdateInfo info;
		info.device = this;
		info.delta_time = update_timer.GetTime();
		float requested_ups = locked_ups;
		
		
		
		// Check if an update is required
		if ( (update_delta_time = update_timer.GetTime().Seconds()) >= ((requested_ups <= 0) ? 0 : (1.0 / requested_ups)) ) {
			
			// Call the update callback
			scene_manager->Update(info);
			if ( update_callback != nullptr ) update_callback(info);
			
			
			++update_count;
			update_timer.Start();
		}
		
		
		// Check if it is time for a UPS print
		if ( ups_timer.GetTime().Seconds() >= 1.0 ) {
			ups = update_count;
			ups_timer.Start();
			
			// Print the ups
			if ( print_ups ) {
				LogMessage("UPS: %i", (int)update_count);
			}
			
			update_count = 0;
		}
	}
}
void AGEDevice::RenderLoop() {
	
	// Start the render timer
	render_timer.Start();
	fps_timer   .Start();
	
	
	double render_delta_time = 0;
	int frame_count = 0;
	
	
	// Render loop
	while ( IsRunning() ) {
		
		
		UpdateInfo info;
		info.device = this;
		info.delta_time = render_timer.GetTime();
		float requested_fps = locked_fps;
		
		
		// Check if an update is required
		if ( (render_delta_time = render_timer.GetTime().Seconds()) >= ((requested_fps <= 0) ? 0 : (1.0 / requested_fps)) ) {
			// Begin the render
			Display *display = GetDisplay();
			display->BeginRender();
			
			// Render the stuff
			scene_manager->Render(info);
			if ( render_callback != nullptr ) render_callback(info);
			
			// Finish up the render
			display->FinishRender();
			display->PollEvents(this);
			
			++frame_count;
			render_timer.Start();
		}
		
		
		// Check if it is time for a UPS print
		if ( fps_timer.GetTime().Seconds() >= 1.0 ) {
			fps = frame_count;
			frame_count = 0;
			fps_timer.Start();
			
			// Print the fps
			if ( print_fps ) {
				LogMessage("FPS: %i", (int)fps);
			}
		}
	}
}

