//
//  GameScripting.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 3/8/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__GameScripting__
#define __AGE__GameScripting__


#include <AGE/Scripting/LuaScript.h>

namespace shootergame {
	
	
	
	/** Loads game libraries for a given state */
	void LoadGameLibraries(age::scripting::LuaState &state);
	
	
	
	
}

#endif /* defined(__AGE__GameScripting__) */
