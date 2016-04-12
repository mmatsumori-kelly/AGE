//
//  Mouse.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/27/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__Mouse__
#define __AGE__Mouse__

namespace age {
	namespace gui {
		class Display;
		
		// Mouse enum
		enum MouseButton {
			AGE_MOUSE_LEFT,
			AGE_MOUSE_MIDDLE,
			AGE_MOUSE_RIGHT
		};
		
		
		/** Mouse input */
		class Mouse {
			double x, y;
			double old_x, old_y;
			bool first_update;
			Display *display;
			
		public:
			Mouse(Display *display) : display(display), x(0), y(0), old_x(0), old_y(0)  { }
			
			/** Returns the delta x movement of the mouse */
			inline double GetDeltaX() {
				return x - old_x;
			}
			/** Returns the delta y movement of the mouse */
			inline double GetDeltaY() {
				return y - old_y;
			}
			/** Returns the x position of the mouse */
			inline double GetX() {
				return x;
			}
			/** Returns the y position of the mouse */
			inline double GetY() {
				return y;
			}
			
			/** Checks if a mouse button is pressed */
			bool IsButtonPressed(MouseButton button);
			
			
			/** Updates the mouse */
			void Update();
		};
		
		
		
	}
}

#endif /* defined(__AGE__Mouse__) */
