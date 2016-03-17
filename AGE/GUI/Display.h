//
//  Display.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/22/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Display__
#define __AGE__Display__

#include <string>
#include "../Vector.h"
#include "Input.h"

namespace age {
	class AGEDevice;
	
	namespace gui {
		
		/** A display to draw on */
		class Display {
			void *window;
			Keyboard keyboard;
			Mouse mouse;
			
			
			
			Display(void *window);
			
			
		public:
			/** Creates a new display */
			static Display* New();
			~Display();
			
			/** Returns the GLFW window handle */
			inline void *GetWindowHandle() {
				return window;
			}
			
			/** Returns the keyboard */
			inline Keyboard& GetKeyboard() {
				return keyboard;
			}
			/** Returns the mouse */
			inline Mouse& GetMouse() {
				return mouse;
			}
			
			/** Sets if teh mouse is captured or not */
			void CaptureMouse(bool captured);
			
			
			/** Sets the window title */
			void SetTitle(const std::string &name);
			/** Sets the window size */
			void SetSize(const IVec2 &size);
			/** Sets the window location */
			void SetLocation(const IVec2 &location);
			/** Gets the window size */
			IVec2 GetSize();
			/** Gets the window location */
			IVec2 GetLocation();
			
			
			/** Maximizes the window */
			void Maximize();
			/** Makes the window's OpenGL context current */
			void MakeCurrent();
			
			
			/** Begins the rendering process */
			void BeginRender();
			/** Finishes the rendering process */
			void FinishRender();
			/** Polls window events */
			void PollEvents(AGEDevice *device);
			
			
		};
		
		
	}
}

#endif /* defined(__AGE__Display__) */
