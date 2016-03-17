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
		
		
		enum MouseButton {
			AGE_MOUSE_LEFT,
			AGE_MOUSE_MIDDLE,
			AGE_MOUSE_RIGHT
		};
		
		
		class Mouse {
			double x, y;
			double old_x, old_y;
			bool first_update;
			Display *display;
			
		public:
			Mouse(Display *display) : display(display), x(0), y(0), old_x(0), old_y(0)  { }
			
			
			inline double GetDeltaX() {
				return x - old_x;
			}
			inline double GetDeltaY() {
				return y - old_y;
			}
			inline double GetX() {
				return x;
			}
			inline double GetY() {
				return y;
			}
			
			
			bool IsButtonPressed(MouseButton button);
			
			
			
			void Update();
			
		};
		
		
		
	}
}

#endif /* defined(__AGE__Mouse__) */
